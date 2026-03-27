#!/usr/bin/env python3
"""
Compilation Time vs N: measures how long the PHF generator takes for
different key set sizes. Shows the O(N^2) cliff for gperf vs O(N) for H&D.
"""
import subprocess
import time
import tempfile
import os
import sys

try:
    import matplotlib.pyplot as plt
    import matplotlib
    matplotlib.use('Agg')
    HAS_MPL = True
except ImportError:
    HAS_MPL = False

# Stock ticker symbols for scalable key sets
TICKERS = [
    "AAPL","ABBV","ABT","ACN","ADBE","AIG","AMD","AMGN","AMT","AMZN",
    "AVGO","AXP","BA","BAC","BK","BKNG","BLK","BMY","C","CAT",
    "CHTR","CL","CMCSA","COF","COP","COST","CRM","CSCO","CVS","CVX",
    "DE","DHR","DIS","DOW","DUK","EMR","EXC","F","FDX","GD",
    "GE","GILD","GM","GOOG","GS","HD","HON","IBM","INTC","INTU",
    "ISRG","JNJ","JPM","KHC","KO","LIN","LLY","LMT","LOW","MA",
    "MCD","MDLZ","MDT","MET","META","MMM","MO","MRK","MS","MSFT",
    "NEE","NFLX","NKE","NVDA","ORCL","PEP","PFE","PG","PM","PYPL",
    "QCOM","RTX","SBUX","SCHW","SO","SPG","T","TGT","TMO","TMUS",
    "TSLA","TXN","UNH","UNP","UPS","USB","V","VZ","WFC","WMT",
]

INCLUDE_DIRS = "-I include -I build/_deps/useful_abstractions-src/include"

def measure_compile_time(n_keys):
    """Compile a PHF with n_keys and return wall-clock seconds."""
    keys = TICKERS[:n_keys]
    kvs = ",".join(f'ConstexprCore::kv<"{k}",{i}>' for i, k in enumerate(keys))

    src = f"""
#include <ConstexprCore/perfect_hash.h>
static constexpr auto m = ConstexprCore::make_perfect_map<{kvs}>();
int main() {{ return m.size(); }}
"""
    with tempfile.NamedTemporaryFile(suffix=".cpp", mode='w', delete=False) as f:
        f.write(src)
        src_path = f.name

    out_path = src_path.replace(".cpp", "")
    try:
        start = time.monotonic()
        result = subprocess.run(
            f"c++ -O0 -std=c++2b -o {out_path} {src_path} {INCLUDE_DIRS} "
            f"-fconstexpr-steps=2147483647 -Wl,-rpath,/usr/lib",
            shell=True, capture_output=True, text=True, timeout=120
        )
        elapsed = time.monotonic() - start
        if result.returncode != 0:
            return None
        return elapsed
    except subprocess.TimeoutExpired:
        return None
    finally:
        os.unlink(src_path)
        if os.path.exists(out_path):
            os.unlink(out_path)

def main():
    sizes = [4, 6, 8, 10, 15, 20, 30, 50, 75, 100]
    results = []

    print("=" * 60)
    print("COMPILATION TIME vs KEY SET SIZE")
    print("=" * 60)
    print(f"{'N':>5s}  {'Time (s)':>10s}  {'Generator':>10s}  Bar")
    print("-" * 60)

    for n in sizes:
        t = measure_compile_time(n)
        if t is None:
            print(f"{n:5d}  {'TIMEOUT':>10s}")
            results.append((n, None))
            continue

        gen = "gperf" if n <= 15 else "H&D"
        bar = "█" * int(t * 10)
        print(f"{n:5d}  {t:10.2f}s  {gen:>10s}  {bar}")
        results.append((n, t))

    print("\nNote: gperf is used for N ≤ 15, Hash-and-Displace for N > 15.")
    print("H&D is O(N) expected, enabling 100 keys in ~2 seconds.")

    if HAS_MPL and any(t for _, t in results if t):
        fig, ax = plt.subplots(figsize=(10, 6))
        ns = [n for n, t in results if t is not None]
        ts = [t for _, t in results if t is not None]
        colors = ['#2196F3' if n <= 15 else '#4CAF50' for n in ns]

        ax.bar(range(len(ns)), ts, color=colors, edgecolor='black', linewidth=0.5)
        ax.set_xticks(range(len(ns)))
        ax.set_xticklabels([str(n) for n in ns])
        ax.set_xlabel("Number of keys (N)", fontsize=12)
        ax.set_ylabel("Compilation time (seconds)", fontsize=12)
        ax.set_title("Compilation Time vs Key Set Size\n"
                      "Blue = gperf (N ≤ 15), Green = Hash-and-Displace (N > 15)", fontsize=13)
        ax.grid(True, axis='y', alpha=0.3)

        plt.tight_layout()
        plt.savefig("perf_viz/05_compile_time_curve.png", dpi=150)
        print("Saved perf_viz/05_compile_time_curve.png")

if __name__ == "__main__":
    main()
