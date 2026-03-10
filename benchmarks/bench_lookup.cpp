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

#line 1 "http_methods_gperf_wrapper"
namespace gperf_http {
#include "http_methods_gperf.inc"
}

#line 1 "cpp_keywords_gperf_wrapper"
namespace gperf_kw {
#include "cpp_keywords_gperf.inc"
}

#line 1 "letters26_gperf_wrapper"
namespace gperf_letters {
#include "letters26_gperf.inc"
}

#line 1 "http_headers50_gperf_wrapper"
namespace gperf_headers {
#include "http_headers50_gperf.inc"
}

// ============================================================================
// Helpers
// ============================================================================

static bool sorted_contains(const std::string_view* begin, const std::string_view* end,
                            std::string_view key) {
    return std::binary_search(begin, end, key);
}

template <typename Keys, typename Lookup>
static void bench_loop(benchmark::State& state, const Keys& keys, Lookup lookup) {
    for (auto _ : state)
        for (auto key : keys) {
            benchmark::DoNotOptimize(key);
            benchmark::DoNotOptimize(lookup(key));
        }
    state.SetItemsProcessed(state.iterations() * keys.size());
}

// ============================================================================
// Test data: Booleans (2 strings)
// ============================================================================

constexpr auto bool_phf = ConstexprCore::make_perfect_set<"true", "false">();

static const std::unordered_set<std::string_view> bool_uset = {"true", "false"};

static constexpr std::array<std::string_view, 2> bool_sorted = []{
    std::array<std::string_view, 2> a = {"true", "false"};
    std::sort(a.begin(), a.end());
    return a;
}();

static constexpr std::array<std::string_view, 2> bool_pos = {"true", "false"};
static constexpr std::array<std::string_view, 2> bool_neg = {"yes", "no"};
static constexpr std::array<std::string_view, 4> bool_mix = {"true", "yes", "false", "no"};

// ============================================================================
// Test data: RGB Colors (3 strings)
// ============================================================================

constexpr auto rgb_phf = ConstexprCore::make_perfect_set<"red", "green", "blue">();

static const std::unordered_set<std::string_view> rgb_uset = {"red", "green", "blue"};

static constexpr std::array<std::string_view, 3> rgb_sorted = []{
    std::array<std::string_view, 3> a = {"red", "green", "blue"};
    std::sort(a.begin(), a.end());
    return a;
}();

static constexpr std::array<std::string_view, 3> rgb_pos = {"red", "green", "blue"};
static constexpr std::array<std::string_view, 3> rgb_neg = {"yellow", "cyan", "magenta"};
static constexpr std::array<std::string_view, 6> rgb_mix = {
    "red", "yellow", "green", "cyan", "blue", "magenta"
};

// ============================================================================
// Test data: Protocols (5 strings)
// ============================================================================

constexpr auto proto_phf = ConstexprCore::make_perfect_set<
    "http:", "https:", "ftp:", "sftp:", "file:"
>();

static const std::unordered_set<std::string_view> proto_uset = {
    "http:", "https:", "ftp:", "sftp:", "file:"
};

static constexpr std::array<std::string_view, 5> proto_sorted = []{
    std::array<std::string_view, 5> a = {"http:", "https:", "ftp:", "sftp:", "file:"};
    std::sort(a.begin(), a.end());
    return a;
}();

static constexpr std::array<std::string_view, 3> proto_pos = {"http:", "ftp:", "file:"};
static constexpr std::array<std::string_view, 3> proto_neg = {"ssh:", "telnet:", "ws:"};
static constexpr std::array<std::string_view, 6> proto_mix = {
    "http:", "ssh:", "ftp:", "telnet:", "file:", "ws:"
};

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
// Test data: Letters a-z (26 strings, all same length)
// ============================================================================

constexpr auto letters_phf = ConstexprCore::make_perfect_set<
    "a", "b", "c", "d", "e", "f", "g", "h", "i", "j",
    "k", "l", "m", "n", "o", "p", "q", "r", "s", "t",
    "u", "v", "w", "x", "y", "z"
>();

static const std::unordered_set<std::string_view> letters_uset = {
    "a", "b", "c", "d", "e", "f", "g", "h", "i", "j",
    "k", "l", "m", "n", "o", "p", "q", "r", "s", "t",
    "u", "v", "w", "x", "y", "z"
};

static constexpr std::array<std::string_view, 26> letters_sorted = []{
    std::array<std::string_view, 26> a = {
        "a", "b", "c", "d", "e", "f", "g", "h", "i", "j",
        "k", "l", "m", "n", "o", "p", "q", "r", "s", "t",
        "u", "v", "w", "x", "y", "z"
    };
    std::sort(a.begin(), a.end());
    return a;
}();

static constexpr std::array<std::string_view, 5> letters_pos = {"a", "m", "z", "g", "t"};
static constexpr std::array<std::string_view, 5> letters_neg = {"A", "1", "!", "aa", ""};
static constexpr std::array<std::string_view, 6> letters_mix = {
    "a", "A", "m", "1", "z", "!"
};

// ============================================================================
// Test data: HTTP Headers (50 strings)
// ============================================================================

constexpr auto headers_phf = ConstexprCore::make_perfect_set<
    "Accept", "Accept-Charset", "Accept-Encoding", "Accept-Language",
    "Accept-Ranges", "Age", "Allow", "Authorization",
    "Cache-Control", "Connection", "Content-Encoding", "Content-Language",
    "Content-Length", "Content-Location", "Content-Type", "Cookie",
    "Date", "ETag", "Expect", "Expires",
    "From", "Host", "If-Match", "If-Modified-Since",
    "If-None-Match", "If-Range", "If-Unmodified-Since", "Keep-Alive",
    "Last-Modified", "Location", "Max-Forwards", "Origin",
    "Pragma", "Proxy-Authenticate", "Proxy-Authorization", "Range",
    "Referer", "Retry-After", "Server", "Set-Cookie",
    "TE", "Trailer", "Transfer-Encoding", "Upgrade",
    "User-Agent", "Vary", "Via", "WWW-Authenticate",
    "Warning", "X-Forwarded-For"
>();

static const std::unordered_set<std::string_view> headers_uset = {
    "Accept", "Accept-Charset", "Accept-Encoding", "Accept-Language",
    "Accept-Ranges", "Age", "Allow", "Authorization",
    "Cache-Control", "Connection", "Content-Encoding", "Content-Language",
    "Content-Length", "Content-Location", "Content-Type", "Cookie",
    "Date", "ETag", "Expect", "Expires",
    "From", "Host", "If-Match", "If-Modified-Since",
    "If-None-Match", "If-Range", "If-Unmodified-Since", "Keep-Alive",
    "Last-Modified", "Location", "Max-Forwards", "Origin",
    "Pragma", "Proxy-Authenticate", "Proxy-Authorization", "Range",
    "Referer", "Retry-After", "Server", "Set-Cookie",
    "TE", "Trailer", "Transfer-Encoding", "Upgrade",
    "User-Agent", "Vary", "Via", "WWW-Authenticate",
    "Warning", "X-Forwarded-For"
};

static constexpr std::array<std::string_view, 50> headers_sorted = []{
    std::array<std::string_view, 50> a = {
        "Accept", "Accept-Charset", "Accept-Encoding", "Accept-Language",
        "Accept-Ranges", "Age", "Allow", "Authorization",
        "Cache-Control", "Connection", "Content-Encoding", "Content-Language",
        "Content-Length", "Content-Location", "Content-Type", "Cookie",
        "Date", "ETag", "Expect", "Expires",
        "From", "Host", "If-Match", "If-Modified-Since",
        "If-None-Match", "If-Range", "If-Unmodified-Since", "Keep-Alive",
        "Last-Modified", "Location", "Max-Forwards", "Origin",
        "Pragma", "Proxy-Authenticate", "Proxy-Authorization", "Range",
        "Referer", "Retry-After", "Server", "Set-Cookie",
        "TE", "Trailer", "Transfer-Encoding", "Upgrade",
        "User-Agent", "Vary", "Via", "WWW-Authenticate",
        "Warning", "X-Forwarded-For"
    };
    std::sort(a.begin(), a.end());
    return a;
}();

static constexpr std::array<std::string_view, 5> headers_pos = {
    "Accept", "Content-Type", "Host", "User-Agent", "Set-Cookie"
};
static constexpr std::array<std::string_view, 5> headers_neg = {
    "X-Custom", "Content-MD5", "Forwarded", "Alt-Svc", "DNT"
};
static constexpr std::array<std::string_view, 6> headers_mix = {
    "Accept", "X-Custom", "Host", "Content-MD5", "Via", "DNT"
};

// ============================================================================
// Booleans benchmarks (N=2)
// ============================================================================

static void BM_Bool_PHF_Positive(benchmark::State& state) {
    bench_loop(state, bool_pos, [](auto k) { return bool_phf.contains(k); });
}
BENCHMARK(BM_Bool_PHF_Positive);

static void BM_Bool_PHF_Negative(benchmark::State& state) {
    bench_loop(state, bool_neg, [](auto k) { return bool_phf.contains(k); });
}
BENCHMARK(BM_Bool_PHF_Negative);

static void BM_Bool_PHF_Mixed(benchmark::State& state) {
    bench_loop(state, bool_mix, [](auto k) { return bool_phf.contains(k); });
}
BENCHMARK(BM_Bool_PHF_Mixed);

static void BM_Bool_USet_Positive(benchmark::State& state) {
    bench_loop(state, bool_pos, [](auto k) { return bool_uset.count(k); });
}
BENCHMARK(BM_Bool_USet_Positive);

static void BM_Bool_USet_Negative(benchmark::State& state) {
    bench_loop(state, bool_neg, [](auto k) { return bool_uset.count(k); });
}
BENCHMARK(BM_Bool_USet_Negative);

static void BM_Bool_USet_Mixed(benchmark::State& state) {
    bench_loop(state, bool_mix, [](auto k) { return bool_uset.count(k); });
}
BENCHMARK(BM_Bool_USet_Mixed);

static void BM_Bool_BinSearch_Positive(benchmark::State& state) {
    bench_loop(state, bool_pos, [](auto k) {
        return sorted_contains(bool_sorted.data(), bool_sorted.data() + bool_sorted.size(), k);
    });
}
BENCHMARK(BM_Bool_BinSearch_Positive);

static void BM_Bool_BinSearch_Negative(benchmark::State& state) {
    bench_loop(state, bool_neg, [](auto k) {
        return sorted_contains(bool_sorted.data(), bool_sorted.data() + bool_sorted.size(), k);
    });
}
BENCHMARK(BM_Bool_BinSearch_Negative);

static void BM_Bool_BinSearch_Mixed(benchmark::State& state) {
    bench_loop(state, bool_mix, [](auto k) {
        return sorted_contains(bool_sorted.data(), bool_sorted.data() + bool_sorted.size(), k);
    });
}
BENCHMARK(BM_Bool_BinSearch_Mixed);

// ============================================================================
// RGB benchmarks (N=3)
// ============================================================================

static void BM_RGB_PHF_Positive(benchmark::State& state) {
    bench_loop(state, rgb_pos, [](auto k) { return rgb_phf.contains(k); });
}
BENCHMARK(BM_RGB_PHF_Positive);

static void BM_RGB_PHF_Negative(benchmark::State& state) {
    bench_loop(state, rgb_neg, [](auto k) { return rgb_phf.contains(k); });
}
BENCHMARK(BM_RGB_PHF_Negative);

static void BM_RGB_PHF_Mixed(benchmark::State& state) {
    bench_loop(state, rgb_mix, [](auto k) { return rgb_phf.contains(k); });
}
BENCHMARK(BM_RGB_PHF_Mixed);

static void BM_RGB_USet_Positive(benchmark::State& state) {
    bench_loop(state, rgb_pos, [](auto k) { return rgb_uset.count(k); });
}
BENCHMARK(BM_RGB_USet_Positive);

static void BM_RGB_USet_Negative(benchmark::State& state) {
    bench_loop(state, rgb_neg, [](auto k) { return rgb_uset.count(k); });
}
BENCHMARK(BM_RGB_USet_Negative);

static void BM_RGB_USet_Mixed(benchmark::State& state) {
    bench_loop(state, rgb_mix, [](auto k) { return rgb_uset.count(k); });
}
BENCHMARK(BM_RGB_USet_Mixed);

static void BM_RGB_BinSearch_Positive(benchmark::State& state) {
    bench_loop(state, rgb_pos, [](auto k) {
        return sorted_contains(rgb_sorted.data(), rgb_sorted.data() + rgb_sorted.size(), k);
    });
}
BENCHMARK(BM_RGB_BinSearch_Positive);

static void BM_RGB_BinSearch_Negative(benchmark::State& state) {
    bench_loop(state, rgb_neg, [](auto k) {
        return sorted_contains(rgb_sorted.data(), rgb_sorted.data() + rgb_sorted.size(), k);
    });
}
BENCHMARK(BM_RGB_BinSearch_Negative);

static void BM_RGB_BinSearch_Mixed(benchmark::State& state) {
    bench_loop(state, rgb_mix, [](auto k) {
        return sorted_contains(rgb_sorted.data(), rgb_sorted.data() + rgb_sorted.size(), k);
    });
}
BENCHMARK(BM_RGB_BinSearch_Mixed);

// ============================================================================
// Protocols benchmarks (N=5)
// ============================================================================

static void BM_Proto_PHF_Positive(benchmark::State& state) {
    bench_loop(state, proto_pos, [](auto k) { return proto_phf.contains(k); });
}
BENCHMARK(BM_Proto_PHF_Positive);

static void BM_Proto_PHF_Negative(benchmark::State& state) {
    bench_loop(state, proto_neg, [](auto k) { return proto_phf.contains(k); });
}
BENCHMARK(BM_Proto_PHF_Negative);

static void BM_Proto_PHF_Mixed(benchmark::State& state) {
    bench_loop(state, proto_mix, [](auto k) { return proto_phf.contains(k); });
}
BENCHMARK(BM_Proto_PHF_Mixed);

static void BM_Proto_USet_Positive(benchmark::State& state) {
    bench_loop(state, proto_pos, [](auto k) { return proto_uset.count(k); });
}
BENCHMARK(BM_Proto_USet_Positive);

static void BM_Proto_USet_Negative(benchmark::State& state) {
    bench_loop(state, proto_neg, [](auto k) { return proto_uset.count(k); });
}
BENCHMARK(BM_Proto_USet_Negative);

static void BM_Proto_USet_Mixed(benchmark::State& state) {
    bench_loop(state, proto_mix, [](auto k) { return proto_uset.count(k); });
}
BENCHMARK(BM_Proto_USet_Mixed);

static void BM_Proto_BinSearch_Positive(benchmark::State& state) {
    bench_loop(state, proto_pos, [](auto k) {
        return sorted_contains(proto_sorted.data(), proto_sorted.data() + proto_sorted.size(), k);
    });
}
BENCHMARK(BM_Proto_BinSearch_Positive);

static void BM_Proto_BinSearch_Negative(benchmark::State& state) {
    bench_loop(state, proto_neg, [](auto k) {
        return sorted_contains(proto_sorted.data(), proto_sorted.data() + proto_sorted.size(), k);
    });
}
BENCHMARK(BM_Proto_BinSearch_Negative);

static void BM_Proto_BinSearch_Mixed(benchmark::State& state) {
    bench_loop(state, proto_mix, [](auto k) {
        return sorted_contains(proto_sorted.data(), proto_sorted.data() + proto_sorted.size(), k);
    });
}
BENCHMARK(BM_Proto_BinSearch_Mixed);

// ============================================================================
// HTTP Methods benchmarks (N=7)
// ============================================================================

static void BM_HTTP_PHF_Positive(benchmark::State& state) {
    bench_loop(state, http_pos, [](auto k) { return http_phf.contains(k); });
}
BENCHMARK(BM_HTTP_PHF_Positive);

static void BM_HTTP_PHF_Negative(benchmark::State& state) {
    bench_loop(state, http_neg, [](auto k) { return http_phf.contains(k); });
}
BENCHMARK(BM_HTTP_PHF_Negative);

static void BM_HTTP_PHF_Mixed(benchmark::State& state) {
    bench_loop(state, http_mix, [](auto k) { return http_phf.contains(k); });
}
BENCHMARK(BM_HTTP_PHF_Mixed);

static void BM_HTTP_Gperf_Positive(benchmark::State& state) {
    bench_loop(state, http_pos, [](auto k) {
        return gperf_http::HttpMethodsGperf::lookup(k.data(), k.size());
    });
}
BENCHMARK(BM_HTTP_Gperf_Positive);

static void BM_HTTP_Gperf_Negative(benchmark::State& state) {
    bench_loop(state, http_neg, [](auto k) {
        return gperf_http::HttpMethodsGperf::lookup(k.data(), k.size());
    });
}
BENCHMARK(BM_HTTP_Gperf_Negative);

static void BM_HTTP_Gperf_Mixed(benchmark::State& state) {
    bench_loop(state, http_mix, [](auto k) {
        return gperf_http::HttpMethodsGperf::lookup(k.data(), k.size());
    });
}
BENCHMARK(BM_HTTP_Gperf_Mixed);

static void BM_HTTP_USet_Positive(benchmark::State& state) {
    bench_loop(state, http_pos, [](auto k) { return http_uset.count(k); });
}
BENCHMARK(BM_HTTP_USet_Positive);

static void BM_HTTP_USet_Negative(benchmark::State& state) {
    bench_loop(state, http_neg, [](auto k) { return http_uset.count(k); });
}
BENCHMARK(BM_HTTP_USet_Negative);

static void BM_HTTP_USet_Mixed(benchmark::State& state) {
    bench_loop(state, http_mix, [](auto k) { return http_uset.count(k); });
}
BENCHMARK(BM_HTTP_USet_Mixed);

static void BM_HTTP_BinSearch_Positive(benchmark::State& state) {
    bench_loop(state, http_pos, [](auto k) {
        return sorted_contains(http_sorted.data(), http_sorted.data() + http_sorted.size(), k);
    });
}
BENCHMARK(BM_HTTP_BinSearch_Positive);

static void BM_HTTP_BinSearch_Negative(benchmark::State& state) {
    bench_loop(state, http_neg, [](auto k) {
        return sorted_contains(http_sorted.data(), http_sorted.data() + http_sorted.size(), k);
    });
}
BENCHMARK(BM_HTTP_BinSearch_Negative);

static void BM_HTTP_BinSearch_Mixed(benchmark::State& state) {
    bench_loop(state, http_mix, [](auto k) {
        return sorted_contains(http_sorted.data(), http_sorted.data() + http_sorted.size(), k);
    });
}
BENCHMARK(BM_HTTP_BinSearch_Mixed);

// ============================================================================
// C++ Keywords benchmarks (N=15)
// ============================================================================

static void BM_KW_PHF_Positive(benchmark::State& state) {
    bench_loop(state, kw_pos, [](auto k) { return kw_phf.contains(k); });
}
BENCHMARK(BM_KW_PHF_Positive);

static void BM_KW_PHF_Negative(benchmark::State& state) {
    bench_loop(state, kw_neg, [](auto k) { return kw_phf.contains(k); });
}
BENCHMARK(BM_KW_PHF_Negative);

static void BM_KW_PHF_Mixed(benchmark::State& state) {
    bench_loop(state, kw_mix, [](auto k) { return kw_phf.contains(k); });
}
BENCHMARK(BM_KW_PHF_Mixed);

static void BM_KW_Gperf_Positive(benchmark::State& state) {
    bench_loop(state, kw_pos, [](auto k) {
        return gperf_kw::CppKeywordsGperf::lookup(k.data(), k.size());
    });
}
BENCHMARK(BM_KW_Gperf_Positive);

static void BM_KW_Gperf_Negative(benchmark::State& state) {
    bench_loop(state, kw_neg, [](auto k) {
        return gperf_kw::CppKeywordsGperf::lookup(k.data(), k.size());
    });
}
BENCHMARK(BM_KW_Gperf_Negative);

static void BM_KW_Gperf_Mixed(benchmark::State& state) {
    bench_loop(state, kw_mix, [](auto k) {
        return gperf_kw::CppKeywordsGperf::lookup(k.data(), k.size());
    });
}
BENCHMARK(BM_KW_Gperf_Mixed);

static void BM_KW_USet_Positive(benchmark::State& state) {
    bench_loop(state, kw_pos, [](auto k) { return kw_uset.count(k); });
}
BENCHMARK(BM_KW_USet_Positive);

static void BM_KW_USet_Negative(benchmark::State& state) {
    bench_loop(state, kw_neg, [](auto k) { return kw_uset.count(k); });
}
BENCHMARK(BM_KW_USet_Negative);

static void BM_KW_USet_Mixed(benchmark::State& state) {
    bench_loop(state, kw_mix, [](auto k) { return kw_uset.count(k); });
}
BENCHMARK(BM_KW_USet_Mixed);

static void BM_KW_BinSearch_Positive(benchmark::State& state) {
    bench_loop(state, kw_pos, [](auto k) {
        return sorted_contains(kw_sorted.data(), kw_sorted.data() + kw_sorted.size(), k);
    });
}
BENCHMARK(BM_KW_BinSearch_Positive);

static void BM_KW_BinSearch_Negative(benchmark::State& state) {
    bench_loop(state, kw_neg, [](auto k) {
        return sorted_contains(kw_sorted.data(), kw_sorted.data() + kw_sorted.size(), k);
    });
}
BENCHMARK(BM_KW_BinSearch_Negative);

static void BM_KW_BinSearch_Mixed(benchmark::State& state) {
    bench_loop(state, kw_mix, [](auto k) {
        return sorted_contains(kw_sorted.data(), kw_sorted.data() + kw_sorted.size(), k);
    });
}
BENCHMARK(BM_KW_BinSearch_Mixed);

// ============================================================================
// Letters a-z benchmarks (N=26, all same length — stresses asso_values)
// ============================================================================

static void BM_Letters_PHF_Positive(benchmark::State& state) {
    bench_loop(state, letters_pos, [](auto k) { return letters_phf.contains(k); });
}
BENCHMARK(BM_Letters_PHF_Positive);

static void BM_Letters_PHF_Negative(benchmark::State& state) {
    bench_loop(state, letters_neg, [](auto k) { return letters_phf.contains(k); });
}
BENCHMARK(BM_Letters_PHF_Negative);

static void BM_Letters_PHF_Mixed(benchmark::State& state) {
    bench_loop(state, letters_mix, [](auto k) { return letters_phf.contains(k); });
}
BENCHMARK(BM_Letters_PHF_Mixed);

static void BM_Letters_Gperf_Positive(benchmark::State& state) {
    bench_loop(state, letters_pos, [](auto k) {
        return gperf_letters::Letters26Gperf::lookup(k.data(), k.size());
    });
}
BENCHMARK(BM_Letters_Gperf_Positive);

static void BM_Letters_Gperf_Negative(benchmark::State& state) {
    bench_loop(state, letters_neg, [](auto k) {
        return gperf_letters::Letters26Gperf::lookup(k.data(), k.size());
    });
}
BENCHMARK(BM_Letters_Gperf_Negative);

static void BM_Letters_Gperf_Mixed(benchmark::State& state) {
    bench_loop(state, letters_mix, [](auto k) {
        return gperf_letters::Letters26Gperf::lookup(k.data(), k.size());
    });
}
BENCHMARK(BM_Letters_Gperf_Mixed);

static void BM_Letters_USet_Positive(benchmark::State& state) {
    bench_loop(state, letters_pos, [](auto k) { return letters_uset.count(k); });
}
BENCHMARK(BM_Letters_USet_Positive);

static void BM_Letters_USet_Negative(benchmark::State& state) {
    bench_loop(state, letters_neg, [](auto k) { return letters_uset.count(k); });
}
BENCHMARK(BM_Letters_USet_Negative);

static void BM_Letters_USet_Mixed(benchmark::State& state) {
    bench_loop(state, letters_mix, [](auto k) { return letters_uset.count(k); });
}
BENCHMARK(BM_Letters_USet_Mixed);

static void BM_Letters_BinSearch_Positive(benchmark::State& state) {
    bench_loop(state, letters_pos, [](auto k) {
        return sorted_contains(letters_sorted.data(), letters_sorted.data() + letters_sorted.size(), k);
    });
}
BENCHMARK(BM_Letters_BinSearch_Positive);

static void BM_Letters_BinSearch_Negative(benchmark::State& state) {
    bench_loop(state, letters_neg, [](auto k) {
        return sorted_contains(letters_sorted.data(), letters_sorted.data() + letters_sorted.size(), k);
    });
}
BENCHMARK(BM_Letters_BinSearch_Negative);

static void BM_Letters_BinSearch_Mixed(benchmark::State& state) {
    bench_loop(state, letters_mix, [](auto k) {
        return sorted_contains(letters_sorted.data(), letters_sorted.data() + letters_sorted.size(), k);
    });
}
BENCHMARK(BM_Letters_BinSearch_Mixed);

// ============================================================================
// HTTP Headers benchmarks (N=50, realistic large set)
// ============================================================================

static void BM_Headers_PHF_Positive(benchmark::State& state) {
    bench_loop(state, headers_pos, [](auto k) { return headers_phf.contains(k); });
}
BENCHMARK(BM_Headers_PHF_Positive);

static void BM_Headers_PHF_Negative(benchmark::State& state) {
    bench_loop(state, headers_neg, [](auto k) { return headers_phf.contains(k); });
}
BENCHMARK(BM_Headers_PHF_Negative);

static void BM_Headers_PHF_Mixed(benchmark::State& state) {
    bench_loop(state, headers_mix, [](auto k) { return headers_phf.contains(k); });
}
BENCHMARK(BM_Headers_PHF_Mixed);

static void BM_Headers_Gperf_Positive(benchmark::State& state) {
    bench_loop(state, headers_pos, [](auto k) {
        return gperf_headers::HttpHeaders50Gperf::lookup(k.data(), k.size());
    });
}
BENCHMARK(BM_Headers_Gperf_Positive);

static void BM_Headers_Gperf_Negative(benchmark::State& state) {
    bench_loop(state, headers_neg, [](auto k) {
        return gperf_headers::HttpHeaders50Gperf::lookup(k.data(), k.size());
    });
}
BENCHMARK(BM_Headers_Gperf_Negative);

static void BM_Headers_Gperf_Mixed(benchmark::State& state) {
    bench_loop(state, headers_mix, [](auto k) {
        return gperf_headers::HttpHeaders50Gperf::lookup(k.data(), k.size());
    });
}
BENCHMARK(BM_Headers_Gperf_Mixed);

static void BM_Headers_USet_Positive(benchmark::State& state) {
    bench_loop(state, headers_pos, [](auto k) { return headers_uset.count(k); });
}
BENCHMARK(BM_Headers_USet_Positive);

static void BM_Headers_USet_Negative(benchmark::State& state) {
    bench_loop(state, headers_neg, [](auto k) { return headers_uset.count(k); });
}
BENCHMARK(BM_Headers_USet_Negative);

static void BM_Headers_USet_Mixed(benchmark::State& state) {
    bench_loop(state, headers_mix, [](auto k) { return headers_uset.count(k); });
}
BENCHMARK(BM_Headers_USet_Mixed);

static void BM_Headers_BinSearch_Positive(benchmark::State& state) {
    bench_loop(state, headers_pos, [](auto k) {
        return sorted_contains(headers_sorted.data(), headers_sorted.data() + headers_sorted.size(), k);
    });
}
BENCHMARK(BM_Headers_BinSearch_Positive);

static void BM_Headers_BinSearch_Negative(benchmark::State& state) {
    bench_loop(state, headers_neg, [](auto k) {
        return sorted_contains(headers_sorted.data(), headers_sorted.data() + headers_sorted.size(), k);
    });
}
BENCHMARK(BM_Headers_BinSearch_Negative);

static void BM_Headers_BinSearch_Mixed(benchmark::State& state) {
    bench_loop(state, headers_mix, [](auto k) {
        return sorted_contains(headers_sorted.data(), headers_sorted.data() + headers_sorted.size(), k);
    });
}
BENCHMARK(BM_Headers_BinSearch_Mixed);
