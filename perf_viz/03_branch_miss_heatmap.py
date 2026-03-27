#!/usr/bin/env python3
"""
Branch Miss Heat Map: matrix of key sets × methods, colored by BM per lookup.
Green = 0 BM (branchless), Red = high BM (branchy).
"""
import json

try:
    import matplotlib.pyplot as plt
    import matplotlib
    import numpy as np
    matplotlib.use('Agg')
    HAS_MPL = True
except ImportError:
    HAS_MPL = False

DATA_FILE = "perf_viz/benchmark_results.json"

METHODS = ["make_perfect_map", "naive", "absl::flat_hash_map", "std::unordered_map", "ankerl::dense"]
METHOD_SHORT = ["PHF", "naive", "absl", "std::umap", "ankerl"]

def load_data():
    with open(DATA_FILE) as f:
        return json.load(f)

def text_heatmap(data):
    hits = [d for d in data if d["workload"] == "hits" and "bm" in d]
    keysets = sorted(set(d["keyset"] for d in hits),
                     key=lambda k: next((d["N"] for d in hits if d["keyset"] == k), 0))

    print("=" * 80)
    print("BRANCH MISSES PER LOOKUP (all hits)")
    print("=" * 80)
    print(f"{'Key Set':<22s}", end="")
    for ms in METHOD_SHORT:
        print(f" {ms:>8s}", end="")
    print()
    print("-" * 80)

    for ks in keysets:
        print(f"{ks:<22s}", end="")
        for method in METHODS:
            match = [d for d in hits if d["keyset"] == ks and d["method"] == method]
            if match:
                bm = match[0]["bm"]
                # Color code: green for 0, red for high
                if bm < 0.01:
                    indicator = "  ✅ 0.00"
                elif bm < 0.5:
                    indicator = f"  🟡 {bm:.2f}"
                else:
                    indicator = f"  🔴 {bm:.2f}"
                print(indicator, end="")
            else:
                print("      N/A", end="")
        print()

    print("\n✅ = 0 branch misses (fully branchless)")
    print("🔴 = high branch misses (>0.5 per lookup, ~7+ cycles wasted)")

def mpl_heatmap(data):
    hits = [d for d in data if d["workload"] == "hits" and "bm" in d]
    keysets = sorted(set(d["keyset"] for d in hits),
                     key=lambda k: next((d["N"] for d in hits if d["keyset"] == k), 0))

    matrix = []
    for ks in keysets:
        row = []
        for method in METHODS:
            match = [d for d in hits if d["keyset"] == ks and d["method"] == method]
            row.append(match[0]["bm"] if match else float('nan'))
        matrix.append(row)

    fig, ax = plt.subplots(figsize=(10, 6))
    arr = np.array(matrix)
    im = ax.imshow(arr, cmap='RdYlGn_r', aspect='auto', vmin=0, vmax=1.5)

    ax.set_xticks(range(len(METHOD_SHORT)))
    ax.set_xticklabels(METHOD_SHORT, fontsize=11)
    ax.set_yticks(range(len(keysets)))
    ax.set_yticklabels(keysets, fontsize=11)

    for i in range(len(keysets)):
        for j in range(len(METHODS)):
            val = arr[i, j]
            color = 'white' if val > 0.7 else 'black'
            ax.text(j, i, f"{val:.2f}", ha='center', va='center', fontsize=11,
                    fontweight='bold', color=color)

    plt.colorbar(im, label="Branch misses per lookup")
    ax.set_title("Branch Misses per Lookup (all hits, shuffled)\n"
                 "Green = branchless (0 BM), Red = branchy (>1 BM)", fontsize=13)
    plt.tight_layout()
    plt.savefig("perf_viz/03_branch_miss_heatmap.png", dpi=150)
    print("Saved perf_viz/03_branch_miss_heatmap.png")

if __name__ == "__main__":
    data = load_data()
    text_heatmap(data)
    if HAS_MPL:
        mpl_heatmap(data)
    else:
        print("\n(Install matplotlib for PNG: pip3 install matplotlib)")
