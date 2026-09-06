#pragma once

#include <algorithm>
#include <cassert>
#include <cstddef>
#include <cstdint>
#include <random>
#include <string_view>
#include <vector>

namespace benchx {

inline std::vector<std::string_view> build_input(
    const std::vector<std::string_view>& pool, std::size_t count, std::uint64_t seed) {
    assert(count == 0 || !pool.empty());
    std::mt19937_64 gen(seed);
    std::vector<std::string_view> result;
    result.reserve(count);
    for (std::size_t i = 0; i < count; ++i) result.push_back(pool[gen() % pool.size()]);
    return result;
}

// Choose the workload class before sampling a key: concatenating the pools
// weights hits by their number of distinct keys instead of the requested 50%.
inline std::vector<std::string_view> build_mixed_input(
    const std::vector<std::string_view>& hits, const std::vector<std::string_view>& misses,
    std::size_t count, std::uint64_t seed) {
    assert(count == 0 || (!hits.empty() && !misses.empty()));
    std::mt19937_64 gen(seed);
    std::vector<std::string_view> result;
    result.reserve(count);
    for (std::size_t i = 0; i < count; ++i) {
        const auto& pool = i % 2 == 0 ? hits : misses;
        result.push_back(pool[gen() % pool.size()]);
    }
    std::shuffle(result.begin(), result.end(), gen);
    return result;
}

} // namespace benchx
