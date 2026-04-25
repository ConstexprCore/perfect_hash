#include <cstddef>
#include <reflect/reflect.h>
#include "counters/bench.h"
#include <iostream>
#include <vector>
#include <string_view>
#include <random>
#include <print>
#include "ConstexprCore/perfect_hash.h"

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

struct stats {
    int total_items;          // Total number of items processed
    int successful_operations; // Number of operations that succeeded
    int failed_operations;     // Number of operations that failed
    int warnings;             // Number of warnings encountered
    int errors;               // Number of errors encountered
    int retries;              // Number of retry attempts
    int bytes_processed;      // Total bytes processed
    int records_read;         // Number of records read
    int records_written;      // Number of records written
    int records_validated;    // Number of records that passed validation
};

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

auto getshit(stats &p, std::string_view key) {
    return  ConstexprCore::reflect::reflect_get(p, key);
}

int main() {
    stats p{10, 5, 3, 1, 2, 0, 100, 50, 25, 10};

    std::vector<std::string_view> keys;
    for(int i = 0; i < 1000; ++i) {
        keys.push_back("total_items");
        keys.push_back("successful_operations");
        keys.push_back("failed_operations");
        keys.push_back("warnings");
        keys.push_back("errors");
        keys.push_back("retries");
        keys.push_back("bytes_processed");
        keys.push_back("records_read");
        keys.push_back("records_written");
        keys.push_back("records_validated");
    }
    std::mt19937_64 gen(42);
    auto shuffle = [&]() {
        std::shuffle(keys.begin(), keys.end(), gen);
    };
    auto naive_fn = [&]() {
        for (auto key : keys) {
            if(key == "total_items") p.total_items++;
            else if(key == "successful_operations") p.successful_operations++;
            else if(key == "failed_operations") p.failed_operations++;
            else if(key == "warnings") p.warnings++;
            else if(key == "errors") p.errors++;
            else if(key == "retries") p.retries++;
            else if(key == "bytes_processed") p.bytes_processed++;
            else if(key == "records_read") p.records_read++;
            else if(key == "records_written") p.records_written++;
            else if(key == "records_validated") p.records_validated++;
            else throw std::runtime_error("Unknown key: " + std::string(key));
        }
    };
    pretty_print("naive", keys.size(),
                 shuffle_bench(naive_fn, shuffle));
    auto reflect_fn = [&]() {
        for (auto key : keys) {
            ConstexprCore::reflect::get_attribute<int>(p, key)++;
        }
    };

    pretty_print("get_attribute", keys.size(),
                 shuffle_bench(reflect_fn, shuffle));
    return EXIT_SUCCESS;
}