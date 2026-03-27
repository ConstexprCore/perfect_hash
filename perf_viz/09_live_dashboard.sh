#!/bin/bash
# Live performance dashboard: runs a single key set repeatedly,
# showing real-time ns, IPC, BM with ANSI colors.
#
# Usage: sudo ./perf_viz/09_live_dashboard.sh [keyset] [method]
# Example: sudo ./perf_viz/09_live_dashboard.sh stock make_perfect_map

KEYSET="${1:-protocol}"
METHOD="${2:-make_perfect_map}"
BENCH="./build/benchmarks/bench_protocol"

if [ ! -f "$BENCH" ]; then
    echo "Error: $BENCH not found."
    exit 1
fi

# ANSI colors
GREEN='\033[0;32m'
RED='\033[0;31m'
YELLOW='\033[0;33m'
BLUE='\033[0;34m'
BOLD='\033[1m'
NC='\033[0m'

clear
echo -e "${BOLD}PHF Live Dashboard${NC} — ${KEYSET} / ${METHOD}"
echo -e "Press Ctrl+C to stop\n"
echo -e "${BOLD}$(printf '%-8s %-8s %-8s %-8s %-8s %-8s' 'Run' 'ns' 'Gv/s' 'IPC' 'BM' 'insn')${NC}"
echo "────────────────────────────────────────────────"

RUN=0
while true; do
    RUN=$((RUN + 1))
    OUTPUT=$($BENCH --filter hits,$METHOD,$KEYSET 2>&1 | grep "$METHOD")

    # Parse the output line
    NS=$(echo "$OUTPUT" | grep -oP '[\d.]+(?= ns)' | head -1)
    GVS=$(echo "$OUTPUT" | grep -oP '[\d.]+(?= Gv/s)' | head -1)
    IPC=$(echo "$OUTPUT" | awk '{for(i=1;i<=NF;i++) if($i=="i/c") print $(i-1)}' | head -1)
    BM=$(echo "$OUTPUT" | awk '{for(i=1;i<=NF;i++) if($i=="bm") print $(i-1)}' | head -1)
    INSN=$(echo "$OUTPUT" | awk '{for(i=1;i<=NF;i++) if($i=="i") print $(i-1)}' | head -1)

    # Color coding
    if [ -n "$NS" ]; then
        NS_COLOR=$GREEN
        [ "$(echo "$NS > 5" | bc 2>/dev/null)" = "1" ] && NS_COLOR=$YELLOW
        [ "$(echo "$NS > 10" | bc 2>/dev/null)" = "1" ] && NS_COLOR=$RED

        BM_COLOR=$GREEN
        [ -n "$BM" ] && [ "$(echo "$BM > 0.1" | bc 2>/dev/null)" = "1" ] && BM_COLOR=$YELLOW
        [ -n "$BM" ] && [ "$(echo "$BM > 0.5" | bc 2>/dev/null)" = "1" ] && BM_COLOR=$RED

        printf "${BLUE}%-8d${NC} ${NS_COLOR}%-8s${NC} %-8s %-8s ${BM_COLOR}%-8s${NC} %-8s\n" \
            "$RUN" "${NS:-N/A}" "${GVS:-N/A}" "${IPC:-N/A}" "${BM:-N/A}" "${INSN:-N/A}"
    else
        echo "  (no perf counters — run with sudo)"
        break
    fi
done
