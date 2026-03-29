# SIMD Exploration Experiments

**Environment**: Apple M3 Max, arm64, -O3, NEON, sudo perf counters, 200K lookups shuffled.

## Baseline (Lemire's latest tuning)

| Key set | ns | insn | IPC | BM |
|---|---|---|---|---|
| MIME (N=15, MaxKeyLen=16) | **2.72** | 88 | 8.55 | 0.00 |
| Headers (N=20, MaxKeyLen=15) | **3.96** | 123 | 8.20 | 0.00 |

## ARM64 NEON Experiments

### Exp 1: NEON TBL Masked 16-byte Load

**Idea**: Load 16 bytes from key via page-safe `vld1q_u8`, then use `vqtbl1q_u8` with a precomputed length-dependent index vector to zero bytes beyond `len`. TBL automatically produces 0 for out-of-range indices (>= 16). Compare the masked result against the stored slot key as two XORed uint64.

| Key set | ns | insn | IPC | BM | vs baseline |
|---|---|---|---|---|---|
| MIME | **1.76** | 53 | 8.47 | 0.00 | **-35%** |

**Verdict**: Strong win. Replaces 48 insn of safe_byte packing (8 bytes × 6 insn each) with ~8 NEON insn (ld1q + tbl + eor + extraction). The TBL mask lookup is one instruction and perfectly handles variable-length keys.

### Exp 2: NEON vceqq Against Stored 16-byte Key ★

**Idea**: Same page-safe load + TBL masking, but compare using `vceqq_u8` (byte-wise equality) and reduce with `vand` across halves. Avoids the XOR + lane extraction path.

| Key set | ns | insn | IPC | BM | vs baseline |
|---|---|---|---|---|---|
| MIME | **1.47** | 47 | 8.38 | 0.00 | **-46%** |

**Verdict**: **Best NEON result.** The `vceqq` + `vand` reduction is more efficient than XOR + OR + lane extraction. 47 instructions total — 41 fewer than baseline's 88. This is the approach to integrate.

### Exp 3: Two memcpy(8) + XOR (MIME only)

**Idea**: For MIME where min_key_len=8, load first 8 bytes via `memcpy`, then load remaining bytes via variable-length `memcpy`.

| Key set | ns | insn | IPC | BM | vs baseline |
|---|---|---|---|---|---|
| MIME | **5.98** | 73 | 3.21 | **0.70** | **+120% REGRESSION** |

**Verdict**: FAILURE. The variable-length second `memcpy(len - 8)` generates branches that mispredict (0.70 BM). IPC collapses from 8.55 to 3.21.

### Exp 4: Scalar Two-word with Branchless Second Load

**Idea**: Load first 8 bytes (memcpy or safe_byte), then load second 8 bytes branchlessly. Universal approach for both MIME and Headers.

| Key set | ns | insn | IPC | BM | vs baseline |
|---|---|---|---|---|---|
| Headers | **7.89** | 61 | 2.05 | **1.20** | **+99% REGRESSION** |

**Verdict**: FAILURE. The `if (len >= 8)` branch for the first load and the `if (len > 8)` for the second generate 1.20 BM, destroying IPC.

### Exp 5: NEON LD1 + EOR + UMAXV Reduction

**Idea**: Same page-safe load + TBL masking, but use XOR followed by `vmaxvq_u8` (max across vector) to check if all bytes are zero. If max of XOR is 0, all bytes match.

| Key set | ns | insn | IPC | BM | vs baseline |
|---|---|---|---|---|---|
| MIME | **1.63** | 52 | 8.41 | 0.00 | **-40%** |

**Verdict**: Strong win, slightly behind Exp 2. The `vmaxvq_u8` reduction is simpler (one instruction) but the vceqq + vand path in Exp 2 has better ILP because it processes both halves simultaneously.

## Summary

| Experiment | MIME ns | insn | IPC | vs baseline |
|---|---|---|---|---|
| Baseline (safe_byte) | 2.72 | 88 | 8.55 | — |
| **Exp 2: NEON vceqq** | **1.47** | **47** | 8.38 | **-46%** |
| Exp 5: NEON EOR+UMAXV | 1.63 | 52 | 8.41 | -40% |
| Exp 1: NEON TBL+XOR | 1.76 | 53 | 8.47 | -35% |
| Exp 3: 2x memcpy | 5.98 | 73 | 3.21 | +120% ❌ |
| Exp 4: Scalar 2-word | 7.89 | 61 | 2.05 | +99% ❌ |

## Why NEON Works Here (When It Didn't Before)

In our earlier SIMD exploration (pre-Lemire), NEON didn't help because:
1. The key packing was the bottleneck, and NEON→scalar extraction was costly
2. We were comparing single uint64 values (NEON overkill)

Now, with Lemire's two-word packed comparison (MaxKeyLen 9-16), the comparison involves TWO uint64 loads + XOR. NEON can do this more efficiently:
- **LD1Q**: loads 16 bytes in one instruction (vs 2 scalar loads)
- **TBL**: zeros variable-length padding in one instruction (vs 8 safe_byte calls = 48 insn)
- **VCEQQ/VEORQ**: compares all 16 bytes in one instruction (vs 2 XOR + 1 OR)
- **VAND/VMAXV**: reduces to scalar in 1-2 insn (vs lane extraction)

The key enabler is the **page-safe 16-byte load** combined with **TBL masking**. This pair eliminates the entire safe_byte overhead (48 insn → 2 insn) safely.

## AVX-512 Opportunities (Intel, documented only)

On Intel with AVX-512:
- **VPCMPB**: compare 64 bytes in one instruction → could handle MaxKeyLen up to 64
- **VPERMB**: byte-level permutation (like TBL but 64 bytes)
- **VPTESTMB**: test and mask in one instruction
- **Masked loads**: `VMOVDQU8` with opmask handles variable-length keys natively without TBL

These would be even more impactful on Intel where the scalar IPC is lower (3-4 vs M3's 8-9).

## Recommendation

**Integrate Exp 2 (NEON vceqq + TBL) for MaxKeyLen 9-16** on ARM64. This reduces MIME from 2.72 → 1.47 ns (-46%) and eliminates 41 instructions. Gate behind `#ifdef __aarch64__` with scalar safe_byte fallback for other architectures.

The page-safe load + TBL pattern is the general technique: it safely handles variable-length keys in 2 NEON instructions, replacing the O(MaxKeyLen) safe_byte chain.
