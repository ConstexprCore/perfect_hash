#ifndef CONSTEXPRCORE_PERFECT_HASH_H
#define CONSTEXPRCORE_PERFECT_HASH_H

#include <ConstexprCore/fixed_string.h>
#include <ConstexprCore/detail/gperf_generator.h>
#include <array>
#include <stdexcept>
#include <string_view>
#include <optional>
#include <tuple>
#include <cstddef>
#include <cstdint>

#ifndef constexprcore_really_inline
#if defined(_MSC_VER) && !defined(__clang__)
#define constexprcore_really_inline __forceinline
#else
#define constexprcore_really_inline inline __attribute__((always_inline))
#endif
#endif

namespace ConstexprCore {

// ============================================================================
// perfect_hash_set
// ============================================================================

template <std::size_t N, std::size_t TableSize = N, std::size_t MaxKeyLen = 64>
struct perfect_hash_set {
    static_assert(N <= 255, "N must be <= 255 for uint8_t key indices");
    static_assert(TableSize <= 255, "TableSize must be <= 255 for uint8_t asso_values");
    static_assert(MaxKeyLen >= 1 && MaxKeyLen < 255,
                  "MaxKeyLen must be in [1, 254] to reserve 0xFF as empty sentinel");
    static_assert(detail::MAX_POSITIONS <= 255, "MAX_POSITIONS must fit in uint8_t");

    static constexpr std::uint8_t POS_LAST_CHAR = 255;
    static constexpr std::uint8_t HD_MODE = 0xFF; // num_positions_ sentinel for Hash-and-Displace mode
    static constexpr bool TABLE_SIZE_IS_POW2 = (TableSize & (TableSize - 1)) == 0;

    // HD_MODE must not collide with a valid num_positions value.
    static_assert(detail::MAX_POSITIONS < HD_MODE,
                  "MAX_POSITIONS must be < 0xFF to avoid collision with HD_MODE sentinel");

    // --- hot data (accessed every lookup) ---
    std::array<std::uint8_t, 256> asso_values_{};
    std::uint8_t num_positions_{};
    std::array<std::uint8_t, detail::MAX_POSITIONS> positions_{};
    std::uint8_t min_key_len_{};
    std::array<std::uint8_t, TableSize> slot_key_len_{};                    // key length (0xFF = empty)
    std::array<std::array<char, MaxKeyLen>, TableSize> slot_key_data_{};    // inline key bytes
    std::array<std::uint64_t, TableSize> packed_keys_{};                    // first 8 bytes packed for branchless cmp

    // --- cold data (rarely accessed) ---
    std::array<std::uint8_t, TableSize> slot_to_key_{};     // hash_slot -> declaration-order index
    std::array<std::uint8_t, N> key_to_slot_{};             // declaration-order index -> slot

    // Shared init logic for both constructors.
    consteval void init_inline_data_(const std::array<std::string_view, N>& keys) {
        // Step 1: Compute min key length for fast rejection in contains().
        std::size_t mn = keys[0].size();
        for (std::size_t i = 1; i < N; ++i)
            if (keys[i].size() < mn) mn = keys[i].size();
        min_key_len_ = static_cast<std::uint8_t>(mn);

        // Step 2: Populate inline key data and inverse mapping.
        for (std::size_t s = 0; s < TableSize; ++s)
            slot_key_len_[s] = 0xFF;
        for (std::size_t s = 0; s < TableSize; ++s) {
            if (slot_to_key_[s] < N) {
                auto k = keys[slot_to_key_[s]];
                slot_key_len_[s] = static_cast<std::uint8_t>(k.size());
                for (std::size_t c = 0; c < k.size(); ++c)
                    slot_key_data_[s][c] = k[c];
                key_to_slot_[slot_to_key_[s]] = static_cast<std::uint8_t>(s);
            }
        }

        // Step 3: Build packed_keys_ for fast key comparison.
        for (std::size_t s = 0; s < TableSize; ++s) {
            if (slot_to_key_[s] < N) {
                auto k = keys[slot_to_key_[s]];
                if constexpr (MaxKeyLen <= 4) {
                    // Overlap encoding: lo16 | hi16<<16 | len<<32.
                    // For MaxKeyLen <= 4, overlap covers all bytes.
                    if (k.size() >= 2) {
                        std::uint64_t lo = static_cast<unsigned char>(k[0])
                            | (static_cast<std::uint64_t>(static_cast<unsigned char>(k[1])) << 8);
                        std::uint64_t hi = static_cast<unsigned char>(k[k.size()-2])
                            | (static_cast<std::uint64_t>(static_cast<unsigned char>(k[k.size()-1])) << 8);
                        packed_keys_[s] = lo | (hi << 16) | (static_cast<std::uint64_t>(k.size()) << 32);
                    } else if (k.size() == 1) {
                        packed_keys_[s] = static_cast<unsigned char>(k[0])
                            | (static_cast<std::uint64_t>(1) << 32);
                    }
                } else if constexpr (MaxKeyLen <= 8) {
                    // Sequential packing: first up to 8 bytes, zero-padded.
                    // Used with safe_byte pack_input_ comparison.
                    std::uint64_t p = 0;
                    for (std::size_t c = 0; c < k.size(); ++c)
                        p |= static_cast<std::uint64_t>(static_cast<unsigned char>(k[c])) << (c * 8);
                    packed_keys_[s] = p;
                } else {
                    // Sequential: first 8 bytes packed (fast filter for long keys).
                    std::uint64_t p = 0;
                    for (std::size_t c = 0; c < k.size() && c < 8; ++c)
                        p |= static_cast<std::uint64_t>(static_cast<unsigned char>(k[c])) << (c * 8);
                    packed_keys_[s] = p;
                }
            }
        }
    }

    // Direct constructor: runs full PHF generation.
    consteval perfect_hash_set(const std::array<std::string_view, N>& keys) {
        for (std::size_t i = 0; i < N; ++i) {
            if (keys[i].size() > MaxKeyLen)
                throw "Key length exceeds MaxKeyLen";
        }

        std::array<std::size_t, 256> full_asso{};
        std::size_t wide_num_positions{};
        std::array<std::size_t, detail::MAX_POSITIONS> wide_positions{};
        std::array<std::size_t, TableSize> wide_slot_to_key{};
        detail::generate_gperf<N, TableSize>(keys, full_asso, wide_num_positions, wide_positions, wide_slot_to_key);

        for (std::size_t i = 0; i < 256; ++i)
            asso_values_[i] = static_cast<std::uint8_t>(full_asso[i] % TableSize);
        num_positions_ = static_cast<std::uint8_t>(wide_num_positions);
        for (std::size_t i = 0; i < wide_num_positions; ++i)
            positions_[i] = (wide_positions[i] == detail::LAST_CHAR)
                ? POS_LAST_CHAR
                : static_cast<std::uint8_t>(wide_positions[i]);
        for (std::size_t i = 0; i < TableSize; ++i)
            slot_to_key_[i] = static_cast<std::uint8_t>(wide_slot_to_key[i]);

        // Verify the reduction didn't break the perfect hash
        for (std::size_t i = 0; i < N; ++i) {
            if (slot_to_key_[compute_hash(keys[i])] != i)
                throw "asso_value reduction broke perfect hash mapping";
        }

        init_inline_data_(keys);
    }

    // Pre-computed constructor: copies data from a phf_result (no recomputation).
    consteval perfect_hash_set(
        const std::array<std::string_view, N>& keys,
        const detail::phf_result<N>& data)
    {
        for (std::size_t i = 0; i < N; ++i) {
            if (keys[i].size() > MaxKeyLen)
                throw "Key length exceeds MaxKeyLen";
        }

        // For gperf mode: reduce asso_values mod TableSize (values can be large from bumping).
        // For H&D mode (num_positions == 0xFF): store raw displacement values (already < 255).
        if (data.num_positions == 0xFF) {
            for (std::size_t i = 0; i < 256; ++i)
                asso_values_[i] = static_cast<std::uint8_t>(data.asso_values[i]);
        } else {
            for (std::size_t i = 0; i < 256; ++i)
                asso_values_[i] = static_cast<std::uint8_t>(data.asso_values[i] % TableSize);
        }
        num_positions_ = static_cast<std::uint8_t>(data.num_positions);
        // Copy positions. For H&D mode (num_positions == 0xFF), only copy
        // the 2 positions used by the bucket hash, not all 255.
        std::size_t pos_count = data.num_positions < detail::MAX_POSITIONS
            ? data.num_positions : detail::MAX_POSITIONS;
        for (std::size_t i = 0; i < pos_count; ++i)
            positions_[i] = (data.positions[i] == detail::LAST_CHAR)
                ? POS_LAST_CHAR
                : static_cast<std::uint8_t>(data.positions[i]);
        for (std::size_t i = 0; i < TableSize; ++i)
            slot_to_key_[i] = static_cast<std::uint8_t>(data.slot_to_key[i]);

        // Verify the reduction didn't break the perfect hash
        for (std::size_t i = 0; i < N; ++i) {
            if (slot_to_key_[compute_hash(keys[i])] != i)
                throw "asso_value reduction broke perfect hash mapping";
        }

        init_inline_data_(keys);
    }

    [[nodiscard]] constexpr std::size_t size() const noexcept { return N; }

    [[nodiscard]] constexpr std::size_t table_size() const noexcept { return TableSize; }

    [[nodiscard]] constexpr std::string_view key_at(std::size_t i) const noexcept {
        std::uint8_t slot = key_to_slot_[i];
        return std::string_view(slot_key_data_[slot].data(), slot_key_len_[slot]);
    }

    // Branchless byte load: returns byte at idx if idx < len, else 0.
    // Always reads from a valid address (falls back to p[0] when out of range).
    [[nodiscard]] static constexpr std::uint64_t safe_byte_(
        const char* p, std::size_t len, std::size_t idx) noexcept {
        const std::size_t has_it = static_cast<std::size_t>(idx < len);
        const std::size_t safe_idx = idx & -has_it;
        const std::uint64_t byte_val = static_cast<unsigned char>(p[safe_idx]);
        return byte_val & -static_cast<std::uint64_t>(has_it);
    }

    // Pack up to 8 key bytes into a uint64, zero-padded. Branchless.
    // Uses if-constexpr on MaxKeyLen to emit only the needed byte loads.
    [[nodiscard]] static constexpr std::uint64_t pack_input_(
        const char* p, std::size_t len) noexcept {
        std::uint64_t v = static_cast<unsigned char>(p[0]);
        if constexpr (MaxKeyLen >= 2) v |= safe_byte_(p, len, 1) << 8;
        if constexpr (MaxKeyLen >= 3) v |= safe_byte_(p, len, 2) << 16;
        if constexpr (MaxKeyLen >= 4) v |= safe_byte_(p, len, 3) << 24;
        if constexpr (MaxKeyLen >= 5) v |= safe_byte_(p, len, 4) << 32;
        if constexpr (MaxKeyLen >= 6) v |= safe_byte_(p, len, 5) << 40;
        if constexpr (MaxKeyLen >= 7) v |= safe_byte_(p, len, 6) << 48;
        if constexpr (MaxKeyLen >= 8) v |= safe_byte_(p, len, 7) << 56;
        return v;
    }

    // Compare key bytes against the stored key at a slot.
    // Three strategies, selected at compile time:
    //
    // 1. Overlap LDRH (fastest, 2 loads): for MaxKeyLen <= 8 and min_key_len >= 2.
    //    Two in-bounds halfword loads p[0..1] and p[len-2..len-1] combined with
    //    length into a single uint64 comparison. 22 insn on ARM64, 0 BM.
    //
    // 2. Branchless safe_byte pack: for MaxKeyLen <= 8 when overlap isn't safe.
    //    Packs up to 8 bytes branchlessly into uint64 using conditional indexing.
    //
    // 3. Byte-by-byte loop: for MaxKeyLen > 8 or consteval context.
    [[nodiscard]] constexpr constexprcore_really_inline bool compare_key_(
        const char* p, std::size_t len, std::size_t slot) const noexcept {
        if consteval {
            // consteval: byte-by-byte (no intrinsics)
            const char* a = slot_key_data_[slot].data();
            for (std::size_t i = 0; i < len; ++i)
                if (a[i] != p[i]) return false;
            return true;
        } else {
            if constexpr (MaxKeyLen <= 4) {
                // Overlap comparison: for MaxKeyLen <= 4, overlap covers all bytes.
                std::uint64_t encoded;
                if (len >= 2) {
                    std::uint16_t lo, hi;
                    __builtin_memcpy(&lo, p, 2);
                    __builtin_memcpy(&hi, p + len - 2, 2);
                    encoded = lo | (static_cast<std::uint64_t>(hi) << 16)
                        | (static_cast<std::uint64_t>(len) << 32);
                } else {
                    encoded = static_cast<unsigned char>(p[0])
                        | (static_cast<std::uint64_t>(len) << 32);
                }
                return encoded == packed_keys_[slot];
            } else if constexpr (MaxKeyLen <= 8) {
                // Branchless safe_byte pack: packs all key bytes into uint64.
                // Slightly more instructions than overlap, but zero branch misses
                // since safe_byte_ uses conditional arithmetic (no branches).
                return pack_input_(p, len) == packed_keys_[slot];
            } else {
                // MaxKeyLen > 8: first 8 bytes as fast filter, then byte loop.
                // Key insight: branch on struct-constant min_key_len_ (perfect
                // prediction) instead of per-key len (data-dependent, mispredicts).
                //   min_key_len >= 8: ALL keys have 8+ bytes → direct memcpy (1 insn)
                //   min_key_len <  8: some keys are short → branchless safe_byte (0 BM)
                std::uint64_t input_val;
                if consteval {
                    input_val = pack_input_(p, len);
                } else {
                    if (min_key_len_ >= 8) {
                        __builtin_memcpy(&input_val, p, 8);
                    } else {
                        input_val = pack_input_(p, len);
                    }
                }
                if (input_val != packed_keys_[slot]) return false;
                // Verify remaining bytes: branchless XOR accumulate with
                // range masking to avoid branches per byte.
                const char* a = slot_key_data_[slot].data();
                std::uint64_t diff = 0;
                for (std::size_t i = 8; i < MaxKeyLen; ++i) {
                    std::uint64_t need = static_cast<std::uint64_t>(i < len);
                    std::uint64_t a_byte = static_cast<unsigned char>(a[i]);
                    std::uint64_t p_byte = safe_byte_(p, len, i);
                    diff |= (a_byte ^ p_byte) & -need;
                }
                return diff == 0;
            }
        }
    }

    [[nodiscard]] constexpr constexprcore_really_inline bool contains(std::string_view key) const noexcept {
        // Reject empty keys early only when no empty key exists in the set.
        // min_key_len_ is a struct constant so this branch compiles away.
        if (min_key_len_ > 0 && key.empty()) return false;
        auto len = key.size();
        // Clamp len to MaxKeyLen so compare_key_ never reads past MaxKeyLen bytes.
        // Out-of-range lengths will fail the len_ok check below.
        auto clamped_len = len <= MaxKeyLen ? len : MaxKeyLen;
        std::size_t slot = compute_hash(key);
        bool len_ok = (slot_key_len_[slot] == static_cast<std::uint8_t>(len));
        bool key_ok = len == 0 || compare_key_(key.data(), clamped_len, slot);
        return len_ok & key_ok;
    }

    [[nodiscard]] constexpr constexprcore_really_inline std::size_t compute_hash(std::string_view key) const noexcept {
        if (num_positions_ == HD_MODE) {
            // H&D mode: uses shared hd_bucket_hash + hd_key_hash from generator.
            std::size_t h = asso_values_[detail::hd_bucket_hash(key)] + detail::hd_key_hash(key);
            if constexpr (TABLE_SIZE_IS_POW2)
                return h & (TableSize - 1);
            else
                return h % TableSize;
        }
        // Standard gperf mode
        std::size_t h = key.size();
        for (std::uint8_t i = 0; i < num_positions_; ++i) {
            std::uint8_t pos = positions_[i];
            std::size_t ch;
            if (pos == POS_LAST_CHAR) {
                ch = key.empty() ? 256 : static_cast<unsigned char>(key.back());
            } else {
                ch = (pos < key.size()) ? static_cast<unsigned char>(key[pos]) : 256;
            }
            if (ch < 256) h += asso_values_[ch];
        }
        if constexpr (TABLE_SIZE_IS_POW2)
            return h & (TableSize - 1);
        else
            return h % TableSize;
    }

    [[nodiscard]] constexpr constexprcore_really_inline std::optional<std::size_t> index_of(std::string_view key) const noexcept {
        if (min_key_len_ > 0 && key.empty()) return std::nullopt;
        auto len = key.size();
        auto clamped_len = len <= MaxKeyLen ? len : MaxKeyLen;
        std::size_t slot = compute_hash(key);
        bool len_ok = (slot_key_len_[slot] == static_cast<std::uint8_t>(len));
        bool key_ok = len == 0 || compare_key_(key.data(), clamped_len, slot);
        if (!(len_ok & key_ok)) return std::nullopt;
        return static_cast<std::size_t>(slot_to_key_[slot]);
    }
};

// ============================================================================
// perfect_hash_map
// ============================================================================

template <std::size_t N, typename ValueT, std::size_t TableSize = N, std::size_t MaxKeyLen = 64>
struct perfect_hash_map {
    perfect_hash_set<N, TableSize, MaxKeyLen> set_;
    std::array<ValueT, N> values_{};

    consteval perfect_hash_map(
        const std::array<std::string_view, N>& keys,
        const std::array<ValueT, N>& values)
        : set_{keys}, values_{values}
    {}

    consteval perfect_hash_map(
        const std::array<std::string_view, N>& keys,
        const std::array<ValueT, N>& values,
        const detail::phf_result<N>& data)
        : set_{keys, data}, values_{values}
    {}

    [[nodiscard]] constexpr std::size_t size() const noexcept { return N; }

    [[nodiscard]] constexpr std::size_t table_size() const noexcept { return TableSize; }

    [[nodiscard]] constexpr constexprcore_really_inline bool contains(std::string_view key) const noexcept {
        return set_.contains(key);
    }

    [[nodiscard]] constexpr constexprcore_really_inline std::optional<ValueT> lookup(std::string_view key) const noexcept {
        auto idx = set_.index_of(key);
        if (idx.has_value()) {
            return values_[*idx];
        }
        return std::nullopt;
    }
};

// ============================================================================
// kv helper
// ============================================================================

template <fixed_string Key, auto Value>
struct kv {
    static constexpr std::string_view key = Key.view();
    static constexpr decltype(Value) value = Value;
};

// ============================================================================
// make_perfect_set
// ============================================================================

template <fixed_string... Keys>
consteval auto make_perfect_set() {
    constexpr std::size_t N = sizeof...(Keys);
    static_assert(N > 0, "make_perfect_set requires at least one key");

    constexpr std::array<std::string_view, N> keys{Keys.view()...};

    // Validate no duplicates
    for (std::size_t i = 0; i < N; ++i) {
        for (std::size_t j = i + 1; j < N; ++j) {
            if (keys[i] == keys[j]) {
                throw "Duplicate key in make_perfect_set";
            }
        }
    }

    // Compute PHF once (determines table size + all data)
    constexpr auto data = detail::compute_phf<N>(keys);
    constexpr std::size_t M = data.table_size;
    constexpr std::size_t MaxLen = detail::max_key_length(keys) > 0 ? detail::max_key_length(keys) : 1;
    return perfect_hash_set<N, M, MaxLen>{keys, data};
}

// ============================================================================
// make_perfect_map
// ============================================================================

template <typename... KVs>
consteval auto make_perfect_map() {
    constexpr std::size_t N = sizeof...(KVs);
    static_assert(N > 0, "make_perfect_map requires at least one entry");

    constexpr std::array<std::string_view, N> keys{KVs::key...};

    // Validate no duplicates
    for (std::size_t i = 0; i < N; ++i) {
        for (std::size_t j = i + 1; j < N; ++j) {
            if (keys[i] == keys[j]) {
                throw "Duplicate key in make_perfect_map";
            }
        }
    }

    using first_kv = typename std::tuple_element<0, std::tuple<KVs...>>::type;
    using ValueT = decltype(first_kv::value);

    constexpr std::array<ValueT, N> values{static_cast<ValueT>(KVs::value)...};

    // Compute PHF once (determines table size + all data)
    constexpr auto data = detail::compute_phf<N>(keys);
    constexpr std::size_t M = data.table_size;
    constexpr std::size_t MaxLen = detail::max_key_length(keys) > 0 ? detail::max_key_length(keys) : 1;
    return perfect_hash_map<N, ValueT, M, MaxLen>{keys, values, data};
}

} // namespace ConstexprCore

#endif // CONSTEXPRCORE_PERFECT_HASH_H
