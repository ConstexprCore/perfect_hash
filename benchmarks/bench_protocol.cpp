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
  std::mt19937 gen;
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

SchemeType fancy_get_scheme_type(std::string_view input) {
  static constexpr auto proto_match =
      ConstexprCore::make_constexpr_perfect_map<
          ConstexprCore::kv<"http", SchemeType::HTTP>,
          ConstexprCore::kv<"https", SchemeType::HTTPS>,
          ConstexprCore::kv<"ftp", SchemeType::FTP>,
          ConstexprCore::kv<"ws", SchemeType::WS>,
          ConstexprCore::kv<"wss", SchemeType::WSS>,
          ConstexprCore::kv<"file", SchemeType::FILE>>();
  auto result = proto_match.lookup(input);
  return result.value_or(SchemeType::NOT_SPECIAL);
}

void collect_benchmark_results(size_t number_strings) {
  std::vector<std::string_view> strings = populate(number_strings);
  constexpr auto methods = ConstexprCore::make_constexpr_perfect_map<
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

  static constexpr std::array<std::string_view, 6> keys = {"http", "https", "ftp", "ws", "wss", "file"};
  static constexpr std::array<SchemeType, 6> values = {SchemeType::HTTP, SchemeType::HTTPS, SchemeType::FTP, SchemeType::WS, SchemeType::WSS, SchemeType::FILE};
  static constexpr auto runtime_map = ConstexprCore::perfect_hash_map<6, SchemeType, 8, 5>{keys, values};

  // This is the user-facing API — no explicit template params needed
  static constexpr auto auto_map = ConstexprCore::make_perfect_map<
      ConstexprCore::kv<"http", SchemeType::HTTP>,
      ConstexprCore::kv<"https", SchemeType::HTTPS>,
      ConstexprCore::kv<"ftp", SchemeType::FTP>,
      ConstexprCore::kv<"ws", SchemeType::WS>,
      ConstexprCore::kv<"wss", SchemeType::WSS>,
      ConstexprCore::kv<"file", SchemeType::FILE>>();

  volatile uint64_t counter = 0;

  auto count_auto_map = [&strings, &counter]() {
    size_t c = 0;
    for (const auto &str : strings) {
      if (auto opt = auto_map.lookup(str); opt) {
        c += static_cast<int>(*opt);
      }
    }
    counter += c;
  };
  pretty_print("make_perfect_map", number_strings, counters::bench(count_auto_map));

  auto count_ours = [&strings, &counter, &methods]() {
    size_t c = 0;

    for (const auto &str : strings) {
      if (auto opt = methods.lookup(str); opt) {
        c += static_cast<int>(*opt);
      }
    }
    counter += c;
  };
  pretty_print("constexpr_perfect_map", number_strings, counters::bench(count_ours));

  auto count_runtime_map = [&strings, &counter]() {
    size_t c = 0;
    for (const auto &str : strings) {
      if (auto opt = runtime_map.lookup(str); opt) {
        c += static_cast<int>(*opt);
      }
    }
    counter += c;
  };
  pretty_print("perfect_hash_map", number_strings, counters::bench(count_runtime_map));
  auto count_classic = [&strings, &counter]() {
    size_t c = 0;
    for (const auto &str : strings) {
      auto type = get_scheme_type(str);
      if (type != SchemeType::NOT_SPECIAL) {
        c += static_cast<int>(type);
      }
    }
    counter += c;
  };

  pretty_print("hand-tuned hash", number_strings, counters::bench(count_classic));

  auto count_std_map = [&strings, &counter]() {
    size_t c = 0;
    for (const auto &str : strings) {
      auto it = std_map.find(str);
      if (it != std_map.end()) {
        c += static_cast<int>(it->second);
      }
    }
    counter += c;
  };
  pretty_print("std::map", number_strings, counters::bench(count_std_map));

  auto count_unordered_map = [&strings, &counter]() {
    size_t c = 0;
    for (const auto &str : strings) {
      auto it = unordered_map.find(str);
      if (it != unordered_map.end()) {
        c += static_cast<int>(it->second);
      }
    }
    counter += c;
  };
  pretty_print("std::unordered_map", number_strings, counters::bench(count_unordered_map));


  auto count_naive = [&strings, &counter]() {
    size_t c = 0;
    for (const auto &str : strings) {
      if (str == "http") c += static_cast<int>(SchemeType::HTTP);
      else if (str == "https") c += static_cast<int>(SchemeType::HTTPS);
      else if (str == "ftp") c += static_cast<int>(SchemeType::FTP);
      else if (str == "ws") c += static_cast<int>(SchemeType::WS);
      else if (str == "wss") c += static_cast<int>(SchemeType::WSS);
      else if (str == "file") c += static_cast<int>(SchemeType::FILE);
    }
    counter += c;
  };
  pretty_print("naive", number_strings, counters::bench(count_naive));

  // === Shuffled order ===
  // Each invocation shuffles before iterating, so the branch predictor
  // can't memorize the sequence across calls.  This is closer to
  // real-world workloads where lookup order is not repeatable.
  std::println("\n=== Shuffled order (defeats branch predictor) ===");

  std::mt19937 rng0(42);
  auto count_auto_map_shuf = [&strings, &counter, &rng0]() {
    std::shuffle(strings.begin(), strings.end(), rng0);
    size_t c = 0;
    for (const auto &str : strings) {
      if (auto opt = auto_map.lookup(str); opt) {
        c += static_cast<int>(*opt);
      }
    }
    counter += c;
  };
  pretty_print("make_perfect_map (shuffled)", number_strings,
               counters::bench(count_auto_map_shuf));

  std::mt19937 rng1(42);
  auto count_ours_shuf = [&strings, &counter, &methods, &rng1]() {
    std::shuffle(strings.begin(), strings.end(), rng1);
    size_t c = 0;
    for (const auto &str : strings) {
      if (auto opt = methods.lookup(str); opt) {
        c += static_cast<int>(*opt);
      }
    }
    counter += c;
  };
  pretty_print("constexpr_perfect_map (shuffled)", number_strings,
               counters::bench(count_ours_shuf));

  std::mt19937 rng2(42);
  auto count_runtime_map_shuf = [&strings, &counter, &rng2]() {
    std::shuffle(strings.begin(), strings.end(), rng2);
    size_t c = 0;
    for (const auto &str : strings) {
      if (auto opt = runtime_map.lookup(str); opt) {
        c += static_cast<int>(*opt);
      }
    }
    counter += c;
  };
  pretty_print("perfect_hash_map (shuffled)", number_strings,
               counters::bench(count_runtime_map_shuf));

  std::mt19937 rng3(42);
  auto count_classic_shuf = [&strings, &counter, &rng3]() {
    std::shuffle(strings.begin(), strings.end(), rng3);
    size_t c = 0;
    for (const auto &str : strings) {
      auto type = get_scheme_type(str);
      if (type != SchemeType::NOT_SPECIAL) {
        c += static_cast<int>(type);
      }
    }
    counter += c;
  };
  pretty_print("hand-tuned hash (shuffled)", number_strings,
               counters::bench(count_classic_shuf));

  std::mt19937 rng4(42);
  auto count_std_map_shuf = [&strings, &counter, &rng4]() {
    std::shuffle(strings.begin(), strings.end(), rng4);
    size_t c = 0;
    for (const auto &str : strings) {
      auto it = std_map.find(str);
      if (it != std_map.end()) {
        c += static_cast<int>(it->second);
      }
    }
    counter += c;
  };
  pretty_print("std::map (shuffled)", number_strings,
               counters::bench(count_std_map_shuf));

  std::mt19937 rng5(42);
  auto count_unordered_map_shuf = [&strings, &counter, &rng5]() {
    std::shuffle(strings.begin(), strings.end(), rng5);
    size_t c = 0;
    for (const auto &str : strings) {
      auto it = unordered_map.find(str);
      if (it != unordered_map.end()) {
        c += static_cast<int>(it->second);
      }
    }
    counter += c;
  };
  pretty_print("std::unordered_map (shuffled)", number_strings,
               counters::bench(count_unordered_map_shuf));

  std::mt19937 rng6(42);
  auto count_naive_shuf = [&strings, &counter, &rng6]() {
    std::shuffle(strings.begin(), strings.end(), rng6);
    size_t c = 0;
    for (const auto &str : strings) {
      if (str == "http") c += static_cast<int>(SchemeType::HTTP);
      else if (str == "https") c += static_cast<int>(SchemeType::HTTPS);
      else if (str == "ftp") c += static_cast<int>(SchemeType::FTP);
      else if (str == "ws") c += static_cast<int>(SchemeType::WS);
      else if (str == "wss") c += static_cast<int>(SchemeType::WSS);
      else if (str == "file") c += static_cast<int>(SchemeType::FILE);
    }
    counter += c;
  };
  pretty_print("naive (shuffled)", number_strings,
               counters::bench(count_naive_shuf));
}

int main(int argc, char **argv) { collect_benchmark_results(20000); }
