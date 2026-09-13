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

// Mixed workload: sample uniformly from the concatenated pools, exactly as the
// original harness did, so the stream is bit-identical to historical runs and
// the hit ratio is |hits| / (|hits| + |misses|) (S&P 100: 100 hit keys + 20
// miss keys -> ~83 % hits). A forced 50/50 shuffle was tried and rejected in
// the PR #30 review: every method then pays ~0.5 branch misses per lookup on
// the CALLER's hit/miss branch, which drowns the differences being measured.
inline std::vector<std::string_view> build_mixed_input(
    const std::vector<std::string_view>& hits, const std::vector<std::string_view>& misses,
    std::size_t count, std::uint64_t seed) {
    std::vector<std::string_view> pool;
    pool.reserve(hits.size() + misses.size());
    pool.insert(pool.end(), hits.begin(), hits.end());
    pool.insert(pool.end(), misses.begin(), misses.end());
    return build_input(pool, count, seed);
}

} // namespace benchx
