/**
 * Reference:
 * Daniel Lemire, "Quickly checking that a string belongs to a small set," in
 * Daniel Lemire's blog, December 30, 2022,
 * https://lemire.me/blog/2022/12/30/quickly-checking-that-a-string-belongs-to-a-small-set/.
 */

#include <algorithm>
#include <chrono>
#include <cstdint>
#include <format>
#include <iostream>
#include <map>
#include <print>
#include <random>
#include <string>
#include <unordered_map>
#include <vector>
#include "ConstexprCore/perfect_hash.h"

#include "counters/bench.h"


template <class Function1, class Function2>
counters::event_aggregate shuffle_bench(Function1 &&function1, Function2 &&function2, size_t min_repeat = 300,
                      size_t min_time_ns = 400'000'000,
                      size_t max_repeat = 1000000,
                      size_t min_time_per_inner_ns = 30000) {
  static thread_local counters::event_collector collector;
  auto fn = std::forward<Function1>(function1);
  auto fn2 = std::forward<Function2>(function2);
  size_t N = min_repeat;
  // Measurement
  counters::event_aggregate aggregate{};
  for (size_t i = 0; i < N; i++) {
    collector.start();
    fn();
    counters::event_count allocate_count = collector.end();
    aggregate << allocate_count;
    fn2();
  }
  return aggregate;
}

enum class SchemeType : uint8_t {
  HTTP = 0,        /**< http:// scheme (port 80) */
  NOT_SPECIAL = 1, /**< Non-special scheme (no default port) */
  HTTPS = 2,       /**< https:// scheme (port 443) */
  WS = 3,          /**< ws:// WebSocket scheme (port 80) */
  FTP = 4,         /**< ftp:// scheme (port 21) */
  WSS = 5,         /**< wss:// secure WebSocket scheme (port 443) */
  FILE = 6         /**< file:// scheme (no default port) */
};

namespace details {
constexpr std::string_view is_special_list[] = {"http", " ",   "https", "ws",
                                                "ftp",  "wss", "file",  " "};
}

SchemeType get_scheme_type(std::string_view scheme) noexcept {
  if (scheme.empty()) {
    return SchemeType::NOT_SPECIAL;
  }
  int hash_value = (2 * scheme.size() + (unsigned)(scheme[0])) & 7;
  const std::string_view target = details::is_special_list[hash_value];
  if ((target[0] == scheme[0]) && (target.substr(1) == scheme.substr(1))) {
    return static_cast<SchemeType>(hash_value);
  } else {
    return SchemeType::NOT_SPECIAL;
  }
}

bool hash_is_special(std::string_view input) {
  return get_scheme_type(input) != SchemeType::NOT_SPECIAL;
}

enum class Method { GET, POST, PUT, DELETE, PATCH, HEAD, OPTIONS };

double pretty_print(const std::string &name, size_t num_values,
                    counters::event_aggregate agg) {
  std::print("{:<50} : ", name);
  std::print(" {:5.3f} ns ", agg.fastest_elapsed_ns() / double(num_values));
  std::print(" {:5.2f} Gv/s ", double(num_values) / agg.fastest_elapsed_ns());
  if (counters::has_performance_counters()) {
    std::print(" {:5.2f} GHz ", agg.cycles() / double(agg.elapsed_ns()));
    std::print(" {:5.2f} c ", agg.fastest_cycles() / double(num_values));
    std::print(" {:5.2f} i ", agg.fastest_instructions() / double(num_values));
    std::print(" {:5.2f} i/c ",
               agg.fastest_instructions() / double(agg.fastest_cycles()));
    std::print(" {:5.2f} bm ", agg.fastest_branch_misses() / double(num_values));
  }
  std::print("\n");
  return double(num_values) / agg.fastest_elapsed_ns();
}

std::vector<std::string_view> populate(size_t length) {
  std::mt19937_64 gen(std::random_device{}());
  // we generate a distribution where http is more common
  std::discrete_distribution<> d({20, 10, 10, 5, 5, 5});
  const static std::string_view options[] = {
      "http", "https", "ftp", "ws", "wss", "file"};
  std::vector<std::string_view> answer;
  answer.reserve(length);
  for (size_t pos = 0; pos < length; pos++) {
    std::string_view picked{options[d(gen)]};
    answer.emplace_back(picked);
  }
  return answer;
}

bool fancy_is_set(std::string_view input) {
  static constexpr auto proto_match =
      ConstexprCore::make_constexpr_perfect_set<"http", "https", "ftp", "ws", "wss",
                                      "file">();
  return proto_match.contains(input);
}

std::optional<SchemeType> fancy_get_scheme_type(std::string_view input) {
  static constexpr auto proto_match =
      ConstexprCore::make_constexpr_perfect_map<
          ConstexprCore::kv<"http", SchemeType::HTTP>,
          ConstexprCore::kv<"https", SchemeType::HTTPS>,
          ConstexprCore::kv<"ftp", SchemeType::FTP>,
          ConstexprCore::kv<"ws", SchemeType::WS>,
          ConstexprCore::kv<"wss", SchemeType::WSS>,
          ConstexprCore::kv<"file", SchemeType::FILE>>();
  return proto_match.lookup(input);
}


std::optional<SchemeType> get_scheme_type_naive(std::string_view input) {
  if (input == "http") return SchemeType::HTTP;
  else if (input == "https") return SchemeType::HTTPS;
  else if (input == "ftp") return SchemeType::FTP;
  else if (input == "ws") return SchemeType::WS;
  else if (input == "wss") return SchemeType::WSS;
  else if (input == "file") return SchemeType::FILE;
  else return std::nullopt;
}

void collect_benchmark_results(size_t number_strings) {
  std::vector<std::string_view> strings = populate(number_strings);
  std::vector<SchemeType> expected_types(strings.size());
  constexpr auto methods = ConstexprCore::make_constexpr_perfect_map<
      ConstexprCore::kv<"http", SchemeType::HTTP>,
      ConstexprCore::kv<"https", SchemeType::HTTPS>,
      ConstexprCore::kv<"ftp", SchemeType::FTP>,
      ConstexprCore::kv<"ws", SchemeType::WS>,
      ConstexprCore::kv<"wss", SchemeType::WSS>,
      ConstexprCore::kv<"file", SchemeType::FILE>
  >();
  static constexpr auto runtime_map = ConstexprCore::make_perfect_map<
      ConstexprCore::kv<"http", SchemeType::HTTP>,
      ConstexprCore::kv<"https", SchemeType::HTTPS>,
      ConstexprCore::kv<"ftp", SchemeType::FTP>,
      ConstexprCore::kv<"ws", SchemeType::WS>,
      ConstexprCore::kv<"wss", SchemeType::WSS>,
      ConstexprCore::kv<"file", SchemeType::FILE>
  >();

  for (const auto &str : strings) {
    bool is_special = (str == "http" || str == "https" || str == "ftp" ||
                       str == "ws" || str == "wss" || str == "file");
    bool is_special_phf = methods.lookup(str).has_value();
    if (is_special != is_special_phf) {
      std::cerr << "Perfect hash function is incorrect for input: '" << str
                << "'\n";
      std::cerr << "Expected: " << is_special << ", Got: " << is_special_phf
                << "\n";
      std::exit(1);
    }
    auto naive_result = get_scheme_type_naive(str);
    auto phf_result = methods.lookup(str);
    if (naive_result != phf_result) {
      std::cerr << "Mismatch between naive and PHF for input: '" << str << "'\n";
      std::exit(1);
    }
    auto runtime_result = runtime_map.lookup(str);
    if (naive_result != runtime_result) {
      std::cerr << "Mismatch between naive and runtime_map for input: '" << str << "'\n";
      std::exit(1);
    }
  }

  static const std::map<std::string_view, SchemeType> std_map = {
      {"http", SchemeType::HTTP},
      {"https", SchemeType::HTTPS},
      {"ftp", SchemeType::FTP},
      {"ws", SchemeType::WS},
      {"wss", SchemeType::WSS},
      {"file", SchemeType::FILE}
  };

  static const std::unordered_map<std::string_view, SchemeType> unordered_map = {
      {"http", SchemeType::HTTP},
      {"https", SchemeType::HTTPS},
      {"ftp", SchemeType::FTP},
      {"ws", SchemeType::WS},
      {"wss", SchemeType::WSS},
      {"file", SchemeType::FILE}
  };
  std::mt19937_64 gen(42); // fixed seed for reproducibility

  auto shuffle = [&strings, &gen]() {
    std::shuffle(strings.begin(), strings.end(), gen);
  };


  auto count_naive = [&strings, &expected_types]() {
    for(size_t i = 0; i < strings.size(); i++) {
      auto opt = get_scheme_type_naive(strings[i]);
      if (opt) {
        expected_types[i] = *opt;
      }
    }
  };
  pretty_print("naive", number_strings, shuffle_bench(count_naive, shuffle));
  gen.seed(42); // reset seed to ensure same shuffle for all benchmarks

  auto count_ours = [&strings, &expected_types, &methods]() {
    for (size_t i = 0; i < strings.size(); i++) {
      auto opt = fancy_get_scheme_type(strings[i]);
      if (opt) {        
        expected_types[i] = *opt;
      }
    }
  };
  pretty_print("constexpr_perfect_map", number_strings, shuffle_bench(count_ours, shuffle));
  gen.seed(42); // reset seed to ensure same shuffle for all benchmarks

  auto count_runtime_map = [&strings, &expected_types]() {
    for (size_t i = 0; i < strings.size(); i++) {
      if (auto opt = runtime_map.lookup(strings[i]); opt) {
        expected_types[i] = *opt;
      }
    }
  };
  pretty_print("perfect_hash_map", number_strings, shuffle_bench(count_runtime_map, shuffle));
  gen.seed(42); // reset seed to ensure same shuffle for all benchmarks
  auto count_classic = [&strings, &expected_types]() {
    for (size_t i = 0; i < strings.size(); i++) {
      auto type = get_scheme_type(strings[i]);
      if (type != SchemeType::NOT_SPECIAL) {
        expected_types[i] = type;
      }
    }
  };

  pretty_print("hand-tuned hash", number_strings, shuffle_bench(count_classic, shuffle));
  gen.seed(42); // reset seed to ensure same shuffle for all benchmarks

  auto count_std_map = [&strings, &expected_types]() {
    for (size_t i = 0; i < strings.size(); i++) {
      auto it = std_map.find(strings[i]);
      if (it != std_map.end()) {
        expected_types[i] = it->second;
      }
    }
  };
  pretty_print("std::map", number_strings, shuffle_bench(count_std_map, shuffle));
  gen.seed(42); // reset seed to ensure same shuffle for all benchmarks

  auto count_unordered_map = [&strings, &expected_types]() {
    for (size_t i = 0; i < strings.size(); i++) {
      auto it = unordered_map.find(strings[i]);
      if (it != unordered_map.end()) {
        expected_types[i] = it->second;
      }
    }
  };
  pretty_print("std::unordered_map", number_strings, shuffle_bench(count_unordered_map, shuffle));
  gen.seed(42); // reset seed to ensure same shuffle for all benchmarks

}

int main(int argc, char **argv) { 
  if (!counters::has_performance_counters()) {
    std::print("Performance counters not available, you may need to run with sudo.\n");
  }
  collect_benchmark_results(200000); 
  return EXIT_SUCCESS;
}
