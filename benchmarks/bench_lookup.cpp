#include <benchmark/benchmark.h>
#include <ConstexprCore/perfect_hash.h>
#include <ConstexprCore/constexpr_hash.h>
#include <unordered_set>
#include <string_view>
#include <array>

using namespace std::string_view_literals;

// ============================================================================
// HTTP Methods (7 strings)
// ============================================================================

constexpr auto http_methods = ConstexprCore::make_perfect_set<
    "GET", "POST", "PUT", "DELETE", "PATCH", "HEAD", "OPTIONS"
>();

static const std::unordered_set<std::string_view> http_methods_uset = {
    "GET", "POST", "PUT", "DELETE", "PATCH", "HEAD", "OPTIONS"
};

static constexpr std::array<std::string_view, 7> http_methods_arr = {
    "GET", "POST", "PUT", "DELETE", "PATCH", "HEAD", "OPTIONS"
};

// Positive lookups
static constexpr std::array<std::string_view, 3> http_positive = {"GET", "DELETE", "OPTIONS"};
// Negative lookups
static constexpr std::array<std::string_view, 3> http_negative = {"CONNECT", "", "gets"};

// -- Perfect hash --

static void BM_PHF_HTTP_Positive(benchmark::State& state) {
    for (auto _ : state) {
        for (auto key : http_positive) {
            benchmark::DoNotOptimize(http_methods.contains(key));
        }
    }
}
BENCHMARK(BM_PHF_HTTP_Positive);

static void BM_PHF_HTTP_Negative(benchmark::State& state) {
    for (auto _ : state) {
        for (auto key : http_negative) {
            benchmark::DoNotOptimize(http_methods.contains(key));
        }
    }
}
BENCHMARK(BM_PHF_HTTP_Negative);

// -- Naive linear scan --

static bool naive_contains(std::string_view key) {
    for (auto m : http_methods_arr) {
        if (m == key) return true;
    }
    return false;
}

static void BM_Naive_HTTP_Positive(benchmark::State& state) {
    for (auto _ : state) {
        for (auto key : http_positive) {
            benchmark::DoNotOptimize(naive_contains(key));
        }
    }
}
BENCHMARK(BM_Naive_HTTP_Positive);

static void BM_Naive_HTTP_Negative(benchmark::State& state) {
    for (auto _ : state) {
        for (auto key : http_negative) {
            benchmark::DoNotOptimize(naive_contains(key));
        }
    }
}
BENCHMARK(BM_Naive_HTTP_Negative);

// -- unordered_set --

static void BM_USet_HTTP_Positive(benchmark::State& state) {
    for (auto _ : state) {
        for (auto key : http_positive) {
            benchmark::DoNotOptimize(http_methods_uset.count(key));
        }
    }
}
BENCHMARK(BM_USet_HTTP_Positive);

static void BM_USet_HTTP_Negative(benchmark::State& state) {
    for (auto _ : state) {
        for (auto key : http_negative) {
            benchmark::DoNotOptimize(http_methods_uset.count(key));
        }
    }
}
BENCHMARK(BM_USet_HTTP_Negative);

// -- Switch on fnv1a hash --

static bool switch_hash_contains(std::string_view key) {
    auto h = ConstexprCore::fnv1a(key);
    switch (h) {
        case ConstexprCore::fnv1a(std::string_view{"GET"}):
            return key == "GET";
        case ConstexprCore::fnv1a(std::string_view{"POST"}):
            return key == "POST";
        case ConstexprCore::fnv1a(std::string_view{"PUT"}):
            return key == "PUT";
        case ConstexprCore::fnv1a(std::string_view{"DELETE"}):
            return key == "DELETE";
        case ConstexprCore::fnv1a(std::string_view{"PATCH"}):
            return key == "PATCH";
        case ConstexprCore::fnv1a(std::string_view{"HEAD"}):
            return key == "HEAD";
        case ConstexprCore::fnv1a(std::string_view{"OPTIONS"}):
            return key == "OPTIONS";
        default:
            return false;
    }
}

static void BM_SwitchHash_HTTP_Positive(benchmark::State& state) {
    for (auto _ : state) {
        for (auto key : http_positive) {
            benchmark::DoNotOptimize(switch_hash_contains(key));
        }
    }
}
BENCHMARK(BM_SwitchHash_HTTP_Positive);

static void BM_SwitchHash_HTTP_Negative(benchmark::State& state) {
    for (auto _ : state) {
        for (auto key : http_negative) {
            benchmark::DoNotOptimize(switch_hash_contains(key));
        }
    }
}
BENCHMARK(BM_SwitchHash_HTTP_Negative);

// ============================================================================
// URL Protocols (5 strings)
// ============================================================================

constexpr auto url_protocols = ConstexprCore::make_perfect_set<
    "http:", "https:", "ftp:", "sftp:", "file:"
>();

static const std::unordered_set<std::string_view> url_protocols_uset = {
    "http:", "https:", "ftp:", "sftp:", "file:"
};

static constexpr std::array<std::string_view, 3> proto_positive = {"http:", "ftp:", "file:"};
static constexpr std::array<std::string_view, 3> proto_negative = {"ssh:", "telnet:", ""};

static void BM_PHF_Proto_Positive(benchmark::State& state) {
    for (auto _ : state) {
        for (auto key : proto_positive) {
            benchmark::DoNotOptimize(url_protocols.contains(key));
        }
    }
}
BENCHMARK(BM_PHF_Proto_Positive);

static void BM_PHF_Proto_Negative(benchmark::State& state) {
    for (auto _ : state) {
        for (auto key : proto_negative) {
            benchmark::DoNotOptimize(url_protocols.contains(key));
        }
    }
}
BENCHMARK(BM_PHF_Proto_Negative);

static void BM_USet_Proto_Positive(benchmark::State& state) {
    for (auto _ : state) {
        for (auto key : proto_positive) {
            benchmark::DoNotOptimize(url_protocols_uset.count(key));
        }
    }
}
BENCHMARK(BM_USet_Proto_Positive);

static void BM_USet_Proto_Negative(benchmark::State& state) {
    for (auto _ : state) {
        for (auto key : proto_negative) {
            benchmark::DoNotOptimize(url_protocols_uset.count(key));
        }
    }
}
BENCHMARK(BM_USet_Proto_Negative);

// ============================================================================
// Mixed workload: 50% hit, 50% miss
// ============================================================================

static constexpr std::array<std::string_view, 6> http_mixed = {
    "GET", "CONNECT", "POST", "TRACE", "HEAD", "get"
};

static void BM_PHF_HTTP_Mixed(benchmark::State& state) {
    for (auto _ : state) {
        for (auto key : http_mixed) {
            benchmark::DoNotOptimize(http_methods.contains(key));
        }
    }
}
BENCHMARK(BM_PHF_HTTP_Mixed);

static void BM_USet_HTTP_Mixed(benchmark::State& state) {
    for (auto _ : state) {
        for (auto key : http_mixed) {
            benchmark::DoNotOptimize(http_methods_uset.count(key));
        }
    }
}
BENCHMARK(BM_USet_HTTP_Mixed);
