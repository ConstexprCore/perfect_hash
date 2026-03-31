#ifndef CONSTEXPRCORE_DETAIL_NEON_COMPARE_H
#define CONSTEXPRCORE_DETAIL_NEON_COMPARE_H


#ifndef constexprcore_really_inline
#if defined(_MSC_VER) && !defined(__clang__)
#define constexprcore_really_inline __forceinline
#else
#define constexprcore_really_inline inline __attribute__((always_inline))
#endif // defined(_MSC_VER) && !defined(__clang__)
#endif // constexprcore_really_inline

#if defined(__aarch64__) && !defined(CONSTEXPRCORE_NO_NEON)
#include <arm_neon.h>
#include <cstdint>
#include <cstddef>
#define CONSTEXPRCORE_HAS_NEON 1


namespace ConstexprCore::detail {

// NEON 16-byte key comparison using TBL masking + vceqq.
// Replaces ~48 instructions of safe_byte packing with ~5 NEON instructions.
// p: input key data, len: key length (1-16), stored: slot_key_data (16+ bytes, zero-padded).
// Returns true if the first 'len' bytes of p match the first 'len' bytes of stored.
constexprcore_really_inline bool neon_compare_16(const char* p, std::size_t len, const char* stored) noexcept {
    // Precomputed TBL index vectors: bytes at index >= len are set to 0x80,
    // which TBL maps to 0, effectively zero-padding the input.
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

    // Page-safe 16-byte load (99.95% fast path on 16KB Apple Silicon pages)
    uint8x16_t raw;
    uintptr_t addr = reinterpret_cast<uintptr_t>(p);
    if (__builtin_expect((addr & 16383) <= 16368, 1)) {
        // todo: this requires silencing sanitizers (clang/gcc).
        raw = vld1q_u8(reinterpret_cast<const uint8_t*>(p));
    } else {
        // Rare fallback: copy byte-by-byte
        alignas(16) std::uint8_t buf[16] = {};
        for (std::size_t j = 0; j < len; j++)
            buf[j] = static_cast<std::uint8_t>(p[j]);
        raw = vld1q_u8(buf);
    }

    // TBL zeros bytes beyond len
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

    uint8x16_t raw;
    uintptr_t addr = reinterpret_cast<uintptr_t>(p);
    if (__builtin_expect((addr & 16383) <= 16368, 1)) {
        raw = vld1q_u8(reinterpret_cast<const uint8_t*>(p));
    } else {
        alignas(16) std::uint8_t buf[16] = {};
        for (std::size_t j = 0; j < len; j++)
            buf[j] = static_cast<std::uint8_t>(p[j]);
        raw = vld1q_u8(buf);
    }

    uint8x16_t mask_vec = vld1q_u8(masks[len]);
    uint8x16_t masked = vqtbl1q_u8(raw, mask_vec);
    std::uint64_t input_packed = vgetq_lane_u64(vreinterpretq_u64_u8(masked), 0);
    return input_packed == stored_packed;
}

} // namespace ConstexprCore::detail

#endif // __aarch64__
#endif // CONSTEXPRCORE_DETAIL_NEON_COMPARE_H
