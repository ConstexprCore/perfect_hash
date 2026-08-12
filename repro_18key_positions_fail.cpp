// Repro: 18 same-length keys that CANNOT be built by the generator.
//
// Construction: length 20, all 'a', key i flips position i to 'b' (i = 0..17).
// Keys i and j differ exactly at positions {i, j}, so any distinguishing
// position set must hit every pair — a vertex cover of K_18 = 17 positions,
// one more than MAX_POSITIONS (16). The length term is useless (all equal),
// LAST_CHAR is useless (positions 18/19 are 'a' everywhere), and H&D cannot
// rescue it either: keys 4..17 are identical at bytes 0-3, the last byte,
// and length -> one 14-key dead class under the fallback's bucket/key-hash.
//
// On main (through 076a1b8) this FAILS after ~2 min of consteval search:
//   error: constexpr variable 'S' must be initialized by a constant expression
//   note: ... throw "Failed to find distinguishing positions for perfect hash"
// (Hash-and-Displace cannot rescue it: keys 4..17 are identical in H&D's
// entire feature view, so it is unreachable AND provably dead.)
//
// On branch francisco/hard-cases this BUILDS via the tier-3 seeded
// whole-key-hash generator: alg=seeded-fullhash, M=32, all lookups verified
// (~114 s compile — one position-search budget burn in the pre-flight,
// then the fallback tiers are fast). See fixing_hard_and_adversarial_cases.md.
//
// The 17-key version of this set (drop any one key) builds via gperf either way.
//
// Build:
//   clang++ -std=c++23 -fconstexpr-steps=1000000000 -arch arm64 \
//     -isysroot "$(xcrun --show-sdk-path)" -I include \
//     -I build-bench/_deps/useful_abstractions-src/include \
//     -c repro_18key_positions_fail.cpp -o /dev/null
#include <ConstexprCore/perfect_hash.h>

static constexpr auto S = ConstexprCore::make_perfect_map<
    ConstexprCore::kv<"baaaaaaaaaaaaaaaaaaa", 0>,
    ConstexprCore::kv<"abaaaaaaaaaaaaaaaaaa", 1>,
    ConstexprCore::kv<"aabaaaaaaaaaaaaaaaaa", 2>,
    ConstexprCore::kv<"aaabaaaaaaaaaaaaaaaa", 3>,
    ConstexprCore::kv<"aaaabaaaaaaaaaaaaaaa", 4>,
    ConstexprCore::kv<"aaaaabaaaaaaaaaaaaaa", 5>,
    ConstexprCore::kv<"aaaaaabaaaaaaaaaaaaa", 6>,
    ConstexprCore::kv<"aaaaaaabaaaaaaaaaaaa", 7>,
    ConstexprCore::kv<"aaaaaaaabaaaaaaaaaaa", 8>,
    ConstexprCore::kv<"aaaaaaaaabaaaaaaaaaa", 9>,
    ConstexprCore::kv<"aaaaaaaaaabaaaaaaaaa", 10>,
    ConstexprCore::kv<"aaaaaaaaaaabaaaaaaaa", 11>,
    ConstexprCore::kv<"aaaaaaaaaaaabaaaaaaa", 12>,
    ConstexprCore::kv<"aaaaaaaaaaaaabaaaaaa", 13>,
    ConstexprCore::kv<"aaaaaaaaaaaaaabaaaaa", 14>,
    ConstexprCore::kv<"aaaaaaaaaaaaaaabaaaa", 15>,
    ConstexprCore::kv<"aaaaaaaaaaaaaaaabaaa", 16>,
    ConstexprCore::kv<"aaaaaaaaaaaaaaaaabaa", 17>>();

int main() { return static_cast<int>(S.table_size()); }
