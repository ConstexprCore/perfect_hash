#ifndef CONSTEXPRCORE_DETAIL_SIMD16_H
#define CONSTEXPRCORE_DETAIL_SIMD16_H

// ============================================================================
// 16-byte "chunk" abstraction shared by the wide (N > 255) container and the
// long-key (MaxKeyLen > 16) comparison ladder.
//
// A chunk is bytes [0, len) of a key fragment, zero-padded to 16 bytes, loaded
// page-safely and masked WITHOUT branching on len (tbl on NEON, AND-mask on
// SSE2/LSX). Both the whole-key hash and the key comparison consume chunks:
//   * hash:    lane0/lane1 give the two little-endian 64-bit halves
//   * compare: eq_chunk + all_equal give a fixed-count, branchless equality
// Everything here is a thin layer over the per-ISA helpers in
// neon_compare.h / sse2_compare.h / lsx_compare.h.
// ============================================================================

#include <cstddef>
#include <cstdint>
#include <cstring>
#include <utility>

#include <ConstexprCore/detail/neon_compare.h>
#include <ConstexprCore/detail/sse2_compare.h>
#include <ConstexprCore/detail/lsx_compare.h>

#ifndef constexprcore_really_inline
#if defined(_MSC_VER) && !defined(__clang__)
#define constexprcore_really_inline __forceinline
#else
#define constexprcore_really_inline inline __attribute__((always_inline))
#endif
#endif

namespace ConstexprCore::detail {

// Branchless: bytes [off, off+16) of a key of length len → chunk length in [0,16].
constexprcore_really_inline std::size_t chunk_len(std::size_t len, std::size_t off) noexcept {
    std::size_t l = len > off ? len - off : 0;
    return l > 16 ? 16 : l;
}

#if CONSTEXPRCORE_HAS_NEON
struct chunk16 { uint8x16_t v; };
using eqmask16 = uint8x16_t;

// Internal-linkage copy of the tbl mask table. On Mach-O an inline/weak
// symbol is reached through the GOT (adrp + ldr + ldr); an internal-linkage
// object is addressed PC-relative (adrp + add + ldr) — one load less on the
// hot path, at the cost of 272 bytes per translation unit.
static constexpr std::uint8_t chunk_tbl_masks[17][16] = {
    {0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {0,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {0,1,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {0,1,2,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {0,1,2,3,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {0,1,2,3,4,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {0,1,2,3,4,5,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {0,1,2,3,4,5,6,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {0,1,2,3,4,5,6,7,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {0,1,2,3,4,5,6,7,8,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {0,1,2,3,4,5,6,7,8,9,0x80,0x80,0x80,0x80,0x80,0x80},
    {0,1,2,3,4,5,6,7,8,9,10,0x80,0x80,0x80,0x80,0x80},
    {0,1,2,3,4,5,6,7,8,9,10,11,0x80,0x80,0x80,0x80},
    {0,1,2,3,4,5,6,7,8,9,10,11,12,0x80,0x80,0x80},
    {0,1,2,3,4,5,6,7,8,9,10,11,12,13,0x80,0x80},
    {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,0x80},
    {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15},
};
constexprcore_really_inline const std::uint8_t* chunk_mask_row(std::size_t len) noexcept {
    return chunk_tbl_masks[len];
}
constexprcore_really_inline chunk16 load_chunk16(const char* p, std::size_t len) noexcept {
    uint8x16_t raw = page_safe_load_16(p, len);
    return { vqtbl1q_u8(raw, vld1q_u8(chunk_mask_row(len))) };
}
// tbl-style rows: byte b of a row is b (keep) or 0x80 (zero)
inline constexpr bool MASK_ROW_INDEX_STYLE = true;
#define CONSTEXPRCORE_HAS_BYTE_SHUFFLE 1
constexprcore_really_inline chunk16 load_chunk16_row(const char* p, const std::uint8_t* row) noexcept {
    return { vqtbl1q_u8(vld1q_u8(reinterpret_cast<const uint8_t*>(p)), vld1q_u8(row)) };
}
constexprcore_really_inline chunk16 load_raw16(const char* p) noexcept {
    return { vld1q_u8(reinterpret_cast<const uint8_t*>(p)) };
}
constexprcore_really_inline chunk16 shuffle_row(chunk16 c, const std::uint8_t* row) noexcept {
    return { vqtbl1q_u8(c.v, vld1q_u8(row)) };
}
constexprcore_really_inline eqmask16 eq_or(eqmask16 a, eqmask16 b) noexcept { return vorrq_u8(a, b); }
constexprcore_really_inline eqmask16 eq_force(bool f) noexcept {
    return vdupq_n_u8(static_cast<std::uint8_t>(-static_cast<int>(f)));
}
constexprcore_really_inline std::uint64_t lane0(chunk16 c) noexcept {
    return vgetq_lane_u64(vreinterpretq_u64_u8(c.v), 0);
}
constexprcore_really_inline std::uint64_t lane1(chunk16 c) noexcept {
    return vgetq_lane_u64(vreinterpretq_u64_u8(c.v), 1);
}
constexprcore_really_inline eqmask16 eq_chunk(chunk16 c, const char* stored) noexcept {
    return vceqq_u8(c.v, vld1q_u8(reinterpret_cast<const uint8_t*>(stored)));
}
constexprcore_really_inline eqmask16 eq_and(eqmask16 a, eqmask16 b) noexcept { return vandq_u8(a, b); }
constexprcore_really_inline bool all_equal(eqmask16 m) noexcept {
    uint8x8_t narrowed = vshrn_n_u16(vreinterpretq_u16_u8(m), 4);
    return vget_lane_u64(vreinterpret_u64_u8(narrowed), 0) == ~0ULL;
}

#elif CONSTEXPRCORE_HAS_SSE2
struct chunk16 { __m128i v; };
using eqmask16 = __m128i;

constexprcore_really_inline chunk16 load_chunk16(const char* p, std::size_t len) noexcept {
    __m128i raw = page_safe_load_16(p, len);
    return { _mm_and_si128(raw, _mm_loadu_si128(reinterpret_cast<const __m128i*>(and_masks[len]))) };
}
// AND-style rows: byte b of a row is 0xFF (keep) or 0x00 (zero).
// SSE2 has no byte shuffle (pshufb is SSSE3), so no branch-free realign here.
inline constexpr bool MASK_ROW_INDEX_STYLE = false;
#define CONSTEXPRCORE_HAS_BYTE_SHUFFLE 0
constexprcore_really_inline chunk16 load_chunk16_row(const char* p, const std::uint8_t* row) noexcept {
    return { _mm_and_si128(_mm_loadu_si128(reinterpret_cast<const __m128i*>(p)),
                           _mm_loadu_si128(reinterpret_cast<const __m128i*>(row))) };
}
constexprcore_really_inline chunk16 load_raw16(const char* p) noexcept {
    return { _mm_loadu_si128(reinterpret_cast<const __m128i*>(p)) };
}
constexprcore_really_inline eqmask16 eq_or(eqmask16 a, eqmask16 b) noexcept { return _mm_or_si128(a, b); }
constexprcore_really_inline eqmask16 eq_force(bool f) noexcept { return _mm_set1_epi8(static_cast<char>(-static_cast<int>(f))); }
constexprcore_really_inline std::uint64_t lane0(chunk16 c) noexcept {
    return static_cast<std::uint64_t>(_mm_cvtsi128_si64(c.v));
}
constexprcore_really_inline std::uint64_t lane1(chunk16 c) noexcept {
    return static_cast<std::uint64_t>(_mm_cvtsi128_si64(_mm_unpackhi_epi64(c.v, c.v)));
}
constexprcore_really_inline eqmask16 eq_chunk(chunk16 c, const char* stored) noexcept {
    return _mm_cmpeq_epi8(c.v, _mm_loadu_si128(reinterpret_cast<const __m128i*>(stored)));
}
constexprcore_really_inline eqmask16 eq_and(eqmask16 a, eqmask16 b) noexcept { return _mm_and_si128(a, b); }
constexprcore_really_inline bool all_equal(eqmask16 m) noexcept {
    return _mm_movemask_epi8(m) == 0xFFFF;
}

#elif CONSTEXPRCORE_HAS_LSX
struct chunk16 { __m128i v; };
using eqmask16 = __m128i;

constexprcore_really_inline chunk16 load_chunk16(const char* p, std::size_t len) noexcept {
    __m128i raw = page_safe_load_16(p, len);
    return { __lsx_vand_v(raw, __lsx_vld(and_masks[len], 0)) };
}
inline constexpr bool MASK_ROW_INDEX_STYLE = false;
#define CONSTEXPRCORE_HAS_BYTE_SHUFFLE 0
constexprcore_really_inline chunk16 load_chunk16_row(const char* p, const std::uint8_t* row) noexcept {
    return { __lsx_vand_v(__lsx_vld(p, 0), __lsx_vld(row, 0)) };
}
constexprcore_really_inline chunk16 load_raw16(const char* p) noexcept { return { __lsx_vld(p, 0) }; }
constexprcore_really_inline eqmask16 eq_or(eqmask16 a, eqmask16 b) noexcept { return __lsx_vor_v(a, b); }
constexprcore_really_inline eqmask16 eq_force(bool f) noexcept { return __lsx_vreplgr2vr_b(-static_cast<int>(f)); }
constexprcore_really_inline std::uint64_t lane0(chunk16 c) noexcept {
    return static_cast<std::uint64_t>(__lsx_vpickve2gr_d(c.v, 0));
}
constexprcore_really_inline std::uint64_t lane1(chunk16 c) noexcept {
    return static_cast<std::uint64_t>(__lsx_vpickve2gr_d(c.v, 1));
}
constexprcore_really_inline eqmask16 eq_chunk(chunk16 c, const char* stored) noexcept {
    return __lsx_vseq_b(c.v, __lsx_vld(stored, 0));
}
constexprcore_really_inline eqmask16 eq_and(eqmask16 a, eqmask16 b) noexcept { return __lsx_vand_v(a, b); }
constexprcore_really_inline bool all_equal(eqmask16 m) noexcept {
    return __lsx_vpickve2gr_w(__lsx_vmskltz_b(m), 0) == 0xFFFF;
}

#else
// Scalar fallback: two little-endian 64-bit words assembled with branchless
// conditional byte loads (never reads past len).
struct chunk16 { std::uint64_t lo, hi; };
struct eqmask16 { std::uint64_t diff; };   // 0 == all equal

constexprcore_really_inline std::uint64_t scalar_safe_byte(const char* p, std::size_t len, std::size_t i) noexcept {
    const std::size_t has = static_cast<std::size_t>(i < len);
    const std::size_t si = i & (std::size_t{0} - has);
    return static_cast<std::uint64_t>(static_cast<unsigned char>(p[si])) & (std::uint64_t{0} - has);
}
constexprcore_really_inline chunk16 load_chunk16(const char* p, std::size_t len) noexcept {
    std::uint64_t lo = 0, hi = 0;
    for (std::size_t i = 0; i < 8; ++i) lo |= scalar_safe_byte(p, len, i) << (8 * i);
    for (std::size_t i = 0; i < 8; ++i) hi |= scalar_safe_byte(p, len, 8 + i) << (8 * i);
    return { lo, hi };
}
constexprcore_really_inline std::uint64_t lane0(chunk16 c) noexcept { return c.lo; }
constexprcore_really_inline std::uint64_t lane1(chunk16 c) noexcept { return c.hi; }
constexprcore_really_inline eqmask16 eq_chunk(chunk16 c, const char* stored) noexcept {
    std::uint64_t a, b;
    std::memcpy(&a, stored, 8);
    std::memcpy(&b, stored + 8, 8);
    return { (c.lo ^ a) | (c.hi ^ b) };
}
constexprcore_really_inline eqmask16 eq_and(eqmask16 a, eqmask16 b) noexcept { return { a.diff | b.diff }; }
constexprcore_really_inline bool all_equal(eqmask16 m) noexcept { return m.diff == 0; }
#endif

// Unguarded masked chunk load: the caller guarantees [p, p+16) is readable.
constexprcore_really_inline chunk16 load_chunk16_unguarded(const char* p, std::size_t len) noexcept {
#if CONSTEXPRCORE_HAS_NEON
    return { vqtbl1q_u8(vld1q_u8(reinterpret_cast<const uint8_t*>(p)), vld1q_u8(chunk_mask_row(len))) };
#elif CONSTEXPRCORE_HAS_SSE2
    return { _mm_and_si128(_mm_loadu_si128(reinterpret_cast<const __m128i*>(p)),
                           _mm_loadu_si128(reinterpret_cast<const __m128i*>(and_masks[len]))) };
#elif CONSTEXPRCORE_HAS_LSX
    return { __lsx_vand_v(__lsx_vld(p, 0), __lsx_vld(and_masks[len], 0)) };
#else
    return load_chunk16(p, len);
#endif
}

// Fixed-count, branchless comparison of a key of length len (<= MaxKeyLen)
// against a stored key zero-padded to a multiple of 16 bytes. Emits exactly
// ceil(MaxKeyLen/16) chunk loads+compares regardless of len: chunks past the
// key are fully masked to zero on both sides and compare equal trivially.
//
// ONE page-safety guard covers the whole 16*C-byte span (instead of one per
// chunk): taken with probability 1 - 16C/4096 (98.4 % for C = 4), independent
// of the key, so the predictor is essentially never wrong. The rare
// page-straddling key is copied into a zeroed stack buffer first.
#if CONSTEXPRCORE_HAS_NEON || CONSTEXPRCORE_HAS_SSE2 || CONSTEXPRCORE_HAS_LSX
// Sliding mask table: chunk i of a key of length len needs the mask row for
// clamp(len - 16i, 0, 16). Lay the rows out so that row (len + 16*(C-1-i))
// IS that row: all-zero rows below, the 17 transition rows, identity rows
// above. Every chunk's mask is then ONE indexed load off a per-chunk base
// (base_i = rows + 256*(C-1-i), offset = len*16) — no clamp arithmetic.
template <std::size_t MaxKeyLen>
struct sliding_mask_table {
    static constexpr std::size_t C = (MaxKeyLen + 15) / 16;
    static constexpr std::size_t ROWS = MaxKeyLen + 16 * (C - 1) + 1;
    alignas(16) std::uint8_t rows[ROWS][16];
};
template <std::size_t MaxKeyLen>
static constexpr sliding_mask_table<MaxKeyLen> sliding_masks_v = [] {
    sliding_mask_table<MaxKeyLen> t{};
    constexpr std::size_t C = sliding_mask_table<MaxKeyLen>::C;
    for (std::size_t v = 0; v < sliding_mask_table<MaxKeyLen>::ROWS; ++v) {
        const long u = static_cast<long>(v) - static_cast<long>(16 * (C - 1));
        const std::size_t keep = u < 0 ? 0 : (u > 16 ? 16 : static_cast<std::size_t>(u));
        for (std::size_t b = 0; b < 16; ++b)
            t.rows[v][b] = b < keep ? (MASK_ROW_INDEX_STYLE ? static_cast<std::uint8_t>(b) : 0xFF)
                                    : (MASK_ROW_INDEX_STYLE ? 0x80 : 0x00);
    }
    return t;
}();

template <std::size_t MaxKeyLen>
constexprcore_really_inline bool compare_chunks_direct(const char* p, std::size_t len, const char* stored) noexcept {
    constexpr std::size_t C = (MaxKeyLen + 15) / 16;
    const auto& SM = sliding_masks_v<MaxKeyLen>;
    eqmask16 m = eq_chunk(load_chunk16_row(p, SM.rows[len + 16 * (C - 1)]), stored);
    [&]<std::size_t... I>(std::index_sequence<I...>) {
        ((m = eq_and(m, eq_chunk(load_chunk16_row(p + 16 * (I + 1), SM.rows[len + 16 * (C - 2 - I)]),
                                 stored + 16 * (I + 1)))), ...);
    }(std::make_index_sequence<C - 1>{});
    return all_equal(m);
}
#else
template <std::size_t MaxKeyLen>
constexprcore_really_inline bool compare_chunks_direct(const char* p, std::size_t len, const char* stored) noexcept {
    constexpr std::size_t C = (MaxKeyLen + 15) / 16;
    eqmask16 m = eq_chunk(load_chunk16_unguarded(p, chunk_len(len, 0)), stored);
    [&]<std::size_t... I>(std::index_sequence<I...>) {
        ((m = eq_and(m, eq_chunk(load_chunk16_unguarded(p + 16 * (I + 1), chunk_len(len, 16 * (I + 1))),
                                 stored + 16 * (I + 1)))), ...);
    }(std::make_index_sequence<C - 1>{});
    return all_equal(m);
}
#endif

#if CONSTEXPRCORE_HAS_BYTE_SHUFFLE
// Realign rows: entry (need, o) holds tbl indices idx[j] = (j < need) ? j + o
// : 0x80 — "the window was loaded o bytes early; shift it back and zero the
// tail". 17 x 16 rows = 4.4 KB, touched sparsely.
struct realign_row_table { alignas(16) std::uint8_t rows[17][16][16]; };
static constexpr realign_row_table realign_rows_v = [] {
    realign_row_table t{};
    for (std::size_t need = 0; need <= 16; ++need)
        for (std::size_t o = 0; o < 16; ++o)
            for (std::size_t j = 0; j < 16; ++j)
                t.rows[need][o][j] = (j < need && j + o < 16) ? static_cast<std::uint8_t>(j + o) : 0x80;
    return t;
}();

// 17..32-byte keys, BRANCH-FREE: no page guard, no slow path, works for any
// input address.
//   chunk 1: load shifted back by o = max(0, page_off - 4080) — the window
//            then ends at the page edge, so it can never fault; a key that
//            itself crosses the edge sets o = 0 (both pages are mapped). The
//            (need, o) tbl row shifts the bytes back and zeroes the tail.
//   chunk 2: the overlap trick — bytes [len-16, len) are inside the key for
//            len >= 16 (never faults, no mask needed, compared against the
//            stored bytes at the same offset); for len < 16 it re-reads
//            chunk 1's window and its compare is forced true.
template <std::size_t MaxKeyLen>
CONSTEXPRCORE_NO_SANITIZE_ADDRESS constexprcore_really_inline bool compare_2chunks_branchfree(const char* p, std::size_t len, const char* stored) noexcept {
    const std::uintptr_t a = reinterpret_cast<std::uintptr_t>(p);
    const std::size_t off = a & 4095;
    const std::size_t need = len < 16 ? len : 16;
    std::size_t o = off > 4080 ? off - 4080 : 0;
    o = (off > 4096 - need) ? 0 : o;             // data reaches the next page → it is mapped
    const char* p1 = p - o;
    eqmask16 m = eq_chunk(shuffle_row(load_raw16(p1), realign_rows_v.rows[need][o]), stored);
    const bool short_key = len < 16;
    const std::size_t off2 = short_key ? 0 : len - 16;
    const char* p2 = short_key ? p1 : p + off2;  // always a safe window
    eqmask16 m2 = eq_or(eq_chunk(load_raw16(p2), stored + off2), eq_force(short_key));
    return all_equal(eq_and(m, m2));
}
#endif

template <std::size_t MaxKeyLen>
CONSTEXPRCORE_NO_SANITIZE_ADDRESS constexprcore_really_inline bool compare_chunks(const char* p, std::size_t len, const char* stored) noexcept {
    constexpr std::size_t C = (MaxKeyLen + 15) / 16;
    static_assert(C >= 1);
#if CONSTEXPRCORE_HAS_BYTE_SHUFFLE && !defined(CONSTEXPRCORE_NO_BRANCHFREE_2CHUNKS)
    // Two-chunk keys (17..32 B) go through the fully branch-free compare: no
    // page guard to mispredict when input keys happen to sit near page ends
    // (measured: a literal pool straddling a page cost 0.75 bm and 3.7x wall
    // time on the guarded form; this form is +5 instructions, always 0 bm).
    if constexpr (C == 2) return compare_2chunks_branchfree<MaxKeyLen>(p, len, stored);
#endif
    constexpr std::size_t SPAN = 16 * C;
    static_assert(SPAN <= 4096, "MaxKeyLen too large for a single-page guard");
    const std::uintptr_t addr = reinterpret_cast<std::uintptr_t>(p);
    if ((addr & 4095) <= 4096 - SPAN) [[likely]] {
        return compare_chunks_direct<MaxKeyLen>(p, len, stored);
    }
    alignas(16) char buf[SPAN] = {};
    for (std::size_t i = 0; i < len; ++i) buf[i] = p[i];
    return compare_chunks_direct<MaxKeyLen>(buf, len, stored);
}

// consteval-friendly little-endian lane of a key: bytes [8*lane, 8*lane+8),
// zero-padded. This is the reference definition the SIMD lane0/lane1 must
// agree with (they do, on little-endian targets: the same byte order the
// packed_keys_ paths already assume).
constexpr std::uint64_t key_lane(const char* p, std::size_t len, std::size_t lane) noexcept {
    std::uint64_t v = 0;
    for (std::size_t b = 0; b < 8; ++b) {
        std::size_t i = 8 * lane + b;
        if (i < len) v |= static_cast<std::uint64_t>(static_cast<unsigned char>(p[i])) << (8 * b);
    }
    return v;
}

} // namespace ConstexprCore::detail

#endif // CONSTEXPRCORE_DETAIL_SIMD16_H
