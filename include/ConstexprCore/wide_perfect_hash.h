#ifndef CONSTEXPRCORE_WIDE_PERFECT_HASH_H
#define CONSTEXPRCORE_WIDE_PERFECT_HASH_H

// ============================================================================
// wide_perfect_hash_set / wide_perfect_hash_map — the N > 255 containers.
//
// Same philosophy as perfect_hash_set: all the search happens in consteval,
// the runtime reads flat arrays, verification is SIMD and branchless. The
// hash is a whole-key multiplicative hash with a per-bucket pilot (see
// detail/wide_generator.h) instead of gperf's chosen byte positions, so it
// scales to thousands of keys and to keys of any length.
//
// Hot path for a ≤7-byte key (AArch64, ~35 instructions, no data-dependent
// branch on a hit stream):
//     ldr q0,[key] · tbl (mask past len) · fmov x,d0 · orr len<<56
//     mul x, K · lsr bucket · lsr/and base · ldrh pilot · add · and
//     ldr packed[slot] · cmp · ldr value[slot]
// ============================================================================

#include <ConstexprCore/detail/gperf_generator.h>   // next_power_of_2, max_key_length
#include <ConstexprCore/detail/wide_generator.h>
#include <ConstexprCore/detail/simd16.h>
#include <array>
#include <cstddef>
#include <cstdint>
#include <optional>
#include <string>
#include <string_view>
#include <type_traits>

namespace ConstexprCore {

// FusedBits > 0: the map stores each value inside the unused bytes of the
// stored lane that carries the length (keys shorter than 7 / 15 bytes leave
// 8*(7-MaxKeyLen) spare bits there). The key compare masks those bits out and
// the value comes back from the load the compare already did — no value
// table in the working set and no extra load.
template <std::size_t N, std::size_t TableSize, std::size_t MaxKeyLen, bool Strong = false, std::size_t FusedBits = 0>
struct wide_perfect_hash_set {
    static_assert(N >= 1, "wide_perfect_hash_set needs at least one key");
    static_assert((TableSize & (TableSize - 1)) == 0 && TableSize >= N, "TableSize must be a power of two >= N");
    static_assert(MaxKeyLen >= 1 && MaxKeyLen <= 4080, "MaxKeyLen out of range");

    static constexpr std::size_t B = detail::wide_result<N>::B;
    static constexpr std::size_t L = detail::wide_lanes_for(MaxKeyLen);
    static constexpr std::size_t LEN_LANE = detail::wide_len_lane_for(MaxKeyLen);
    static constexpr std::size_t B_BITS = detail::wide_log2(B);
    static constexpr std::size_t M_BITS = detail::wide_log2(TableSize);
    static constexpr std::size_t CHUNKS = (MaxKeyLen + 15) / 16;
    // ≤15-byte keys: compare packed lanes (the length rides in a spare byte).
    // MaxKeyLen == 16 has two lanes but no spare byte, so it takes the
    // chunk + explicit-length path like longer keys.
    static constexpr bool LANE_COMPARE = (LEN_LANE != std::size_t(-1));
    // spare bits in the length lane: bytes [MaxKeyLen - 8*LEN_LANE, 7)
    static constexpr std::size_t SPARE_SHIFT = (LEN_LANE == std::size_t(-1)) ? 0 : 8 * (MaxKeyLen - 8 * LEN_LANE);
    static constexpr std::size_t SPARE_BITS = (LEN_LANE == std::size_t(-1)) ? 0 : 8 * (7 - (MaxKeyLen - 8 * LEN_LANE));
    static_assert(FusedBits <= SPARE_BITS, "FusedBits does not fit in the spare bytes of the length lane");
    static constexpr std::uint64_t FUSED_MASK = FusedBits == 0 ? 0 : (((std::uint64_t{1} << FusedBits) - 1) << SPARE_SHIFT);
    using index_t = std::conditional_t<(N < 65535), std::uint16_t, std::uint32_t>;
    using pilot_t = std::conditional_t<(TableSize <= 65536), std::uint16_t, std::uint32_t>;

    // --- hot data, most latency-critical array first (offset 0 → no add
    //     before the indexed load) ---
    std::array<pilot_t, B> pilots_{};
    // ≤15-byte keys: the lanes themselves (length folded in) — an ldp + 2 xor
    // verifies the key. Longer keys: inline bytes, 16-byte padded, + length.
    struct no_storage_t {};
    [[no_unique_address]] std::conditional_t<LANE_COMPARE,
        std::array<std::array<std::uint64_t, L>, TableSize>, no_storage_t> packed_lanes_{};
    [[no_unique_address]] std::conditional_t<!LANE_COMPARE,
        std::array<std::array<char, CHUNKS * 16>, TableSize>, no_storage_t> slot_key_data_{};
    [[no_unique_address]] std::conditional_t<!LANE_COMPARE,
        std::array<std::uint16_t, TableSize>, no_storage_t> slot_key_len_{};
    std::array<std::uint64_t, L> muls_{};            // per-lane multipliers (from the seed)
    std::uint64_t seed_{};
    std::uint8_t min_key_len_{};
    // --- cold data ---
    std::array<index_t, TableSize> slot_to_key_{};   // N == empty
    std::array<index_t, N> key_to_slot_{};

    consteval wide_perfect_hash_set(const std::array<std::string_view, N>& keys,
                                    const detail::wide_result<N>& plan) {
        if (plan.table_size != TableSize) throw "wide_perfect_hash_set: plan/table size mismatch";
        if (plan.strong != Strong) throw "wide_perfect_hash_set: plan/hash variant mismatch";
        seed_ = plan.seed;
        muls_ = detail::wide_muls<L>(plan.seed);
        std::size_t mn = keys[0].size();
        for (std::size_t i = 1; i < N; ++i) if (keys[i].size() < mn) mn = keys[i].size();
        min_key_len_ = static_cast<std::uint8_t>(mn > 255 ? 255 : mn);
        for (std::size_t b = 0; b < B; ++b) pilots_[b] = static_cast<pilot_t>(plan.pilots[b]);
        for (std::size_t s = 0; s < TableSize; ++s) {
            slot_to_key_[s] = static_cast<index_t>(plan.slot_to_key[s] < N ? plan.slot_to_key[s] : N);
            if constexpr (!LANE_COMPARE) slot_key_len_[s] = 0xFFFF;
        }
        for (std::size_t s = 0; s < TableSize; ++s) {
            const std::size_t ki = slot_to_key_[s];
            if (ki >= N) continue;
            const std::string_view k = keys[ki];
            key_to_slot_[ki] = static_cast<index_t>(s);
            if constexpr (LANE_COMPARE) {
                packed_lanes_[s] = detail::wide_key_lanes<MaxKeyLen>(k);
            } else {
                for (std::size_t c = 0; c < k.size(); ++c) slot_key_data_[s][c] = k[c];
                slot_key_len_[s] = static_cast<std::uint16_t>(k.size());
            }
        }
        // Verify the whole thing end to end at compile time.
        for (std::size_t i = 0; i < N; ++i) {
            auto s = slot_match(keys[i]);
            if (!s || *s != key_to_slot_[i]) throw "wide_perfect_hash_set: verification failed";
        }
    }

    [[nodiscard]] constexpr std::size_t size() const noexcept { return N; }
    [[nodiscard]] constexpr std::size_t table_size() const noexcept { return TableSize; }
    [[nodiscard]] constexpr std::size_t bucket_count() const noexcept { return B; }
    [[nodiscard]] constexpr std::string_view algorithm_name() const noexcept {
        return Strong ? std::string_view("wide-pilot/strong") : std::string_view("wide-pilot");
    }
    [[nodiscard]] constexpr std::string algorithm_description() const {
        return "wide-pilot: h = " + std::string(Strong ? "avalanche(" : "(") + "xor of " + std::to_string(L) +
               " lane(s) x K_i, seed " + std::to_string(seed_) + "); bucket = h >> " + std::to_string(64 - B_BITS) +
               " [" + std::to_string(B) + " buckets]; slot = ((h >> " + std::to_string(64 - B_BITS - M_BITS) +
               ") + pilot[bucket]) & " + std::to_string(TableSize - 1) +
               (LANE_COMPARE ? "; verify = packed lanes" : "; verify = 16B chunks + len");
    }
    // key_at: when the lanes are the storage, the key bytes ARE the lanes
    // (little-endian, length in the top byte of the length lane), so the
    // view points into packed_lanes_ — no second copy of the keys is kept.
    // Runtime only for that storage form (reinterpret_cast); the map itself
    // is fully usable at compile time.
    [[nodiscard]] constexpr std::string_view key_at(std::size_t i) const noexcept {
        const std::size_t s = key_to_slot_[i];
        if constexpr (LANE_COMPARE) {
            const std::size_t len = static_cast<std::size_t>(packed_lanes_[s][LEN_LANE] >> 56);
            return std::string_view(reinterpret_cast<const char*>(packed_lanes_[s].data()), len);
        } else {
            return std::string_view(slot_key_data_[s].data(), slot_key_len_[s]);
        }
    }

    // Fused-value plumbing (used by wide_perfect_hash_map when FusedBits > 0).
    consteval void fuse_value_(std::size_t slot, std::uint64_t v) {
        if (v & ~((std::uint64_t{1} << FusedBits) - 1)) throw "wide_perfect_hash_set: fused value out of range";
        packed_lanes_[slot][LEN_LANE] |= v << SPARE_SHIFT;
    }
    [[nodiscard]] constexpr constexprcore_really_inline std::uint64_t fused_value_(std::size_t slot) const noexcept {
        return (packed_lanes_[slot][LEN_LANE] & FUSED_MASK) >> SPARE_SHIFT;
    }

    [[nodiscard]] constexpr constexprcore_really_inline std::size_t slot_of_(std::uint64_t h) const noexcept {
        const std::size_t bucket = B_BITS == 0 ? 0 : static_cast<std::size_t>(h >> (64 - B_BITS));
        const std::size_t base = static_cast<std::size_t>(h >> (64 - B_BITS - M_BITS)) & (TableSize - 1);
        return (base + pilots_[bucket]) & (TableSize - 1);
    }

    // Core: returns the slot if the key is present. No data-dependent branch
    // on a hit stream except the page-safety guard inside the chunk load.
    [[nodiscard]] constexpr constexprcore_really_inline std::optional<std::size_t> slot_match(std::string_view key) const noexcept {
        if (min_key_len_ > 0 && key.empty()) return std::nullopt;
        const std::size_t len = key.size();
        const char* p = key.data();
        // One clamp serves both the load and the folded length byte. With a
        // length lane, clamp to MaxKeyLen + 1 (<= 16, still one chunk): a
        // too-long key then carries length byte MaxKeyLen + 1, which no stored
        // key has, and — for MaxKeyLen = 7 / 15 — a non-zero byte OR-ed into
        // that same top byte; either way a guaranteed mismatch with no extra
        // compare. Without a length lane, lengths are checked explicitly.
        constexpr std::size_t CLAMP = (LEN_LANE != std::size_t(-1)) ? MaxKeyLen + 1 : MaxKeyLen;
        const std::size_t clamped = len <= CLAMP ? len : CLAMP;
        const std::uint64_t len_byte = static_cast<std::uint64_t>(clamped);
        if (std::is_constant_evaluated()) {
            std::array<std::uint64_t, L> lanes{};
            for (std::size_t i = 0; i < L; ++i) lanes[i] = detail::key_lane(p, clamped, i);
            if constexpr (LEN_LANE != std::size_t(-1)) lanes[LEN_LANE] |= len_byte << 56;
            const std::size_t slot = slot_of_(detail::wide_hash<L, Strong>(lanes, muls_));
            bool ok = true;
            if constexpr (LANE_COMPARE) {
                for (std::size_t i = 0; i < L; ++i) {
                    const std::uint64_t keep = (i == LEN_LANE) ? ~FUSED_MASK : ~std::uint64_t{0};
                    ok = ok && (((packed_lanes_[slot][i] ^ lanes[i]) & keep) == 0);
                }
            } else {
                ok = (slot_key_len_[slot] == len);
                for (std::size_t c = 0; ok && c < clamped; ++c) ok = (slot_key_data_[slot][c] == p[c]);
            }
            static_assert(LEN_LANE == std::size_t(-1) || CLAMP <= 16, "one-chunk clamp");
            return ok ? std::optional<std::size_t>{slot} : std::nullopt;
        } else {
            std::array<std::uint64_t, L> lanes;
            if constexpr (L == 1) {
                lanes[0] = detail::lane0(detail::load_chunk16(p, clamped));
            } else if constexpr (L == 2) {
                const auto c = detail::load_chunk16(p, clamped);
                lanes[0] = detail::lane0(c);
                lanes[1] = detail::lane1(c);
            } else {
                for (std::size_t j = 0; j < CHUNKS; ++j) {
                    const auto c = detail::load_chunk16(p + 16 * j, detail::chunk_len(clamped, 16 * j));
                    lanes[2 * j] = detail::lane0(c);
                    lanes[2 * j + 1] = detail::lane1(c);
                }
            }
            if constexpr (LEN_LANE != std::size_t(-1)) lanes[LEN_LANE] |= len_byte << 56;
            const std::size_t slot = slot_of_(detail::wide_hash<L, Strong>(lanes, muls_));
            bool ok;
            if constexpr (LANE_COMPARE) {
                std::uint64_t diff = packed_lanes_[slot][0] ^ lanes[0];
                if constexpr (L == 2) diff |= packed_lanes_[slot][1] ^ lanes[1];
                if constexpr (FusedBits > 0) diff &= ~FUSED_MASK;   // one logical-immediate AND
                ok = (diff == 0);
            } else {
                // stored lengths are <= MaxKeyLen, so a too-long key fails here
                ok = (slot_key_len_[slot] == len);
                ok &= detail::compare_chunks<MaxKeyLen>(p, clamped, slot_key_data_[slot].data());
            }
            return ok ? std::optional<std::size_t>{slot} : std::nullopt;
        }
    }

    [[nodiscard]] constexpr constexprcore_really_inline bool contains(std::string_view key) const noexcept {
        return slot_match(key).has_value();
    }
    [[nodiscard]] constexpr constexprcore_really_inline std::optional<std::size_t> index_of(std::string_view key) const noexcept {
        auto s = slot_match(key);
        if (!s) return std::nullopt;
        return std::optional<std::size_t>{slot_to_key_[*s]};
    }
};

namespace detail {
// Can values of this type ride inside the spare bytes of the length lane?
template <typename ValueT, std::size_t MaxKeyLen>
constexpr std::size_t wide_fused_bits() {
    constexpr std::size_t LEN_LANE = wide_len_lane_for(MaxKeyLen);
    if constexpr (LEN_LANE == std::size_t(-1) || !std::is_integral_v<ValueT> || std::is_same_v<ValueT, bool>) return 0;
    else {
        constexpr std::size_t spare = 8 * (7 - (MaxKeyLen - 8 * LEN_LANE));
        return (sizeof(ValueT) * 8 <= spare) ? sizeof(ValueT) * 8 : 0;
    }
}
} // namespace detail

template <std::size_t N, typename ValueT, std::size_t TableSize, std::size_t MaxKeyLen, bool Strong = false,
          std::size_t FusedBits = detail::wide_fused_bits<ValueT, MaxKeyLen>()>
struct wide_perfect_hash_map {
    static constexpr bool FUSED = (FusedBits > 0);
    using value_t = std::remove_const_t<ValueT>;
    struct no_storage_t {};
    // values first: slot-indexed load with no offset add (unused when fused)
    [[no_unique_address]] std::conditional_t<!FUSED, std::array<value_t, TableSize>, no_storage_t> slot_values_{};
    wide_perfect_hash_set<N, TableSize, MaxKeyLen, Strong, FusedBits> set_;

    consteval wide_perfect_hash_map(const std::array<std::string_view, N>& keys,
                                    const std::array<ValueT, N>& values,
                                    const detail::wide_result<N>& plan)
        : set_{keys, plan} {
        for (std::size_t s = 0; s < TableSize; ++s) {
            const std::size_t ki = set_.slot_to_key_[s];
            if (ki >= N) continue;
            if constexpr (FUSED) {
                using U = std::make_unsigned_t<value_t>;
                set_.fuse_value_(s, static_cast<std::uint64_t>(static_cast<U>(values[ki])));
            } else {
                slot_values_[s] = values[ki];
            }
        }
        if constexpr (FUSED) {
            // fusing touched the stored lanes: re-verify every key against them
            for (std::size_t i = 0; i < N; ++i)
                if (!set_.contains(keys[i])) throw "wide_perfect_hash_map: fused values broke a key compare";
        }
    }
    [[nodiscard]] constexpr std::size_t size() const noexcept { return N; }
    [[nodiscard]] constexpr std::size_t table_size() const noexcept { return TableSize; }
    [[nodiscard]] constexpr std::string_view algorithm_name() const noexcept {
        return FUSED ? (Strong ? std::string_view("wide-pilot/strong/fused") : std::string_view("wide-pilot/fused"))
                     : set_.algorithm_name();
    }
    [[nodiscard]] constexpr std::string algorithm_description() const {
        return set_.algorithm_description() + (FUSED ? "; value fused into the stored lane" : "");
    }
    [[nodiscard]] constexpr std::string_view key_at(std::size_t i) const noexcept { return set_.key_at(i); }
    [[nodiscard]] constexpr constexprcore_really_inline bool contains(std::string_view key) const noexcept {
        return set_.contains(key);
    }
    [[nodiscard]] constexpr constexprcore_really_inline std::optional<ValueT> lookup(std::string_view key) const noexcept {
        auto s = set_.slot_match(key);
        if (!s.has_value()) return std::nullopt;
        if constexpr (FUSED) {
            using U = std::make_unsigned_t<value_t>;
            return static_cast<ValueT>(static_cast<U>(set_.fused_value_(*s)));
        } else {
            return slot_values_[*s];
        }
    }
};

// ---------------------------------------------------------------------------
// Factories. The key array must have static storage (an `inline constexpr`
// or `static constexpr` std::array<std::string_view, N>) so it can be a
// reference template argument: the plan is computed from it as a constant
// expression, which is what lets the result type carry the chosen table size.
// ---------------------------------------------------------------------------
namespace detail {
template <std::size_t N>
consteval std::size_t wide_max_len(const std::array<std::string_view, N>& keys) {
    const std::size_t m = max_key_length(keys);
    return m > 0 ? m : 1;
}
// Smallest unsigned type that holds every index 0..N-1.
template <std::size_t N>
using wide_index_value_t = std::conditional_t<(N <= 256), std::uint8_t,
                           std::conditional_t<(N <= 65536), std::uint16_t, std::uint32_t>>;
} // namespace detail

template <const auto& Keys>
consteval auto make_wide_perfect_set() {
    constexpr std::size_t N = Keys.size();
    constexpr std::size_t MaxLen = detail::wide_max_len(Keys);
    constexpr auto plan = detail::wide_build<N, MaxLen>(Keys);
    return wide_perfect_hash_set<N, plan.table_size, MaxLen, plan.strong>{Keys, plan};
}

template <const auto& Keys, const auto& Values>
consteval auto make_wide_perfect_map() {
    constexpr std::size_t N = Keys.size();
    static_assert(Values.size() == N, "keys and values must have the same length");
    // value_type of the array (may be const-qualified, like kv<>::value)
    using ValueT = typename std::remove_cvref_t<decltype(Values)>::value_type;
    constexpr std::size_t MaxLen = detail::wide_max_len(Keys);
    constexpr auto plan = detail::wide_build<N, MaxLen>(Keys);
    return wide_perfect_hash_map<N, ValueT, plan.table_size, MaxLen, plan.strong>{Keys, Values, plan};
}

// Convenience: values = declaration index (0..N-1), stored in the smallest
// integer type that fits — the value table is part of the hot working set.
template <const auto& Keys>
consteval auto make_wide_perfect_index_map() {
    constexpr std::size_t N = Keys.size();
    using ValueT = detail::wide_index_value_t<N>;
    constexpr std::size_t MaxLen = detail::wide_max_len(Keys);
    constexpr auto plan = detail::wide_build<N, MaxLen>(Keys);
    std::array<ValueT, N> values{};
    for (std::size_t i = 0; i < N; ++i) values[i] = static_cast<ValueT>(i);
    return wide_perfect_hash_map<N, ValueT, plan.table_size, MaxLen, plan.strong>{Keys, values, plan};
}

} // namespace ConstexprCore

#endif // CONSTEXPRCORE_WIDE_PERFECT_HASH_H
