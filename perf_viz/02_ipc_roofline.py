#!/usr/bin/env python3
"""
IPC Roofline Plot: scatter plot of IPC vs instruction count.
Bubble size = ns/lookup. Color = method.

Demonstrates the core thesis: branchless code with more instructions
beats branchy code with fewer instructions on wide OoO cores.
"""
import json
import sys

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
    "std::unordered_map": "#9E9E9E",
    "ankerl::dense": "#FF9800",
    "absl::flat_hash_map": "#4CAF50",
}

METHOD_SHORT = {
    "make_perfect_map": "PHF",
    "naive": "naive",
    "std::unordered_map": "std::umap",
    "ankerl::dense": "ankerl",
    "absl::flat_hash_map": "absl",
}

def load_data():
    with open(DATA_FILE) as f:
        return json.load(f)

def text_plot(data):
    hits = [d for d in data if d["workload"] == "hits" and "insn" in d]
    print("=" * 80)
    print("IPC vs INSTRUCTION COUNT (all hits, bubble = ns/lookup)")
    print("=" * 80)
    print(f"{'Method':<22s} {'KeySet':<20s} {'Insn':>6s} {'IPC':>6s} {'ns':>7s} {'BM':>5s}")
    print("-" * 80)

    # Sort by IPC descending
    hits.sort(key=lambda d: -d.get("ipc", 0))
    for d in hits:
        method = METHOD_SHORT.get(d["method"], d["method"])
        marker = "★" if d.get("bm", 1) < 0.01 else " "
        print(f"  {marker} {method:<20s} {d['keyset']:<20s} {d['insn']:6.0f} {d['ipc']:6.2f} {d['ns']:7.2f} {d.get('bm', -1):5.2f}")

    print("\n★ = zero branch misses")
    print("\nINSIGHT: PHF achieves IPC 8-9 (near M3 max of ~10) with 72-172 insn.")
    print("         Naive has only 71 insn but IPC < 2 due to branch misses.")
    print("         More instructions + zero branches = faster execution.")

def mpl_plot(data):
    hits = [d for d in data if d["workload"] == "hits" and "insn" in d]

    fig, ax = plt.subplots(figsize=(12, 8))

    for d in hits:
        color = METHOD_COLORS.get(d["method"], "#000000")
        size = d["ns"] * 40
        alpha = 0.7
        ax.scatter(d["insn"], d["ipc"], s=size, c=color, alpha=alpha,
                   edgecolors='black', linewidth=0.5)
        label = f"{d['keyset'][:8]}"
        ax.annotate(label, (d["insn"], d["ipc"]),
                    textcoords="offset points", xytext=(5, 5),
                    fontsize=7, alpha=0.8)

    # Legend
    for method, color in METHOD_COLORS.items():
        ax.scatter([], [], c=color, s=80, label=METHOD_SHORT[method],
                   edgecolors='black', linewidth=0.5)
    ax.legend(loc='upper right', fontsize=10)

    ax.set_xlabel("Instructions per lookup", fontsize=12)
    ax.set_ylabel("IPC (instructions per cycle)", fontsize=12)
    ax.set_title("IPC vs Instruction Count (bubble size = ns/lookup)\n"
                 "Top-left = fast (high IPC, few insn). Bottom-right = slow.", fontsize=13)
    ax.axhline(y=8, color='gray', linestyle='--', alpha=0.3, label='M3 ~max IPC')
    ax.set_ylim(0, 10)
    ax.grid(True, alpha=0.2)

    plt.tight_layout()
    plt.savefig("perf_viz/02_ipc_roofline.png", dpi=150)
    print("Saved perf_viz/02_ipc_roofline.png")

if __name__ == "__main__":
    data = load_data()
    text_plot(data)
    if HAS_MPL:
        mpl_plot(data)
    else:
        print("\n(Install matplotlib for PNG: pip3 install matplotlib)")
