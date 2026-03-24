/**
 * Compile-time perfect hash benchmark suite.
 *
 * Tests PHF lookup across key sets that vary in size and key length.
 * Each set is benchmarked in three workload modes:
 *   - All hits:   every lookup finds a match (primary use case)
 *   - All misses: every lookup fails (negative filter use case)
 *   - Mixed:      50/50 hits and misses
 *
 * Reference:
 * Daniel Lemire, "Quickly checking that a string belongs to a small set,"
 * https://lemire.me/blog/2022/12/30/quickly-checking-that-a-string-belongs-to-a-small-set/
 */

#include <algorithm>
#include <cstdint>
#include <cstring>
#include <iostream>
#include <optional>
#include <print>
#include <random>
#include <string>
#include <unordered_map>
#include <vector>

#include "ConstexprCore/perfect_hash.h"
#include "counters/bench.h"

// ============================================================================
// Infrastructure
// ============================================================================

template <class Function1, class Function2>
counters::event_aggregate shuffle_bench(Function1 &&function1,
                                        Function2 &&function2,
                                        size_t min_repeat = 300) {
  static thread_local counters::event_collector collector;
  auto fn = std::forward<Function1>(function1);
  auto fn2 = std::forward<Function2>(function2);
  counters::event_aggregate aggregate{};
  for (size_t i = 0; i < min_repeat; i++) {
    collector.start();
    fn();
    aggregate << collector.end();
    fn2();
  }
  return aggregate;
}

void pretty_print(const std::string &name, size_t num_values,
                  counters::event_aggregate agg) {
  std::print("  {:<48} : ", name);
  std::print(" {:6.3f} ns ", agg.fastest_elapsed_ns() / double(num_values));
  std::print(" {:5.2f} Gv/s", double(num_values) / agg.fastest_elapsed_ns());
  if (counters::has_performance_counters()) {
    std::print("  {:5.2f} c  {:5.2f} i  {:4.2f} i/c  {:4.2f} bm",
               agg.fastest_cycles() / double(num_values),
               agg.fastest_instructions() / double(num_values),
               agg.fastest_instructions() / double(agg.fastest_cycles()),
               agg.fastest_branch_misses() / double(num_values));
  }
  std::print("\n");
}

// Build a shuffled input vector from a pool of candidate strings.
std::vector<std::string_view> build_input(
    const std::vector<std::string_view> &pool, size_t count, uint64_t seed) {
  std::mt19937_64 gen(seed);
  std::vector<std::string_view> result;
  result.reserve(count);
  for (size_t i = 0; i < count; i++)
    result.push_back(pool[gen() % pool.size()]);
  return result;
}

// Generic benchmark: runs PHF, naive, and unordered_map on a given input vector.
template <typename PHFMap, typename NaiveFn>
void bench_workload(const std::string &label,
                    std::vector<std::string_view> &input,
                    size_t num_strings,
                    const PHFMap &phf_map,
                    NaiveFn naive_fn,
                    const std::unordered_map<std::string_view, int> &uset) {
  std::vector<int> results(num_strings, 0);
  std::mt19937_64 gen(42);
  auto shuffle = [&]() {
    std::shuffle(input.begin(), input.end(), gen);
  };

  // constexpr_perfect_map
  gen.seed(42);
  auto phf_fn = [&]() {
    for (size_t i = 0; i < input.size(); i++) {
      auto opt = phf_map.lookup(input[i]);
      if (opt) results[i] = static_cast<int>(*opt);
    }
  };
  pretty_print(label + " constexpr_perfect_map", num_strings,
               shuffle_bench(phf_fn, shuffle));

  // naive if/else
  gen.seed(42);
  auto naive_bench = [&]() {
    for (size_t i = 0; i < input.size(); i++) {
      auto opt = naive_fn(input[i]);
      if (opt) results[i] = *opt;
    }
  };
  pretty_print(label + " naive", num_strings,
               shuffle_bench(naive_bench, shuffle));

  // std::unordered_map
  gen.seed(42);
  auto uset_fn = [&]() {
    for (size_t i = 0; i < input.size(); i++) {
      auto it = uset.find(input[i]);
      if (it != uset.end()) results[i] = it->second;
    }
  };
  pretty_print(label + " std::unordered_map", num_strings,
               shuffle_bench(uset_fn, shuffle));
}

// Run a full key-set benchmark with all three workload modes.
template <typename PHFMap, typename NaiveFn>
void run_keyset(const std::string &name,
                const PHFMap &phf_map,
                NaiveFn naive_fn,
                const std::vector<std::string_view> &hit_keys,
                const std::vector<std::string_view> &miss_keys,
                size_t num_strings = 200000) {

  // Compute MaxKeyLen for display
  size_t max_len = 0;
  for (auto &k : hit_keys) max_len = std::max(max_len, k.size());

  std::println("\n=== {} (N={}, MaxKeyLen={}) ===", name, hit_keys.size(), max_len);

  // Build unordered_map baseline
  std::unordered_map<std::string_view, int> uset;
  for (size_t i = 0; i < hit_keys.size(); i++)
    uset[hit_keys[i]] = static_cast<int>(i);

  // Build workload vectors
  auto hits   = build_input(hit_keys, num_strings, 42);
  auto misses = build_input(miss_keys, num_strings, 42);

  // Mixed: 50/50 interleaved
  std::vector<std::string_view> mixed_pool;
  mixed_pool.insert(mixed_pool.end(), hit_keys.begin(), hit_keys.end());
  mixed_pool.insert(mixed_pool.end(), miss_keys.begin(), miss_keys.end());
  auto mixed = build_input(mixed_pool, num_strings, 42);

  std::println("  --- all hits ---");
  bench_workload("hits  ", hits, num_strings, phf_map, naive_fn, uset);
  std::println("  --- all misses ---");
  bench_workload("misses", misses, num_strings, phf_map, naive_fn, uset);
  std::println("  --- mixed (50/50) ---");
  bench_workload("mixed ", mixed, num_strings, phf_map, naive_fn, uset);
}

// ============================================================================
// Key set 1: URL Protocols (6 keys, MaxKeyLen=5)
// ============================================================================

static constexpr auto protocol_phf =
    ConstexprCore::make_perfect_map<
        ConstexprCore::kv<"http", 0>,
        ConstexprCore::kv<"https", 1>,
        ConstexprCore::kv<"ftp", 2>,
        ConstexprCore::kv<"ws", 3>,
        ConstexprCore::kv<"wss", 4>,
        ConstexprCore::kv<"file", 5>>();

std::optional<int> protocol_naive(std::string_view s) {
  if (s == "http") return 0;
  if (s == "https") return 1;
  if (s == "ftp") return 2;
  if (s == "ws") return 3;
  if (s == "wss") return 4;
  if (s == "file") return 5;
  return std::nullopt;
}

// Key sets 2-5 (C++ Keywords, HTTP Headers, MIME Types, Stock Tickers)
// are defined below but commented out because the consteval PHF generator
// cannot handle N>10 in reasonable time. See scalability note at bottom.

// Key sets 3-5 removed — consteval PHF generation is too slow for N>10.
// See scalability analysis in main() comment below.

// ============================================================================
// Main
// ============================================================================

int main() {
  if (!counters::has_performance_counters())
    std::println("Performance counters not available, run with sudo.");

  // --- URL Protocols (6 keys, short) ---
  run_keyset("URL Protocols", protocol_phf, protocol_naive,
    {"http","https","ftp","ws","wss","file"},
    {"ssh","telnet","mailto","data","blob","urn"});

  // NOTE: Larger key sets (C++ Keywords N=15, HTTP Headers N=25, MIME N=20,
  // Tickers N=30+) are omitted because the consteval PHF generator takes
  // minutes to hours and >19GB memory for N>10.
  //
  // The consteval interpreter is ~1000x slower than native execution. The
  // gperf-style collision-and-bump solver runs O(N * M * iterations) array
  // operations, each tracked step-by-step by the compiler. For N=15, M=16,
  // this means billions of consteval steps.
  //
  // Fixing this requires either:
  // 1. A fundamentally faster algorithm (CHD/hash-and-displace: O(N) expected)
  // 2. Moving PHF generation to a build-time native tool (like gperf itself)
  // 3. Dramatically reducing the iteration budget and compensating with
  //    larger table sizes (trades space for compile time)
}
