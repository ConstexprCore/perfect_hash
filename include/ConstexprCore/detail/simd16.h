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

template <std::size_t MaxKeyLen>
CONSTEXPRCORE_NO_SANITIZE_ADDRESS constexprcore_really_inline bool compare_chunks(const char* p, std::size_t len, const char* stored) noexcept {
    constexpr std::size_t C = (MaxKeyLen + 15) / 16;
    static_assert(C >= 1);
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
