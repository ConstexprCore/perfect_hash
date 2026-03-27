#!/usr/bin/env python3
"""
Regression Tracker: compare current benchmark results against a baseline.
Flags any regression > 5% in ns/lookup for PHF (make_perfect_map) hits.

Usage:
  # Save current results as baseline:
  python3 perf_viz/10_regression_tracker.py --save-baseline

  # Compare against baseline:
  python3 perf_viz/10_regression_tracker.py

  # Compare two JSON files:
  python3 perf_viz/10_regression_tracker.py --baseline old.json --current new.json
"""
import json
import sys
import os
import shutil
import argparse

DATA_FILE = "perf_viz/benchmark_results.json"
BASELINE_FILE = "perf_viz/baseline_results.json"
THRESHOLD = 0.05  # 5% regression threshold

def load_phf_hits(path):
    with open(path) as f:
        data = json.load(f)
    return {d["keyset"]: d for d in data
            if d["workload"] == "hits" and d["method"] == "make_perfect_map"}

def compare(baseline_path, current_path):
    baseline = load_phf_hits(baseline_path)
    current = load_phf_hits(current_path)

    print("=" * 70)
    print("REGRESSION CHECK: PHF make_perfect_map (all hits)")
    print(f"  Baseline: {baseline_path}")
    print(f"  Current:  {current_path}")
    print(f"  Threshold: {THRESHOLD*100:.0f}%")
    print("=" * 70)
    print(f"{'Key Set':<22s} {'Base ns':>8s} {'Curr ns':>8s} {'Delta':>8s} {'Status':>10s}")
    print("-" * 70)

    regressions = 0
    for keyset in sorted(set(baseline) | set(current)):
        b = baseline.get(keyset)
        c = current.get(keyset)
        if not b or not c:
            print(f"{keyset:<22s} {'N/A':>8s} {'N/A':>8s}")
            continue

        b_ns = b["ns"]
        c_ns = c["ns"]
        delta = (c_ns - b_ns) / b_ns

        if delta > THRESHOLD:
            status = "🔴 REGRESS"
            regressions += 1
        elif delta < -THRESHOLD:
            status = "🟢 IMPROVED"
        else:
            status = "✅ OK"

        print(f"{keyset:<22s} {b_ns:8.2f} {c_ns:8.2f} {delta:+7.1%}  {status}")

        # Also compare IPC and BM if available
        if "ipc" in b and "ipc" in c:
            ipc_delta = c["ipc"] - b["ipc"]
            bm_delta = c.get("bm", 0) - b.get("bm", 0)
            if abs(ipc_delta) > 0.5 or abs(bm_delta) > 0.1:
                print(f"{'':22s} IPC: {b['ipc']:.2f} → {c['ipc']:.2f}  BM: {b.get('bm',0):.2f} → {c.get('bm',0):.2f}")

    print("-" * 70)
    if regressions:
        print(f"⚠️  {regressions} regression(s) detected (>{THRESHOLD*100:.0f}% slower)")
        return 1
    else:
        print("✅ No regressions detected.")
        return 0

def main():
    parser = argparse.ArgumentParser(description="PHF regression tracker")
    parser.add_argument("--save-baseline", action="store_true",
                        help="Save current results as the baseline")
    parser.add_argument("--baseline", default=BASELINE_FILE,
                        help=f"Baseline file (default: {BASELINE_FILE})")
    parser.add_argument("--current", default=DATA_FILE,
                        help=f"Current results file (default: {DATA_FILE})")
    args = parser.parse_args()

    if args.save_baseline:
        if not os.path.exists(args.current):
            print(f"Error: {args.current} not found. Run benchmarks first.")
            sys.exit(1)
        shutil.copy2(args.current, args.baseline)
        print(f"Saved baseline to {args.baseline}")
        return

    if not os.path.exists(args.baseline):
        print(f"No baseline found at {args.baseline}.")
        print(f"Run with --save-baseline first to create one.")
        sys.exit(1)

    if not os.path.exists(args.current):
        print(f"Error: {args.current} not found. Run benchmarks first.")
        sys.exit(1)

    sys.exit(compare(args.baseline, args.current))

if __name__ == "__main__":
    main()
