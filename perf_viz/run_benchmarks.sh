#!/bin/bash
# Run all benchmarks and capture structured output as JSON.
# Usage: sudo ./perf_viz/run_benchmarks.sh [output.json]
#
# Requires: bench_protocol built with -DPH_BUILD_BENCHMARKS=ON
# Run with sudo for hardware performance counters on macOS.

set -e

OUTPUT="${1:-perf_viz/benchmark_results.json}"
BENCH="./build/benchmarks/bench_protocol"

if [ ! -f "$BENCH" ]; then
    echo "Error: $BENCH not found. Build with -DPH_BUILD_BENCHMARKS=ON first."
    exit 1
fi

echo "Running benchmarks (this takes ~2 minutes)..."

# Capture raw output
RAW=$($BENCH 2>&1)

# Parse into JSON using Python
python3 -c "
import json, re, sys

raw = '''$RAW'''

results = []
current_keyset = None

for line in raw.strip().split('\n'):
    # Match key set header: === Name (N=X, MaxKeyLen=Y) ===
    m = re.match(r'=== (.+?) \(N=(\d+), MaxKeyLen=(\d+)\) ===', line)
    if m:
        current_keyset = {'name': m.group(1), 'N': int(m.group(2)), 'MaxKeyLen': int(m.group(3))}
        continue

    # Match workload header
    if '--- all hits ---' in line: workload = 'hits'
    elif '--- all misses ---' in line: workload = 'misses'
    elif '--- mixed' in line: workload = 'mixed'
    else: workload = getattr(sys.modules[__name__], '_last_workload', 'hits')

    # Match result line
    m = re.match(r'\s+\S+\s+(.+?)\s+:\s+([\d.]+) ns\s+([\d.]+) Gv/s(?:\s+([\d.]+) c\s+([\d.]+) i\s+([\d.]+) i/c\s+([\d.]+) bm)?', line)
    if m and current_keyset:
        entry = {
            'keyset': current_keyset['name'],
            'N': current_keyset['N'],
            'MaxKeyLen': current_keyset['MaxKeyLen'],
            'workload': workload,
            'method': m.group(1).strip(),
            'ns': float(m.group(2)),
            'gvs': float(m.group(3)),
        }
        if m.group(4):
            entry['cycles'] = float(m.group(4))
            entry['insn'] = float(m.group(5))
            entry['ipc'] = float(m.group(6))
            entry['bm'] = float(m.group(7))
        results.append(entry)
    sys.modules[__name__]._last_workload = workload

with open('$OUTPUT', 'w') as f:
    json.dump(results, f, indent=2)
print(f'Wrote {len(results)} results to $OUTPUT')
"
