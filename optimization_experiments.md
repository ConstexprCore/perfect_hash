# Optimization Experiments Report

**Environment**: Apple M3 Max, arm64, -O3, sudo perf counters, 200K lookups shuffled between iterations.

## Baseline

| Key set | ns | insn | IPC | BM |
|---|---|---|---|---|
| Protocols (N=6) | **1.87** | 59 | 8.71 | 0.00 |
| MIME (N=15, long keys) | **3.86** | 116 | 7.93 | 0.00 |

## Experiment Results

### Exp A: contains() only (skip optional<> wrapping)

**Idea**: `lookup()` returns `optional<ValueT>` which has construction overhead (discriminant + value). Using `contains()` avoids this.

| Key set | ns | insn | IPC | BM | vs baseline |
|---|---|---|---|---|---|
| Protocols | **1.68** | 54 | 8.88 | 0.00 | -10% (5 insn saved) |
| MIME | **3.49** | 111 | 8.30 | 0.00 | -10% (5 insn saved) |

**Verdict**: `optional<>` costs ~5 instructions per lookup. For `contains()`-only use cases (e.g., membership testing), this is a free 10% win. Could expose a `contains()` fast path that skips the value lookup entirely.

---

### Exp B: Fully inlined manual lookup (protocols)

**Idea**: Hand-write the lookup as inline code: hash → slot → overlap → done. No generic function calls, no struct indirection.

| Key set | ns | insn | IPC | BM | vs baseline |
|---|---|---|---|---|---|
| Protocols | **0.98** | 33 | 8.67 | 0.00 | **-47%** (26 insn saved) |

**Verdict**: The theoretical floor for protocols is **0.98 ns / 33 instructions**. The current library adds 26 instructions of overhead: `compute_hash()` genericity (position loop setup even for 1 position), `compare_key_()` dispatch, and `lookup()` → `index_of()` → `optional<>` wrapping. Closing this gap requires specializing the hot path for common configurations.

---

### Exp C: Fused 8-byte memcpy load for MIME

**Idea**: Since MIME min_key_len=8, use `memcpy(8)` + branchless tail instead of `safe_byte` for the first 8 bytes. (Note: this is already what the library does internally.)

| Key set | ns | insn | IPC | BM | vs baseline |
|---|---|---|---|---|---|
| MIME | **7.60** | 47 | 1.63 | **0.94** | **+97% REGRESSION** |

**Verdict**: FAILURE. The hand-written version introduces a branchy tail loop (`for j in 8..len: ok &= a[j] == key[j]`) that the compiler doesn't unroll. The 0.94 BM from the tail loop branch destroys performance. The library's branchless `safe_byte` XOR-accumulate tail is correct — it's more instructions but zero branches.

**Lesson**: Never replace a branchless loop with a branchy one, even if it has fewer instructions.

---

### Exp D: NEON 16-byte compare for MIME

**Idea**: Use ARM NEON to load 16 bytes from both key and slot, compare with `vceqq_u8` in a single instruction.

| Key set | ns | insn | IPC | BM | vs baseline |
|---|---|---|---|---|---|
| MIME | **9.52** | 61 | 1.68 | **1.05** | **+147% REGRESSION** |

**Verdict**: FAILURE. The NEON comparison itself is fast (1 instruction) but:
1. Loading variable-length key data into a NEON register requires branches (len > 8 check for the high half)
2. The `vgetq_lane_u64` extraction from NEON → scalar is expensive
3. The `&&` conditional on two 64-bit lanes introduces a branch

The scalar `memcpy` + `safe_byte` approach is better because it stays entirely in the scalar pipeline with zero branches.

**Lesson**: NEON is not helpful for single-lookup string comparison — the scalar→NEON→scalar transfer overhead exceeds the comparison savings.

---

### Exp E: index_of() directly (skip lookup wrapper)

**Idea**: Call `set_.index_of()` directly instead of going through `map.lookup()` → `set_.index_of()` → `optional<ValueT>`.

| Key set | ns | insn | IPC | BM | vs baseline |
|---|---|---|---|---|---|
| Protocols | **1.77** | 57 | 8.85 | 0.00 | -5% (2 insn saved) |

**Verdict**: Minor win. The `perfect_hash_map::lookup()` wrapper adds ~2 instructions for the `optional<ValueT>` construction beyond `optional<size_t>` from `index_of()`.

---

### Exp F: Hash-first pipeline (gperf protocols)

**Idea**: Compute the hash (which only needs `key[0]`) first, then start loading `slot_key_len_[slot]` and `packed_keys_[slot]` while simultaneously computing the overlap encoding. This pipelines the hash table lookups with the key comparison.

| Key set | ns | insn | IPC | BM | vs baseline |
|---|---|---|---|---|---|
| Protocols | **0.92** | 30 | 8.59 | 0.00 | **-51%** (29 insn saved) |

**Verdict**: **Best result.** 0.92 ns with only 30 instructions. The key insight: by loading `packed_keys_[slot]` BEFORE computing the overlap encoding, the CPU's out-of-order engine can overlap the memory load latency with the overlap computation. The library's current code computes everything sequentially.

Combined with the overlap comparison (2 halfword loads), this is the theoretical minimum for the gperf path.

---

## Summary

| Experiment | Protocols | MIME | Key Insight |
|---|---|---|---|
| **Baseline** | **1.87 ns** | **3.86 ns** | — |
| A: contains() only | 1.68 ns (-10%) | 3.49 ns (-10%) | optional<> costs 5 insn |
| **B: Manual inline** | **0.98 ns (-47%)** | — | 26 insn of generic overhead |
| C: Fused 8B load | — | 7.60 ns (+97%) ❌ | Branchy tail kills perf |
| D: NEON 16B compare | — | 9.52 ns (+147%) ❌ | Scalar→NEON transfer too costly |
| E: index_of() direct | 1.77 ns (-5%) | — | Minor wrapper overhead |
| **F: Hash-first pipeline** | **0.92 ns (-51%)** | — | Pipeline hash load with comparison |

## Recommendations

1. **Expose `contains()` as the primary API** for membership testing. It's 10% faster than `lookup()` across all key sets (saves optional<> wrapping).

2. **Pipeline hash table loads with comparison** (Exp F). The current `compute_hash()` → `compare_key_()` sequence is serial. By loading `packed_keys_[slot]` immediately after computing the slot (before building the overlap encoding), the CPU overlaps memory latency with computation. This is a 51% improvement for protocols.

3. **Specialize for common MaxKeyLen values** (Exp B). The generic `pack_input_()` with `if constexpr` on MaxKeyLen already helps, but the function call overhead through `compute_hash()` → `compare_key_()` adds 26 instructions that a hand-inlined version avoids.

4. **Never use NEON for single-lookup string comparison** (Exp D). The scalar pipeline with branchless `safe_byte` consistently beats NEON due to the scalar→vector→scalar transfer cost.

5. **Never replace branchless loops with branchy ones** (Exp C). Even if the branchy version has fewer instructions, the branch misses (0.94 BM) cost more than the extra branchless instructions.
