#ifndef CONSTEXPRCORE_DETAIL_NEON_SMH_H
#define CONSTEXPRCORE_DETAIL_NEON_SMH_H

// SMH (Shuffle-based Matching) for small perfect hash sets using ARM NEON.
// All keys are packed into two 16-byte NEON registers (32 bytes total).
// A single global shuffle table maps each packed byte position to the
// corresponding query byte index. At query time the query is loaded once
// (page-safe), masked to its length, shuffled twice, compared against both
// packed registers, and a 64-bit mask is extracted. A carry-propagation
// trick then detects whether any key's full byte range matched.
//
// Reference: https://branchfree.org/2018/05/30/smh-the-swiss-army-chainsaw-of-shuffle-based-matching-sequences/

#if CONSTEXPRCORE_HAS_NEON

#include <arm_neon.h>
#include <cstdint>
#include <cstddef>

namespace ConstexprCore::detail {

// Bit-position helpers for the narrowing cascade.
// After vshrn_n_u16(cmp,4) + vcombine + vshrn_n_u16(combined,2) the 64-bit
// mask allocates bits to each of the 32 packed-buffer positions as follows
// (within each group of 4 positions sharing one output byte):
//   pos 4k+0 : 2 bits at offset 8k        (bits [8k+1 : 8k  ])
//   pos 4k+1 : 4 bits at offset 8k+2      (bits [8k+5 : 8k+2])
//   pos 4k+2 : 2 bits at offset 8k+6      (bits [8k+7 : 8k+6])
//   pos 4k+3 : invisible (0 bits) — verified by byte-by-byte fallback

// Lowest mask bit for packed-buffer position p.  -1 if invisible.
constexpr int smh_bit_lsb(std::size_t p) {
    int g = static_cast<int>(p / 4);
    switch (p % 4) {
    case 0: return 8 * g;
    case 1: return 8 * g + 2;
    case 2: return 8 * g + 6;
    default: return -1;
    }
}

// Highest mask bit for packed-buffer position p.  -1 if invisible.
constexpr int smh_bit_msb(std::size_t p) {
    int g = static_cast<int>(p / 4);
    switch (p % 4) {
    case 0: return 8 * g + 1;
    case 1: return 8 * g + 5;
    case 2: return 8 * g + 7;
    default: return -1;
    }
}

// MSB of the last *visible* position of a key at [off, off+len).
constexpr int smh_key_msb(std::size_t off, std::size_t len) {
    for (std::size_t i = len; i > 0; --i) {
        int b = smh_bit_msb(off + i - 1);
        if (b >= 0) return b;
    }
    return -1;
}

// Runtime: load query, mask to length, shuffle twice, compare, extract mask,
// apply carry trick.  Returns the carry-trick result (non-zero ↔ ≥1 match).
CONSTEXPRCORE_NO_SANITIZE_ADDRESS
constexprcore_really_inline std::uint64_t neon_smh_match(
    const char* p,
    std::size_t len,
    const std::uint8_t* packed,
    const std::uint8_t* shuffle0,
    const std::uint8_t* shuffle1,
    std::uint64_t msb_mask,
    std::uint64_t lsb_mask) noexcept
{
    // Page-safe 16-byte load, then zero bytes >= len via TBL masking
    uint8x16_t raw   = page_safe_load_16(p, len);
    uint8x16_t query = vqtbl1q_u8(raw, vld1q_u8(tbl_masks[len]));

    // Shuffle query into alignment with each packed register
    uint8x16_t shuffled0 = vqtbl1q_u8(query, vld1q_u8(shuffle0));
    uint8x16_t shuffled1 = vqtbl1q_u8(query, vld1q_u8(shuffle1));

    // Compare against packed keys
    uint8x16_t cmp0 = vceqq_u8(shuffled0, vld1q_u8(packed));
    uint8x16_t cmp1 = vceqq_u8(shuffled1, vld1q_u8(packed + 16));

    // Narrowing cascade → 64-bit mask
    uint8x8_t  narrow0  = vshrn_n_u16(vreinterpretq_u16_u8(cmp0), 4);
    uint8x8_t  narrow1  = vshrn_n_u16(vreinterpretq_u16_u8(cmp1), 4);
    uint8x16_t combined = vcombine_u8(narrow0, narrow1);
    uint8x8_t  narrow2  = vshrn_n_u16(vreinterpretq_u16_u8(combined), 2);
    std::uint64_t mask   = vget_lane_u64(vreinterpret_u64_u8(narrow2), 0);

    // Carry-propagation trick: for each key range, clearing its MSB and
    // adding 1 at its LSB causes the carry to reach the MSB only if every
    // visible bit in between was set (i.e. every visible byte matched).
    std::uint64_t result = mask & ~msb_mask;
    result += lsb_mask;
    result &= msb_mask;
    return result;
}

} // namespace ConstexprCore::detail

#endif // CONSTEXPRCORE_HAS_NEON
#endif // CONSTEXPRCORE_DETAIL_NEON_SMH_H
