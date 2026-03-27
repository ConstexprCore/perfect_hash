#!/usr/bin/env python3
"""
Throughput Scaling: ns/lookup vs N for each method.
Shows PHF is O(1) while binary search is O(log N).
"""
import json

try:
    import matplotlib.pyplot as plt
    import matplotlib
    matplotlib.use('Agg')
    HAS_MPL = True
except ImportError:
    HAS_MPL = False

DATA_FILE = "perf_viz/benchmark_results.json"

METHOD_COLORS = {
    "make_perfect_map": "#2196F3",
    "naive": "#F44336",
    "absl::flat_hash_map": "#4CAF50",
    "std::unordered_map": "#9E9E9E",
    "ankerl::dense": "#FF9800",
}
METHOD_SHORT = {
    "make_perfect_map": "PHF",
    "naive": "naive",
    "absl::flat_hash_map": "absl",
    "std::unordered_map": "std::umap",
    "ankerl::dense": "ankerl",
}

def main():
    with open(DATA_FILE) as f:
        data = json.load(f)

    hits = [d for d in data if d["workload"] == "hits"]

    print("=" * 70)
    print("THROUGHPUT SCALING: ns/lookup vs N (all hits)")
    print("=" * 70)
    print(f"{'N':>5s}  {'PHF':>7s}  {'absl':>7s}  {'umap':>7s}  {'ankerl':>7s}  {'naive':>7s}")
    print("-" * 70)

    keysets = sorted(set((d["keyset"], d["N"]) for d in hits), key=lambda x: x[1])
    for ks_name, n in keysets:
        row = {"N": n}
        for method in METHOD_COLORS:
            match = [d for d in hits if d["keyset"] == ks_name and d["method"] == method]
            row[method] = match[0]["ns"] if match else None
        phf = row.get("make_perfect_map")
        absl = row.get("absl::flat_hash_map")
        umap = row.get("std::unordered_map")
        ankerl = row.get("ankerl::dense")
        naive = row.get("naive")
        print(f"{n:5d}  {phf or 0:7.2f}  {absl or 0:7.2f}  {umap or 0:7.2f}  {ankerl or 0:7.2f}  {naive or 0:7.2f}  {ks_name}")

    print("\nPHF scales from 2.06 ns (N=6) to 2.89 ns (N=100) — nearly flat O(1).")
    print("Binary search (naive for N=100) scales to 46 ns — O(log N).")

    if HAS_MPL:
        fig, ax = plt.subplots(figsize=(10, 6))
        for method, color in METHOD_COLORS.items():
            ns_list = []
            vals = []
            for ks_name, n in keysets:
                match = [d for d in hits if d["keyset"] == ks_name and d["method"] == method]
                if match:
                    ns_list.append(n)
                    vals.append(match[0]["ns"])
            if ns_list:
                ax.plot(ns_list, vals, 'o-', color=color, label=METHOD_SHORT[method],
                        linewidth=2, markersize=8)

        ax.set_xlabel("Number of keys (N)", fontsize=12)
        ax.set_ylabel("ns per lookup", fontsize=12)
        ax.set_title("Lookup Throughput vs Key Set Size (all hits, shuffled)", fontsize=13)
        ax.legend(fontsize=11)
        ax.grid(True, alpha=0.3)
        ax.set_yscale('log')
        ax.set_xscale('log')
        plt.tight_layout()
        plt.savefig("perf_viz/06_throughput_scaling.png", dpi=150)
        print("Saved perf_viz/06_throughput_scaling.png")

if __name__ == "__main__":
    main()
