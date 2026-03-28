/**
 * Compile-time perfect hash benchmark suite.
 *
 * Tests PHF lookup across key sets that vary in size and key length.
 * Each set is benchmarked in three workload modes:
 *   - All hits:   every lookup finds a match (primary use case)
 *   - All misses: every lookup fails (negative filter use case)
 *   - Mixed:      50/50 hits and misses
 *
 * Reference:
 * Daniel Lemire, "Quickly checking that a string belongs to a small set,"
 * https://lemire.me/blog/2022/12/30/quickly-checking-that-a-string-belongs-to-a-small-set/
 */

#include <algorithm>
#include <cstdint>
#include <cstring>
#include <format>
#include <iostream>
#include <optional>
#include <print>
#include <random>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>
#include <ankerl/unordered_dense.h>
#include <absl/container/flat_hash_map.h>
#include <frozen/unordered_map.h>
#include <frozen/string.h>
#include "phf.hh"
#include "hashes.hh"

// ============================================================================
// Filter support: --filter hits,make_perfect_map,protocol
//   Workloads: hits, misses, mixed
//   Methods:   make_perfect_map, naive, unordered_map, ankerl, absl, frozen, kronuz, gperf
//   Keysets:   protocol, stock, keyword, header, mime
// Omitting a category means "run all" for that category.
// ============================================================================

struct BenchFilter {
  std::set<std::string> workloads; // hits, misses, mixed
  std::set<std::string> methods;   // make_perfect_map, naive, unordered_map
  std::set<std::string> keysets;   // protocol, stock, keyword, header, mime

  bool run_workload(const std::string &w) const {
    return workloads.empty() || workloads.count(w);
  }
  bool run_method(const std::string &m) const {
    return methods.empty() || methods.count(m);
  }
  bool run_keyset(const std::string &k) const {
    return keysets.empty() || keysets.count(k);
  }
};

BenchFilter parse_filter(const std::string &arg) {
  BenchFilter f;
  static const std::set<std::string> valid_workloads = {"hits", "misses", "mixed"};
  static const std::set<std::string> valid_methods = {"make_perfect_map", "naive", "unordered_map", "ankerl", "absl", "frozen", "kronuz", "gperf"};
  static const std::set<std::string> valid_keysets = {"protocol", "stock", "keyword", "header", "mime"};

  size_t start = 0;
  while (start < arg.size()) {
    size_t end = arg.find(',', start);
    if (end == std::string::npos) end = arg.size();
    std::string token = arg.substr(start, end - start);
    if (valid_workloads.count(token))      f.workloads.insert(token);
    else if (valid_methods.count(token))   f.methods.insert(token);
    else if (valid_keysets.count(token))    f.keysets.insert(token);
    else std::println(stderr, "Warning: unknown filter token '{}'", token);
    start = end + 1;
  }
  return f;
}

#include "ConstexprCore/perfect_hash.h"
#include "counters/bench.h"

namespace gperf_protocol {
#include "gperf/protocol_gperf.inc"
}
namespace gperf_stock {
#include "gperf/stock_gperf.inc"
}
namespace gperf_keyword {
#include "gperf/keyword_gperf.inc"
}
namespace gperf_header {
#include "gperf/header_gperf.inc"
}
namespace gperf_mime {
#include "gperf/mime_gperf.inc"
}

// ============================================================================
// Infrastructure
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
  std::print("  {:<48} : ", name);
  std::print(" {:6.3f} ns ", agg.fastest_elapsed_ns() / double(num_values));
  std::print(" {:5.2f} Gv/s", double(num_values) / agg.fastest_elapsed_ns());
  if (counters::has_performance_counters()) {
    std::print("  {:5.2f} c  {:5.2f} i  {:4.2f} i/c  {:4.2f} bm",
               agg.fastest_cycles() / double(num_values),
               agg.fastest_instructions() / double(num_values),
               agg.fastest_instructions() / double(agg.fastest_cycles()),
               agg.fastest_branch_misses() / double(num_values));
  }
  std::print("\n");
}

// Build a shuffled input vector from a pool of candidate strings.
std::vector<std::string_view> build_input(
    const std::vector<std::string_view> &pool, size_t count, uint64_t seed) {
  std::mt19937_64 gen(seed);
  std::vector<std::string_view> result;
  result.reserve(count);
  for (size_t i = 0; i < count; i++)
    result.push_back(pool[gen() % pool.size()]);
  return result;
}

// Generic benchmark: runs PHF, naive, and unordered_map on a given input vector.
template <typename PHFMap, typename NaiveFn, typename FrozenMap, typename KronuzPHF, typename GperfFn>
void bench_workload(const std::string &label,
                    std::vector<std::string_view> &input,
                    size_t num_strings,
                    const PHFMap &phf_map,
                    NaiveFn naive_fn,
                    const std::unordered_map<std::string_view, int> &uset,
                    const FrozenMap &frozen_map,
                    const KronuzPHF &kronuz_phf,
                    GperfFn gperf_fn,
                    const BenchFilter &filter) {
  std::vector<int> results(num_strings, 0);
  std::mt19937_64 gen(42);
  auto shuffle = [&]() {
    std::shuffle(input.begin(), input.end(), gen);
  };

  // make_perfect_map (perfect_hash_set-based, not NTTP constexpr_perfect_map)
  if (filter.run_method("make_perfect_map")) {
    gen.seed(42);
    auto phf_fn = [&]() {
      for (size_t i = 0; i < input.size(); i++) {
        auto opt = phf_map.lookup(input[i]);
        if (opt) results[i] = static_cast<int>(*opt);
      }
    };
    pretty_print(label + " make_perfect_map", num_strings,
                 shuffle_bench(phf_fn, shuffle));
    volatile auto sum = std::accumulate(results.begin(), results.end(), 0); // prevent optimization
  }

  // naive if/else
  if (filter.run_method("naive")) {
    gen.seed(42);
    auto naive_bench = [&]() {
      for (size_t i = 0; i < input.size(); i++) {
        auto opt = naive_fn(input[i]);
        if (opt) results[i] = *opt;
      }
    };
    pretty_print(label + " naive", num_strings,
                 shuffle_bench(naive_bench, shuffle));
    volatile auto sum = std::accumulate(results.begin(), results.end(), 0); // prevent optimization
  }

  // std::unordered_map
  if (filter.run_method("unordered_map")) {
    gen.seed(42);
    auto uset_fn = [&]() {
      for (size_t i = 0; i < input.size(); i++) {
        auto it = uset.find(input[i]);
        if (it != uset.end()) results[i] = it->second;
      }
    };
    pretty_print(label + " std::unordered_map", num_strings,
                 shuffle_bench(uset_fn, shuffle));
    volatile auto sum = std::accumulate(results.begin(), results.end(), 0); // prevent optimization
  }

  // ankerl::unordered_dense (fast flat hash map)
  if (filter.run_method("ankerl")) {
    static thread_local ankerl::unordered_dense::map<std::string_view, int> amap;
    if (amap.empty()) {
      for (auto& [k, v] : uset) amap[k] = v;
    }
    gen.seed(42);
    auto amap_fn = [&]() {
      for (size_t i = 0; i < input.size(); i++) {
        auto it = amap.find(input[i]);
        if (it != amap.end()) results[i] = it->second;
      }
    };
    pretty_print(label + " ankerl::dense", num_strings,
                 shuffle_bench(amap_fn, shuffle));
    volatile auto sum = std::accumulate(results.begin(), results.end(), 0); // prevent optimization
    amap.clear();
  }

  // absl::flat_hash_map (Google's SwissTable)
  if (filter.run_method("absl")) {
    static thread_local absl::flat_hash_map<std::string_view, int> absmap;
    if (absmap.empty()) {
      for (auto& [k, v] : uset) absmap[k] = v;
    }
    gen.seed(42);
    auto absmap_fn = [&]() {
      for (size_t i = 0; i < input.size(); i++) {
        auto it = absmap.find(input[i]);
        if (it != absmap.end()) results[i] = it->second;
      }
    };
    pretty_print(label + " absl::flat_hash_map", num_strings,
                 shuffle_bench(absmap_fn, shuffle));
    absmap.clear();
    volatile auto sum = std::accumulate(results.begin(), results.end(), 0); // prevent optimization
  }

  // frozen::unordered_map (compile-time perfect hash)
  if (filter.run_method("frozen")) {
    gen.seed(42);
    auto frozen_fn = [&]() {
      for (size_t i = 0; i < input.size(); i++) {
        auto it = frozen_map.find(frozen::string(input[i].data(), input[i].size()));
        if (it != frozen_map.end()) results[i] = it->second;
      }
    };
    pretty_print(label + " frozen::unordered_map", num_strings,
                 shuffle_bench(frozen_fn, shuffle));
    volatile auto sum = std::accumulate(results.begin(), results.end(), 0); // prevent optimization
  }

  // Kronuz constexpr-phf (hash-based perfect hash)
  if (filter.run_method("kronuz")) {
    gen.seed(42);
    auto kronuz_fn = [&]() {
      for (size_t i = 0; i < input.size(); i++) {
        auto h = fnv1ah32::hash(input[i].data(), input[i].size());
        auto pos = kronuz_phf.find(h);
        if (pos != phf::npos) results[i] = static_cast<int>(pos);
      }
    };
    pretty_print(label + " kronuz::phf", num_strings,
                 shuffle_bench(kronuz_fn, shuffle));
    volatile auto sum = std::accumulate(results.begin(), results.end(), 0); // prevent optimization
  }

  // gperf (GNU perfect hash)
  if (filter.run_method("gperf")) {
    gen.seed(42);
    auto gperf_bench = [&]() {
      for (size_t i = 0; i < input.size(); i++) {
        auto result = gperf_fn(input[i]);
        if (result) results[i] = *result;
      }
    };
    pretty_print(label + " gperf", num_strings,
                 shuffle_bench(gperf_bench, shuffle));
    volatile auto sum = std::accumulate(results.begin(), results.end(), 0); // prevent optimization
  }
}

// Run a full key-set benchmark with all three workload modes.
template <typename PHFMap, typename NaiveFn, typename FrozenMap, typename KronuzPHF, typename GperfFn>
void run_keyset(const std::string &name,
                const PHFMap &phf_map,
                NaiveFn naive_fn,
                const FrozenMap &frozen_map,
                const KronuzPHF &kronuz_phf,
                GperfFn gperf_fn,
                const std::vector<std::string_view> &hit_keys,
                const std::vector<std::string_view> &miss_keys,
                const BenchFilter &filter,
                size_t num_strings = 200000) {

  // Compute MaxKeyLen for display
  size_t max_len = 0;
  for (auto &k : hit_keys) max_len = std::max(max_len, k.size());

  std::println("\n=== {} (N={}, MaxKeyLen={}) ===", name, hit_keys.size(), max_len);

  // Build unordered_map baseline
  std::unordered_map<std::string_view, int> uset;
  for (size_t i = 0; i < hit_keys.size(); i++)
    uset[hit_keys[i]] = static_cast<int>(i);

  // Build workload vectors
  auto hits   = build_input(hit_keys, num_strings, 42);
  auto misses = build_input(miss_keys, num_strings, 42);

  // Mixed: 50/50 interleaved
  std::vector<std::string_view> mixed_pool;
  mixed_pool.insert(mixed_pool.end(), hit_keys.begin(), hit_keys.end());
  mixed_pool.insert(mixed_pool.end(), miss_keys.begin(), miss_keys.end());
  auto mixed = build_input(mixed_pool, num_strings, 42);

  if (filter.run_workload("hits")) {
    std::println("  --- all hits ---");
    bench_workload("hits  ", hits, num_strings, phf_map, naive_fn, uset, frozen_map, kronuz_phf, gperf_fn, filter);
  }
  if (filter.run_workload("misses")) {
    std::println("  --- all misses ---");
    bench_workload("misses", misses, num_strings, phf_map, naive_fn, uset, frozen_map, kronuz_phf, gperf_fn, filter);
  }
  if (filter.run_workload("mixed")) {
    std::println("  --- mixed (50/50) ---");
    bench_workload("mixed ", mixed, num_strings, phf_map, naive_fn, uset, frozen_map, kronuz_phf, gperf_fn, filter);
  }
}

// ============================================================================
// Key set 1: URL Protocols (6 keys, MaxKeyLen=5)
// ============================================================================

// Use make_perfect_map with overlap LDRH comparison — fastest for small sets
// with min_key_len >= 2 (two in-bounds halfword loads + single uint64 compare).
static constexpr auto protocol_phf =
    ConstexprCore::make_perfect_map<
        ConstexprCore::kv<"http", 0>,
        ConstexprCore::kv<"https", 1>,
        ConstexprCore::kv<"ftp", 2>,
        ConstexprCore::kv<"ws", 3>,
        ConstexprCore::kv<"wss", 4>,
        ConstexprCore::kv<"file", 5>>();

static constexpr frozen::unordered_map<frozen::string, int, 6> protocol_frozen = {
    {"http", 0}, {"https", 1}, {"ftp", 2},
    {"ws", 3}, {"wss", 4}, {"file", 5}
};

static constexpr auto protocol_kronuz = [] {
  fnv1ah32 h{};
  return phf::make_phf({h("http"), h("https"), h("ftp"), h("ws"), h("wss"), h("file")});
}();

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
// Key set 2: S&P 100 Stock Tickers (100 keys, MaxKeyLen=4)
// Large N, short keys — stress test for the PHF generator.
// Uses Hash-and-Displace algorithm (O(N) expected) for fast consteval.
// ============================================================================

static constexpr auto ticker_phf =
    ConstexprCore::make_perfect_map<
        ConstexprCore::kv<"AAPL",0>,ConstexprCore::kv<"ABBV",1>,
        ConstexprCore::kv<"ABT",2>,ConstexprCore::kv<"ACN",3>,
        ConstexprCore::kv<"ADBE",4>,ConstexprCore::kv<"AIG",5>,
        ConstexprCore::kv<"AMD",6>,ConstexprCore::kv<"AMGN",7>,
        ConstexprCore::kv<"AMT",8>,ConstexprCore::kv<"AMZN",9>,
        ConstexprCore::kv<"AVGO",10>,ConstexprCore::kv<"AXP",11>,
        ConstexprCore::kv<"BA",12>,ConstexprCore::kv<"BAC",13>,
        ConstexprCore::kv<"BK",14>,ConstexprCore::kv<"BKNG",15>,
        ConstexprCore::kv<"BLK",16>,ConstexprCore::kv<"BMY",17>,
        ConstexprCore::kv<"C",18>,ConstexprCore::kv<"CAT",19>,
        ConstexprCore::kv<"CHTR",20>,ConstexprCore::kv<"CL",21>,
        ConstexprCore::kv<"CMCSA",22>,ConstexprCore::kv<"COF",23>,
        ConstexprCore::kv<"COP",24>,ConstexprCore::kv<"COST",25>,
        ConstexprCore::kv<"CRM",26>,ConstexprCore::kv<"CSCO",27>,
        ConstexprCore::kv<"CVS",28>,ConstexprCore::kv<"CVX",29>,
        ConstexprCore::kv<"DE",30>,ConstexprCore::kv<"DHR",31>,
        ConstexprCore::kv<"DIS",32>,ConstexprCore::kv<"DOW",33>,
        ConstexprCore::kv<"DUK",34>,ConstexprCore::kv<"EMR",35>,
        ConstexprCore::kv<"EXC",36>,ConstexprCore::kv<"F",37>,
        ConstexprCore::kv<"FDX",38>,ConstexprCore::kv<"GD",39>,
        ConstexprCore::kv<"GE",40>,ConstexprCore::kv<"GILD",41>,
        ConstexprCore::kv<"GM",42>,ConstexprCore::kv<"GOOG",43>,
        ConstexprCore::kv<"GS",44>,ConstexprCore::kv<"HD",45>,
        ConstexprCore::kv<"HON",46>,ConstexprCore::kv<"IBM",47>,
        ConstexprCore::kv<"INTC",48>,ConstexprCore::kv<"INTU",49>,
        ConstexprCore::kv<"ISRG",50>,ConstexprCore::kv<"JNJ",51>,
        ConstexprCore::kv<"JPM",52>,ConstexprCore::kv<"KHC",53>,
        ConstexprCore::kv<"KO",54>,ConstexprCore::kv<"LIN",55>,
        ConstexprCore::kv<"LLY",56>,ConstexprCore::kv<"LMT",57>,
        ConstexprCore::kv<"LOW",58>,ConstexprCore::kv<"MA",59>,
        ConstexprCore::kv<"MCD",60>,ConstexprCore::kv<"MDLZ",61>,
        ConstexprCore::kv<"MDT",62>,ConstexprCore::kv<"MET",63>,
        ConstexprCore::kv<"META",64>,ConstexprCore::kv<"MMM",65>,
        ConstexprCore::kv<"MO",66>,ConstexprCore::kv<"MRK",67>,
        ConstexprCore::kv<"MS",68>,ConstexprCore::kv<"MSFT",69>,
        ConstexprCore::kv<"NEE",70>,ConstexprCore::kv<"NFLX",71>,
        ConstexprCore::kv<"NKE",72>,ConstexprCore::kv<"NVDA",73>,
        ConstexprCore::kv<"ORCL",74>,ConstexprCore::kv<"PEP",75>,
        ConstexprCore::kv<"PFE",76>,ConstexprCore::kv<"PG",77>,
        ConstexprCore::kv<"PM",78>,ConstexprCore::kv<"PYPL",79>,
        ConstexprCore::kv<"QCOM",80>,ConstexprCore::kv<"RTX",81>,
        ConstexprCore::kv<"SBUX",82>,ConstexprCore::kv<"SCHW",83>,
        ConstexprCore::kv<"SO",84>,ConstexprCore::kv<"SPG",85>,
        ConstexprCore::kv<"T",86>,ConstexprCore::kv<"TGT",87>,
        ConstexprCore::kv<"TMO",88>,ConstexprCore::kv<"TMUS",89>,
        ConstexprCore::kv<"TSLA",90>,ConstexprCore::kv<"TXN",91>,
        ConstexprCore::kv<"UNH",92>,ConstexprCore::kv<"UNP",93>,
        ConstexprCore::kv<"UPS",94>,ConstexprCore::kv<"USB",95>,
        ConstexprCore::kv<"V",96>,ConstexprCore::kv<"VZ",97>,
        ConstexprCore::kv<"WFC",98>,ConstexprCore::kv<"WMT",99>>();

static constexpr frozen::unordered_map<frozen::string, int, 100> ticker_frozen = {
    {"AAPL",0},{"ABBV",1},{"ABT",2},{"ACN",3},{"ADBE",4},{"AIG",5},{"AMD",6},{"AMGN",7},{"AMT",8},{"AMZN",9},
    {"AVGO",10},{"AXP",11},{"BA",12},{"BAC",13},{"BK",14},{"BKNG",15},{"BLK",16},{"BMY",17},{"C",18},{"CAT",19},
    {"CHTR",20},{"CL",21},{"CMCSA",22},{"COF",23},{"COP",24},{"COST",25},{"CRM",26},{"CSCO",27},{"CVS",28},{"CVX",29},
    {"DE",30},{"DHR",31},{"DIS",32},{"DOW",33},{"DUK",34},{"EMR",35},{"EXC",36},{"F",37},{"FDX",38},{"GD",39},
    {"GE",40},{"GILD",41},{"GM",42},{"GOOG",43},{"GS",44},{"HD",45},{"HON",46},{"IBM",47},{"INTC",48},{"INTU",49},
    {"ISRG",50},{"JNJ",51},{"JPM",52},{"KHC",53},{"KO",54},{"LIN",55},{"LLY",56},{"LMT",57},{"LOW",58},{"MA",59},
    {"MCD",60},{"MDLZ",61},{"MDT",62},{"MET",63},{"META",64},{"MMM",65},{"MO",66},{"MRK",67},{"MS",68},{"MSFT",69},
    {"NEE",70},{"NFLX",71},{"NKE",72},{"NVDA",73},{"ORCL",74},{"PEP",75},{"PFE",76},{"PG",77},{"PM",78},{"PYPL",79},
    {"QCOM",80},{"RTX",81},{"SBUX",82},{"SCHW",83},{"SO",84},{"SPG",85},{"T",86},{"TGT",87},{"TMO",88},{"TMUS",89},
    {"TSLA",90},{"TXN",91},{"UNH",92},{"UNP",93},{"UPS",94},{"USB",95},{"V",96},{"VZ",97},{"WFC",98},{"WMT",99}
};

static constexpr auto ticker_kronuz = [] {
  fnv1ah32 h{};
  return phf::make_phf({
    h("AAPL"),h("ABBV"),h("ABT"),h("ACN"),h("ADBE"),h("AIG"),h("AMD"),h("AMGN"),h("AMT"),h("AMZN"),
    h("AVGO"),h("AXP"),h("BA"),h("BAC"),h("BK"),h("BKNG"),h("BLK"),h("BMY"),h("C"),h("CAT"),
    h("CHTR"),h("CL"),h("CMCSA"),h("COF"),h("COP"),h("COST"),h("CRM"),h("CSCO"),h("CVS"),h("CVX"),
    h("DE"),h("DHR"),h("DIS"),h("DOW"),h("DUK"),h("EMR"),h("EXC"),h("F"),h("FDX"),h("GD"),
    h("GE"),h("GILD"),h("GM"),h("GOOG"),h("GS"),h("HD"),h("HON"),h("IBM"),h("INTC"),h("INTU"),
    h("ISRG"),h("JNJ"),h("JPM"),h("KHC"),h("KO"),h("LIN"),h("LLY"),h("LMT"),h("LOW"),h("MA"),
    h("MCD"),h("MDLZ"),h("MDT"),h("MET"),h("META"),h("MMM"),h("MO"),h("MRK"),h("MS"),h("MSFT"),
    h("NEE"),h("NFLX"),h("NKE"),h("NVDA"),h("ORCL"),h("PEP"),h("PFE"),h("PG"),h("PM"),h("PYPL"),
    h("QCOM"),h("RTX"),h("SBUX"),h("SCHW"),h("SO"),h("SPG"),h("T"),h("TGT"),h("TMO"),h("TMUS"),
    h("TSLA"),h("TXN"),h("UNH"),h("UNP"),h("UPS"),h("USB"),h("V"),h("VZ"),h("WFC"),h("WMT")
  });
}();

// Left here intentionally for dissambly inspection of the generated code.
std::optional<int> ticker_fancy(std::string_view s) {
  return ticker_phf.lookup(s);
}

std::optional<int> ticker_naive(std::string_view s) {
  // Binary search for 100 keys
  static constexpr std::array<std::string_view, 100> sorted = []() {
    std::array<std::string_view, 100> a = {
      "AAPL","ABBV","ABT","ACN","ADBE","AIG","AMD","AMGN","AMT","AMZN",
      "AVGO","AXP","BA","BAC","BK","BKNG","BLK","BMY","C","CAT",
      "CHTR","CL","CMCSA","COF","COP","COST","CRM","CSCO","CVS","CVX",
      "DE","DHR","DIS","DOW","DUK","EMR","EXC","F","FDX","GD",
      "GE","GILD","GM","GOOG","GS","HD","HON","IBM","INTC","INTU",
      "ISRG","JNJ","JPM","KHC","KO","LIN","LLY","LMT","LOW","MA",
      "MCD","MDLZ","MDT","MET","META","MMM","MO","MRK","MS","MSFT",
      "NEE","NFLX","NKE","NVDA","ORCL","PEP","PFE","PG","PM","PYPL",
      "QCOM","RTX","SBUX","SCHW","SO","SPG","T","TGT","TMO","TMUS",
      "TSLA","TXN","UNH","UNP","UPS","USB","V","VZ","WFC","WMT"
    };
    std::sort(a.begin(), a.end());
    return a;
  }();
  auto it = std::lower_bound(sorted.begin(), sorted.end(), s);
  if (it != sorted.end() && *it == s)
    return static_cast<int>(it - sorted.begin());
  return std::nullopt;
}

// ============================================================================
// Key set 3: C++ Keywords (15 keys, MaxKeyLen=6) — gperf mode
// ============================================================================

static constexpr auto keyword_phf =
    ConstexprCore::make_perfect_map<
        ConstexprCore::kv<"auto", 0>,   ConstexprCore::kv<"bool", 1>,
        ConstexprCore::kv<"break", 2>,  ConstexprCore::kv<"case", 3>,
        ConstexprCore::kv<"char", 4>,   ConstexprCore::kv<"class", 5>,
        ConstexprCore::kv<"const", 6>,  ConstexprCore::kv<"do", 7>,
        ConstexprCore::kv<"double", 8>, ConstexprCore::kv<"else", 9>,
        ConstexprCore::kv<"enum", 10>,  ConstexprCore::kv<"float", 11>,
        ConstexprCore::kv<"for", 12>,   ConstexprCore::kv<"goto", 13>,
        ConstexprCore::kv<"if", 14>>();

static constexpr frozen::unordered_map<frozen::string, int, 15> keyword_frozen = {
    {"auto", 0}, {"bool", 1}, {"break", 2}, {"case", 3},
    {"char", 4}, {"class", 5}, {"const", 6}, {"do", 7},
    {"double", 8}, {"else", 9}, {"enum", 10}, {"float", 11},
    {"for", 12}, {"goto", 13}, {"if", 14}
};

static constexpr auto keyword_kronuz = [] {
  fnv1ah32 h{};
  return phf::make_phf({
    h("auto"), h("bool"), h("break"), h("case"),
    h("char"), h("class"), h("const"), h("do"),
    h("double"), h("else"), h("enum"), h("float"),
    h("for"), h("goto"), h("if")
  });
}();

std::optional<int> keyword_naive(std::string_view s) {
  if (s == "auto") return 0;   if (s == "bool") return 1;
  if (s == "break") return 2;  if (s == "case") return 3;
  if (s == "char") return 4;   if (s == "class") return 5;
  if (s == "const") return 6;  if (s == "do") return 7;
  if (s == "double") return 8; if (s == "else") return 9;
  if (s == "enum") return 10;  if (s == "float") return 11;
  if (s == "for") return 12;   if (s == "goto") return 13;
  if (s == "if") return 14;
  return std::nullopt;
}

// ============================================================================
// Key set 4: HTTP Headers (20 keys, MaxKeyLen=17) — H&D mode
// ============================================================================

static constexpr auto header_phf =
    ConstexprCore::make_perfect_map<
        ConstexprCore::kv<"Accept", 0>,
        ConstexprCore::kv<"Accept-Encoding", 1>,
        ConstexprCore::kv<"Authorization", 2>,
        ConstexprCore::kv<"Cache-Control", 3>,
        ConstexprCore::kv<"Connection", 4>,
        ConstexprCore::kv<"Content-Length", 5>,
        ConstexprCore::kv<"Content-Type", 6>,
        ConstexprCore::kv<"Cookie", 7>,
        ConstexprCore::kv<"Date", 8>,
        ConstexprCore::kv<"Host", 9>,
        ConstexprCore::kv<"If-None-Match", 10>,
        ConstexprCore::kv<"Location", 11>,
        ConstexprCore::kv<"Origin", 12>,
        ConstexprCore::kv<"Referer", 13>,
        ConstexprCore::kv<"Server", 14>,
        ConstexprCore::kv<"Set-Cookie", 15>,
        ConstexprCore::kv<"User-Agent", 16>,
        ConstexprCore::kv<"Vary", 17>,
        ConstexprCore::kv<"Via", 18>,
        ConstexprCore::kv<"X-Forwarded-For", 19>>();

std::optional<int> header_fancy(std::string_view s) {
  return header_phf.lookup(s);
}

static constexpr frozen::unordered_map<frozen::string, int, 20> header_frozen = {
    {"Accept", 0}, {"Accept-Encoding", 1}, {"Authorization", 2},
    {"Cache-Control", 3}, {"Connection", 4}, {"Content-Length", 5},
    {"Content-Type", 6}, {"Cookie", 7}, {"Date", 8}, {"Host", 9},
    {"If-None-Match", 10}, {"Location", 11}, {"Origin", 12},
    {"Referer", 13}, {"Server", 14}, {"Set-Cookie", 15},
    {"User-Agent", 16}, {"Vary", 17}, {"Via", 18}, {"X-Forwarded-For", 19}
};

static constexpr auto header_kronuz = [] {
  fnv1ah32 h{};
  return phf::make_phf({
    h("Accept"), h("Accept-Encoding"), h("Authorization"),
    h("Cache-Control"), h("Connection"), h("Content-Length"),
    h("Content-Type"), h("Cookie"), h("Date"), h("Host"),
    h("If-None-Match"), h("Location"), h("Origin"),
    h("Referer"), h("Server"), h("Set-Cookie"),
    h("User-Agent"), h("Vary"), h("Via"), h("X-Forwarded-For")
  });
}();

std::optional<int> header_naive(std::string_view s) {
  if (s == "Accept") return 0;          if (s == "Accept-Encoding") return 1;
  if (s == "Authorization") return 2;   if (s == "Cache-Control") return 3;
  if (s == "Connection") return 4;      if (s == "Content-Length") return 5;
  if (s == "Content-Type") return 6;    if (s == "Cookie") return 7;
  if (s == "Date") return 8;            if (s == "Host") return 9;
  if (s == "If-None-Match") return 10;  if (s == "Location") return 11;
  if (s == "Origin") return 12;         if (s == "Referer") return 13;
  if (s == "Server") return 14;         if (s == "Set-Cookie") return 15;
  if (s == "User-Agent") return 16;     if (s == "Vary") return 17;
  if (s == "Via") return 18;            if (s == "X-Forwarded-For") return 19;
  return std::nullopt;
}

// ============================================================================
// Key set 5: MIME Types (15 keys, MaxKeyLen=24) — gperf mode (N=15)
// ============================================================================

static constexpr auto mime_phf =
    ConstexprCore::make_perfect_map<
        ConstexprCore::kv<"text/html", 0>,
        ConstexprCore::kv<"text/plain", 1>,
        ConstexprCore::kv<"text/css", 2>,
        ConstexprCore::kv<"application/json", 3>,
        ConstexprCore::kv<"application/xml", 4>,
        ConstexprCore::kv<"application/pdf", 5>,
        ConstexprCore::kv<"application/zip", 6>,
        ConstexprCore::kv<"image/png", 7>,
        ConstexprCore::kv<"image/jpeg", 8>,
        ConstexprCore::kv<"image/gif", 9>,
        ConstexprCore::kv<"image/webp", 10>,
        ConstexprCore::kv<"audio/mpeg", 11>,
        ConstexprCore::kv<"video/mp4", 12>,
        ConstexprCore::kv<"font/woff2", 13>,
        ConstexprCore::kv<"font/woff", 14>>();

// Left here intentionally for dissambly inspection of the generated code.
std::optional<int> mime_phf_lookup(std::string_view s) {
  return mime_phf.lookup(s);
}
static constexpr frozen::unordered_map<frozen::string, int, 15> mime_frozen = {
    {"text/html", 0}, {"text/plain", 1}, {"text/css", 2},
    {"application/json", 3}, {"application/xml", 4},
    {"application/pdf", 5}, {"application/zip", 6},
    {"image/png", 7}, {"image/jpeg", 8}, {"image/gif", 9},
    {"image/webp", 10}, {"audio/mpeg", 11}, {"video/mp4", 12},
    {"font/woff2", 13}, {"font/woff", 14}
};

static constexpr auto mime_kronuz = [] {
  fnv1ah32 h{};
  return phf::make_phf({
    h("text/html"), h("text/plain"), h("text/css"),
    h("application/json"), h("application/xml"),
    h("application/pdf"), h("application/zip"),
    h("image/png"), h("image/jpeg"), h("image/gif"),
    h("image/webp"), h("audio/mpeg"), h("video/mp4"),
    h("font/woff2"), h("font/woff")
  });
}();

std::optional<int> mime_naive(std::string_view s) {
  if (s == "text/html") return 0;         if (s == "text/plain") return 1;
  if (s == "text/css") return 2;           if (s == "application/json") return 3;
  if (s == "application/xml") return 4;    if (s == "application/pdf") return 5;
  if (s == "application/zip") return 6;    if (s == "image/png") return 7;
  if (s == "image/jpeg") return 8;         if (s == "image/gif") return 9;
  if (s == "image/webp") return 10;        if (s == "audio/mpeg") return 11;
  if (s == "video/mp4") return 12;         if (s == "font/woff2") return 13;
  if (s == "font/woff") return 14;
  return std::nullopt;
}

// ============================================================================
// Verification
// ============================================================================

template <typename PHFMap, typename NaiveFn, typename FrozenMap, typename KronuzPHF, typename GperfFn>
bool verify_keyset(const std::string &name,
                   const PHFMap &phf_map,
                   NaiveFn naive_fn,
                   const FrozenMap &frozen_map,
                   const KronuzPHF &kronuz_phf,
                   GperfFn gperf_fn,
                   const std::vector<std::string_view> &hit_keys,
                   const std::vector<std::string_view> &miss_keys) {
  bool ok = true;
  auto fail = [&](const std::string &msg) {
    std::println(stderr, "  FAIL [{}]: {}", name, msg);
    ok = false;
  };

  // Build reference map
  std::unordered_map<std::string_view, int> ref;
  for (size_t i = 0; i < hit_keys.size(); i++)
    ref[hit_keys[i]] = static_cast<int>(i);

  // Mixed pool: all hits then all misses
  std::vector<std::string_view> mixed_pool;
  mixed_pool.insert(mixed_pool.end(), hit_keys.begin(), hit_keys.end());
  mixed_pool.insert(mixed_pool.end(), miss_keys.begin(), miss_keys.end());

  for (auto &key : mixed_pool) {
    auto ref_it = ref.find(key);
    bool is_hit = ref_it != ref.end();
    int ref_val = is_hit ? ref_it->second : -1;

    // make_perfect_map
    auto phf_result = phf_map.lookup(key);
    if (is_hit) {
      if (!phf_result)
        fail(std::format("make_perfect_map: missed hit key '{}'", key));
      else if (static_cast<int>(*phf_result) != ref_val)
        fail(std::format("make_perfect_map: key '{}' got {} expected {}", key, static_cast<int>(*phf_result), ref_val));
    } else {
      if (phf_result)
        fail(std::format("make_perfect_map: false positive for miss key '{}'", key));
    }

    // naive
    auto naive_result = naive_fn(key);
    if (is_hit) {
      if (!naive_result)
        fail(std::format("naive: missed hit key '{}'", key));
      else if (*naive_result != ref_val)
        fail(std::format("naive: key '{}' got {} expected {}", key, *naive_result, ref_val));
    } else {
      if (naive_result)
        fail(std::format("naive: false positive for miss key '{}'", key));
    }

    // frozen
    auto frozen_it = frozen_map.find(frozen::string(key.data(), key.size()));
    if (is_hit) {
      if (frozen_it == frozen_map.end())
        fail(std::format("frozen: missed hit key '{}'", key));
      else if (frozen_it->second != ref_val)
        fail(std::format("frozen: key '{}' got {} expected {}", key, frozen_it->second, ref_val));
    } else {
      if (frozen_it != frozen_map.end())
        fail(std::format("frozen: false positive for miss key '{}'", key));
    }

    // kronuz (hash-based, only checks hit/miss — no value comparison)
    auto kronuz_hash = fnv1ah32::hash(key.data(), key.size());
    auto kronuz_pos = kronuz_phf.find(kronuz_hash);
    if (is_hit) {
      if (kronuz_pos == phf::npos)
        fail(std::format("kronuz: missed hit key '{}'", key));
    }
    // Note: kronuz may false-positive on misses due to hash collisions — not checked

    // gperf (returns first char of matched string, only checks hit/miss for value)
    auto gperf_result = gperf_fn(key);
    if (is_hit) {
      if (!gperf_result)
        fail(std::format("gperf: missed hit key '{}'", key));
    } else {
      if (gperf_result)
        fail(std::format("gperf: false positive for miss key '{}'", key));
    }
  }

  std::println("  {} {}", ok ? "OK" : "FAIL", name);
  return ok;
}

// ============================================================================
// Main
// ============================================================================

int main(int argc, char *argv[]) {
  if (!counters::has_performance_counters())
    std::println("Performance counters not available, run with sudo.");

  BenchFilter filter;
  bool verify = false;
  for (int i = 1; i < argc; i++) {
    std::string arg = argv[i];
    if (arg == "--help" || arg == "-h") {
      std::println("Usage: {} [OPTIONS]\n", argv[0]);
      std::println("Options:");
      std::println("  --filter <tokens>  Comma-separated list of filter tokens");
      std::println("  --verify, -V       Verify all maps return correct results");
      std::println("  --help, -h         Show this help message\n");
      std::println("Filter tokens (mix and match):");
      std::println("  Workloads: hits, misses, mixed");
      std::println("  Methods:   make_perfect_map, naive, unordered_map, ankerl, absl, frozen, kronuz, gperf");
      std::println("  Keysets:   protocol, stock, keyword, header, mime\n");
      std::println("Omitting a category runs all values for that category.\n");
      std::println("Examples:");
      std::println("  {} --filter hits,make_perfect_map,protocol", argv[0]);
      std::println("  {} --filter hits,misses,stock", argv[0]);
      std::println("  {} --verify", argv[0]);
      return 0;
    }
    if (arg == "--verify" || arg == "-V") {
      verify = true;
    }
    if (arg == "--filter" && i + 1 < argc) {
      filter = parse_filter(argv[++i]);
    }
  }

  // gperf wrapper: lookup returns const char* (null on miss) → std::optional<int>
  auto gperf_protocol = [](std::string_view s) -> std::optional<int> {
    auto r = gperf_protocol::ProtocolGperf::lookup(s.data(), s.size());
    return r ? std::optional<int>(static_cast<int>(r[0])) : std::nullopt;
  };
  auto gperf_stock = [](std::string_view s) -> std::optional<int> {
    auto r = gperf_stock::StockGperf::lookup(s.data(), s.size());
    return r ? std::optional<int>(static_cast<int>(r[0])) : std::nullopt;
  };
  auto gperf_keyword = [](std::string_view s) -> std::optional<int> {
    auto r = gperf_keyword::KeywordGperf::lookup(s.data(), s.size());
    return r ? std::optional<int>(static_cast<int>(r[0])) : std::nullopt;
  };
  auto gperf_header = [](std::string_view s) -> std::optional<int> {
    auto r = gperf_header::HeaderGperf::lookup(s.data(), s.size());
    return r ? std::optional<int>(static_cast<int>(r[0])) : std::nullopt;
  };
  auto gperf_mime = [](std::string_view s) -> std::optional<int> {
    auto r = gperf_mime::MimeGperf::lookup(s.data(), s.size());
    return r ? std::optional<int>(static_cast<int>(r[0])) : std::nullopt;
  };

  if (verify) {
    std::println("\n=== Verification ===");
    bool all_ok = true;
    all_ok &= verify_keyset("URL Protocols", protocol_phf, protocol_naive, protocol_frozen, protocol_kronuz, gperf_protocol,
      {"http","https","ftp","ws","wss","file"},
      {"ssh","telnet","mailto","data","blob","urn"});
    all_ok &= verify_keyset("S&P 100 Tickers", ticker_phf, ticker_naive, ticker_frozen, ticker_kronuz, gperf_stock,
      {"AAPL","ABBV","ABT","ACN","ADBE","AIG","AMD","AMGN","AMT","AMZN",
       "AVGO","AXP","BA","BAC","BK","BKNG","BLK","BMY","C","CAT",
       "CHTR","CL","CMCSA","COF","COP","COST","CRM","CSCO","CVS","CVX",
       "DE","DHR","DIS","DOW","DUK","EMR","EXC","F","FDX","GD",
       "GE","GILD","GM","GOOG","GS","HD","HON","IBM","INTC","INTU",
       "ISRG","JNJ","JPM","KHC","KO","LIN","LLY","LMT","LOW","MA",
       "MCD","MDLZ","MDT","MET","META","MMM","MO","MRK","MS","MSFT",
       "NEE","NFLX","NKE","NVDA","ORCL","PEP","PFE","PG","PM","PYPL",
       "QCOM","RTX","SBUX","SCHW","SO","SPG","T","TGT","TMO","TMUS",
       "TSLA","TXN","UNH","UNP","UPS","USB","V","VZ","WFC","WMT"},
      {"RIVN","PLTR","SNAP","UBER","LYFT","COIN","HOOD","DKNG","SOFI","RBLX",
       "ROKU","ZM","ABNB","DASH","CRWD","NET","SNOW","DDOG","MDB","PATH"});
    all_ok &= verify_keyset("C++ Keywords", keyword_phf, keyword_naive, keyword_frozen, keyword_kronuz, gperf_keyword,
      {"auto","bool","break","case","char","class","const",
       "do","double","else","enum","float","for","goto","if"},
      {"int","void","return","while","switch","struct","static",
       "extern","inline","virtual","public","private","throw","try","catch"});
    all_ok &= verify_keyset("HTTP Headers", header_phf, header_naive, header_frozen, header_kronuz, gperf_header,
      {"Accept","Accept-Encoding","Authorization","Cache-Control",
       "Connection","Content-Length","Content-Type","Cookie",
       "Date","Host","If-None-Match","Location","Origin","Referer",
       "Server","Set-Cookie","User-Agent","Vary","Via","X-Forwarded-For"},
      {"X-Request-Id","Forwarded","Alt-Svc","DNT","Upgrade-Insecure-Requests",
       "X-Frame-Options","Content-Security-Policy","Strict-Transport-Security",
       "Pragma","Warning"});
    all_ok &= verify_keyset("MIME Types", mime_phf, mime_naive, mime_frozen, mime_kronuz, gperf_mime,
      {"text/html","text/plain","text/css","application/json",
       "application/xml","application/pdf","application/zip",
       "image/png","image/jpeg","image/gif","image/webp",
       "audio/mpeg","video/mp4","font/woff2","font/woff"},
      {"text/xml","text/csv","application/gzip","application/wasm",
       "image/avif","image/tiff","audio/ogg","video/webm",
       "font/otf","application/x-www-form-urlencoded"});
    return all_ok ? 0 : 1;
  }

  // --- URL Protocols (6 keys, short) ---
  if (filter.run_keyset("protocol")) {
    run_keyset("URL Protocols", protocol_phf, protocol_naive, protocol_frozen, protocol_kronuz, gperf_protocol,
      {"http","https","ftp","ws","wss","file"},
      {"ssh","telnet","mailto","data","blob","urn"},
      filter);
  }

  // --- S&P 100 Stock Tickers (100 keys, short) ---
  if (filter.run_keyset("stock")) {
    run_keyset("S&P 100 Tickers", ticker_phf, ticker_naive, ticker_frozen, ticker_kronuz, gperf_stock,
      {"AAPL","ABBV","ABT","ACN","ADBE","AIG","AMD","AMGN","AMT","AMZN",
       "AVGO","AXP","BA","BAC","BK","BKNG","BLK","BMY","C","CAT",
       "CHTR","CL","CMCSA","COF","COP","COST","CRM","CSCO","CVS","CVX",
       "DE","DHR","DIS","DOW","DUK","EMR","EXC","F","FDX","GD",
       "GE","GILD","GM","GOOG","GS","HD","HON","IBM","INTC","INTU",
       "ISRG","JNJ","JPM","KHC","KO","LIN","LLY","LMT","LOW","MA",
       "MCD","MDLZ","MDT","MET","META","MMM","MO","MRK","MS","MSFT",
       "NEE","NFLX","NKE","NVDA","ORCL","PEP","PFE","PG","PM","PYPL",
       "QCOM","RTX","SBUX","SCHW","SO","SPG","T","TGT","TMO","TMUS",
       "TSLA","TXN","UNH","UNP","UPS","USB","V","VZ","WFC","WMT"},
      {"RIVN","PLTR","SNAP","UBER","LYFT","COIN","HOOD","DKNG","SOFI","RBLX",
       "ROKU","ZM","ABNB","DASH","CRWD","NET","SNOW","DDOG","MDB","PATH"},
      filter);
  }

  // --- C++ Keywords (15 keys, short-medium) ---
  if (filter.run_keyset("keyword")) {
    run_keyset("C++ Keywords", keyword_phf, keyword_naive, keyword_frozen, keyword_kronuz, gperf_keyword,
      {"auto","bool","break","case","char","class","const",
       "do","double","else","enum","float","for","goto","if"},
      {"int","void","return","while","switch","struct","static",
       "extern","inline","virtual","public","private","throw","try","catch"},
      filter);
  }

  // --- HTTP Headers (20 keys, long) ---
  if (filter.run_keyset("header")) {
    run_keyset("HTTP Headers", header_phf, header_naive, header_frozen, header_kronuz, gperf_header,
      {"Accept","Accept-Encoding","Authorization","Cache-Control",
       "Connection","Content-Length","Content-Type","Cookie",
       "Date","Host","If-None-Match","Location","Origin","Referer",
       "Server","Set-Cookie","User-Agent","Vary","Via","X-Forwarded-For"},
      {"X-Request-Id","Forwarded","Alt-Svc","DNT","Upgrade-Insecure-Requests",
       "X-Frame-Options","Content-Security-Policy","Strict-Transport-Security",
       "Pragma","Warning"},
      filter);
  }

  // --- MIME Types (15 keys, long) ---
  if (filter.run_keyset("mime")) {
    run_keyset("MIME Types", mime_phf, mime_naive, mime_frozen, mime_kronuz, gperf_mime,
      {"text/html","text/plain","text/css","application/json",
       "application/xml","application/pdf","application/zip",
       "image/png","image/jpeg","image/gif","image/webp",
       "audio/mpeg","video/mp4","font/woff2","font/woff"},
      {"text/xml","text/csv","application/gzip","application/wasm",
       "image/avif","image/tiff","audio/ogg","video/webm",
       "font/otf","application/x-www-form-urlencoded"},
      filter);
  }
}
