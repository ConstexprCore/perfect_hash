// Classic-vs-wide crossover sweep on short keys (EXPERIMENTAL_DIARY.md, Day 3).
//
// Instantiates BOTH containers on the first N S&P 500 tickers (MaxKeyLen 4-5) and
// times hits / misses / mixed (uniform sample over hits ++ misses, |misses| = N/5)
// for N = 8..128; -DPH_CROSSOVER_BIG=ON (BENCH_CROSSOVER_BIG) adds N = 192 and 255,
// where the classic generator falls to the H&D and seeded whole-key tiers (several
// minutes of consteval). `int` values, so the wide map is the unfused form, as in
// bench_protocol's S&P 100 set.
#include <ConstexprCore/perfect_hash.h>
#include <ConstexprCore/wide_perfect_hash.h>
#include "bench_common.h"
#include "sp500_symbols.inc"

template <std::size_t N>
consteval std::array<std::string_view, N> take(const std::array<std::string_view, 503>& src) {
    std::array<std::string_view, N> a{};
    for (std::size_t i = 0; i < N; ++i) a[i] = src[i];
    return a;
}
template <std::size_t N> inline constexpr auto keys_v = take<N>(sp500_symbols);
template <std::size_t N> inline constexpr auto vals_v = [] {
    std::array<int, N> v{}; for (std::size_t i = 0; i < N; ++i) v[i] = static_cast<int>(i); return v; }();

template <const auto& Keys, const auto& Values>
consteval auto make_classic_map() {
    constexpr std::size_t N = Keys.size();
    constexpr auto data = ConstexprCore::compute_phf<N>(Keys);
    constexpr std::size_t MaxLen = ConstexprCore::detail::max_key_length(Keys);
    return ConstexprCore::perfect_hash_map<N, int, data.table_size, MaxLen>{Keys, Values, data};
}
template <std::size_t N> inline constexpr auto classic_v = make_classic_map<keys_v<N>, vals_v<N>>();
template <std::size_t N> inline constexpr auto wide_v = ConstexprCore::make_wide_perfect_map<keys_v<N>, vals_v<N>>();

template <std::size_t N>
void run_n(std::size_t num_strings) {
    const auto& classic = classic_v<N>;
    const auto& wide = wide_v<N>;
    std::vector<std::string_view> hit_pool(keys_v<N>.begin(), keys_v<N>.end());
    const std::size_t nmiss = std::max<std::size_t>(2, N / 5);
    std::vector<std::string_view> miss_pool(sp500_miss_symbols.begin(), sp500_miss_symbols.begin() + nmiss);
    std::size_t maxlen = 0;
    for (auto k : hit_pool) maxlen = std::max(maxlen, k.size());
    // both containers must agree before we time them
    for (std::size_t i = 0; i < N; ++i) {
        if (!classic.lookup(hit_pool[i]) || *classic.lookup(hit_pool[i]) != int(i)) { std::println("classic wrong at N={}", N); std::exit(1); }
        if (!wide.lookup(hit_pool[i]) || *wide.lookup(hit_pool[i]) != int(i)) { std::println("wide wrong at N={}", N); std::exit(1); }
    }
    for (auto m : miss_pool) if (classic.lookup(m) || wide.lookup(m)) { std::println("false positive at N={}", N); std::exit(1); }

    auto hits = benchx::build_input(hit_pool, num_strings, 42);
    auto misses = benchx::build_input(miss_pool, num_strings, 42);
    auto mixed = benchx::build_mixed_input(hit_pool, miss_pool, num_strings, 42);
    std::println("\n=== N={} MaxKeyLen={} misses={} (classic: {}, M={}; wide: {}, M={}) ===",
                 N, maxlen, nmiss, classic.algorithm_name(), classic.table_size(), wide.algorithm_name(), wide.table_size());
    auto run = [&](const char* wl, std::vector<std::string_view>& in) {
        benchx::run_method(std::string(wl) + " classic", in, [&](std::string_view s) { return classic.lookup(s); });
        benchx::run_method(std::string(wl) + " wide   ", in, [&](std::string_view s) { return wide.lookup(s); });
    };
    run("hits  ", hits); run("misses", misses); run("mixed ", mixed);
}

int main() {
    const std::size_t n = 200000;
    run_n<8>(n); run_n<16>(n); run_n<32>(n); run_n<64>(n); run_n<100>(n); run_n<128>(n);
#if BENCH_CROSSOVER_BIG
    run_n<192>(n); run_n<255>(n);
#endif
    return 0;
}
