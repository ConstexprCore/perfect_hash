# Why the gperf-style Generator Explodes in Consteval

## The algorithm

Our PHF generator uses a gperf-style association-value hashing algorithm
(generalized Cichelli). The hash function has the form:

```
h(key) = key.size() + SUM(asso_values[key[pos_i]]) % TableSize
```

The generator must find values for the `asso_values[256]` array such that
every key hashes to a unique slot. It does this in two phases.

### Phase 1: Position selection

Pick which character positions in the keys to examine. The goal is the
fewest positions that distinguish all key pairs that could collide.

The pair-checking function compares every pair of keys: **O(N²)** per call.
The backtracking search calls it up to `budget` times. Total:
**O(N² × budget)**.

| N   | Pairs | Budget | Operations |
|-----|-------|--------|------------|
| 6   | 15    | 5,000  | 75K        |
| 15  | 105   | 5,000  | 525K       |
| 30  | 435   | 5,000  | 2.2M       |

### Phase 2: Asso-value solving (the bottleneck)

Start with `asso_values = {0}`. Then iterate:

```
for each of 12 jump values:
    reset asso_values to 0
    for up to M × 500 iterations:
        hash ALL N keys                    ← O(N × num_positions)
        assign slots, find first collision ← O(M)
        if no collision: DONE
        else:
            find the character that differs between the colliding pair
            bump asso_values[that_char] += jump
```

This is collision-detect-and-bump: a random walk through asso-value space.

**The critical problem**: every iteration re-hashes ALL N keys from scratch,
even though bumping one character's asso_value only affects the 1-5 keys
that use that character. There is no incremental update.

| N   | M   | Total hash ops (worst case)      |
|-----|-----|----------------------------------|
| 6   | 8   | 12 × 4,000 × 6 = **288K**       |
| 15  | 16  | 12 × 8,000 × 15 = **1.4M**      |
| 30  | 32  | 12 × 16,000 × 30 = **5.8M**     |
| 50  | 64  | 12 × 32,000 × 50 = **19.2M**    |
| 100 | 128 | 12 × 64,000 × 100 = **76.8M**   |

Each hash operation involves `num_positions` array lookups into
`asso_values[]`, plus a modular reduction. In consteval, each array
lookup costs ~10-100 compiler-internal steps (bounds checking, lifetime
tracking, AST node traversal). So 5.8M hash ops becomes **~500M consteval
steps**.

## Why consteval is ~1000x slower than native

The `consteval` interpreter is not a compiled program. It is the compiler's
constant expression evaluator — a tree-walking interpreter that executes
code statement-by-statement at compile time.

A native `asso_values[ch] += jump` is one CPU instruction (~1 ns).

The same line in consteval requires the compiler to:
1. Look up `asso_values` in its constexpr variable table
2. Verify the array is still in its valid lifetime
3. Evaluate the index expression `ch`
4. Bounds-check: is `ch < 256`?
5. Load the value from the compiler's internal array representation
6. Evaluate `jump`
7. Perform the addition
8. Store the result back
9. Increment the constexpr step counter
10. Check if the step limit has been exceeded

Additionally, a `std::array<size_t, 256>` in consteval is not a contiguous
2KB memory block with cache-friendly access. It is 256 individually tracked
values in the compiler's internal representation. There is no SIMD, no
cache prefetching, no out-of-order execution.

The ~1000x slowdown breaks down as:
- ~10x from interpreter overhead per operation
- ~10x from no hardware acceleration (no cache, no SIMD, no OoO)
- ~10x from memory representation overhead (tracked nodes vs raw bytes)

## Measured impact

| Key set         | N   | Compile time | Memory  | Outcome       |
|-----------------|-----|-------------|---------|---------------|
| URL Protocols   | 6   | 6 seconds   | ~500MB  | Success       |
| C++ Keywords    | 15  | >10 minutes | >19GB   | OOM / timeout |
| Stock Tickers   | 20  | >10 minutes | OOM     | Compiler crash|
| HTTP Headers    | 25  | N/A         | N/A     | Infeasible    |

## Why Hash-and-Displace is the solution

The gperf approach tries to find **one global** asso_values assignment that
avoids all collisions simultaneously. This is a search problem with
unpredictable iteration count.

Hash-and-Displace breaks it into **independent sub-problems**:

```
1. Hash each key into a bucket: bucket = h1(key) % B       O(N)
2. Sort buckets by size, largest first                      O(N)
3. For each bucket:
     try seed = 0, 1, 2, ...
     until h2(seed, key) maps ALL bucket keys
     to currently-empty slots                               O(N) expected
4. Store each bucket's seed                                 O(B)
```

Each bucket typically has 1-3 keys. Finding a seed that places 2 keys into
empty slots (out of ~2N available) almost always succeeds on the first few
tries. The expected total work across all buckets is **O(N)**.

| N   | gperf-style (hash ops) | Hash-and-Displace (ops) | Speedup |
|-----|------------------------|-------------------------|---------|
| 6   | 288K                   | ~50                     | 5,000x  |
| 30  | 5.8M                   | ~200                    | 29,000x |
| 100 | 76.8M                  | ~600                    | 128,000x|

This makes N=100+ keys feasible in consteval — what currently crashes the
compiler would complete in milliseconds.

## References

- GNU gperf manual: https://www.gnu.org/software/gperf/manual/gperf.html
- Schmidt, "gperf: A Perfect Hash Function Generator" (1990)
- Belazzougui, Botelho, Dietzfelbinger, "Hash, Displace, and Compress" (ESA 2009)
- Frozen library (constexpr Hash-and-Displace): https://github.com/serge-sans-paille/frozen
- Hanov, "Throw Away the Keys: Easy, Minimal Perfect Hashing": http://stevehanov.ca/blog/?id=119
