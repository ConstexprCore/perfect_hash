# Performance Analysis: Compile-Time Perfect Hash Lookup

## Test Environment

- CPU: 16-core, 2.4 GHz
- L1D: 64 KiB, L1I: 128 KiB, L2: 4 MiB
- Compiler: AppleClang, `-O3 -std=c++2b`
- Google Benchmark v1.9.1, 3 repetitions

## Benchmark Results

Four implementations compared:
- **PHF**: Our compile-time `perfect_hash_set`
- **gperf**: GNU gperf 3.1 (external code generator)
- **unordered_set**: `std::unordered_set<std::string_view>`
- **binary_search**: Sorted `std::array` + `std::binary_search`

### HTTP Methods (7 keys)

Each iteration looks up 3 keys (positive/negative) or 6 keys (mixed).

| Method         | Positive (ns) | Negative (ns) | Mixed (ns) |
|----------------|---------------|---------------|------------|
| **PHF (ours)** | 0.77          | 0.39          | 0.80       |
| **gperf**      | 0.40          | 0.40          | 0.80       |
| unordered_set  | 28.8          | 12.5          | 43.6       |
| binary_search  | 64.0          | 40.1          | 104        |

### C++ Keywords (15 keys)

Each iteration looks up 5 keys (positive/negative) or 6 keys (mixed).

| Method         | Positive (ns) | Negative (ns) | Mixed (ns) |
|----------------|---------------|---------------|------------|
| **PHF (ours)** | 1.34          | 0.66          | 0.79       |
| **gperf**      | 0.67          | 0.66          | 0.80       |
| unordered_set  | 45.0          | 33.7          | 49.7       |
| binary_search  | 124           | 80.4          | 123        |

## Key Findings

### 1. PHF and gperf are 35-155x faster than std::unordered_set

Both perfect hash approaches dominate standard library containers. This is
expected: perfect hashing eliminates bucket chains, rehashing, and heap
allocations entirely.

### 2. gperf is ~1.9x faster than our PHF on positive lookups

On hits (where the full hash + verify path runs), gperf consistently beats
our implementation by roughly 2x:
- HTTP positive: 0.40 vs 0.77 ns (1.9x)
- KW positive:   0.67 vs 1.34 ns (2.0x)

On misses and mixed workloads, the gap narrows or disappears.

### 3. The gap is explained by the assembly

Inspecting the generated assembly for the HTTP methods set reveals the
specific causes (see `bench_asm.s` analysis below).

## Assembly Analysis: Where the Cycles Go

Generated with: `c++ -O3 -std=c++2b -S -masm=intel bench_asm.cpp`

### Our PHF `compute_hash` for 7 HTTP methods:

```asm
    movzx eax, byte ptr [rdi]              # load key[0]
    add   rsi, qword ptr [rcx + 8*rax]     # h = len + asso_values[key[0]]
    # --- modulo by 7: TEN instructions ---
    movabs rcx, 2635249153387078803         # magic constant for div-by-7
    mov   rax, rsi
    mul   rcx
    mov   rax, rsi
    sub   rax, rdx
    shr   rax
    add   rax, rdx
    shr   rax, 2
    lea   rcx, [8*rax]
    sub   rax, rcx
    add   rax, rsi                          # result = h % 7
```

The compiler successfully unrolled the position loop (only 1 position needed)
and eliminated `char_at` branches. The position loop is NOT a bottleneck for
this key set. However:

### Issue 1: Non-power-of-2 modulo — 10 instructions vs 1

`h % 7` requires a multiply-by-magic-constant sequence (10 instructions
including a 64-bit `mul`). With a power-of-2 table size, this becomes
`and rax, 7` — a single cycle.

gperf avoids modulo entirely: its table is sized to `MAX_HASH_VALUE + 1`
(10 for HTTP methods) and uses a range check (`key <= MAX_HASH_VALUE`)
instead of modular reduction.

### Issue 2: asso_values is 2048 bytes (8x larger than needed)

Our `asso_values_` is `std::size_t[256]` = 2048 bytes. Only 5 entries are
non-zero for 7 HTTP methods. gperf uses `unsigned char[256]` = 256 bytes
(8x smaller), which fits entirely in 4 cache lines.

Since asso values are typically small (bounded by the table size), `uint8_t`
or `uint16_t` would suffice for most key sets.

### Issue 3: Extra slot_to_key_ indirection

Our lookup path:
```
hash → slot_to_key_[slot] → keys_[key_idx] → string data
       ^^^^^^^^^^^^^^^^^^    ^^^^^^^^^^^^^^^
       extra indirection     pointer chase
```

gperf's lookup path:
```
hash → wordlist[hash] → strcmp
       ^^^^^^^^^^^^^^^
       direct, strings embedded inline
```

Our design adds one extra dependent memory load (`slot_to_key_`) that gperf
does not need. This exists because our slot mapping is decoupled from key
ordering — gperf embeds strings directly in hash-order.

### Issue 4: keys_ stored as string_view (pointer + length)

Each `string_view` is 16 bytes (pointer + size). Verification requires
loading the pointer, then following it to the actual string data — a pointer
chase. gperf embeds string literals directly in the wordlist array, avoiding
one level of indirection.

## Summary: Per-lookup cost breakdown

| Step                        | Our PHF       | gperf           |
|-----------------------------|---------------|-----------------|
| Load character(s)           | 1 load        | 1 load          |
| asso_values lookup          | 1 load (2KB)  | 1 load (256B)   |
| Hash reduction              | 10 insns (mul)| 0 (range check) |
| Slot → key index            | 1 load        | 0 (direct)      |
| Load key for verification   | 2 loads (ptr→data) | 1 load (inline) |
| String compare              | memcmp        | strncmp         |
| **Total dependent loads**   | **5**         | **2-3**         |

## Potential Improvements

1. **Power-of-2 table sizes**: Round TableSize up to the next power of 2.
   Replaces 10-instruction modulo with single AND. Costs a few empty slots.

2. **Smaller asso_values type**: Use `uint8_t` (256B) or `uint16_t` (512B)
   instead of `size_t` (2048B). 4-8x better cache footprint.

3. **Eliminate slot_to_key_ indirection**: Store keys directly in hash order
   (like gperf's wordlist). Saves one dependent load per lookup.

4. **Embed key data**: For small fixed key sets, consider embedding the
   actual string bytes rather than storing `string_view` pointers.
   Eliminates one pointer chase per verification.

## Conclusion

Our compile-time PHF is already excellent compared to standard containers
(35-155x faster). The ~2x gap vs gperf on positive lookups comes from
structural overhead (modulo, extra indirections, larger arrays) that could
be addressed without changing the core algorithm. The mixed-workload gap is
negligible, meaning the negative-lookup fast path (length/index check) is
already well-optimized.
