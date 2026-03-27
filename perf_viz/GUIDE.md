# Performance Visualization Guide

This guide walks through each of the 10 analysis tools with example output from an Apple M3 Max (arm64, -O3, shuffled workloads, `sudo` for hardware perf counters).

## Setup

```bash
# Build
cmake -B build -DCMAKE_BUILD_TYPE=Release -DCMAKE_OSX_ARCHITECTURES=arm64 -DPH_BUILD_BENCHMARKS=ON
cmake --build build --target bench_protocol

# Collect data (sudo required for cycles/insn/BM counters)
sudo ./perf_viz/run_benchmarks.sh
```

---

## 01 — Instruction Breakdown

**What it shows**: Where instructions are spent in each PHF lookup, as stacked bars per key set.

```bash
python3 perf_viz/01_instruction_breakdown.py
```

```
URL Protocols (N=6, MaxKeyLen=5, total=72 insn)
----------------------------------------------------------------------
  🟦 Hash (gperf)           7 insn ( 9.7%) ████
  ⬜ Range+Len check        7 insn ( 9.7%) ████
  🟧 Key comparison        24 insn (33.3%) ████████████████
  🟩 Value lookup           5 insn ( 6.9%) ███
  ⬛ Loop overhead         26 insn (36.1%) ██████████████████

S&P 100 Tickers (N=100, MaxKeyLen=5, total=91 insn)
----------------------------------------------------------------------
  🟦 Bucket hash            8 insn ( 8.8%) ████
  🟪 Key hash (H&D)        20 insn (22.0%) ██████████
  ⬜ Range+Len check        7 insn ( 7.7%) ███
  🟧 Key comparison        24 insn (26.4%) █████████████
  🟩 Value lookup           5 insn ( 5.5%) ██
  ⬛ Loop overhead         24 insn (26.4%) █████████████

HTTP Headers (N=20, MaxKeyLen=15, total=172 insn)
----------------------------------------------------------------------
  🟦 Bucket hash            8 insn ( 4.7%) ██
  🟪 Key hash (H&D)        20 insn (11.6%) █████
  ⬜ Range+Len check        7 insn ( 4.1%) ██
  🟧 Key comparison        85 insn (49.4%) ████████████████████████
  🟩 Value lookup           5 insn ( 2.9%) █
  ⬛ Loop overhead         44 insn (25.6%) ████████████
```

**Insight**: Key comparison dominates for long keys (Headers: 49%, MIME: 46%). For short keys, the comparison is only 26-33% — loop overhead from the benchmark harness is actually the largest component.

---

## 02 — IPC Roofline Plot

**What it shows**: Instructions per cycle vs instruction count. Demonstrates that branchless code with more instructions beats branchy code with fewer instructions.

```bash
python3 perf_viz/02_ipc_roofline.py
```

```
Method                 KeySet                 Insn    IPC      ns    BM
--------------------------------------------------------------------------------
  ★ PHF                  URL Protocols            72   9.05    1.97  0.00
  ★ PHF                  MIME Types              126   8.73    3.81  0.00
  ★ PHF                  C++ Keywords             88   8.69    2.56  0.00
  ★ PHF                  S&P 100 Tickers          91   8.32    2.89  0.00
  ★ PHF                  HTTP Headers            172   7.89    5.70  0.00
    absl                 C++ Keywords             99   3.05    9.14  0.70
    absl                 URL Protocols           104   2.67   10.29  0.85
    naive                S&P 100 Tickers         333   1.86   46.17  2.77
    naive                URL Protocols            71   1.55   11.50  1.05

★ = zero branch misses
```

**Insight**: PHF achieves IPC 8-9 (near the M3 Max theoretical maximum of ~10) despite having 72-172 instructions. Naive has only 71 instructions for protocols but IPC of 1.55 — branch misses stall the pipeline. The M3's wide decode (8+) is fully utilized only when the code is branchless.

With `matplotlib` installed, generates a scatter plot (`02_ipc_roofline.png`) where:
- X-axis = instructions per lookup
- Y-axis = IPC
- Bubble size = ns/lookup
- Color = method

---

## 03 — Branch Miss Heat Map

**What it shows**: A matrix of branch misses per lookup across all key sets and methods.

```bash
python3 perf_viz/03_branch_miss_heatmap.py
```

```
Key Set                     PHF    naive     absl std::umap   ankerl
--------------------------------------------------------------------------------
URL Protocols           ✅ 0.00  🔴 1.05  🔴 0.85  🔴 1.02  🔴 1.02
MIME Types              ✅ 0.00  🔴 1.42  🔴 0.67  🔴 0.85  🔴 0.83
C++ Keywords            ✅ 0.00  🔴 1.36  🔴 0.70  🔴 0.98  🔴 1.05
HTTP Headers            ✅ 0.00  🔴 1.40  🔴 1.23  🔴 1.50  🔴 1.73
S&P 100 Tickers         ✅ 0.00  🔴 2.77  🔴 0.62  🔴 0.83  🔴 1.33
```

**Insight**: PHF is a wall of green — zero branch misses across every key set. Every other method has 0.6-2.8 misses per lookup. Each miss costs ~15 cycles on the M3, explaining why methods with fewer instructions (naive: 71) are still slower than PHF (72-172).

---

## 04 — Assembly Analysis

**What it shows**: Annotated ARM64 assembly for PHF lookup functions with instruction, branch, and load counts.

```bash
bash perf_viz/04_asm_analysis.sh
```

```
============================================
proto_lookup: 50 instructions, 3 branches, 6 loads
============================================
     1  __Z12proto_lookup...:
     2      sub   x9, x1, #6          ; range check: len - 6
     3      cmn   x9, #4              ; (len-6) < -4 → len in [2,5]
     4      b.lo  LBB0_5              ; reject out-of-range
     5      mov   x8, x0
     6      ldrb  w11, [x0]           ; key[0]
     ...    ; hash: asso_values[key[0]] + len, AND 7
     ...    ; safe_byte pack: 5 bytes → uint64
     ...    ; single cmp against packed_keys_[slot]
    50      ret
```

**Insight**: The standalone function shows the full inlined lookup path. The `safe_byte` pack dominates for MaxKeyLen=5 (24 of 50 instructions). The hash is only 7 instructions. Zero function calls.

---

## 05 — Compilation Time Curve

**What it shows**: How long the PHF generator takes at compile time for different key set sizes.

```bash
python3 perf_viz/05_compile_time_curve.py
```

```
    N    Time (s)   Generator  Bar
------------------------------------------------------------
    4        0.62s       gperf  ██████
    6        0.64s       gperf  ██████
    8        0.67s       gperf  ██████
   10        0.72s       gperf  ███████
   15        0.95s       gperf  █████████
   20        0.87s         H&D  ████████
   30        0.95s         H&D  █████████
   50        1.10s         H&D  ███████████
   75        1.35s         H&D  █████████████
  100        1.67s         H&D  ████████████████
```

**Insight**: gperf handles N≤15 in under 1 second but would take minutes/hours for N>20 (O(N² × iterations) in consteval). Hash-and-Displace is O(N) expected — 100 keys compile in 1.67 seconds. Without H&D, the compiler crashed at N=20 with 19GB memory usage.

---

## 06 — Throughput Scaling

**What it shows**: Lookup time vs number of keys for each method.

```bash
python3 perf_viz/06_throughput_scaling.py
```

```
    N      PHF     absl     umap   ankerl    naive
----------------------------------------------------------------------
    6     1.97    10.29    13.32    12.10    11.50  URL Protocols
   15     2.56     9.14    12.86    13.70    13.24  C++ Keywords
   15     3.81     8.75    12.69    11.65    13.98  MIME Types
   20     5.70    11.75    19.03    19.52    15.09  HTTP Headers
  100     2.89    10.04    13.55    17.75    46.17  S&P 100 Tickers
```

**Insight**: PHF is nearly flat from N=6 (1.97 ns) to N=100 (2.89 ns) for short keys — true O(1). The N=15/20 bumps for MIME/Headers are from longer keys (MaxKeyLen 15-16), not from N scaling. Binary search (naive at N=100) explodes to 46 ns — O(log N). Hash maps are flat but 3-5x slower than PHF.

---

## 07 — Memory Footprint

**What it shows**: Estimated memory usage for each method's data structure.

```bash
python3 perf_viz/07_memory_footprint.py
```

```
Key Set             N      PHF     absl     umap   ankerl  PHF savings
----------------------------------------------------------------------
Protocols           6     400B     464B     544B     512B  PHF is 1.2x smaller
Keywords           15     545B     489B    1264B     568B  PHF is 0.9x smaller
MIME Types         15     705B     489B    1264B     568B  PHF is 0.7x smaller
Headers            20    1094B     639B    1664B     764B  PHF is 0.6x smaller
Tickers           100    2294B    2914B    8064B    3564B  PHF is 1.3x smaller
```

**Insight**: PHF stores everything inline in the struct (constexpr, zero heap allocation). For small N, PHF and absl are comparable in size. For N=100, PHF is 1.3x smaller than absl and 3.5x smaller than `std::unordered_map`. The PHF struct is entirely in `.rodata` — no dynamic allocation, no cache-cold pointers.

---

## 08 — Flame Graph

**What it shows**: CPU time distribution as an interactive SVG flame graph.

```bash
# Requires FlameGraph tools
sudo bash perf_viz/08_flamegraph.sh
# Opens perf_viz/flamegraph.svg
```

On Linux, uses `perf record`. On macOS, uses `sample(1)`. For best results on macOS, use Instruments.app with the "Time Profiler" template.

---

## 09 — Live Dashboard

**What it shows**: Real-time performance metrics with ANSI color coding as the benchmark runs repeatedly.

```bash
sudo bash perf_viz/09_live_dashboard.sh stock make_perfect_map
```

```
PHF Live Dashboard — stock / make_perfect_map
Press Ctrl+C to stop

Run      ns       Gv/s     IPC      BM       insn
────────────────────────────────────────────────
1        2.89     0.35     8.30     0.00     91.07
2        2.91     0.34     8.28     0.00     91.07
3        2.88     0.35     8.32     0.00     91.07
4        2.90     0.34     8.29     0.00     91.07
```

Green = fast (<5 ns), yellow = moderate (5-10 ns), red = slow (>10 ns). Useful during interactive optimization: make a code change, rebuild, watch the dashboard for instant feedback.

---

## 10 — Regression Tracker

**What it shows**: Compares current benchmark results against a saved baseline, flags regressions >5%.

```bash
# Save current results as baseline
python3 perf_viz/10_regression_tracker.py --save-baseline

# After making changes, run benchmarks again and compare
sudo ./perf_viz/run_benchmarks.sh
python3 perf_viz/10_regression_tracker.py
```

```
REGRESSION CHECK: PHF make_perfect_map (all hits)
  Baseline: perf_viz/baseline_results.json
  Current:  perf_viz/benchmark_results.json
  Threshold: 5%
======================================================================
Key Set                 Base ns  Curr ns    Delta     Status
----------------------------------------------------------------------
C++ Keywords               2.56     2.56   +0.0%  ✅ OK
HTTP Headers               5.70     5.70   +0.0%  ✅ OK
MIME Types                 3.81     3.81   +0.0%  ✅ OK
S&P 100 Tickers            2.89     2.89   +0.0%  ✅ OK
URL Protocols              1.97     1.97   +0.0%  ✅ OK
----------------------------------------------------------------------
✅ No regressions detected.
```

If a regression is detected:

```
S&P 100 Tickers            2.89     3.45   +19.4%  🔴 REGRESS
                          IPC: 8.30 → 6.12  BM: 0.00 → 0.45
```

Returns exit code 1 on regression, suitable for CI integration.

---

## Generating PNG Plots

All tools that produce charts have optional `matplotlib` support:

```bash
pip3 install matplotlib numpy
python3 perf_viz/02_ipc_roofline.py       # → 02_ipc_roofline.png
python3 perf_viz/03_branch_miss_heatmap.py # → 03_branch_miss_heatmap.png
python3 perf_viz/05_compile_time_curve.py  # → 05_compile_time_curve.png
python3 perf_viz/06_throughput_scaling.py  # → 06_throughput_scaling.png
python3 perf_viz/07_memory_footprint.py    # → 07_memory_footprint.png
```

All PNGs are saved to the `perf_viz/` directory at 150 DPI.
