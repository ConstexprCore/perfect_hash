#ifndef CONSTEXPRCORE_DETAIL_NEON_COMPARE_H
#define CONSTEXPRCORE_DETAIL_NEON_COMPARE_H


#ifndef constexprcore_really_inline
#if defined(_MSC_VER) && !defined(__clang__)
#define constexprcore_really_inline __forceinline
#else
#define constexprcore_really_inline inline __attribute__((always_inline))
#endif // defined(_MSC_VER) && !defined(__clang__)
#endif // constexprcore_really_inline

#ifndef CONSTEXPRCORE_NO_SANITIZE_ADDRESS
#if defined(__GNUC__) || defined(__clang__)
#define CONSTEXPRCORE_NO_SANITIZE_ADDRESS __attribute__((no_sanitize("address")))
#else
#define CONSTEXPRCORE_NO_SANITIZE_ADDRESS
#endif
#endif // CONSTEXPRCORE_NO_SANITIZE_ADDRESS

#if defined(__aarch64__) && !defined(CONSTEXPRCORE_NO_NEON)
#include <arm_neon.h>
#include <cstdint>
#include <cstddef>
#define CONSTEXPRCORE_HAS_NEON 1


namespace ConstexprCore::detail {

// TBL index masks: bytes at index >= len are set to 0x80 (TBL maps to 0).
// Shared by neon_compare_8, neon_compare_16, and neon_compare_32.
inline constexpr std::uint8_t tbl_masks[17][16] = {
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

// Page-safe 16-byte load helper. Returns raw NEON vector from p.
// Falls back to byte-by-byte copy for addresses near page boundaries.
CONSTEXPRCORE_NO_SANITIZE_ADDRESS constexprcore_really_inline uint8x16_t page_safe_load_16(const char* p, std::size_t len) noexcept {
    uintptr_t addr = reinterpret_cast<uintptr_t>(p);
    if (__builtin_expect((addr & 16383) <= 16368, 1)) {
        return vld1q_u8(reinterpret_cast<const uint8_t*>(p));
    }
    alignas(16) std::uint8_t buf[16] = {};
    for (std::size_t j = 0; j < len; j++)
        buf[j] = static_cast<std::uint8_t>(p[j]);
    return vld1q_u8(buf);
}

// NEON 16-byte key comparison using TBL masking + vceqq.
// p: input key data, len: key length (1-16), stored: slot_key_data (16+ bytes, zero-padded).
constexprcore_really_inline bool neon_compare_16(const char* p, std::size_t len, const char* stored) noexcept {
    // Local mask copy — gives better codegen (PC-relative addressing) than shared table.
    static constexpr std::uint8_t masks[17][16] = {
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

    uint8x16_t raw = page_safe_load_16(p, len);

    uint8x16_t mask_vec = vld1q_u8(masks[len]);
    uint8x16_t input = vqtbl1q_u8(raw, mask_vec);

    // Compare against stored key (zero-padded in slot_key_data_)
    uint8x16_t stored_vec = vld1q_u8(reinterpret_cast<const uint8_t*>(stored));
    uint8x16_t cmp = vceqq_u8(input, stored_vec);

    // Reduce: narrowing shift pairs adjacent bytes into one, 0xFF only if both were 0xFF
    uint8x8_t narrowed = vshrn_n_u16(vreinterpretq_u16_u8(cmp), 4);
    return vget_lane_u64(vreinterpret_u64_u8(narrowed), 0) == ~0ULL;
}

// NEON 8-byte key comparison for MaxKeyLen <= 8.
// Same page-safe load + TBL masking, but extracts lower uint64 instead of full 16-byte vceqq.
// Replaces the safe_byte_ chain (~5 conditional insn per byte) with ~5 NEON insn total.
// p: input key data, len: key length (1-8), stored_packed: packed_keys_[slot] value.
constexprcore_really_inline bool neon_compare_8(const char* p, std::size_t len, std::uint64_t stored_packed) noexcept {
    static constexpr std::uint8_t masks[9][16] = {
        {0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
        {0,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
        {0,1,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
        {0,1,2,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
        {0,1,2,3,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
        {0,1,2,3,4,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
        {0,1,2,3,4,5,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
        {0,1,2,3,4,5,6,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
        {0,1,2,3,4,5,6,7,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    };

    uint8x16_t raw = page_safe_load_16(p, len);

    uint8x16_t mask_vec = vld1q_u8(masks[len]);
    uint8x16_t masked = vqtbl1q_u8(raw, mask_vec);
    std::uint64_t input_packed = vgetq_lane_u64(vreinterpretq_u64_u8(masked), 0);
    return input_packed == stored_packed;
}

// NEON comparison for MaxKeyLen 17-32.
// Two passes: first 16 bytes + tail bytes (16+).
// When len <= 16, tail_len = 0 and TBL mask zeros everything, so the second
// vceqq is trivially all-equal without needing a branch.
constexprcore_really_inline bool neon_compare_32(const char* p, std::size_t len, const char* stored) noexcept {
    // --- First 16 bytes ---
    std::size_t len1 = len <= 16 ? len : 16;
    uint8x16_t raw1 = page_safe_load_16(p, len1);
    uint8x16_t input1 = vqtbl1q_u8(raw1, vld1q_u8(tbl_masks[len1]));
    uint8x16_t stored1 = vld1q_u8(reinterpret_cast<const uint8_t*>(stored));
    uint8x16_t cmp1 = vceqq_u8(input1, stored1);

    // --- Tail bytes (16+) ---
    std::size_t tail_len = len > 16 ? len - 16 : 0;
    uint8x16_t raw2 = tail_len > 0 ? page_safe_load_16(p + 16, tail_len) : vdupq_n_u8(0);
    uint8x16_t input2 = vqtbl1q_u8(raw2, vld1q_u8(tbl_masks[tail_len]));
    uint8x16_t stored2 = vld1q_u8(reinterpret_cast<const uint8_t*>(stored + 16));
    uint8x16_t cmp2 = vceqq_u8(input2, stored2);

    // --- Combine both passes ---
    uint8x16_t combined = vandq_u8(cmp1, cmp2);
    uint8x8_t narrowed = vshrn_n_u16(vreinterpretq_u16_u8(combined), 4);
    return vget_lane_u64(vreinterpret_u64_u8(narrowed), 0) == ~0ULL;
}

} // namespace ConstexprCore::detail

#endif // __aarch64__
#endif // CONSTEXPRCORE_DETAIL_NEON_COMPARE_H
