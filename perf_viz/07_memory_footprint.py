#!/usr/bin/env python3
"""
Memory Footprint Comparison: struct size in bytes for each method × key set.
PHF stores everything inline (~1-3 KB), hash maps have dynamic allocations.
"""

try:
    import matplotlib.pyplot as plt
    import matplotlib
    import numpy as np
    matplotlib.use('Agg')
    HAS_MPL = True
except ImportError:
    HAS_MPL = False

# PHF struct sizes (computed from template parameters)
# perfect_hash_set<N, TableSize, MaxKeyLen>:
#   asso_values: 256 bytes
#   num_positions + positions: 1 + 16 = 17 bytes
#   min_key_len: 1 byte
#   slot_key_len: TableSize bytes
#   slot_key_data: TableSize * MaxKeyLen bytes
#   packed_keys: TableSize * 8 bytes
#   slot_to_key: TableSize bytes
#   key_to_slot: N bytes
#   Total ≈ 274 + TableSize * (MaxKeyLen + 10) + N

def phf_size(n, table_size, max_key_len):
    return 274 + table_size * (max_key_len + 10) + n

# Estimated hash map sizes (bytes per entry for small maps):
#   std::unordered_map: ~80 bytes/entry (node-based, pointers, bucket array)
#   absl::flat_hash_map: ~40 bytes/entry (flat, SwissTable metadata)
#   ankerl::unordered_dense: ~48 bytes/entry (flat, robin hood)
# Plus per-key: string_view is 16 bytes, int is 4 bytes = 20 bytes payload
# Plus overhead: bucket array, metadata, load factor headroom

def umap_size(n):
    return 64 + n * 80  # rough: 80 bytes per node + bucket pointers

def absl_size(n):
    # SwissTable: ~1 byte metadata per slot + 24 bytes per slot (kv + padding)
    # Load factor ~87.5%, so table_size ≈ n * 1.15
    table_size = max(16, int(n * 1.15))
    return table_size * 25 + 64  # metadata + slots + header

def ankerl_size(n):
    table_size = max(16, int(n * 1.25))
    return table_size * 28 + 64

KEYSETS = [
    ("Protocols",   6,    8,   5),
    ("Keywords",   15,   16,   6),
    ("MIME Types",  15,  16,  16),
    ("Headers",    20,   32,  15),
    ("Tickers",   100,  128,   5),
]

def main():
    print("=" * 70)
    print("MEMORY FOOTPRINT (bytes, estimated)")
    print("=" * 70)
    print(f"{'Key Set':<16s} {'N':>4s}  {'PHF':>7s}  {'absl':>7s}  {'umap':>7s}  {'ankerl':>7s}  PHF savings")
    print("-" * 70)

    phf_sizes = []
    absl_sizes = []
    for name, n, ts, mkl in KEYSETS:
        p = phf_size(n, ts, mkl)
        a = absl_size(n)
        u = umap_size(n)
        ak = ankerl_size(n)
        ratio = a / p
        print(f"{name:<16s} {n:4d}  {p:6d}B  {a:6d}B  {u:6d}B  {ak:6d}B  PHF is {ratio:.1f}x smaller than absl")
        phf_sizes.append(p)
        absl_sizes.append(a)

    print(f"\nPHF stores all data inline in the struct (constexpr, zero allocation).")
    print(f"Hash maps require heap allocation, bucket arrays, and per-node overhead.")

    if HAS_MPL:
        fig, ax = plt.subplots(figsize=(10, 6))
        x = np.arange(len(KEYSETS))
        w = 0.2
        labels = [f"{name}\n(N={n})" for name, n, _, _ in KEYSETS]

        ax.bar(x - 1.5*w, [phf_size(n, ts, mkl) for _, n, ts, mkl in KEYSETS],
               w, label='PHF', color='#2196F3')
        ax.bar(x - 0.5*w, [absl_size(n) for _, n, _, _ in KEYSETS],
               w, label='absl', color='#4CAF50')
        ax.bar(x + 0.5*w, [umap_size(n) for _, n, _, _ in KEYSETS],
               w, label='std::umap', color='#9E9E9E')
        ax.bar(x + 1.5*w, [ankerl_size(n) for _, n, _, _ in KEYSETS],
               w, label='ankerl', color='#FF9800')

        ax.set_xticks(x)
        ax.set_xticklabels(labels, fontsize=10)
        ax.set_ylabel("Memory footprint (bytes)", fontsize=12)
        ax.set_title("Memory Footprint per Key Set", fontsize=13)
        ax.legend(fontsize=11)
        ax.grid(True, axis='y', alpha=0.3)
        plt.tight_layout()
        plt.savefig("perf_viz/07_memory_footprint.png", dpi=150)
        print("Saved perf_viz/07_memory_footprint.png")

if __name__ == "__main__":
    main()
