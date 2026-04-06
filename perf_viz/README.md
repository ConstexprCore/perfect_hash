# Performance Visualization Tools

Tools for analyzing and visualizing PHF benchmark performance.

## Quick Start

```bash
# Build benchmarks
cmake -B build -DCMAKE_BUILD_TYPE=Release -DPH_BUILD_BENCHMARKS=ON
cmake --build build --target bench_protocol

# Collect data (run with sudo for perf counters)
sudo ./perf_viz/run_benchmarks.sh

# Generate all text-based visualizations
python3 perf_viz/01_instruction_breakdown.py
python3 perf_viz/02_ipc_roofline.py
python3 perf_viz/03_branch_miss_heatmap.py
python3 perf_viz/06_throughput_scaling.py
python3 perf_viz/07_memory_footprint.py

# Generate plots (requires: pip3 install matplotlib numpy)
# PNG files saved to perf_viz/*.png

# Assembly analysis
bash perf_viz/04_asm_analysis.sh

# Compilation time curve (takes ~2 min)
python3 perf_viz/05_compile_time_curve.py

# Flame graph (requires FlameGraph tools)
sudo bash perf_viz/08_flamegraph.sh

# Live dashboard
sudo bash perf_viz/09_live_dashboard.sh stock make_perfect_map

# Regression tracking
python3 perf_viz/10_regression_tracker.py --save-baseline  # first time
python3 perf_viz/10_regression_tracker.py                  # after changes
```

## Tools

| # | Tool | Output | Description |
|---|------|--------|-------------|
| 01 | instruction_breakdown | text | Stacked bar: where instructions go per key set (PHF only) |
| 02 | ipc_roofline | text + PNG | IPC vs insn scatter (branchless vs branchy) |
| 03 | branch_miss_heatmap | text + PNG | Key set × method branch-miss matrix |
| 04 | asm_analysis | text | Annotated assembly with section counts |
| 05 | compile_time_curve | text + PNG | Compilation time vs N (gperf vs H&D) |
| 06 | throughput_scaling | text + PNG | ns/lookup vs N for each method |
| 07 | memory_footprint | text + PNG | Struct size comparison |
| 08 | flamegraph | SVG | CPU time flame graph (requires FlameGraph tools) |
| 09 | live_dashboard | terminal | Real-time ns/IPC/BM display |
| 10 | regression_tracker | text | Compare current vs baseline, flag >5% regressions |

## Methods benchmarked

`make_perfect_map`, `gperf`, `std::unordered_map`, `ankerl::dense`,
`absl::flat_hash_map`, `frozen::unordered_map`, `kronuz::phf`, `pthash`, `naive`

## Key sets

| Filter token | Display name | N | MaxKeyLen |
|---|---|---|---|
| `protocol` | URL Protocols | 6 | 5 |
| `stock` | S&P 100 Tickers | 100 | 5 |
| `keyword` | C++ Keywords | 15 | 6 |
| `header` | HTTP Headers | 20 | 17 |
| `mime` | MIME Types | 15 | 24 |
| `letters` | Letters a-z | 26 | 1 |
| `headers50` | HTTP Headers 50 | 50 | 19 |
| `jsreserved` | JavaScript Reserved Words | 45 | 10 |

## Data Format

`benchmark_results.json` contains an array of objects:
```json
{
  "keyset": "URL Protocols",
  "N": 6,
  "MaxKeyLen": 5,
  "workload": "hits",
  "method": "make_perfect_map",
  "ns": 2.06,
  "gvs": 0.49,
  "cycles": 7.83,
  "insn": 72.07,
  "ipc": 9.20,
  "bm": 0.00
}
```
