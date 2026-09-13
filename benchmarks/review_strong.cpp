// Focused fallback benchmark. Forces Strong=true; does not represent normal
// automatic fast-hash dispatch. Pass the iteration count as argv[1].
#include <ConstexprCore/wide_perfect_hash.h>
#include <chrono>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>

#ifndef PH_STRONG_N
#define PH_STRONG_N 96
#endif
constexpr std::size_t nkeys = PH_STRONG_N;
constexpr std::size_t maxlen = 32;
constexpr auto key_bytes = [] {
    std::array<std::array<char, maxlen>, nkeys> bytes{};
    for (std::size_t i = 0; i < nkeys; ++i) {
        for (std::size_t j = 0; j < maxlen; ++j)
            bytes[i][j] = static_cast<char>('a' + (i * 13 + j * 17) % 26);
        for (std::size_t j = 0; j < 4; ++j)
            bytes[i][maxlen - 4 + j] = "0123456789abcdef"[(i >> (j * 4)) & 15];
    }
    return bytes;
}();
constexpr auto keys = [] {
    std::array<std::string_view, nkeys> out{};
    for (std::size_t i = 0; i < nkeys; ++i) out[i] = {key_bytes[i].data(), maxlen};
    return out;
}();
constexpr auto strong_plan = []() consteval {
    constexpr std::size_t lanes_count = ConstexprCore::detail::wide_lanes_for(maxlen);
    std::array<std::array<std::uint64_t, lanes_count>, nkeys> lanes{};
    for (std::size_t i = 0; i < nkeys; ++i)
        lanes[i] = ConstexprCore::detail::wide_key_lanes<maxlen>(keys[i]);
    ConstexprCore::detail::wide_result<nkeys> plan{};
    if (!ConstexprCore::detail::wide_try_seeds<nkeys, ConstexprCore::detail::next_power_of_2(nkeys) * 2, lanes_count, true>(lanes, 48, plan))
        throw "strong benchmark plan failed";
    return plan;
}();
constexpr auto strong_map = []() consteval {
    std::array<unsigned, nkeys> values{};
    for (std::size_t i = 0; i < nkeys; ++i) values[i] = static_cast<unsigned>(i);
    return ConstexprCore::wide_perfect_hash_map<nkeys, unsigned, strong_plan.table_size, maxlen, true>{keys, values, strong_plan};
}();

int main(int argc, char** argv) {
    const std::size_t rounds = argc > 1 ? std::strtoull(argv[1], nullptr, 10) : 1000000;
    std::vector<std::string> backing;
    backing.reserve(nkeys);
    for (std::size_t i = 0; i < nkeys; ++i) backing.emplace_back(keys[(i * 37) % nkeys]);
    std::vector<std::string_view> probes;
    std::vector<std::array<std::uint64_t, 4>> lanes;
    for (auto& s : backing) {
        probes.emplace_back(s);
        lanes.push_back(ConstexprCore::detail::wide_key_lanes<maxlen>(s));
    }
    unsigned long long sum = 0;
    auto begin = std::chrono::steady_clock::now();
    for (std::size_t round = 0; round < rounds; ++round) {
        for (auto key : probes) {
            asm volatile("" : "+m"(key) : : "memory");
            const auto value = strong_map.lookup_or(key, 99999);
            asm volatile("" : : "r"(value));
            sum += value;
        }
    }
    auto end = std::chrono::steady_clock::now();
    std::printf("strong_map,%g,%llu,seeds=%zu\n", std::chrono::duration<double, std::nano>(end - begin).count() / (rounds * probes.size()), sum, strong_plan.seeds_tried);
    sum = 0;
    begin = std::chrono::steady_clock::now();
    for (std::size_t round = 0; round < rounds; ++round) {
        for (const auto& key : lanes) {
            const auto* ptr = &key;
            asm volatile("" : "+r"(ptr) : : "memory");
            const auto value = ConstexprCore::detail::wide_hash<4, true>(*ptr, strong_map.set_.muls_);
            asm volatile("" : : "r"(value));
            sum += value;
        }
    }
    end = std::chrono::steady_clock::now();
    std::printf("strong_hash4,%g,%llu\n", std::chrono::duration<double, std::nano>(end - begin).count() / (rounds * lanes.size()), sum);
}
