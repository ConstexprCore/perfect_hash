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
import shutil

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

INCLUDE_DIRS = ["-I", "include", "-I", "build/_deps/useful_abstractions-src/include"]
TIMEOUT_SECONDS = 120


def detect_compiler():
    compiler = os.environ.get("CXX") or shutil.which("c++") or "c++"
    try:
        result = subprocess.run(
            [compiler, "--version"],
            capture_output=True,
            text=True,
            timeout=10,
            check=False,
        )
        banner = (result.stdout or result.stderr).lower()
    except OSError:
        return compiler, []

    if "clang" in banner:
        return compiler, ["-fconstexpr-steps=2147483647"]
    if "gcc" in banner or "g++" in banner:
        return compiler, ["-fconstexpr-ops-limit=2147483647"]
    return compiler, []


COMPILER, CONSTEXPR_FLAGS = detect_compiler()

def measure_compile_time(n_keys):
    """Compile a PHF with n_keys and return (status, payload)."""
    keys = TICKERS[:n_keys]
    kvs = ",".join(f'ConstexprCore::kv<"{k}",{i}>' for i, k in enumerate(keys))

    src = f"""
#include <ConstexprCore/perfect_hash.h>
#include <iostream>
static constexpr auto m = ConstexprCore::make_perfect_map<{kvs}>();
int main() {{
    std::cout << m.algorithm_name() << "\\n";
    return static_cast<int>(m.size() == {n_keys} ? 0 : 1);
}}
"""
    with tempfile.NamedTemporaryFile(suffix=".cpp", mode='w', delete=False) as f:
        f.write(src)
        src_path = f.name

    out_path = src_path.replace(".cpp", "")
    try:
        start = time.monotonic()
        cmd = [
            COMPILER,
            "-O0",
            "-std=c++2b",
            "-o",
            out_path,
            src_path,
            *INCLUDE_DIRS,
            *CONSTEXPR_FLAGS,
        ]
        result = subprocess.run(
            cmd,
            capture_output=True,
            text=True,
            timeout=TIMEOUT_SECONDS,
            check=False,
        )
        elapsed = time.monotonic() - start
        if result.returncode != 0:
            message = (result.stderr or result.stdout).strip().splitlines()
            return "error", (message[0] if message else f"compiler exited with {result.returncode}")

        run_result = subprocess.run(
            [out_path],
            capture_output=True,
            text=True,
            timeout=10,
            check=False,
        )
        if run_result.returncode != 0:
            message = (run_result.stderr or run_result.stdout).strip().splitlines()
            return "error", (message[0] if message else f"probe exited with {run_result.returncode}")

        algorithm = run_result.stdout.strip() or "unknown"
        return "ok", {"time": elapsed, "algorithm": algorithm}
    except subprocess.TimeoutExpired:
        return "timeout", None
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
    print(f"Compiler: {COMPILER} {' '.join(CONSTEXPR_FLAGS) if CONSTEXPR_FLAGS else '(no extra constexpr flag)'}")
    print(f"{'N':>5s}  {'Time (s)':>10s}  {'Generator':>10s}  Bar")
    print("-" * 60)

    for n in sizes:
        status, payload = measure_compile_time(n)
        if status == "timeout":
            print(f"{n:5d}  {'TIMEOUT':>10s}")
            results.append((n, None, None))
            continue
        if status == "error":
            print(f"{n:5d}  {'BUILD ERROR':>10s}  {payload}")
            results.append((n, None, None))
            continue

        t = payload["time"]
        gen = payload["algorithm"]
        bar = "█" * int(t * 10)
        print(f"{n:5d}  {t:10.2f}s  {gen:>10s}  {bar}")
        results.append((n, t, gen))

    if HAS_MPL and any(t is not None for _, t, _ in results):
        fig, ax = plt.subplots(figsize=(10, 6))
        ns = [n for n, t, _ in results if t is not None]
        ts = [t for _, t, _ in results if t is not None]
        colors = [
            '#2196F3' if alg == 'gperf' else '#4CAF50' if alg == 'H&D' else '#9E9E9E'
            for _, _, alg in results if alg is not None
        ]

        ax.bar(range(len(ns)), ts, color=colors, edgecolor='black', linewidth=0.5)
        ax.set_xticks(range(len(ns)))
        ax.set_xticklabels([str(n) for n in ns])
        ax.set_xlabel("Number of keys (N)", fontsize=12)
        ax.set_ylabel("Compilation time (seconds)", fontsize=12)
        ax.set_title("Compilation Time vs Key Set Size\n"
                      "Blue = gperf, Green = Hash-and-Displace (detected from generated PHF)", fontsize=13)
        ax.grid(True, axis='y', alpha=0.3)

        plt.tight_layout()
        plt.savefig("perf_viz/05_compile_time_curve.png", dpi=150)
        print("Saved perf_viz/05_compile_time_curve.png")

if __name__ == "__main__":
    main()
