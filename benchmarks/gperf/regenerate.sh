#!/bin/sh
# Regenerate the gperf baselines from their .gperf inputs:
#
#   benchmarks/gperf/regenerate.sh [path/to/gperf]
#
# Each input carries its own options. All of them are maps (%struct-type with
# an int value), like the other benchmark methods. The comparison is per set:
# %compare-lengths on the long-key sets, where it is faster, and
# %compare-strncmp on the short-key sets, where it is. Two other options were
# measured and left out (issue #29): %switch=1 was slower on every set, and
# -m 10000 made no consistent difference.
#
# The checked-in files come from GNU gperf 3.3. Apple's /usr/bin/gperf is
# 3.0.3, which emits `register` (removed in C++17).
set -eu
GPERF=${1:-gperf}
here=$(cd "$(dirname "$0")" && pwd)

gen() {  # gen <dir> <name>
  (cd "$1" && "$GPERF" "$2.gperf" > "$2_gperf.inc")
  echo "  $1/$2_gperf.inc"
}

"$GPERF" --version | head -n 1
for f in "$here"/*.gperf; do
  gen "$here" "$(basename "$f" .gperf)"
done
# Ticker sets: inputs written by ../data/gen_symbol_headers.py.
for name in sp500 nasdaq; do
  gen "$here/../data" "$name"
done
