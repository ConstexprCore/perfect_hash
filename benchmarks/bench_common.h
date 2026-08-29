// Shared benchmark harness (shuffled lookups, fastest-of-N, perf counters via
// lemire/counters). Extracted for bench_tickers.cpp; bench_protocol.cpp keeps
// its own inline copy of the same loop.
#pragma once

#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <numeric>
#include <print>
#include <random>
#include <set>
#include <string>
#include <string_view>
#include <vector>

#include "counters/bench.h"

namespace benchx {

template <class Function1, class Function2>
counters::event_aggregate shuffle_bench(Function1 &&function1, Function2 &&function2,
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

inline void pretty_print(const std::string &name, size_t num_values, counters::event_aggregate agg) {
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

inline std::vector<std::string_view> build_input(const std::vector<std::string_view> &pool,
                                                 size_t count, uint64_t seed) {
  std::mt19937_64 gen(seed);
  std::vector<std::string_view> result;
  result.reserve(count);
  for (size_t i = 0; i < count; i++) result.push_back(pool[gen() % pool.size()]);
  return result;
}

// Generic filter: any token not in a category means "run all" for it.
struct Filter {
  std::set<std::string> workloads, methods, keysets;
  bool on(const std::set<std::string> &s, const std::string &k) const { return s.empty() || s.count(k); }
  bool workload(const std::string &k) const { return on(workloads, k); }
  bool method(const std::string &k) const { return on(methods, k); }
  bool keyset(const std::string &k) const { return on(keysets, k); }
};

inline Filter parse_filter(const std::string &arg, const std::set<std::string> &valid_workloads,
                           const std::set<std::string> &valid_methods,
                           const std::set<std::string> &valid_keysets) {
  Filter f;
  size_t start = 0;
  while (start < arg.size()) {
    size_t end = arg.find(',', start);
    if (end == std::string::npos) end = arg.size();
    std::string token = arg.substr(start, end - start);
    if (valid_workloads.count(token)) f.workloads.insert(token);
    else if (valid_methods.count(token)) f.methods.insert(token);
    else if (valid_keysets.count(token)) f.keysets.insert(token);
    else std::println(stderr, "Warning: unknown filter token '{}'", token);
    start = end + 1;
  }
  return f;
}

// Run one method: `lookup(sv) -> std::optional<int>`-like callable over a
// shuffled input, fastest of `repeat`, then print.
template <typename Lookup>
void run_method(const std::string &label, std::vector<std::string_view> &input, Lookup &&lookup,
                size_t repeat = 300) {
  std::vector<int> results(input.size(), 0);
  std::mt19937_64 gen(42);
  auto shuffle = [&]() { std::shuffle(input.begin(), input.end(), gen); };
  auto body = [&]() {
    for (size_t i = 0; i < input.size(); i++) {
      auto r = lookup(input[i]);
      if (r) results[i] = static_cast<int>(*r);
    }
  };
  pretty_print(label, input.size(), shuffle_bench(body, shuffle, repeat));
  volatile auto sum = std::accumulate(results.begin(), results.end(), 0);
  (void)sum;
}

} // namespace benchx
