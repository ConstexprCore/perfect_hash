#!/bin/bash
# Generate flame graphs for PHF benchmark.
#
# On Linux: uses perf record + flamegraph.pl
# On macOS: uses sample(1) + stackcollapse
#
# Requires: FlameGraph tools (https://github.com/brendangregg/FlameGraph)
#   git clone https://github.com/brendangregg/FlameGraph /tmp/FlameGraph

set -e

BENCH="./build/benchmarks/bench_protocol"
FG_DIR="${FLAMEGRAPH_DIR:-/tmp/FlameGraph}"

if [ ! -f "$BENCH" ]; then
    echo "Error: $BENCH not found."
    exit 1
fi

if [ ! -d "$FG_DIR" ]; then
    echo "Cloning FlameGraph tools..."
    git clone --depth 1 https://github.com/brendangregg/FlameGraph "$FG_DIR"
fi

OS=$(uname)
OUTPUT="perf_viz/flamegraph.svg"

if [ "$OS" = "Linux" ]; then
    echo "Recording with perf (Linux)..."
    sudo perf record -g -F 99 -- "$BENCH" --filter hits,make_perfect_map,stock
    sudo perf script | "$FG_DIR/stackcollapse-perf.pl" | "$FG_DIR/flamegraph.pl" > "$OUTPUT"
    sudo rm -f perf.data
elif [ "$OS" = "Darwin" ]; then
    echo "Recording with sample (macOS)..."
    echo "Running benchmark for 5 seconds..."
    "$BENCH" --filter hits,make_perfect_map,stock &
    PID=$!
    sleep 1
    sudo sample "$PID" 3 -f "$OUTPUT.sample" 2>/dev/null || true
    wait "$PID" 2>/dev/null || true

    if [ -f "$OUTPUT.sample" ]; then
        # Convert macOS sample output to flamegraph
        "$FG_DIR/stackcollapse-sample.awk" < "$OUTPUT.sample" | \
            "$FG_DIR/flamegraph.pl" > "$OUTPUT" 2>/dev/null && \
            echo "Saved $OUTPUT" || \
            echo "Note: macOS sample format may need manual conversion."
        rm -f "$OUTPUT.sample"
    else
        echo "Note: macOS sampling requires sudo. Try:"
        echo "  sudo sample <PID> 3"
        echo ""
        echo "Alternative: use Instruments.app with 'Time Profiler' template."
    fi
else
    echo "Unsupported OS: $OS"
    exit 1
fi
