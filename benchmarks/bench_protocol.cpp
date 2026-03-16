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
#include <print>
#include <random>
#include <string>
#include <vector>

#include "ConstexprCore/perfect_hash.h"

#include "counters/bench.h"

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
  }
  std::print("\n");
  return double(num_values) / agg.fastest_elapsed_ns();
}

std::vector<std::string_view> populate(size_t length) {
  std::mt19937 gen;
  // we generate a distribution where https is more common
  std::discrete_distribution<> d({20, 20, 10, 10, 5, 5, 5, 5, 5, 5, 5});
  const static char *options[] = {
      "https\0\0\0",    "http\0\0\0\0",  "ftp\0\0\0\0\0", "file\0\0\0\0",
      "ws\0\0\0\0\0\0", "wss\0\0\0\0\0", "garbage\0",     "fake\0\0\0\0",
      "httpr\0\0\0",    "filer\0\0\0",    "bad\0\0\0\0\0"};
  std::vector<std::string_view> answer;
  answer.reserve(length);
  for (size_t pos = 0; pos < length; pos++) {
    const char *picked{options[d(gen)]};
    answer.emplace_back(std::string_view(picked, strlen(picked)));
  }
  return answer;
}

bool hash_is_special(std::string_view input) {
  static constexpr std::string_view table_hashnocheat_is_special[] = {
      "http", "", "https", "ws", "ftp", "wss", "file", ""};
  if (input.empty()) {
    return false;
  }
  int hash_value = (2 * input.size() + (unsigned)(input[0])) & 7;
  const std::string_view target = table_hashnocheat_is_special[hash_value];
  return (target[0] == input[0]) && (target.substr(1) == input.substr(1));
}

bool fancy_is_set(std::string_view input) {
  static constexpr auto proto_match =
      ConstexprCore::make_constexpr_perfect_set<"http", "https", "ftp", "ws", "wss",
                                      "file">();
  return proto_match.contains(input);
}

void collect_benchmark_results(size_t number_strings) {
  std::vector<std::string_view> strings = populate(number_strings);
  constexpr auto proto_match =
      ConstexprCore::make_constexpr_perfect_set<"http", "https", "ftp", "ws", "wss",
                                      "file">();

  for (const auto &str : strings) {
    bool is_special = (str == "http" || str == "https" || str == "ftp" ||
                       str == "file" || str == "ws" || str == "wss");
    bool is_special_hash = hash_is_special(str);
    if (is_special != is_special_hash) {
      std::cerr << "Hash function is incorrect for input: '" << str << "'\n";
      std::cerr << "Expected: " << is_special << ", Got: " << is_special_hash
                << "\n";
      std::exit(1);
    }
    bool is_special_phf = proto_match.contains(str);
    if (is_special != is_special_phf) {
      std::cerr << "Perfect hash function is incorrect for input: '" << str
                << "'\n";
      std::cerr << "Expected: " << is_special << ", Got: " << is_special_phf
                << "\n";
      std::exit(1);
    }
  }

  volatile uint64_t counter = 0;
  auto count_naive = [&strings, &counter]() {
    size_t c = 0;
    for (const auto &str : strings) {
      c += (str == "http" || str == "https" || str == "ftp" || str == "file" ||
            str == "ws" || str == "wss");
    }
    counter += c;
  };
  pretty_print("naive", number_strings, counters::bench(count_naive));
  auto count_classic = [&strings, &counter]() {
    size_t c = 0;
    for (const auto &str : strings) {
      c += hash_is_special(str);
    }
    counter += c;
  };
  pretty_print("hash", number_strings, counters::bench(count_classic));
  auto count_ours = [&strings, &counter, &proto_match]() {
    size_t c = 0;

    for (const auto &str : strings) {
      c += proto_match.contains(str);
    }
    counter += c;
  };
  pretty_print("perfect_hash", number_strings, counters::bench(count_ours));
}

int main(int argc, char **argv) { collect_benchmark_results(20000); }
