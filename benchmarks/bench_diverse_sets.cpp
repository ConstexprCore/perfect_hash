/**
 * Diverse key-set benchmarks for compile-time perfect hash.
 *
 * Tests PHF lookup across key sets that vary in:
 *   - Size: 6 keys (protocols) to 50+ keys (HTTP headers, MIME types)
 *   - Key length: 2-5 bytes (protocols) to 20+ bytes (headers)
 *   - Hit/miss ratio: 100% hits, 50/50 mixed, 100% misses
 *
 * Each set preserves real-world meaning so results are directly applicable.
 */

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <map>
#include <optional>
#include <print>
#include <random>
#include <string>
#include <unordered_map>
#include <vector>

#include "ConstexprCore/perfect_hash.h"
#include "counters/bench.h"

// ============================================================================
// Benchmark infrastructure (same as bench_protocol.cpp)
// ============================================================================

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

void pretty_print(const std::string &name, size_t num_values,
                  counters::event_aggregate agg) {
  std::print("{:<55} : ", name);
  std::print(" {:5.3f} ns ", agg.fastest_elapsed_ns() / double(num_values));
  std::print(" {:5.2f} Gv/s ", double(num_values) / agg.fastest_elapsed_ns());
  if (counters::has_performance_counters()) {
    std::print(" {:5.2f} c ", agg.fastest_cycles() / double(num_values));
    std::print(" {:5.2f} i ", agg.fastest_instructions() / double(num_values));
    std::print(" {:5.2f} i/c ",
               agg.fastest_instructions() / double(agg.fastest_cycles()));
    std::print(" {:5.2f} bm ",
               agg.fastest_branch_misses() / double(num_values));
  }
  std::print("\n");
}

// ============================================================================
// Generic benchmark runner for any key set
// ============================================================================

template <typename PHFMap, typename NaiveFn>
void run_keyset_benchmark(
    const std::string &set_name,
    const PHFMap &phf_map,
    NaiveFn naive_fn,
    const std::vector<std::string_view> &hit_keys,
    const std::vector<std::string_view> &miss_keys,
    size_t num_strings = 200000) {

  // Build input vectors
  std::mt19937_64 gen(42);

  // All-hits workload
  std::vector<std::string_view> hits_input;
  hits_input.reserve(num_strings);
  for (size_t i = 0; i < num_strings; i++)
    hits_input.push_back(hit_keys[gen() % hit_keys.size()]);

  // All-misses workload
  std::vector<std::string_view> misses_input;
  misses_input.reserve(num_strings);
  for (size_t i = 0; i < num_strings; i++)
    misses_input.push_back(miss_keys[gen() % miss_keys.size()]);

  // 50/50 mixed workload
  std::vector<std::string_view> mixed_input;
  mixed_input.reserve(num_strings);
  for (size_t i = 0; i < num_strings; i++) {
    if (gen() & 1)
      mixed_input.push_back(hit_keys[gen() % hit_keys.size()]);
    else
      mixed_input.push_back(miss_keys[gen() % miss_keys.size()]);
  }

  // Result storage (prevents dead-code elimination)
  std::vector<int> results(num_strings, 0);

  std::println("\n=== {} (N={}, MaxKeyLen={}) ===",
               set_name, hit_keys.size(),
               [&]{ size_t m=0; for (auto& k : hit_keys) m = std::max(m, k.size()); return m; }());

  auto run_workload = [&](const std::string &label,
                          std::vector<std::string_view> &input) {
    auto shuffle = [&]() {
      std::shuffle(input.begin(), input.end(), gen);
    };

    // PHF (constexpr_perfect_map)
    gen.seed(42);
    auto phf_fn = [&]() {
      for (size_t i = 0; i < input.size(); i++) {
        auto opt = phf_map.lookup(input[i]);
        if (opt) results[i] = static_cast<int>(*opt);
      }
    };
    pretty_print("  " + label + " constexpr_perfect_map", num_strings,
                 shuffle_bench(phf_fn, shuffle));

    // Naive if/else chain
    gen.seed(42);
    auto naive_bench = [&]() {
      for (size_t i = 0; i < input.size(); i++) {
        auto opt = naive_fn(input[i]);
        if (opt) results[i] = static_cast<int>(*opt);
      }
    };
    pretty_print("  " + label + " naive", num_strings,
                 shuffle_bench(naive_bench, shuffle));

    // std::unordered_map (built from hit_keys)
    static thread_local std::unordered_map<std::string_view, int> uset;
    if (uset.empty()) {
      for (size_t i = 0; i < hit_keys.size(); i++)
        uset[hit_keys[i]] = static_cast<int>(i);
    }
    gen.seed(42);
    auto uset_fn = [&]() {
      for (size_t i = 0; i < input.size(); i++) {
        auto it = uset.find(input[i]);
        if (it != uset.end()) results[i] = it->second;
      }
    };
    pretty_print("  " + label + " std::unordered_map", num_strings,
                 shuffle_bench(uset_fn, shuffle));

    uset.clear(); // reset for next key set
  };

  run_workload("hits  ", hits_input);
  run_workload("misses", misses_input);
  run_workload("mixed ", mixed_input);
}

// ============================================================================
// Key set 1: URL Protocols (6 keys, MaxKeyLen=5) — small, short keys
// ============================================================================

static constexpr auto protocol_map =
    ConstexprCore::make_constexpr_perfect_map<
        ConstexprCore::kv<"http", 0>,
        ConstexprCore::kv<"https", 1>,
        ConstexprCore::kv<"ftp", 2>,
        ConstexprCore::kv<"ws", 3>,
        ConstexprCore::kv<"wss", 4>,
        ConstexprCore::kv<"file", 5>>();

std::optional<int> protocol_naive(std::string_view s) {
  if (s == "http") return 0;
  if (s == "https") return 1;
  if (s == "ftp") return 2;
  if (s == "ws") return 3;
  if (s == "wss") return 4;
  if (s == "file") return 5;
  return std::nullopt;
}

// ============================================================================
// Key set 2: C++ Keywords (15 keys, MaxKeyLen=8) — medium, short-medium keys
// ============================================================================

static constexpr auto keyword_map =
    ConstexprCore::make_constexpr_perfect_map<
        ConstexprCore::kv<"auto", 0>,
        ConstexprCore::kv<"bool", 1>,
        ConstexprCore::kv<"break", 2>,
        ConstexprCore::kv<"case", 3>,
        ConstexprCore::kv<"char", 4>,
        ConstexprCore::kv<"class", 5>,
        ConstexprCore::kv<"const", 6>,
        ConstexprCore::kv<"do", 7>,
        ConstexprCore::kv<"double", 8>,
        ConstexprCore::kv<"else", 9>,
        ConstexprCore::kv<"enum", 10>,
        ConstexprCore::kv<"float", 11>,
        ConstexprCore::kv<"for", 12>,
        ConstexprCore::kv<"goto", 13>,
        ConstexprCore::kv<"if", 14>>();

std::optional<int> keyword_naive(std::string_view s) {
  if (s == "auto") return 0;
  if (s == "bool") return 1;
  if (s == "break") return 2;
  if (s == "case") return 3;
  if (s == "char") return 4;
  if (s == "class") return 5;
  if (s == "const") return 6;
  if (s == "do") return 7;
  if (s == "double") return 8;
  if (s == "else") return 9;
  if (s == "enum") return 10;
  if (s == "float") return 11;
  if (s == "for") return 12;
  if (s == "goto") return 13;
  if (s == "if") return 14;
  return std::nullopt;
}

// ============================================================================
// Key set 3: HTTP Headers (25 keys, MaxKeyLen=19) — large, long keys
// ============================================================================

static constexpr auto header_map =
    ConstexprCore::make_constexpr_perfect_map<
        ConstexprCore::kv<"Accept", 0>,
        ConstexprCore::kv<"Accept-Encoding", 1>,
        ConstexprCore::kv<"Accept-Language", 2>,
        ConstexprCore::kv<"Authorization", 3>,
        ConstexprCore::kv<"Cache-Control", 4>,
        ConstexprCore::kv<"Connection", 5>,
        ConstexprCore::kv<"Content-Length", 6>,
        ConstexprCore::kv<"Content-Type", 7>,
        ConstexprCore::kv<"Cookie", 8>,
        ConstexprCore::kv<"Date", 9>,
        ConstexprCore::kv<"ETag", 10>,
        ConstexprCore::kv<"Host", 11>,
        ConstexprCore::kv<"If-Match", 12>,
        ConstexprCore::kv<"If-None-Match", 13>,
        ConstexprCore::kv<"Keep-Alive", 14>,
        ConstexprCore::kv<"Location", 15>,
        ConstexprCore::kv<"Origin", 16>,
        ConstexprCore::kv<"Referer", 17>,
        ConstexprCore::kv<"Server", 18>,
        ConstexprCore::kv<"Set-Cookie", 19>,
        ConstexprCore::kv<"Transfer-Encoding", 20>,
        ConstexprCore::kv<"User-Agent", 21>,
        ConstexprCore::kv<"Vary", 22>,
        ConstexprCore::kv<"Via", 23>,
        ConstexprCore::kv<"X-Forwarded-For", 24>>();

std::optional<int> header_naive(std::string_view s) {
  if (s == "Accept") return 0;
  if (s == "Accept-Encoding") return 1;
  if (s == "Accept-Language") return 2;
  if (s == "Authorization") return 3;
  if (s == "Cache-Control") return 4;
  if (s == "Connection") return 5;
  if (s == "Content-Length") return 6;
  if (s == "Content-Type") return 7;
  if (s == "Cookie") return 8;
  if (s == "Date") return 9;
  if (s == "ETag") return 10;
  if (s == "Host") return 11;
  if (s == "If-Match") return 12;
  if (s == "If-None-Match") return 13;
  if (s == "Keep-Alive") return 14;
  if (s == "Location") return 15;
  if (s == "Origin") return 16;
  if (s == "Referer") return 17;
  if (s == "Server") return 18;
  if (s == "Set-Cookie") return 19;
  if (s == "Transfer-Encoding") return 20;
  if (s == "User-Agent") return 21;
  if (s == "Vary") return 22;
  if (s == "Via") return 23;
  if (s == "X-Forwarded-For") return 24;
  return std::nullopt;
}

// ============================================================================
// Key set 4: MIME Types (20 keys, MaxKeyLen=24) — medium, long keys
// ============================================================================

static constexpr auto mime_map =
    ConstexprCore::make_constexpr_perfect_map<
        ConstexprCore::kv<"text/html", 0>,
        ConstexprCore::kv<"text/plain", 1>,
        ConstexprCore::kv<"text/css", 2>,
        ConstexprCore::kv<"text/javascript", 3>,
        ConstexprCore::kv<"application/json", 4>,
        ConstexprCore::kv<"application/xml", 5>,
        ConstexprCore::kv<"application/pdf", 6>,
        ConstexprCore::kv<"application/zip", 7>,
        ConstexprCore::kv<"application/octet-stream", 8>,
        ConstexprCore::kv<"image/png", 9>,
        ConstexprCore::kv<"image/jpeg", 10>,
        ConstexprCore::kv<"image/gif", 11>,
        ConstexprCore::kv<"image/svg+xml", 12>,
        ConstexprCore::kv<"image/webp", 13>,
        ConstexprCore::kv<"audio/mpeg", 14>,
        ConstexprCore::kv<"video/mp4", 15>,
        ConstexprCore::kv<"font/woff2", 16>,
        ConstexprCore::kv<"font/woff", 17>,
        ConstexprCore::kv<"multipart/form-data", 18>,
        ConstexprCore::kv<"application/javascript", 19>>();

std::optional<int> mime_naive(std::string_view s) {
  if (s == "text/html") return 0;
  if (s == "text/plain") return 1;
  if (s == "text/css") return 2;
  if (s == "text/javascript") return 3;
  if (s == "application/json") return 4;
  if (s == "application/xml") return 5;
  if (s == "application/pdf") return 6;
  if (s == "application/zip") return 7;
  if (s == "application/octet-stream") return 8;
  if (s == "image/png") return 9;
  if (s == "image/jpeg") return 10;
  if (s == "image/gif") return 11;
  if (s == "image/svg+xml") return 12;
  if (s == "image/webp") return 13;
  if (s == "audio/mpeg") return 14;
  if (s == "video/mp4") return 15;
  if (s == "font/woff2") return 16;
  if (s == "font/woff") return 17;
  if (s == "multipart/form-data") return 18;
  if (s == "application/javascript") return 19;
  return std::nullopt;
}

// ============================================================================
// Main
// ============================================================================

int main() {
  if (!counters::has_performance_counters())
    std::println("Performance counters not available, run with sudo.");

  // --- Protocols (6 keys, short) ---
  {
    std::vector<std::string_view> hits = {"http","https","ftp","ws","wss","file"};
    std::vector<std::string_view> misses = {"ssh","telnet","mailto","data","blob","urn"};
    run_keyset_benchmark("URL Protocols", protocol_map, protocol_naive, hits, misses);
  }

  // --- C++ Keywords (15 keys, short-medium) ---
  {
    std::vector<std::string_view> hits = {
      "auto","bool","break","case","char","class","const",
      "do","double","else","enum","float","for","goto","if"
    };
    std::vector<std::string_view> misses = {
      "int","void","return","while","switch","struct","static",
      "extern","inline","virtual","public","private","throw","try","catch"
    };
    run_keyset_benchmark("C++ Keywords", keyword_map, keyword_naive, hits, misses);
  }

  // --- HTTP Headers (25 keys, long) ---
  {
    std::vector<std::string_view> hits = {
      "Accept","Accept-Encoding","Accept-Language","Authorization",
      "Cache-Control","Connection","Content-Length","Content-Type",
      "Cookie","Date","ETag","Host","If-Match","If-None-Match",
      "Keep-Alive","Location","Origin","Referer","Server","Set-Cookie",
      "Transfer-Encoding","User-Agent","Vary","Via","X-Forwarded-For"
    };
    std::vector<std::string_view> misses = {
      "X-Request-Id","X-Correlation-Id","Forwarded","Alt-Svc","DNT",
      "Upgrade-Insecure-Requests","X-Frame-Options","X-XSS-Protection",
      "Content-Security-Policy","Strict-Transport-Security","X-Custom",
      "Pragma","Warning","Expect","Range"
    };
    run_keyset_benchmark("HTTP Headers", header_map, header_naive, hits, misses);
  }

  // --- MIME Types (20 keys, long) ---
  {
    std::vector<std::string_view> hits = {
      "text/html","text/plain","text/css","text/javascript",
      "application/json","application/xml","application/pdf",
      "application/zip","application/octet-stream","image/png",
      "image/jpeg","image/gif","image/svg+xml","image/webp",
      "audio/mpeg","video/mp4","font/woff2","font/woff",
      "multipart/form-data","application/javascript"
    };
    std::vector<std::string_view> misses = {
      "text/xml","text/csv","application/gzip","application/wasm",
      "image/avif","image/tiff","audio/ogg","video/webm",
      "font/otf","application/x-www-form-urlencoded"
    };
    run_keyset_benchmark("MIME Types", mime_map, mime_naive, hits, misses);
  }
}
