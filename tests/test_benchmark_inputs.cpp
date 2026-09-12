#include <doctest/doctest.h>

#include <algorithm>
#include "../benchmarks/bench_input.h"

TEST_CASE("Mixed benchmark inputs sample the concatenated key pools") {
    const std::vector<std::string_view> hits{"hit"};
    const std::vector<std::string_view> misses{"miss1", "miss2", "miss3", "miss4"};
    for (const std::size_t count : {0, 1, 2, 99, 1000}) {
        const auto input = benchx::build_mixed_input(hits, misses, count, 42);
        CHECK(input.size() == count);
        CHECK(input == benchx::build_mixed_input(hits, misses, count, 42));
        // Same stream the original harness produced: uniform over hits ++ misses.
        std::vector<std::string_view> pool(hits);
        pool.insert(pool.end(), misses.begin(), misses.end());
        CHECK(input == benchx::build_input(pool, count, 42));
        for (auto key : input) {
            CHECK((key == "hit" || std::find(misses.begin(), misses.end(), key) != misses.end()));
        }
    }
    // The hit ratio follows the pool sizes (1 of 5 here), not a forced 50 %.
    const auto big = benchx::build_mixed_input(hits, misses, 100000, 42);
    const auto hit_count = std::count(big.begin(), big.end(), "hit");
    CHECK(hit_count > 18000);
    CHECK(hit_count < 22000);
    CHECK(benchx::build_mixed_input({}, {}, 0, 42).empty());
    CHECK(benchx::build_input({}, 0, 42).empty());
}
