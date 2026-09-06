#include <doctest/doctest.h>
#include "../benchmarks/bench_input.h"

TEST_CASE("Mixed benchmark inputs balance unequal key pools") {
    const std::vector<std::string_view> hits{"hit"};
    const std::vector<std::string_view> misses{"miss1", "miss2", "miss3", "miss4"};
    for (const std::size_t count : {0, 1, 2, 99, 1000}) {
        const auto input = benchx::build_mixed_input(hits, misses, count, 42);
        CHECK(input.size() == count);
        CHECK(std::count(input.begin(), input.end(), "hit") == (count + 1) / 2);
        CHECK(input == benchx::build_mixed_input(hits, misses, count, 42));
        for (auto key : input) {
            CHECK((key == "hit" || std::find(misses.begin(), misses.end(), key) != misses.end()));
        }
    }
    CHECK(benchx::build_mixed_input({}, {}, 0, 42).empty());
    CHECK(benchx::build_input({}, 0, 42).empty());
}
