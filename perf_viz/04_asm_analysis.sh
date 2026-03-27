#!/bin/bash
# Generate annotated ARM64 assembly for PHF lookup functions.
# Outputs colored section breakdown for each key set.

set -e

ASM_FILE="/tmp/phf_asm_analysis.s"
SRC_FILE="/tmp/phf_asm_src.cpp"

cat > "$SRC_FILE" << 'EOF'
#include <ConstexprCore/perfect_hash.h>
#include <optional>

// Protocols (gperf, N=6)
static constexpr auto proto = ConstexprCore::make_perfect_map<
    ConstexprCore::kv<"http",0>,ConstexprCore::kv<"https",1>,
    ConstexprCore::kv<"ftp",2>,ConstexprCore::kv<"ws",3>,
    ConstexprCore::kv<"wss",4>,ConstexprCore::kv<"file",5>>();

// MIME (gperf, N=15, long keys)
static constexpr auto mime = ConstexprCore::make_perfect_map<
    ConstexprCore::kv<"text/html",0>,ConstexprCore::kv<"text/plain",1>,
    ConstexprCore::kv<"text/css",2>,ConstexprCore::kv<"application/json",3>,
    ConstexprCore::kv<"application/xml",4>,ConstexprCore::kv<"application/pdf",5>,
    ConstexprCore::kv<"application/zip",6>,ConstexprCore::kv<"image/png",7>,
    ConstexprCore::kv<"image/jpeg",8>,ConstexprCore::kv<"image/gif",9>,
    ConstexprCore::kv<"image/webp",10>,ConstexprCore::kv<"audio/mpeg",11>,
    ConstexprCore::kv<"video/mp4",12>,ConstexprCore::kv<"font/woff2",13>,
    ConstexprCore::kv<"font/woff",14>>();

std::optional<int> proto_lookup(std::string_view k) { return proto.lookup(k); }
std::optional<int> mime_lookup(std::string_view k) { return mime.lookup(k); }
EOF

echo "Compiling ARM64 assembly..."
c++ -O3 -std=c++2b -S -o "$ASM_FILE" "$SRC_FILE" \
    -I include -I build/_deps/useful_abstractions-src/include \
    -fconstexpr-steps=2147483647 -target arm64-apple-macos 2>/dev/null

for FUNC in proto_lookup mime_lookup; do
    MANGLED=$(grep "^__Z.*${FUNC}" "$ASM_FILE" | head -1 | sed 's/:.*//')
    if [ -z "$MANGLED" ]; then continue; fi

    INSN_COUNT=$(awk "/^${MANGLED}/,/^\t\.cfi_endproc/" "$ASM_FILE" | grep -c "^\t[a-z]")
    BRANCH_COUNT=$(awk "/^${MANGLED}/,/^\t\.cfi_endproc/" "$ASM_FILE" | grep -c "^\tb\.")
    LOAD_COUNT=$(awk "/^${MANGLED}/,/^\t\.cfi_endproc/" "$ASM_FILE" | grep -c "^\tldr")

    echo ""
    echo "============================================"
    echo "$FUNC: $INSN_COUNT instructions, $BRANCH_COUNT branches, $LOAD_COUNT loads"
    echo "============================================"
    awk "/^${MANGLED}/,/^\t\.cfi_endproc/" "$ASM_FILE" | \
        grep -v '^\t\.' | grep -v '^\s*;' | grep -v '^\s*$' | grep -v '^Lloh' | \
        cat -n
done

echo ""
echo "Full assembly saved to $ASM_FILE"
