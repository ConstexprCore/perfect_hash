# PR 30 review and local measurements

Review baseline: `7d49ef211d3038478dfbfcb4b07588d17c00bf61`.
Measurements taken on Apple M3 Max with AppleClang 15, native arm64, Release `-O3`.
No hardware performance counters were available; these results make no new claims
about instruction counts or branch misses.

## Changes retained

- Removed factory duplicate-key scans already performed by the generator. This
  preserves duplicate diagnostics and reduces repeated constant evaluation.
- Fixed fused two-lane key comparison, singleton tables, empty views, padded
  chunks, `const bool` values, and slot indices in doubled wide tables.
- Mixed the strong fallback between lanes so changes that cancel in the fast
  hash can be separated. The ordinary fast hash is unchanged.
- Bounded the configurable position search, including budgets of one and two,
  and kept H&D metadata inside that budget.
- Dispatched keys of 255–4,080 bytes to the wide container and corrected the
  single-header dependency order.
- Fixed short-literal comparisons under compiler optimization and LTO. Known
  short objects use a padded copy; GCC/Clang SSE2 query windows use explicit
  mapped-memory loads so later optimization cannot change membership results.
- Made mixed benchmarks explicitly 50% hits, independent of key-pool sizes.
  Previously, for example, the S&P 100 benchmark sampled 100 hit keys and 20
  miss keys from a combined pool, producing about 83% hits.

## Compile-time improvement

`benchmarks/review_compile.cpp` instantiates a 100-key set and a 100-key map with
distinct lengths. Minimal solver work makes repeated validation visible. One
warmup pair and 15 alternating measured pairs used `-fsyntax-only`; the only
difference in the isolated before/after comparison was the redundant scans.

| Median | Before | After | Change |
|---|---:|---:|---:|
| Translation unit | 0.660862 s | 0.568111 s | −14.0% |

The new version won all 15 pairs. This is a dedicated factory benchmark, not a
claim of a 14% reduction for every application or key set.

After configuring dependencies with CMake, the benchmark can be compiled with:

```sh
clang++ -std=c++2b -fsyntax-only -fconstexpr-steps=1000000000 \
  -Iinclude -Ibuild/_deps/useful_abstractions-src/include \
  benchmarks/review_compile.cpp
```

Use `-fconstexpr-ops-limit=1000000000` for GCC. On macOS select the native Xcode
compiler and SDK; an Intel Homebrew compiler produces a different target.

## Strong fallback correctness cost

`benchmarks/review_strong.cpp` forces `Strong=true` on 96 synthetic 32-byte keys.
Five alternating process runs measured the entire lookup and the isolated
four-lane hash. The map measurement includes the other correctness repairs;
the hash measurement isolates the added mixing.

| Median | Before | After |
|---|---:|---:|
| Forced-strong lookup | 4.204 ns | 5.125 ns |
| Four-lane strong hash | 0.829 ns | 1.273 ns |
| 512-key forced-strong compile | 0.590 s | 0.593 s |

This is an explicit cost of making the fallback handle additional binary key
sets. It is not a runtime optimization. The default fast hash does not pay it.
Compile the source with `-O3`, the same include paths and constexpr limits as
above, and run with an iteration count such as `250000`. Defining `PH_STRONG_N=512`
and using `-fsyntax-only` measures the larger compile-time case.

## Experiment rejected

Replacing the NEON realignment table with an addition to the existing byte mask
saved 4,352 bytes of table storage. Five alternating runs of 300 shuffled
200,000-lookup batches showed the following hit times:

| Set | Existing table | Computed mask |
|---|---:|---:|
| Counters | 1.728 ns | 1.771 ns |
| HTTP Headers | 1.242 ns | 1.242 ns |
| HTTP Headers 50 | 1.809 ns | 1.856 ns |
| MIME Types | 1.418 ns | 1.512 ns |

The experiment was reverted because the affected cases lost 2.5–6.6%.

## Full runtime comparison and validation

Both revisions use the corrected workload generator, identical dependencies,
compiler flags, and benchmark translation units. Runs alternate order to reduce
drift. Each reported process result is the fastest of 300 shuffled batches of
200,000 lookups; the comparison uses the median of five process results.
Hits, misses, and exact 50/50 mixtures are measured for all twelve key sets.

The test suite includes fixed and runtime keys, lane-by-lane fused comparisons,
empty views, padded tails, configurable position budgets, large key lengths, and
wide-dispatch single-header smoke coverage. Big-endian and LSX execution are not
available locally; MSVC was not tested locally.


| Hit workload | Before (ns) | After initial repairs (ns) |
|---|---:|---:|
| C++ Keywords | 1.310 | 1.336 |
| Counters | 1.878 | 1.878 |
| HTTP Headers | 1.354 | 1.328 |
| HTTP Headers 50 | 1.921 | 1.921 |
| Java FQCNs | 2.089 | 2.050 |
| JavaScript Reserved Words | 1.596 | 1.503 |
| Letters a-z | 0.581 | 0.571 |
| MIME Types | 1.515 | 1.541 |
| Nasdaq-listed Tickers | 1.676 | 1.704 |
| S&P 100 Tickers | 1.335 | 1.294 |
| S&P 500 Tickers | 1.329 | 1.345 |
| URL Protocols | 1.272 | 1.295 |

Across all 36 dataset/workload combinations, median changes ranged from −5.8%
to +4.4%. Most changes were within 2%; the HTTP Headers mixed case was 6.766 →
7.062 ns (+4.4%). These lookup results do not establish a general runtime speedup.
The retained performance improvement is reduced compile-time work. All samples,
including misses and mixtures, are in [the result file](../perf_viz/pr30_review_results.json).

The compiler-known-object fallback was added after this full comparison. A second
five-pair comparison against the repaired build covered every affected native
dataset (Headers, Headers 50, MIME, Counters, FQCNs) on hits, misses, and mixtures.
Its median changes ranged from −1.8% to +1.2%. The subsequent explicit-load change
is compiled only on SSE2 targets.

Final local test configurations include native AppleClang/NEON, forced scalar,
AppleClang x86-64/SSE2 under Rosetta, and GCC 16 x86-64/SSE2 in Docker. Separate-TU
LTO membership checks are registered through CMake when IPO is supported.

All checks passed: 68 CTest cases each on NEON, AppleClang/SSE2, and GCC/SSE2;
69 in scalar mode, which has an additional scalar-only test. The generated
single-header and LTO smoke tests are included in each configuration.

## SSE2 load hardening

An object-size check alone fixed the ordinary literal tests but failed a
separate-TU LTO membership check. The final SSE2 implementation uses an explicit
mapped-memory load and integer address formation for page-guarded tail windows.
It retains the library's page-safe overread design; this does not make unknown
runtime pointers subject to a general C++ object-bound check.

`benchmarks/review_sse2_mapped.cpp` compared the intrinsic and explicit-load
versions over seven alternating process pairs under Rosetta. Checksums matched.

| Operation | Intrinsic | Explicit load | Added time |
|---|---:|---:|---:|
| Masked 16-byte load | 0.498 ns | 0.540 ns | 0.041 ns |
| 32-byte comparison | 1.169 ns | 1.219 ns | 0.050 ns |
| 64-byte comparison | 2.076 ns | 2.148 ns | 0.072 ns |

These are emulated x86 measurements of a correctness cost, not native x86
performance claims. The Intel assembly dialect passed an LTO runtime check.
AVX2 and AVX-512 variants compiled and linked; AVX execution was unavailable.
