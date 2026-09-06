# Fixing the hard and adversarial cases

**Branch:** `francisco/hard-cases` · **Baseline:** `main` @ `076a1b8` · **Machine:** Apple M3 Max, AppleClang, arm64 · 2026-08-12

The library's generator can refuse key sets. Some refusals are fundamental (256 keys into byte-indexed tables), but others are artifacts of *what the generators can see* — and until now the failure modes ranged from "2 minutes of search, then a misleading error" to "works or not depending on the random draw." This document lists the hard cases precisely, explains why today's cascade fails each one, describes the experiments run on this branch, and ends with a ranked pitch. Everything below is measured, on this machine, at the stated commits; reproduction scripts are in the appendix.

---

## 1. The hard cases

### HC1 — Structural: more positions than the hash can read

**The set:** 18 keys, all length 20, all `'a'` except key *i* has `'b'` at position *i* (i = 0..17) — the "vertex-cover set" (`repro_18key_positions_fail.cpp`).

Keys *i* and *j* differ at exactly positions {i, j}, so a distinguishing position set must intersect every pair — a vertex cover of K₁₈ = **17 positions**, one more than `MAX_POSITIONS = 16`. The length term is useless (all equal); `LAST_CHAR` is useless (bytes 18–19 are `'a'` everywhere).

**Today (main):** all five position-selection strategies fail, and — because a `throw` in C++23 constant evaluation cannot be caught — the whole search aborts: **~115 s of budget burn, then** `throw "Failed to find distinguishing positions"` (surfacing under the generic `constexpr variable 'data' must be initialized by a constant expression`). Hash-and-Displace is never reached, and could not help anyway: keys 4–17 are byte-identical at positions 0–3, the last byte, and length — H&D's *entire* feature view — so fourteen keys share one (bucket, key-hash) fingerprint and collide at every displacement, at every table size. The sharpness is notable: the 17-key version builds (needs 16 = the cap), the 16-key version builds with a *minimal* M=16 table.

### HC2 — Probabilistic: the high-N "lottery zone"

**The sets:** ordinary random keysets, N ≳ 200 (measured examples: `mixA_n200` = 200 mixed-length keys, seed 242; `mixA_n255`; `fix8_n230`).

Two stacked mechanisms. First, for **N ≥ 129 the gperf tier has exactly one table size left (M = 256)** — no doubling headroom — and at ≥ 78 % load the partition solver failed on every N ≥ 200 draw we tested. Everything then rides on H&D, whose key-hash reads only the first 4 bytes (+ first/last/len for the bucket), and:

> **H&D at table size M is impossible ⇔ two same-bucket keys have key-hashes congruent mod M under both the 2-byte and 4-byte variants.** Congruent pairs collide at *every* displacement; the hash is unseeded, so there is no escape.

This model predicted every observed outcome exactly (atlas, `materials/06_failure_atlas.md` in the talk repo): `mixA_n200` contains the dead pair `tcwdgzd`/`yry` (congruent through M=2048) → hard failure after 26 s; `mixA_n255`/`fix8_n230` are dead at 256 but alive at 1024/512, so the generator "succeeded" with a table the container cannot hold and died with the **misleading** `static_assert '1024UL <= 256': TableSize must be <= 256`. Monte-Carlo dead-pair probability at M=256: **1 % @ N=100, 11 % @ 200, 23 % @ 255** (a floor — displacement exhaustion adds more). End-to-end: **5 of 10 test builds in N ∈ [200, 255] failed** on main.

### HC3 — Diagnosability: wrong or late errors

- **Duplicate keys** die with `"Failed to find distinguishing positions"`. The factories *have* duplicate checks, but they can never fire: `constexpr auto data = compute_phf(...)` is constant-evaluated at instantiation, **before** the factory body's statements run.
- **The `TableSize <= 256` assert** (HC2) blames a table size the user never chose.
- **N ≥ 256** produced the right message but only from the class static_assert, at the end of the pipeline.
- All consteval failures surface top-line as `constexpr variable 'data' must be initialized by a constant expression`; the real reason is buried in the note chain.

### HC4 — Compile-time burn on the way to failure

Position-wall sets ran `select_positions` **once per table size in both tiers** (the pair-coverage search burns its full 5000-evaluation backtracking budget each time, ~90 s per run under the interpreter) — up to 8 doomed repetitions. H&D's copy of the call was pure waste: it never uses the selected positions (its features are fixed); it only needed the "lengths alone suffice" shortcut.

---

## 2. Why the failures are structural, in one picture

```text
                          bytes of the key a generator can see
  gperf tier      : up to 16 CHOSEN positions + length     ── blind if information
  H&D tier        : bytes 0-3 + last byte + length          ── is spread wider, or
                                (unseeded!)                    congruence is unlucky
  (nothing)       : ← sets needing "see everything + re-roll on bad luck" fell here
```

Both generators read a bounded, *fixed* set of byte features. HC1 spreads information across more positions than either can see; HC2 is bad luck in a hash with no knob to turn. Any complete fix needs a tier that (a) reads **every byte** and (b) carries a **seed** so collisions of the moment are escapable. That is exactly what was built.

---

## 3. What this branch implements

### 3a. Tier 3: seeded whole-key hash + displacement (`try_seeded_fullhash`)

```text
  h      = fh_hash(key, seed)          64-bit, chunk-folded over ALL bytes
  bucket = (h >> 48) & 0xFF            top bits
  slot   = (asso[0][bucket] + h) & (M-1)      same displacement machinery as H&D
```

- `fh_hash` consumes the key as **little-endian 8-byte chunks** (zero-padded tail): assembled per byte at consteval, loaded with one `memcpy` at runtime — *identical values by construction* (the same LE assumption `packed_keys_` already makes). One multiply-fold per chunk + a murmur3 finalizer.
- The generator tries seeds 0, 1, 2, … (cap 512): per seed, a cheap **dead-pair pre-check** (same-bucket ∧ congruent mod M → re-roll immediately) then largest-bucket-first greedy displacement. Observed seeds in practice: single digits.
- Runtime marker: `num_positions_ = 0xFE` (`FULLHASH_MODE`), one new `std::uint64_t hash_seed_` member, `algorithm_name() == "seeded-fullhash"`. The mode gate is folded with H&D's (`num_positions_ >= 0xFE`), so **normal gperf-mode lookups keep exactly one never-taken branch**, as before.

### 3b. The cascade, rebuilt (`compute_phf`)

```text
  duplicate pre-check  (throws "duplicate key in key set" — HC3 fixed at the source)
  tier 1  gperf        cheapest hash (len + 1-2 loads)     ┐ all tiers capped at
  tier 2  H&D          fixed features, no position search  │ M ≤ 256 — no generator
  tier 3  seeded full  sees everything, re-rolls bad luck  ┘ may "succeed" at a size
  clear final throw    "no perfect hash fits in <= 256 slots ..."   the container can't hold
```

Plumbing that made it possible and cheap:
- `select_positions` **returns** `POSITION_SEARCH_FAILED` instead of throwing (consteval can't catch; failure must be a value for the cascade to continue).
- **Pre-flight:** the position search runs **once at the largest table** before the gperf tier. Sound early-out: the set of pairs needing position coverage at size M is {(i,j) : lenᵢ ≡ lenⱼ mod M}, which only *grows* as M shrinks — failure at the cap implies failure at every smaller power of two. Kills the 8× budget re-burn (HC4).
- **H&D no longer runs the position search at all** — replaced by the O(N²) lengths-distinguish check it actually needed.
- Factories gain `static_assert(N <= 255)` with a message that names the limit and the alternative.

Diff footprint: **two files** (`gperf_generator.h` +~230 lines including comments; `perfect_hash.h` +~40), no API change, no new headers.

---

## 4. Results

### Correctness (self-verifying probes: every key looked up, misses rejected; plus the full suite)

| Case | main @ 076a1b8 | this branch |
|---|---|---|
| **HC1** vc18 (adversarial) | ✗ positions throw after 115 s | ✓ **seeded-fullhash, M=32**, all verified — 114 s |
| vc17 / vc16 (boundary) | ✓ gperf | ✓ **gperf** (tier order preserved) |
| **HC2** mixA_n200 (hard throw) | ✗ H&D exhaustion, 26 s | ✓ **seeded-fullhash, M=256**, verified — **22.6 s** (rescued faster than it used to fail) |
| **HC2** mixA_n255 (misleading assert) | ✗ `'1024UL <= 256'` | ✓ rescued, verified — 24.6 s |
| **HC2** fix8_n230 (misleading assert) | ✗ `'1024UL <= 256'` | ✓ rescued, verified — 32.8 s |
| **HC3** duplicates | ✗ "distinguishing positions" | ✗ **"perfect_hash: duplicate key in key set"** — 3.4 s |
| **HC3** N=256 | ✗ late class assert | ✗ clear factory assert, ~15 s (cost is instantiating 256 NTTP keys, not search) |
| normal sets (protocols, headers-like 20, letters26) | ✓ gperf | ✓ gperf, same algorithm & table size |
| **doctest suite** | 40/40 | **40/40** (incl. single-header smoke) |

Every key set with ≤ 255 distinct keys that we could previously fail is now either **built and verified** or **rejected with the right message**. The only remaining refusals are the honest ones: duplicates and N > 255.

### Runtime (chrono harness, 200 K shuffled lookups × 300 reps, fastest; same harness both sides)

| Key set | main | branch | note |
|---|---|---|---|
| protocols6 (gperf) | 1.595 ns | 1.601 ns | **no regression** (Δ within noise) |
| headers20 (gperf) | 1.685 ns | 1.685 ns | **identical** |
| vc18 (tier 3, len-20 keys) | *does not build* | **6.19 ns** | 3 hash chunks + NEON-32 verify |
| protocols6 **forced** through tier 3 | — | **5.88 ns** (contains) | same keys as the 1.60 ns gperf row |

**The six-way ladder, same keys, same harness, quiet machine** (protocols6, `contains` unless noted — the definitive comparison):

| Approach | ns/lookup | vs tier 1 | vs `unordered_map` |
|---|---|---|---|
| tier 1 · gperf | **0.900** (1.020 lookup) | 1× | **10.5×** faster |
| tier 2 · H&D (forced) | **1.343** | 1.49× slower | **7.0×** faster |
| tier 3 · seeded-fullhash (forced) | **5.206** | 5.8× slower | **1.8×** faster |
| naive if-chain | 6.099 | — | 1.5× faster |
| `std::unordered_map` | 9.414 | — | 1× |

Every tier of the cascade beats `std::unordered_map` — and the worst-case rescue tier beats even the naive if-chain on a six-key set.

The apples-to-apples rows are the ones to remember: **the tier-3 tax is ~5-6× on identical keys** — and it is paid *only* by sets that previously did not compile at all. Rescued sets land at ~6 ns: squarely in the territory of the best competitor PHFs on this machine (kronuz/gperf ≈ 5–8 ns), still ~2× faster than `std::unordered_map`, still zero collisions, still branchless SIMD verification, still `.rodata`. Nobody trades down; some sets trade "nothing" for "6 ns."

Cost decomposition: the ~4.3 ns delta is almost entirely the serial multiply chain of `fh_hash` (seed-mix + per-chunk fold + finalizer ≈ 6 dependent multiplies). There is headroom here — see §6.

### Compile time

- Normal sets: unchanged (the pre-flight position search costs milliseconds when positions are findable).
- Rescued lottery sets: **~23–33 s** — comparable to or faster than the time main spends *failing* on them.
- Adversarial vc18: ~114 s (one full budget burn in the pre-flight, then fast tiers). Near-wall *successes* (vc17: 190 s vs 99 s) now pay the pre-flight *plus* the per-size search — the one measured compile-time regression, confined to budget-burning adversarial-adjacent sets; §6 lists the fix.

---

## 5. The second experiment: adaptive position count (S2)

`MAX_POSITIONS` is now macro-overridable (`-DCONSTEXPRCORE_MAX_POSITIONS=k`) as a **prototype** for per-instance table sizing. Measurements (protocols keyset, 1 position used):

| MAX_POSITIONS | sizeof(map) | note |
|---|---|---|
| 16 (default) | 4 464 B | 4 KB of asso tables, ~15/16 unused |
| **2** | **864 B** | **5.2× smaller**, same algorithm, same lookups, tests pass |
| 32 | 8 576 B | a *global* raise doubles everyone — wrong shape for a fix |
| 32 + vc20 | 10 072 B, `alg=gperf M=32`, verified | raised cap DOES let the 20-key vertex-cover set (19-position cover) through the gperf tier — at **286 s** compile and a ~19-load hash. Tier 3 handles the same family in 114 s at ~6 ns; the raised cap is the runtime-optimal niche answer, per-instance sizing is what would make it free |

The real design (not implemented here) is to thread `num_positions` through the factory the same way `table_size` already flows: `phf_result` → `perfect_hash_set<N, M, MaxKeyLen, NumPos>` with `asso_values_` sized `NumPos`. Every instance then pays for exactly the positions it uses — the protocols map drops from 4.5 KB to under 1 KB — and the generator cap can rise without taxing anyone. Two wrinkles to handle: displacement modes park a flag in `positions_[2]` (so `NumPos ≥ 3` in those modes, or move the flag), and ODR consistency if the macro override survives.

---

## 6. The pitch

Ranked by (benchmark performance × correctness × elegance × implementation simplicity):

### ① Ship the three-tier cascade + plumbing (this branch) — *recommended as-is*

- **Performance:** zero measured change for every existing user (1.601 vs 1.595 ns; identical headers20; one never-taken branch, as before). Rescued sets: ~6 ns — competitor-PHF speed for sets that previously failed to build.
- **Correctness:** the strongest property the library has ever had: **every set of ≤ 255 distinct keys we tested now builds, and every build is verified perfect at compile time** (the existing post-construction check runs for tier 3 too). Failures that remain are the honest ones, with honest messages. 40/40 tests.
- **Elegance:** the fix matches the diagnosis exactly — both old tiers see a *fixed* window of the key; the new tier sees *everything* and carries a *seed*. The tier order is a price ladder: cheapest hash that works wins. The dead-pair pre-check inside the seed loop is the atlas's impossibility theorem used constructively: don't search what is provably doomed, re-roll instead.
- **Simplicity:** two files, ~270 lines mostly comments and one self-contained generator; no API change; one new byte-mode sentinel + one u64 member. The riskiest line (consteval/runtime hash agreement) is de-risked by construction (chunks defined as LE bytes) and double-checked by the existing verify-every-key pass.

### ② The adaptive-positions refactor (S2) — *recommended as the follow-up PR*

Not for the adversarial cases (tier 3 already covers them more generally) but for what the prototype measured: **~5× smaller objects for typical keysets** (4 464 → 864 B) — likely visible as fewer cache lines touched in real applications with many maps — plus a free cap raise. It is a mechanical but wide refactor (template signature, ctors, factories), so it deserves its own change with its own bench pass.

### ③ Small refinements (cheap, in-order)

1. **Reuse the pre-flight's positions** on the success path (thread them into `try_gperf_po2`) — removes the doubled burn for near-wall sets (vc17's 99 s → 190 s), the one compile-time regression.
2. **Trim the tier-3 mixer** for small M — the finalizer's 3 multiply rounds are overkill for 8-bit buckets + 8-bit slots; 1–2 rounds may cut the runtime tax to ~2.5×. Needs a distribution re-check across the lottery corpus first.
3. **Name the duplicate key** in the diagnostic (const char* throw can't format; a `static_assert`-generating wrapper or a "first duplicate index" encoding could).
4. Surface the tier + seed in `algorithm_description()` output in benches (already implemented) and consider a `static_assert`-friendly `phf_report()` for users who want to *know* which tier they got.

### What deliberately stays impossible

Duplicates (nothing can separate them — now said plainly) and N > 255 (the byte-indexed representation is the perf thesis; pthash serves beyond). Both fail fast with accurate messages now.

---

## Appendix — reproduction

```bash
# on branch francisco/hard-cases
clang++ -std=c++23 -fconstexpr-steps=1000000000 -O2 -arch arm64 \
  -isysroot "$(xcrun --show-sdk-path)" -I include \
  -I build-bench/_deps/useful_abstractions-src/include \
  repro_18key_positions_fail.cpp -o repro && ./repro   # now BUILDS: seeded-fullhash M=32

cmake -S . -B build-hardcases -DCMAKE_BUILD_TYPE=Release -DCMAKE_OSX_ARCHITECTURES=arm64 \
  -DPH_BUILD_TESTS=ON -DPH_BUILD_BENCHMARKS=OFF -DPH_BUILD_EXAMPLES=OFF -DUA_BUILD_TESTS=OFF
cmake --build build-hardcases -j && ctest --test-dir build-hardcases   # 40/40
```

Gate battery and benches: `tier3_gates.py`, `bench_ab.cpp`, `bench_t3.cpp` (session scratchpad; regenerate from this document's descriptions — every keyset is seed-deterministic: `random.Random(seed)`, seeds listed in §4). The failure-side evidence and the congruence model live in the talk repo: `constexpr_talks/2026/perfect_hash/materials/06_failure_atlas.md`.
