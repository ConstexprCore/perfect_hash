#!/usr/bin/env python3
"""
Instruction Breakdown: stacked bar chart showing where instructions go
for each key set (PHF hits only).

Shows: hash computation, key comparison, value lookup, loop overhead.
Based on assembly analysis of the compiled binary.
"""
import json
import sys

# Instruction breakdown from assembly analysis (-O3).
# Totals are from measured perf counter data; per-section splits are from
# manual annotation of the generated assembly.
BREAKDOWN = {
    "URL Protocols": {
        "N": 6, "total": 72, "MaxKeyLen": 5,
        "range_check": 3, "hash": 7, "length_check": 4,
        "comparison": 24, "value_lookup": 5, "return": 3, "loop_overhead": 26
    },
    "S&P 100 Tickers": {
        "N": 100, "total": 91, "MaxKeyLen": 5,
        "range_check": 3, "bucket_hash": 8, "key_hash": 20, "length_check": 4,
        "comparison": 24, "value_lookup": 5, "return": 3, "loop_overhead": 24
    },
    "C++ Keywords": {
        "N": 15, "total": 88, "MaxKeyLen": 6,
        "range_check": 3, "hash": 7, "length_check": 4,
        "comparison": 29, "value_lookup": 5, "return": 3, "loop_overhead": 37
    },
    "HTTP Headers": {
        "N": 20, "total": 172, "MaxKeyLen": 17,
        "range_check": 3, "bucket_hash": 8, "key_hash": 20, "length_check": 4,
        "comparison": 85, "value_lookup": 5, "return": 3, "loop_overhead": 44
    },
    "MIME Types": {
        "N": 15, "total": 126, "MaxKeyLen": 24,
        "range_check": 3, "hash": 7, "length_check": 4,
        "comparison": 58, "value_lookup": 5, "return": 3, "loop_overhead": 46
    },
    "Letters a-z": {
        "N": 26, "total": 12, "MaxKeyLen": 1,
        "range_check": 2, "hash": 0, "length_check": 1,
        "comparison": 2, "value_lookup": 3, "return": 2, "loop_overhead": 2
    },
    "HTTP Headers 50": {
        "N": 50, "total": 185, "MaxKeyLen": 19,
        "range_check": 3, "bucket_hash": 8, "key_hash": 20, "length_check": 4,
        "comparison": 96, "value_lookup": 5, "return": 3, "loop_overhead": 46
    },
    "JavaScript Reserved Words": {
        "N": 45, "total": 110, "MaxKeyLen": 10,
        "range_check": 3, "bucket_hash": 8, "key_hash": 20, "length_check": 4,
        "comparison": 38, "value_lookup": 5, "return": 3, "loop_overhead": 29
    },
}

BAR_WIDTH = 50

def bar(value, total, char="█"):
    n = int(value / total * BAR_WIDTH)
    return char * n

def print_breakdown():
    print("=" * 80)
    print("INSTRUCTION BREAKDOWN PER LOOKUP (PHF, all hits, ARM64 -O3)")
    print("=" * 80)

    for name, data in BREAKDOWN.items():
        total = data["total"]
        print(f"\n{name} (N={data['N']}, MaxKeyLen={data['MaxKeyLen']}, total={total} insn)")
        print("-" * 70)

        sections = []
        if "hash" in data:
            sections.append(("Hash (gperf)", data["hash"], "🟦"))
        if "bucket_hash" in data:
            sections.append(("Bucket hash", data["bucket_hash"], "🟦"))
        if "key_hash" in data:
            sections.append(("Key hash (H&D)", data["key_hash"], "🟪"))
        sections.append(("Range+Len check", data["range_check"] + data["length_check"], "⬜"))
        sections.append(("Key comparison", data["comparison"], "🟧"))
        sections.append(("Value lookup", data["value_lookup"], "🟩"))
        sections.append(("Loop overhead", data["loop_overhead"], "⬛"))

        for label, count, emoji in sections:
            pct = count / total * 100
            w = int(count / total * BAR_WIDTH)
            print(f"  {emoji} {label:<20s} {count:3d} insn ({pct:4.1f}%) {'█' * w}")

    print("\n" + "=" * 80)
    print("KEY INSIGHT: comparison dominates for long keys (Headers 50: 52%, Headers: 49%, MIME: 46%)")
    print("Short keys (Protocols, Tickers) are bounded by loop overhead.")
    print("Letters a-z use the direct char-index fast path (~12 insn total).")
    print("=" * 80)

if __name__ == "__main__":
    print_breakdown()
