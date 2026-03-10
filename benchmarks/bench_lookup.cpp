#include <benchmark/benchmark.h>
#include <ConstexprCore/perfect_hash.h>
#include <unordered_set>
#include <string_view>
#include <array>
#include <algorithm>
#include <cstring>

// ============================================================================
// gperf-generated code (included directly)
// ============================================================================

// Suppress gperf's line directives
#line 1 "http_methods_gperf_wrapper"
namespace gperf_http {
#include "http_methods_gperf.inc"
}

#line 1 "cpp_keywords_gperf_wrapper"
namespace gperf_kw {
#include "cpp_keywords_gperf.inc"
}

// ============================================================================
// Test data: HTTP Methods (7 strings)
// ============================================================================

constexpr auto http_phf = ConstexprCore::make_perfect_set<
    "GET", "POST", "PUT", "DELETE", "PATCH", "HEAD", "OPTIONS"
>();

static const std::unordered_set<std::string_view> http_uset = {
    "GET", "POST", "PUT", "DELETE", "PATCH", "HEAD", "OPTIONS"
};

static constexpr std::array<std::string_view, 7> http_sorted = []{
    std::array<std::string_view, 7> a = {
        "GET", "POST", "PUT", "DELETE", "PATCH", "HEAD", "OPTIONS"
    };
    std::sort(a.begin(), a.end());
    return a;
}();

static constexpr std::array<std::string_view, 3> http_pos = {"GET", "DELETE", "OPTIONS"};
static constexpr std::array<std::string_view, 3> http_neg = {"CONNECT", "TRACE", "gets"};
static constexpr std::array<std::string_view, 6> http_mix = {
    "GET", "CONNECT", "POST", "TRACE", "HEAD", "get"
};

// ============================================================================
// Test data: C++ Keywords (15 strings)
// ============================================================================

constexpr auto kw_phf = ConstexprCore::make_perfect_set<
    "auto", "bool", "break", "case", "char",
    "class", "const", "do", "double", "else",
    "enum", "float", "for", "goto", "if"
>();

static const std::unordered_set<std::string_view> kw_uset = {
    "auto", "bool", "break", "case", "char",
    "class", "const", "do", "double", "else",
    "enum", "float", "for", "goto", "if"
};

static constexpr std::array<std::string_view, 15> kw_sorted = []{
    std::array<std::string_view, 15> a = {
        "auto", "bool", "break", "case", "char",
        "class", "const", "do", "double", "else",
        "enum", "float", "for", "goto", "if"
    };
    std::sort(a.begin(), a.end());
    return a;
}();

static constexpr std::array<std::string_view, 5> kw_pos = {"auto", "const", "for", "if", "double"};
static constexpr std::array<std::string_view, 5> kw_neg = {"int", "void", "return", "string", "while"};
static constexpr std::array<std::string_view, 6> kw_mix = {
    "auto", "int", "const", "void", "if", "return"
};

// ============================================================================
// Helpers
// ============================================================================

static bool sorted_contains(const std::string_view* begin, const std::string_view* end,
                            std::string_view key) {
    return std::binary_search(begin, end, key);
}

// ============================================================================
// HTTP Methods benchmarks
// ============================================================================

// --- Compile-time PHF ---

static void BM_HTTP_PHF_Positive(benchmark::State& state) {
    for (auto _ : state) {
        for (auto key : http_pos)
            benchmark::DoNotOptimize(http_phf.contains(key));
    }
}
BENCHMARK(BM_HTTP_PHF_Positive);

static void BM_HTTP_PHF_Negative(benchmark::State& state) {
    for (auto _ : state) {
        for (auto key : http_neg)
            benchmark::DoNotOptimize(http_phf.contains(key));
    }
}
BENCHMARK(BM_HTTP_PHF_Negative);

static void BM_HTTP_PHF_Mixed(benchmark::State& state) {
    for (auto _ : state) {
        for (auto key : http_mix)
            benchmark::DoNotOptimize(http_phf.contains(key));
    }
}
BENCHMARK(BM_HTTP_PHF_Mixed);

// --- gperf ---

static void BM_HTTP_Gperf_Positive(benchmark::State& state) {
    for (auto _ : state) {
        for (auto key : http_pos)
            benchmark::DoNotOptimize(gperf_http::HttpMethodsGperf::lookup(key.data(), key.size()));
    }
}
BENCHMARK(BM_HTTP_Gperf_Positive);

static void BM_HTTP_Gperf_Negative(benchmark::State& state) {
    for (auto _ : state) {
        for (auto key : http_neg)
            benchmark::DoNotOptimize(gperf_http::HttpMethodsGperf::lookup(key.data(), key.size()));
    }
}
BENCHMARK(BM_HTTP_Gperf_Negative);

static void BM_HTTP_Gperf_Mixed(benchmark::State& state) {
    for (auto _ : state) {
        for (auto key : http_mix)
            benchmark::DoNotOptimize(gperf_http::HttpMethodsGperf::lookup(key.data(), key.size()));
    }
}
BENCHMARK(BM_HTTP_Gperf_Mixed);

// --- std::unordered_set ---

static void BM_HTTP_USet_Positive(benchmark::State& state) {
    for (auto _ : state) {
        for (auto key : http_pos)
            benchmark::DoNotOptimize(http_uset.count(key));
    }
}
BENCHMARK(BM_HTTP_USet_Positive);

static void BM_HTTP_USet_Negative(benchmark::State& state) {
    for (auto _ : state) {
        for (auto key : http_neg)
            benchmark::DoNotOptimize(http_uset.count(key));
    }
}
BENCHMARK(BM_HTTP_USet_Negative);

static void BM_HTTP_USet_Mixed(benchmark::State& state) {
    for (auto _ : state) {
        for (auto key : http_mix)
            benchmark::DoNotOptimize(http_uset.count(key));
    }
}
BENCHMARK(BM_HTTP_USet_Mixed);

// --- Sorted array + binary search ---

static void BM_HTTP_BinSearch_Positive(benchmark::State& state) {
    for (auto _ : state) {
        for (auto key : http_pos)
            benchmark::DoNotOptimize(sorted_contains(http_sorted.data(),
                http_sorted.data() + http_sorted.size(), key));
    }
}
BENCHMARK(BM_HTTP_BinSearch_Positive);

static void BM_HTTP_BinSearch_Negative(benchmark::State& state) {
    for (auto _ : state) {
        for (auto key : http_neg)
            benchmark::DoNotOptimize(sorted_contains(http_sorted.data(),
                http_sorted.data() + http_sorted.size(), key));
    }
}
BENCHMARK(BM_HTTP_BinSearch_Negative);

static void BM_HTTP_BinSearch_Mixed(benchmark::State& state) {
    for (auto _ : state) {
        for (auto key : http_mix)
            benchmark::DoNotOptimize(sorted_contains(http_sorted.data(),
                http_sorted.data() + http_sorted.size(), key));
    }
}
BENCHMARK(BM_HTTP_BinSearch_Mixed);

// ============================================================================
// C++ Keywords benchmarks (15 keys — larger set)
// ============================================================================

// --- Compile-time PHF ---

static void BM_KW_PHF_Positive(benchmark::State& state) {
    for (auto _ : state) {
        for (auto key : kw_pos)
            benchmark::DoNotOptimize(kw_phf.contains(key));
    }
}
BENCHMARK(BM_KW_PHF_Positive);

static void BM_KW_PHF_Negative(benchmark::State& state) {
    for (auto _ : state) {
        for (auto key : kw_neg)
            benchmark::DoNotOptimize(kw_phf.contains(key));
    }
}
BENCHMARK(BM_KW_PHF_Negative);

static void BM_KW_PHF_Mixed(benchmark::State& state) {
    for (auto _ : state) {
        for (auto key : kw_mix)
            benchmark::DoNotOptimize(kw_phf.contains(key));
    }
}
BENCHMARK(BM_KW_PHF_Mixed);

// --- gperf ---

static void BM_KW_Gperf_Positive(benchmark::State& state) {
    for (auto _ : state) {
        for (auto key : kw_pos)
            benchmark::DoNotOptimize(gperf_kw::CppKeywordsGperf::lookup(key.data(), key.size()));
    }
}
BENCHMARK(BM_KW_Gperf_Positive);

static void BM_KW_Gperf_Negative(benchmark::State& state) {
    for (auto _ : state) {
        for (auto key : kw_neg)
            benchmark::DoNotOptimize(gperf_kw::CppKeywordsGperf::lookup(key.data(), key.size()));
    }
}
BENCHMARK(BM_KW_Gperf_Negative);

static void BM_KW_Gperf_Mixed(benchmark::State& state) {
    for (auto _ : state) {
        for (auto key : kw_mix)
            benchmark::DoNotOptimize(gperf_kw::CppKeywordsGperf::lookup(key.data(), key.size()));
    }
}
BENCHMARK(BM_KW_Gperf_Mixed);

// --- std::unordered_set ---

static void BM_KW_USet_Positive(benchmark::State& state) {
    for (auto _ : state) {
        for (auto key : kw_pos)
            benchmark::DoNotOptimize(kw_uset.count(key));
    }
}
BENCHMARK(BM_KW_USet_Positive);

static void BM_KW_USet_Negative(benchmark::State& state) {
    for (auto _ : state) {
        for (auto key : kw_neg)
            benchmark::DoNotOptimize(kw_uset.count(key));
    }
}
BENCHMARK(BM_KW_USet_Negative);

static void BM_KW_USet_Mixed(benchmark::State& state) {
    for (auto _ : state) {
        for (auto key : kw_mix)
            benchmark::DoNotOptimize(kw_uset.count(key));
    }
}
BENCHMARK(BM_KW_USet_Mixed);

// --- Sorted array + binary search ---

static void BM_KW_BinSearch_Positive(benchmark::State& state) {
    for (auto _ : state) {
        for (auto key : kw_pos)
            benchmark::DoNotOptimize(sorted_contains(kw_sorted.data(),
                kw_sorted.data() + kw_sorted.size(), key));
    }
}
BENCHMARK(BM_KW_BinSearch_Positive);

static void BM_KW_BinSearch_Negative(benchmark::State& state) {
    for (auto _ : state) {
        for (auto key : kw_neg)
            benchmark::DoNotOptimize(sorted_contains(kw_sorted.data(),
                kw_sorted.data() + kw_sorted.size(), key));
    }
}
BENCHMARK(BM_KW_BinSearch_Negative);

static void BM_KW_BinSearch_Mixed(benchmark::State& state) {
    for (auto _ : state) {
        for (auto key : kw_mix)
            benchmark::DoNotOptimize(sorted_contains(kw_sorted.data(),
                kw_sorted.data() + kw_sorted.size(), key));
    }
}
BENCHMARK(BM_KW_BinSearch_Mixed);
