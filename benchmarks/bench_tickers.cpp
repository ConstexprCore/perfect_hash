// ============================================================================
// Ticker benchmarks: N > 255 key sets (S&P 500 = 503 keys, Nasdaq = 5581 keys)
//
// Our lane is the wide-mode container (make_wide_perfect_index_map). The
// competitors are the same field as bench_protocol plus the structures people
// actually reach for in order-book / feed-handler code:
//   * sorted array + binary search                      (binsearch)
//   * 27-ary array trie over [A-Z.]                      (trie)
//   * symbol packed into a u64 → integer hash map        (u64_absl, u64_ankerl, u64_umap)
// The u64 lanes use OUR page-safe SIMD packing, so they are measured on their
// table, not on a naive byte loop.
//
// Filter tokens: workloads hits,misses,mixed · methods wide,unordered_map,absl,
// ankerl,frozen,kronuz,gperf,pthash,binsearch,trie,u64_absl,u64_ankerl,u64_umap
// · keysets sp500,nasdaq.
// ============================================================================
#include <ConstexprCore/wide_perfect_hash.h>

#include <absl/container/flat_hash_map.h>
#include <ankerl/unordered_dense.h>
#include <frozen/string.h>
#include <frozen/unordered_map.h>
#include <phf.hh>
#include <hashes.hh>

#include <array>
#include <cstdio>
#include <optional>
#include <string_view>
#include <unordered_map>
#include <utility>
#include <vector>

#include "bench_common.h"
#include "pthash_wrapper.h"
#include "sp500_symbols.inc"
#include "nasdaq_symbols.inc"

namespace gperf_sp500 {
#include "sp500_gperf.inc"
}
#undef TOTAL_KEYWORDS
#undef MIN_WORD_LENGTH
#undef MAX_WORD_LENGTH
#undef MIN_HASH_VALUE
#undef MAX_HASH_VALUE
namespace gperf_nasdaq {
#include "nasdaq_gperf.inc"
}

#ifndef TICKERS_FROZEN_SP500
#define TICKERS_FROZEN_SP500 1
#endif
#ifndef TICKERS_FROZEN_NASDAQ
#define TICKERS_FROZEN_NASDAQ 1
#endif
#ifndef TICKERS_KRONUZ_NASDAQ
#define TICKERS_KRONUZ_NASDAQ 1
#endif

using benchx::run_method;

// ---------------------------------------------------------------------------
// ours
// ---------------------------------------------------------------------------
static constexpr auto sp500_wide = ConstexprCore::make_wide_perfect_index_map<sp500_symbols>();
static constexpr auto nasdaq_wide = ConstexprCore::make_wide_perfect_index_map<nasdaq_symbols>();

// ---------------------------------------------------------------------------
// frozen / kronuz (compile-time competitors)
// ---------------------------------------------------------------------------
template <std::size_t N, std::size_t... I>
constexpr auto make_frozen_pairs_impl(const std::array<std::string_view, N>& keys, std::index_sequence<I...>) {
  return std::array<std::pair<frozen::string, int>, N>{
      std::pair<frozen::string, int>{frozen::string(keys[I]), static_cast<int>(I)}...};
}
template <std::size_t N>
constexpr auto make_frozen_pairs(const std::array<std::string_view, N>& keys) {
  return make_frozen_pairs_impl(keys, std::make_index_sequence<N>{});
}
#if TICKERS_FROZEN_SP500
static constexpr auto sp500_frozen = frozen::make_unordered_map(make_frozen_pairs(sp500_symbols));
#endif
#if TICKERS_FROZEN_NASDAQ
static constexpr auto nasdaq_frozen = frozen::make_unordered_map(make_frozen_pairs(nasdaq_symbols));
#endif

template <std::size_t N>
struct hash_array { std::uint32_t v[N]; };
template <std::size_t N>
constexpr hash_array<N> make_fnv_hashes(const std::array<std::string_view, N>& keys) {
  hash_array<N> h{};
  for (std::size_t i = 0; i < N; ++i) h.v[i] = fnv1ah32::hash(keys[i].data(), keys[i].size());
  return h;
}
static constexpr auto sp500_fnv = make_fnv_hashes(sp500_symbols);
static constexpr auto sp500_kronuz = phf::make_phf(sp500_fnv.v);
#if TICKERS_KRONUZ_NASDAQ
static constexpr auto nasdaq_fnv = make_fnv_hashes(nasdaq_symbols);
static constexpr auto nasdaq_kronuz = phf::make_phf(nasdaq_fnv.v);
#endif

// ---------------------------------------------------------------------------
// order-book style baselines
// ---------------------------------------------------------------------------
// Symbol → u64 with the library's own page-safe masked load (length in the top byte).
static inline std::uint64_t pack_symbol(std::string_view s) noexcept {
  std::size_t len = s.size() <= 7 ? s.size() : 7;
  return ConstexprCore::detail::lane0(ConstexprCore::detail::load_chunk16(s.data(), len)) |
         (static_cast<std::uint64_t>(s.size() & 0xFF) << 56);
}

// 27-ary array trie over [A-Z.] (the classic feed-handler symbol table).
struct ArrayTrie {
  static constexpr int ALPHA = 27;
  std::vector<std::array<std::uint16_t, ALPHA>> next;   // 0 = no child
  std::vector<int> value;                                // -1 = not terminal
  static int idx(char c) noexcept { return c == '.' ? 26 : (c - 'A'); }
  void build(const std::vector<std::string_view>& keys) {
    next.assign(1, {}); value.assign(1, -1);
    for (std::size_t i = 0; i < keys.size(); ++i) {
      std::uint16_t node = 0;
      for (char c : keys[i]) {
        int k = idx(c);
        if (next[node][k] == 0) {
          next[node][k] = static_cast<std::uint16_t>(next.size());
          next.push_back({}); value.push_back(-1);
        }
        node = next[node][k];
      }
      value[node] = static_cast<int>(i);
    }
  }
  std::optional<int> find(std::string_view s) const noexcept {
    std::uint16_t node = 0;
    for (char c : s) {
      unsigned k = static_cast<unsigned>(c - 'A');
      if (c == '.') k = 26; else if (k >= 26) return std::nullopt;
      node = next[node][k];
      if (node == 0) return std::nullopt;
    }
    int v = value[node];
    return v >= 0 ? std::optional<int>{v} : std::nullopt;
  }
};

// ---------------------------------------------------------------------------
// one key set
// ---------------------------------------------------------------------------
template <typename Wide, typename FrozenT, typename KronuzT, typename GperfFn>
void run_keyset(const std::string& name, const Wide& wide, const FrozenT* frozen_map,
                const KronuzT* kronuz_map, GperfFn gperf_fn,
                const std::vector<std::string_view>& hits_pool,
                const std::vector<std::string_view>& miss_pool,
                const benchx::Filter& filter, bool describe, size_t num_strings = 200000) {
  std::size_t max_len = 0;
  for (auto& k : hits_pool) max_len = std::max(max_len, k.size());
  std::println("\n=== {} (N={}, MaxKeyLen={}) ===", name, hits_pool.size(), max_len);
  if (describe) std::println("  ours: {} | table {} | sizeof {} bytes", wide.algorithm_description(),
                             wide.table_size(), sizeof(wide));

  // runtime competitors
  std::unordered_map<std::string_view, int> umap;
  absl::flat_hash_map<std::string_view, int> amap;
  ankerl::unordered_dense::map<std::string_view, int> dmap;
  std::unordered_map<std::uint64_t, int> umap64;
  absl::flat_hash_map<std::uint64_t, int> amap64;
  ankerl::unordered_dense::map<std::uint64_t, int> dmap64;
  std::vector<std::string_view> sorted(hits_pool);
  std::sort(sorted.begin(), sorted.end());
  ArrayTrie trie; trie.build(hits_pool);
  PthashWrapper pthash_map; pthash_map.build(hits_pool);
  for (std::size_t i = 0; i < hits_pool.size(); ++i) {
    umap[hits_pool[i]] = amap[hits_pool[i]] = dmap[hits_pool[i]] = static_cast<int>(i);
    auto pk = pack_symbol(hits_pool[i]);
    umap64[pk] = amap64[pk] = dmap64[pk] = static_cast<int>(i);
  }

  auto hits = benchx::build_input(hits_pool, num_strings, 42);
  auto misses = benchx::build_input(miss_pool, num_strings, 42);
  std::vector<std::string_view> mixed_pool(hits_pool);
  mixed_pool.insert(mixed_pool.end(), miss_pool.begin(), miss_pool.end());
  auto mixed = benchx::build_input(mixed_pool, num_strings, 42);

  auto run = [&](const char* wl, std::vector<std::string_view>& input) {
    std::string L = std::string(wl) + " ";
    if (filter.method("wide"))
      run_method(L + "make_wide_perfect_map (" + std::string(wide.algorithm_name()) + ")", input,
                 [&](std::string_view s) { return wide.lookup(s); });
    if (filter.method("binsearch"))
      run_method(L + "sorted array + binary search", input, [&](std::string_view s) -> std::optional<int> {
        auto it = std::lower_bound(sorted.begin(), sorted.end(), s);
        if (it != sorted.end() && *it == s) return static_cast<int>(it - sorted.begin());
        return std::nullopt;
      });
    if (filter.method("trie"))
      run_method(L + "array trie (27-ary)", input, [&](std::string_view s) { return trie.find(s); });
    if (filter.method("unordered_map"))
      run_method(L + "std::unordered_map", input, [&](std::string_view s) -> std::optional<int> {
        auto it = umap.find(s); if (it != umap.end()) return it->second; return std::nullopt; });
    if (filter.method("absl"))
      run_method(L + "absl::flat_hash_map", input, [&](std::string_view s) -> std::optional<int> {
        auto it = amap.find(s); if (it != amap.end()) return it->second; return std::nullopt; });
    if (filter.method("ankerl"))
      run_method(L + "ankerl::dense", input, [&](std::string_view s) -> std::optional<int> {
        auto it = dmap.find(s); if (it != dmap.end()) return it->second; return std::nullopt; });
    if (filter.method("u64_umap"))
      run_method(L + "u64 symbol -> std::unordered_map", input, [&](std::string_view s) -> std::optional<int> {
        auto it = umap64.find(pack_symbol(s)); if (it != umap64.end()) return it->second; return std::nullopt; });
    if (filter.method("u64_absl"))
      run_method(L + "u64 symbol -> absl::flat_hash_map", input, [&](std::string_view s) -> std::optional<int> {
        auto it = amap64.find(pack_symbol(s)); if (it != amap64.end()) return it->second; return std::nullopt; });
    if (filter.method("u64_ankerl"))
      run_method(L + "u64 symbol -> ankerl::dense", input, [&](std::string_view s) -> std::optional<int> {
        auto it = dmap64.find(pack_symbol(s)); if (it != dmap64.end()) return it->second; return std::nullopt; });
    if (filter.method("frozen") && frozen_map)
      run_method(L + "frozen::unordered_map", input, [&](std::string_view s) -> std::optional<int> {
        auto it = frozen_map->find(frozen::string(s.data(), s.size()));
        if (it != frozen_map->end()) return it->second; return std::nullopt; });
    if (filter.method("kronuz") && kronuz_map)
      run_method(L + "kronuz::phf", input, [&](std::string_view s) -> std::optional<int> {
        auto pos = kronuz_map->find(fnv1ah32::hash(s.data(), s.size()));
        if (pos != phf::npos) return static_cast<int>(pos); return std::nullopt; });
    if (filter.method("gperf"))
      run_method(L + "gperf", input, gperf_fn);
    if (filter.method("pthash")) {
      std::vector<int> results(input.size(), 0);
      std::mt19937_64 gen(42);
      auto shuffle = [&]() { std::shuffle(input.begin(), input.end(), gen); };
      benchx::pretty_print(L + "pthash", input.size(),
                           benchx::shuffle_bench([&]() { pthash_map.bench_lookup(input, results); }, shuffle));
    }
  };
  if (filter.workload("hits"))   { std::println("  --- all hits ---");     run("hits  ", hits); }
  if (filter.workload("misses")) { std::println("  --- all misses ---");   run("misses", misses); }
  if (filter.workload("mixed"))  { std::println("  --- mixed (50/50) ---"); run("mixed ", mixed); }
}

template <typename Wide>
bool verify(const std::string& name, const Wide& wide, const std::vector<std::string_view>& hits,
            const std::vector<std::string_view>& misses) {
  bool ok = true;
  for (std::size_t i = 0; i < hits.size(); ++i) {
    auto v = wide.lookup(hits[i]);
    if (!v || *v != i) { std::println(stderr, "  FAIL [{}]: hit '{}' -> {}", name, hits[i], v ? int(*v) : -1); ok = false; }
  }
  for (auto m : misses)
    if (wide.lookup(m)) { std::println(stderr, "  FAIL [{}]: false positive '{}'", name, m); ok = false; }
  std::println("  {} {}", ok ? "OK" : "FAIL", name);
  return ok;
}

int main(int argc, char* argv[]) {
  if (!counters::has_performance_counters())
    std::println("Performance counters not available, run with sudo.");
  static const std::set<std::string> WL = {"hits", "misses", "mixed"};
  static const std::set<std::string> METHODS = {"wide", "unordered_map", "absl", "ankerl", "frozen", "kronuz",
                                                "gperf", "pthash", "binsearch", "trie", "u64_absl",
                                                "u64_ankerl", "u64_umap"};
  static const std::set<std::string> KEYSETS = {"sp500", "nasdaq"};
  benchx::Filter filter;
  bool do_verify = false, describe = false;
  for (int i = 1; i < argc; i++) {
    std::string arg = argv[i];
    if (arg == "--help" || arg == "-h") {
      std::println("Usage: {} [--filter tok,tok,...] [--verify] [--describe]", argv[0]);
      std::println("  workloads: hits misses mixed");
      std::println("  methods:   wide unordered_map absl ankerl frozen kronuz gperf pthash binsearch trie u64_absl u64_ankerl u64_umap");
      std::println("  keysets:   sp500 nasdaq");
      return 0;
    }
    if (arg == "--verify" || arg == "-V") do_verify = true;
    if (arg == "--describe" || arg == "-D") describe = true;
    if (arg == "--filter" && i + 1 < argc) filter = benchx::parse_filter(argv[++i], WL, METHODS, KEYSETS);
  }

  std::vector<std::string_view> sp500_hits(sp500_symbols.begin(), sp500_symbols.end());
  std::vector<std::string_view> sp500_miss(sp500_miss_symbols.begin(), sp500_miss_symbols.end());
  std::vector<std::string_view> nasdaq_hits(nasdaq_symbols.begin(), nasdaq_symbols.end());
  std::vector<std::string_view> nasdaq_miss(nasdaq_miss_symbols.begin(), nasdaq_miss_symbols.end());

  auto gperf_sp500_fn = [](std::string_view s) -> std::optional<int> {
    auto r = gperf_sp500::Sp500Gperf::lookup(s.data(), s.size());
    return r ? std::optional<int>(static_cast<int>(r[0])) : std::nullopt;
  };
  auto gperf_nasdaq_fn = [](std::string_view s) -> std::optional<int> {
    auto r = gperf_nasdaq::NasdaqGperf::lookup(s.data(), s.size());
    return r ? std::optional<int>(static_cast<int>(r[0])) : std::nullopt;
  };

  if (do_verify) {
    bool ok = true;
    ok &= verify("S&P 500", sp500_wide, sp500_hits, sp500_miss);
    ok &= verify("Nasdaq", nasdaq_wide, nasdaq_hits, nasdaq_miss);
    return ok ? 0 : 1;
  }

#if TICKERS_FROZEN_SP500
  const auto* sp500_frozen_p = &sp500_frozen;
#else
  const decltype(sp500_kronuz)* sp500_frozen_p = nullptr;   // placeholder type, never used
#endif
#if TICKERS_FROZEN_NASDAQ
  const auto* nasdaq_frozen_p = &nasdaq_frozen;
#else
  const decltype(sp500_kronuz)* nasdaq_frozen_p = nullptr;
#endif
#if TICKERS_KRONUZ_NASDAQ
  const auto* nasdaq_kronuz_p = &nasdaq_kronuz;
#else
  const decltype(sp500_kronuz)* nasdaq_kronuz_p = nullptr;
#endif

  if (filter.keyset("sp500"))
    run_keyset("S&P 500 Tickers", sp500_wide, sp500_frozen_p, &sp500_kronuz, gperf_sp500_fn, sp500_hits,
               sp500_miss, filter, describe);
  if (filter.keyset("nasdaq"))
    run_keyset("Nasdaq-listed Tickers", nasdaq_wide, nasdaq_frozen_p, nasdaq_kronuz_p, gperf_nasdaq_fn,
               nasdaq_hits, nasdaq_miss, filter, describe);
  return 0;
}
