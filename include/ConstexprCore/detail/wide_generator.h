#ifndef CONSTEXPRCORE_DETAIL_WIDE_GENERATOR_H
#define CONSTEXPRCORE_DETAIL_WIDE_GENERATOR_H

// ============================================================================
// Wide-mode generator: perfect hashing for key sets beyond the byte-indexed
// design (N > 255), and for any N where a fixed-position hash is undesirable.
//
// Shape (a compile-time PTHash / CHD): every lookup is
//
//     lanes  = the key as little-endian 64-bit words (zero-padded, length
//              folded into a spare top byte when one exists)
//     h      = lanes[0]*K0 ^ lanes[1]*K1 ^ ...             1 multiply per lane (K from seed)
//     bucket = h >> (64 - log2 B)                          top bits
//     base   = (h >> (64 - log2 B - log2 M)) & (M - 1)     next bits
//     slot   = (base + pilot[bucket]) & (M - 1)            one u16 load
//     hit    = stored lanes at slot == lanes               one 8/16-byte load
//
// The generator chooses the seed and the pilot table so that all N keys land
// on distinct slots. Two keys in the same bucket with equal base are a "dead
// pair" (no pilot can separate them): the generator detects that up front and
// re-rolls the seed instead of searching a doomed placement.
//
// Everything is consteval; the runtime side only ever reads the tables.
// ============================================================================

#include <array>
#include <cstddef>
#include <cstdint>
#include <string_view>

#include <ConstexprCore/detail/gperf_generator.h>   // next_power_of_2
#include <ConstexprCore/detail/simd16.h>

namespace ConstexprCore::detail {

// ---------------------------------------------------------------------------
// Hashing primitives (shared consteval/runtime, must stay bit-identical)
// ---------------------------------------------------------------------------

// splitmix64 step: turns a seed index into a well-spread 64-bit seed.
constexpr std::uint64_t wide_seed_from_index(std::uint64_t i) noexcept {
    std::uint64_t z = (i + 1) * 0x9E3779B97F4A7C15ULL;
    z = (z ^ (z >> 30)) * 0xBF58476D1CE4E5B9ULL;
    z = (z ^ (z >> 27)) * 0x94D049BB133111EBULL;
    return z ^ (z >> 31);
}

// Number of 64-bit lanes the hash consumes for a given MaxKeyLen, and which
// lane (if any) carries the key length in its top byte.
//   MaxKeyLen <=  7 : 1 lane,  length in lane 0's top byte
//   MaxKeyLen <= 15 : 2 lanes, length in lane 1's top byte
//   otherwise       : ceil(MaxKeyLen/16)*2 lanes, length checked separately
constexpr std::size_t wide_lanes_for(std::size_t max_key_len) noexcept {
    if (max_key_len <= 7) return 1;
    if (max_key_len <= 15) return 2;
    return ((max_key_len + 15) / 16) * 2;
}
constexpr std::size_t wide_len_lane_for(std::size_t max_key_len) noexcept {
    if (max_key_len <= 7) return 0;
    if (max_key_len <= 15) return 1;
    return std::size_t(-1);
}

// Reference (consteval) lane extraction for a whole key.
template <std::size_t MaxKeyLen>
constexpr std::array<std::uint64_t, wide_lanes_for(MaxKeyLen)>
wide_key_lanes(std::string_view key) noexcept {
    constexpr std::size_t L = wide_lanes_for(MaxKeyLen);
    constexpr std::size_t LEN_LANE = wide_len_lane_for(MaxKeyLen);
    std::array<std::uint64_t, L> lanes{};
    for (std::size_t i = 0; i < L; ++i) lanes[i] = key_lane(key.data(), key.size(), i);
    if constexpr (LEN_LANE != std::size_t(-1))
        lanes[LEN_LANE] |= static_cast<std::uint64_t>(key.size() & 0xFF) << 56;
    return lanes;
}

// Per-lane multipliers derived from the seed: one random odd 64-bit constant
// per lane. The seed is NOT xor-ed into the key — that costs a second 64-bit
// immediate (4 instructions on AArch64) on the critical path. Re-rolling the
// multiplier is just as effective at breaking dead pairs, and cheaper.
constexpr std::uint64_t wide_mult(std::uint64_t seed, std::size_t lane) noexcept {
    return wide_seed_from_index(seed * 8 + lane) | 1ULL;
}

// The hash. Strong=false: one multiply per lane, xor-combined — the lowest
// latency form; its bucket/base bits are the top bits of a multiplicative
// hash, which is good enough for real key sets because the generator
// VERIFIES the result and re-seeds on dead pairs. Strong=true adds a final
// avalanche for key sets where the fast form keeps producing dead pairs.
template <std::size_t L, bool Strong>
constexpr std::uint64_t wide_hash(const std::array<std::uint64_t, L>& lanes,
                                  const std::array<std::uint64_t, L>& muls) noexcept {
    std::uint64_t h = lanes[0] * muls[0];
    for (std::size_t i = 1; i < L; ++i) h ^= lanes[i] * muls[i];
    if constexpr (Strong) {
        h ^= h >> 29;
        h *= 0xBF58476D1CE4E5B9ULL;
        h ^= h >> 32;
    }
    return h;
}

template <std::size_t L>
constexpr std::array<std::uint64_t, L> wide_muls(std::uint64_t seed) noexcept {
    std::array<std::uint64_t, L> m{};
    for (std::size_t i = 0; i < L; ++i) m[i] = wide_mult(seed, i);
    return m;
}

constexpr std::size_t wide_log2(std::size_t pow2) noexcept {
    std::size_t l = 0;
    while ((std::size_t{1} << l) < pow2) ++l;
    return l;
}

// ---------------------------------------------------------------------------
// Build result
// ---------------------------------------------------------------------------

constexpr std::size_t wide_buckets_for(std::size_t n) noexcept {
    // ~2 keys per bucket on average (B = next_pow2(N)/2). Tiny table, easy
    // placement, and few same-bucket pairs (dead pairs scale with N^2/B).
    std::size_t b = next_power_of_2(n) / 2;
    return b == 0 ? 1 : b;
}

template <std::size_t N>
struct wide_result {
    static constexpr std::size_t B = wide_buckets_for(N);
    static constexpr std::size_t MinM = next_power_of_2(N);
    static constexpr std::size_t MaxM = MinM * 2;            // one doubling allowed
    std::size_t table_size{};                                // M actually used
    std::uint64_t seed{};
    bool strong{};                                           // which wide_hash variant
    std::size_t seeds_tried{};                               // diagnostics
    std::array<std::uint32_t, B> pilots{};
    std::array<std::uint32_t, MaxM> slot_to_key{};           // N == empty
};

// ---------------------------------------------------------------------------
// Placement for one (M, seed, Strong) triple. Returns false on a dead pair or
// a bucket that cannot be placed.
// ---------------------------------------------------------------------------
template <std::size_t N, std::size_t M, std::size_t L, bool Strong>
consteval bool wide_try_place(
    const std::array<std::array<std::uint64_t, L>, N>& lanes,
    std::uint64_t seed,
    wide_result<N>& out)
{
    constexpr std::size_t B = wide_result<N>::B;
    constexpr std::size_t b_bits = wide_log2(B);
    constexpr std::size_t m_bits = wide_log2(M);
    static_assert(b_bits + m_bits <= 64);

    const std::array<std::uint64_t, L> muls = wide_muls<L>(seed);
    std::array<std::uint32_t, N> bucket{};
    std::array<std::uint32_t, N> base{};
    for (std::size_t i = 0; i < N; ++i) {
        const std::uint64_t h = wide_hash<L, Strong>(lanes[i], muls);
        bucket[i] = static_cast<std::uint32_t>(b_bits == 0 ? 0 : (h >> (64 - b_bits)));
        base[i]   = static_cast<std::uint32_t>((h >> (64 - b_bits - m_bits)) & (M - 1));
    }

    // Counting sort keys by bucket → contiguous key ranges per bucket.
    std::array<std::uint32_t, B + 1> start{};
    for (std::size_t i = 0; i < N; ++i) ++start[bucket[i] + 1];
    for (std::size_t b = 0; b < B; ++b) start[b + 1] += start[b];
    std::array<std::uint32_t, N> order{};
    {
        std::array<std::uint32_t, B> fill{};
        for (std::size_t i = 0; i < N; ++i) {
            const std::uint32_t bk = bucket[i];
            order[start[bk] + fill[bk]++] = static_cast<std::uint32_t>(i);
        }
    }

    // Dead-pair check: same bucket, same base → unfixable for this seed.
    for (std::size_t b = 0; b < B; ++b) {
        for (std::size_t x = start[b]; x < start[b + 1]; ++x)
            for (std::size_t y = x + 1; y < start[b + 1]; ++y)
                if (base[order[x]] == base[order[y]]) return false;
    }

    // Process buckets largest-first (counting sort on bucket size).
    std::size_t max_size = 0;
    for (std::size_t b = 0; b < B; ++b) {
        const std::size_t sz = start[b + 1] - start[b];
        if (sz > max_size) max_size = sz;
    }
    std::array<std::uint32_t, B> border{};
    {
        // sizes are in [0, max_size]; bucket sort descending
        std::size_t pos = 0;
        for (std::size_t sz = max_size; sz > 0; --sz)
            for (std::size_t b = 0; b < B; ++b)
                if (start[b + 1] - start[b] == sz) border[pos++] = static_cast<std::uint32_t>(b);
        // empty buckets are never visited
        for (std::size_t b = 0; b < B; ++b)
            if (start[b + 1] == start[b]) border[pos++] = static_cast<std::uint32_t>(b);
    }

    std::array<std::uint8_t, M> taken{};
    for (std::size_t s = 0; s < M; ++s) out.slot_to_key[s] = static_cast<std::uint32_t>(N);
    for (std::size_t b = 0; b < B; ++b) out.pilots[b] = 0;

    for (std::size_t bi = 0; bi < B; ++bi) {
        const std::uint32_t bk = border[bi];
        const std::size_t lo = start[bk], hi = start[bk + 1];
        if (lo == hi) break;   // remaining buckets are empty (sorted descending)
        bool placed = false;
        for (std::size_t d = 0; d < M && !placed; ++d) {
            bool ok = true;
            for (std::size_t x = lo; x < hi; ++x) {
                const std::size_t slot = (base[order[x]] + d) & (M - 1);
                if (taken[slot]) { ok = false; break; }
            }
            if (ok) {
                for (std::size_t x = lo; x < hi; ++x) {
                    const std::size_t slot = (base[order[x]] + d) & (M - 1);
                    taken[slot] = 1;
                    out.slot_to_key[slot] = order[x];
                }
                out.pilots[bk] = static_cast<std::uint32_t>(d);
                placed = true;
            }
        }
        if (!placed) return false;
    }
    for (std::size_t s = M; s < wide_result<N>::MaxM; ++s) out.slot_to_key[s] = static_cast<std::uint32_t>(N);
    out.table_size = M;
    out.seed = seed;
    out.strong = Strong;
    return true;
}

template <std::size_t N, std::size_t M, std::size_t L, bool Strong>
consteval bool wide_try_seeds(
    const std::array<std::array<std::uint64_t, L>, N>& lanes,
    std::size_t max_seeds,
    wide_result<N>& out)
{
    for (std::size_t si = 0; si < max_seeds; ++si) {
        ++out.seeds_tried;
        if (wide_try_place<N, M, L, Strong>(lanes, si, out)) return true;
    }
    return false;
}

// Full search: tight table first (lookup footprint), fast hash before the
// strong one (lookup latency), then one table doubling.
template <std::size_t N, std::size_t MaxKeyLen>
consteval wide_result<N> wide_build(const std::array<std::string_view, N>& keys) {
    constexpr std::size_t L = wide_lanes_for(MaxKeyLen);
    for (std::size_t i = 0; i < N; ++i)
        if (keys[i].size() > MaxKeyLen) throw "perfect_hash (wide): key longer than MaxKeyLen";

    std::array<std::array<std::uint64_t, L>, N> lanes{};
    for (std::size_t i = 0; i < N; ++i) lanes[i] = wide_key_lanes<MaxKeyLen>(keys[i]);

    // Duplicate detection in O(N log N) on the lanes (an O(N^2) string_view
    // sweep costs minutes of consteval at N = 5 000+). Identical lanes means
    // identical bytes and length (length is folded in), or — when the length
    // is not folded in — keys that differ only by trailing NUL bytes, which
    // no hash of the lanes can separate either. Both are rejected.
    {
        std::array<std::uint32_t, N> idx{};
        for (std::size_t i = 0; i < N; ++i) idx[i] = static_cast<std::uint32_t>(i);
        // heap sort by lanes (no recursion, no allocation)
        auto less = [&](std::uint32_t a, std::uint32_t b) {
            for (std::size_t l = 0; l < L; ++l) {
                if (lanes[a][l] != lanes[b][l]) return lanes[a][l] < lanes[b][l];
            }
            return false;
        };
        auto sift = [&](std::size_t root, std::size_t end) {
            while (true) {
                std::size_t child = 2 * root + 1;
                if (child >= end) break;
                if (child + 1 < end && less(idx[child], idx[child + 1])) ++child;
                if (!less(idx[root], idx[child])) break;
                std::uint32_t t = idx[root]; idx[root] = idx[child]; idx[child] = t;
                root = child;
            }
        };
        for (std::size_t s = N / 2; s-- > 0;) sift(s, N);
        for (std::size_t end = N; end-- > 1;) {
            std::uint32_t t = idx[0]; idx[0] = idx[end]; idx[end] = t;
            sift(0, end);
        }
        for (std::size_t i = 1; i < N; ++i)
            if (lanes[idx[i - 1]] == lanes[idx[i]]) {
                if (keys[idx[i - 1]] == keys[idx[i]]) throw "perfect_hash (wide): duplicate key in key set";
                throw "perfect_hash (wide): two keys differ only by trailing NUL bytes";
            }
    }

    wide_result<N> out{};
    constexpr std::size_t MinM = wide_result<N>::MinM;
    constexpr std::size_t MaxM = wide_result<N>::MaxM;
    constexpr std::size_t FAST_SEEDS = 48, STRONG_SEEDS = 48;
    if (wide_try_seeds<N, MinM, L, false>(lanes, FAST_SEEDS, out)) return out;
    if (wide_try_seeds<N, MinM, L, true >(lanes, STRONG_SEEDS, out)) return out;
    if (wide_try_seeds<N, MaxM, L, false>(lanes, FAST_SEEDS, out)) return out;
    if (wide_try_seeds<N, MaxM, L, true >(lanes, STRONG_SEEDS, out)) return out;
    throw "perfect_hash (wide): no seed/pilot assignment found (tried tight and 2x tables, fast and strong hashes)";
}

} // namespace ConstexprCore::detail

#endif // CONSTEXPRCORE_DETAIL_WIDE_GENERATOR_H
