#include <cstddef>
#include <reflect/reflect.h>
#include "counters/bench.h"
#include <iostream>
#include <vector>
#include <string_view>
#include <random>
#include <print>
#include "counters/bench.h"
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

struct Person {
    std::string name;
    int age;
    double height;
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

int main() {
    Person p{"Alice", 30, 1.75};

    std::vector<std::string_view> keys = {"name", "age", "height"};
    for(int i = 0; i < 1000; ++i) {
        keys.push_back("name");
        keys.push_back("age");
        keys.push_back("height");
    }
    std::mt19937_64 gen(42);
    auto shuffle = [&]() {
        std::shuffle(keys.begin(), keys.end(), gen);
    };
    auto reflect_fn = [&]() {
        for (auto key : keys) {
            try {
                auto val = ConstexprCore::reflect::reflect_get(p, key);
            } catch (const std::exception& e) {
                // Should not happen for valid keys
                std::cerr << "Exception: " << e.what() << std::endl;
            }
        }
    };

    pretty_print("reflect_get Person fields", keys.size(),
                 shuffle_bench(reflect_fn, shuffle));
    static constexpr auto protocol_phf =
    ConstexprCore::make_perfect_map<
        ConstexprCore::kv<"name", 0>,
        ConstexprCore::kv<"age", 1>,
        ConstexprCore::kv<"height", 2>>();
    auto fn = [&]() {
        size_t idx = 0;
        for (auto key : keys) {
            idx += *protocol_phf.lookup(key);
        }
        volatile auto sink = idx; // prevent optimization
    };
    pretty_print("reflect_get Person fields", keys.size(),
                 shuffle_bench(fn, shuffle));
    return 0;
}