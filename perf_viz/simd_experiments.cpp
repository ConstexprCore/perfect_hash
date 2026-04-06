/**
 * SIMD exploration experiments for ARM64 NEON — ALL key sets.
 *
 * Experiments:
 *   Exp 2:   NEON vceqq for MIME (MaxKeyLen=16)
 *   Exp 6:   NEON vceqq for Headers (MaxKeyLen=15, padded stored keys)
 *   Exp 7:   NEON TBL → uint64 extraction for MaxKeyLen ≤ 8
 *            (Protocols, Keywords, Tickers)
 *   Exp 8:   NEON vceqq universal for MaxKeyLen ≤ 8
 *            (compare against padded 16B stored keys)
 *   Exp 9:   NEON EOR+UMAXV for Headers (MaxKeyLen=15)
 */
#include <string>
#include <algorithm>
#include <cstdint>
#include <cstring>
#include <optional>
#include <print>
#include <random>
#include <vector>

#include "ConstexprCore/perfect_hash.h"
#include "counters/bench.h"

#ifdef __aarch64__
#include <arm_neon.h>
#endif

template <class F1, class F2>
counters::event_aggregate shuffle_bench(F1 &&f1, F2 &&f2, size_t n = 300) {
  static thread_local counters::event_collector collector;
  counters::event_aggregate agg{};
  for (size_t i = 0; i < n; i++) {
    collector.start(); f1(); agg << collector.end(); f2();
  }
  return agg;
}

void pp(const std::string &name, size_t n, counters::event_aggregate agg) {
  std::print("  {:<50s} : {:5.3f} ns", name, agg.fastest_elapsed_ns() / double(n));
  if (counters::has_performance_counters())
    std::print("  {:5.0f} i  {:4.2f} i/c  {:4.2f} bm",
      agg.fastest_instructions() / double(n),
      agg.fastest_instructions() / double(agg.fastest_cycles()),
      agg.fastest_branch_misses() / double(n));
  std::print("\n");
}

// ============================================================================
// Key sets
// ============================================================================

// Protocols (N=6, MaxKeyLen=5, min_key_len=2, gperf)
static constexpr auto protocols = ConstexprCore::make_perfect_map<
    ConstexprCore::kv<"http",0>,ConstexprCore::kv<"https",1>,
    ConstexprCore::kv<"ftp",2>,ConstexprCore::kv<"ws",3>,
    ConstexprCore::kv<"wss",4>,ConstexprCore::kv<"file",5>>();

// C++ Keywords (N=15, MaxKeyLen=6, min_key_len=2, gperf)
static constexpr auto keywords = ConstexprCore::make_perfect_map<
    ConstexprCore::kv<"auto",0>,ConstexprCore::kv<"bool",1>,
    ConstexprCore::kv<"break",2>,ConstexprCore::kv<"case",3>,
    ConstexprCore::kv<"char",4>,ConstexprCore::kv<"class",5>,
    ConstexprCore::kv<"const",6>,ConstexprCore::kv<"do",7>,
    ConstexprCore::kv<"double",8>,ConstexprCore::kv<"else",9>,
    ConstexprCore::kv<"enum",10>,ConstexprCore::kv<"float",11>,
    ConstexprCore::kv<"for",12>,ConstexprCore::kv<"goto",13>,
    ConstexprCore::kv<"if",14>>();

// S&P 100 Stock Tickers (N=100, MaxKeyLen=5, min_key_len=1, H&D)
static constexpr auto tickers = ConstexprCore::make_perfect_map<
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

// HTTP Headers (N=20, MaxKeyLen=15, min_key_len=3, gperf)
static constexpr auto headers = ConstexprCore::make_perfect_map<
    ConstexprCore::kv<"Accept",0>,ConstexprCore::kv<"Accept-Encoding",1>,
    ConstexprCore::kv<"Authorization",2>,ConstexprCore::kv<"Cache-Control",3>,
    ConstexprCore::kv<"Connection",4>,ConstexprCore::kv<"Content-Length",5>,
    ConstexprCore::kv<"Content-Type",6>,ConstexprCore::kv<"Cookie",7>,
    ConstexprCore::kv<"Date",8>,ConstexprCore::kv<"Host",9>,
    ConstexprCore::kv<"If-None-Match",10>,ConstexprCore::kv<"Location",11>,
    ConstexprCore::kv<"Origin",12>,ConstexprCore::kv<"Referer",13>,
    ConstexprCore::kv<"Server",14>,ConstexprCore::kv<"Set-Cookie",15>,
    ConstexprCore::kv<"User-Agent",16>,ConstexprCore::kv<"Vary",17>,
    ConstexprCore::kv<"Via",18>,ConstexprCore::kv<"X-Forwarded-For",19>>();

// MIME Types (N=15, MaxKeyLen=16, min_key_len=8, gperf)
static constexpr auto mime = ConstexprCore::make_perfect_map<
    ConstexprCore::kv<"text/html",0>,ConstexprCore::kv<"text/plain",1>,
    ConstexprCore::kv<"text/css",2>,ConstexprCore::kv<"application/json",3>,
    ConstexprCore::kv<"application/xml",4>,ConstexprCore::kv<"application/pdf",5>,
    ConstexprCore::kv<"application/zip",6>,ConstexprCore::kv<"image/png",7>,
    ConstexprCore::kv<"image/jpeg",8>,ConstexprCore::kv<"image/gif",9>,
    ConstexprCore::kv<"image/webp",10>,ConstexprCore::kv<"audio/mpeg",11>,
    ConstexprCore::kv<"video/mp4",12>,ConstexprCore::kv<"font/woff2",13>,
    ConstexprCore::kv<"font/woff",14>>();

std::vector<std::string_view> make_input(const std::vector<std::string_view>& keys, size_t n) {
  std::mt19937_64 gen(42);
  std::vector<std::string_view> v;
  v.reserve(n);
  for (size_t i = 0; i < n; i++) v.push_back(keys[gen() % keys.size()]);
  return v;
}

int main() {
  if (!counters::has_performance_counters())
    std::println("No perf counters — run with sudo.");

  constexpr size_t N = 200000;

  auto proto_keys = make_input({"http","https","ftp","ws","wss","file"}, N);
  auto kw_keys = make_input({"auto","bool","break","case","char","class","const",
    "do","double","else","enum","float","for","goto","if"}, N);
  auto ticker_keys = make_input({
    "AAPL","ABBV","ABT","ACN","ADBE","AIG","AMD","AMGN","AMT","AMZN",
    "AVGO","AXP","BA","BAC","BK","BKNG","BLK","BMY","C","CAT",
    "CHTR","CL","CMCSA","COF","COP","COST","CRM","CSCO","CVS","CVX",
    "DE","DHR","DIS","DOW","DUK","EMR","EXC","F","FDX","GD",
    "GE","GILD","GM","GOOG","GS","HD","HON","IBM","INTC","INTU",
    "ISRG","JNJ","JPM","KHC","KO","LIN","LLY","LMT","LOW","MA",
    "MCD","MDLZ","MDT","MET","META","MMM","MO","MRK","MS","MSFT",
    "NEE","NFLX","NKE","NVDA","ORCL","PEP","PFE","PG","PM","PYPL",
    "QCOM","RTX","SBUX","SCHW","SO","SPG","T","TGT","TMO","TMUS",
    "TSLA","TXN","UNH","UNP","UPS","USB","V","VZ","WFC","WMT"}, N);
  auto header_keys = make_input({"Accept","Accept-Encoding","Authorization",
    "Cache-Control","Connection","Content-Length","Content-Type","Cookie",
    "Date","Host","If-None-Match","Location","Origin","Referer",
    "Server","Set-Cookie","User-Agent","Vary","Via","X-Forwarded-For"}, N);
  auto mime_keys = make_input({"text/html","text/plain","text/css",
    "application/json","application/xml","application/pdf","application/zip",
    "image/png","image/jpeg","image/gif","image/webp","audio/mpeg",
    "video/mp4","font/woff2","font/woff"}, N);

  std::mt19937_64 gen(42);
  auto shuffle_proto   = [&]() { std::shuffle(proto_keys.begin(), proto_keys.end(), gen); };
  auto shuffle_kw      = [&]() { std::shuffle(kw_keys.begin(), kw_keys.end(), gen); };
  auto shuffle_tickers = [&]() { std::shuffle(ticker_keys.begin(), ticker_keys.end(), gen); };
  auto shuffle_hdrs    = [&]() { std::shuffle(header_keys.begin(), header_keys.end(), gen); };
  auto shuffle_mime    = [&]() { std::shuffle(mime_keys.begin(), mime_keys.end(), gen); };
  volatile uint64_t sink = 0;

  // ========================================================================
  // BASELINES — library contains() for all key sets
  // ========================================================================
  std::println("=== BASELINES (library contains) ===");

  gen.seed(42);
  pp("Protocols  (N=6,  MKL=5,  gperf)", N, shuffle_bench([&](){
    for (size_t i = 0; i < proto_keys.size(); i++)
      sink = sink + protocols.contains(proto_keys[i]);
  }, shuffle_proto));

  gen.seed(42);
  pp("Keywords   (N=15, MKL=6,  gperf)", N, shuffle_bench([&](){
    for (size_t i = 0; i < kw_keys.size(); i++)
      sink = sink +keywords.contains(kw_keys[i]);
  }, shuffle_kw));

  gen.seed(42);
  pp("Tickers    (N=100,MKL=5,  H&D)  ", N, shuffle_bench([&](){
    for (size_t i = 0; i < ticker_keys.size(); i++)
      sink = sink +tickers.contains(ticker_keys[i]);
  }, shuffle_tickers));

  gen.seed(42);
  pp("Headers    (N=20, MKL=15, gperf)", N, shuffle_bench([&](){
    for (size_t i = 0; i < header_keys.size(); i++)
      sink = sink +headers.contains(header_keys[i]);
  }, shuffle_hdrs));

  gen.seed(42);
  pp("MIME       (N=15, MKL=16, gperf)", N, shuffle_bench([&](){
    for (size_t i = 0; i < mime_keys.size(); i++)
      sink = sink +mime.contains(mime_keys[i]);
  }, shuffle_mime));

#ifdef __aarch64__
  static constexpr auto& ps = protocols.set_;
  static constexpr auto& ks = keywords.set_;
  static constexpr auto& ts = tickers.set_;
  static constexpr auto& hs = headers.set_;
  static constexpr auto& ms = mime.set_;

  // Precomputed TBL index vectors for each possible length (0-16)
  // TBL automatically produces 0 for out-of-range indices (>= 16).
  static const uint8x16_t tbl_masks[17] = {
    {0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {0,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {0,1,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {0,1,2,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {0,1,2,3,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {0,1,2,3,4,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {0,1,2,3,4,5,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {0,1,2,3,4,5,6,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {0,1,2,3,4,5,6,7,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {0,1,2,3,4,5,6,7,8,0x80,0x80,0x80,0x80,0x80,0x80,0x80},
    {0,1,2,3,4,5,6,7,8,9,0x80,0x80,0x80,0x80,0x80,0x80},
    {0,1,2,3,4,5,6,7,8,9,10,0x80,0x80,0x80,0x80,0x80},
    {0,1,2,3,4,5,6,7,8,9,10,11,0x80,0x80,0x80,0x80},
    {0,1,2,3,4,5,6,7,8,9,10,11,12,0x80,0x80,0x80},
    {0,1,2,3,4,5,6,7,8,9,10,11,12,13,0x80,0x80},
    {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,0x80},
    {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15},
  };

  // Helper: page-safe 16-byte NEON load + TBL mask
  auto neon_load_masked = [](const char* data, size_t len) __attribute__((always_inline)) -> uint8x16_t {
    uint8x16_t raw;
    uintptr_t addr = reinterpret_cast<uintptr_t>(data);
    if (__builtin_expect((addr & 16383) <= 16368, 1)) {
      raw = vld1q_u8(reinterpret_cast<const uint8_t*>(data));
    } else {
      alignas(16) uint8_t buf[16] = {};
      std::memcpy(buf, data, len);
      raw = vld1q_u8(buf);
    }
    return vqtbl1q_u8(raw, tbl_masks[len]);
  };

  // ========================================================================
  // Precompute 16-byte padded stored keys for headers (MaxKeyLen=15).
  // Needed because slot_key_data_ is only 15 bytes per slot — loading 16
  // bytes would read one garbage byte from the next slot.
  // ========================================================================
  constexpr size_t HDR_TS = headers.set_.table_size();
  alignas(16) uint8_t hdr_stored16[HDR_TS][16] = {};
  for (size_t s = 0; s < HDR_TS; s++)
    std::memcpy(hdr_stored16[s], hs.slot_key_data_[s].data(), 15);

  // ========================================================================
  // EXP 6: NEON vceqq for Headers (MaxKeyLen=15)
  // Same approach as Exp 2 (MIME), but with padded stored keys.
  // ========================================================================
  std::println("\n=== EXP 6: NEON vceqq for Headers (MaxKeyLen=15) ===");

  gen.seed(42);
  pp("Headers NEON vceqq 16B (padded)", N, shuffle_bench([&](){
    for (size_t i = 0; i < header_keys.size(); i++) {
      auto key = header_keys[i];
      auto len = key.size();
      if (len == 0 || len > 15) { continue; }
      auto slot = hs.compute_hash(key);
      auto expected_len = hs.slot_key_len_[slot];
      uint8x16_t stored = vld1q_u8(hdr_stored16[slot]);
      uint8x16_t masked = neon_load_masked(key.data(), len);
      uint8x16_t cmp = vceqq_u8(stored, masked);
      uint8x8_t min8 = vand_u8(vget_low_u8(cmp), vget_high_u8(cmp));
      uint64_t all_eq = vget_lane_u64(vreinterpret_u64_u8(min8), 0);
      bool len_ok = (expected_len == static_cast<uint8_t>(len));
      bool key_ok = (all_eq == ~0ULL);
      sink = sink +(len_ok & key_ok);
    }
  }, shuffle_hdrs));

  // ========================================================================
  // EXP 2 (re-run): NEON vceqq for MIME (MaxKeyLen=16)
  // Baseline comparison — slot_key_data_ is already 16 bytes.
  // ========================================================================
  std::println("\n=== EXP 2 (re-run): NEON vceqq for MIME (MaxKeyLen=16) ===");

  gen.seed(42);
  pp("MIME NEON vceqq 16B", N, shuffle_bench([&](){
    for (size_t i = 0; i < mime_keys.size(); i++) {
      auto key = mime_keys[i];
      auto len = key.size();
      if (len == 0 || len > 16) { continue; }
      auto slot = ms.compute_hash(key);
      auto expected_len = ms.slot_key_len_[slot];
      uint8x16_t stored = vld1q_u8(reinterpret_cast<const uint8_t*>(
          ms.slot_key_data_[slot].data()));
      uint8x16_t masked = neon_load_masked(key.data(), len);
      uint8x16_t cmp = vceqq_u8(stored, masked);
      uint8x8_t min8 = vand_u8(vget_low_u8(cmp), vget_high_u8(cmp));
      uint64_t all_eq = vget_lane_u64(vreinterpret_u64_u8(min8), 0);
      bool len_ok = (expected_len == static_cast<uint8_t>(len));
      bool key_ok = (all_eq == ~0ULL);
      sink = sink +(len_ok & key_ok);
    }
  }, shuffle_mime));

  // ========================================================================
  // EXP 7: NEON TBL → uint64 extraction for MaxKeyLen ≤ 8
  //
  // Idea: Replace the safe_byte packing chain (5-6 × safe_byte = 30-36 insn)
  // with NEON: vld1q(16B) + vqtbl1q(mask to len bytes) + extract lower u64.
  // Compare resulting uint64 against packed_keys_ (same byte encoding on LE).
  // This replaces O(MaxKeyLen) safe_byte calls with ~5 NEON instructions.
  // ========================================================================
  std::println("\n=== EXP 7: NEON TBL → uint64 for MaxKeyLen ≤ 8 ===");

  // Protocols (MaxKeyLen=5)
  gen.seed(42);
  pp("Protocols NEON TBL→u64 (MKL=5)", N, shuffle_bench([&](){
    for (size_t i = 0; i < proto_keys.size(); i++) {
      auto key = proto_keys[i];
      auto len = key.size();
      if (len == 0 || len > 5) { continue; }
      auto slot = ps.compute_hash(key);
      auto expected_len = ps.slot_key_len_[slot];
      uint8x16_t masked = neon_load_masked(key.data(), len);
      uint64_t input_packed = vget_lane_u64(vreinterpret_u64_u8(vget_low_u8(masked)), 0);
      bool len_ok = (expected_len == static_cast<uint8_t>(len));
      bool key_ok = (input_packed == ps.packed_keys_[slot]);
      sink = sink +(len_ok & key_ok);
    }
  }, shuffle_proto));

  // Keywords (MaxKeyLen=6)
  gen.seed(42);
  pp("Keywords NEON TBL→u64 (MKL=6)", N, shuffle_bench([&](){
    for (size_t i = 0; i < kw_keys.size(); i++) {
      auto key = kw_keys[i];
      auto len = key.size();
      if (len == 0 || len > 6) { continue; }
      auto slot = ks.compute_hash(key);
      auto expected_len = ks.slot_key_len_[slot];
      uint8x16_t masked = neon_load_masked(key.data(), len);
      uint64_t input_packed = vget_lane_u64(vreinterpret_u64_u8(vget_low_u8(masked)), 0);
      bool len_ok = (expected_len == static_cast<uint8_t>(len));
      bool key_ok = (input_packed == ks.packed_keys_[slot]);
      sink = sink +(len_ok & key_ok);
    }
  }, shuffle_kw));

  // Tickers (MaxKeyLen=5, H&D mode)
  gen.seed(42);
  pp("Tickers NEON TBL→u64 (MKL=5,H&D)", N, shuffle_bench([&](){
    for (size_t i = 0; i < ticker_keys.size(); i++) {
      auto key = ticker_keys[i];
      auto len = key.size();
      if (len == 0 || len > 5) { continue; }
      auto slot = ts.compute_hash(key);
      auto expected_len = ts.slot_key_len_[slot];
      uint8x16_t masked = neon_load_masked(key.data(), len);
      uint64_t input_packed = vget_lane_u64(vreinterpret_u64_u8(vget_low_u8(masked)), 0);
      bool len_ok = (expected_len == static_cast<uint8_t>(len));
      bool key_ok = (input_packed == ts.packed_keys_[slot]);
      sink = sink +(len_ok & key_ok);
    }
  }, shuffle_tickers));

  // ========================================================================
  // EXP 8: NEON vceqq universal for MaxKeyLen ≤ 8
  //
  // Same as Exp 7 but uses vceqq against padded 16B stored keys instead of
  // uint64 extraction. Tests whether full NEON comparison is better even
  // for small keys.
  // ========================================================================
  std::println("\n=== EXP 8: NEON vceqq universal for MaxKeyLen ≤ 8 ===");

  // Precompute 16B padded stored keys for protocols, keywords, tickers
  constexpr size_t PROTO_TS = protocols.set_.table_size();
  constexpr size_t KW_TS = keywords.set_.table_size();
  constexpr size_t TICK_TS = tickers.set_.table_size();

  alignas(16) uint8_t proto_stored16[PROTO_TS][16] = {};
  alignas(16) uint8_t kw_stored16[KW_TS][16] = {};
  alignas(16) uint8_t tick_stored16[TICK_TS][16] = {};

  for (size_t s = 0; s < PROTO_TS; s++)
    std::memcpy(proto_stored16[s], ps.slot_key_data_[s].data(), 5);
  for (size_t s = 0; s < KW_TS; s++)
    std::memcpy(kw_stored16[s], ks.slot_key_data_[s].data(), 6);
  for (size_t s = 0; s < TICK_TS; s++)
    std::memcpy(tick_stored16[s], ts.slot_key_data_[s].data(), 5);

  // Protocols vceqq
  gen.seed(42);
  pp("Protocols NEON vceqq 16B (MKL=5)", N, shuffle_bench([&](){
    for (size_t i = 0; i < proto_keys.size(); i++) {
      auto key = proto_keys[i];
      auto len = key.size();
      if (len == 0 || len > 5) { continue; }
      auto slot = ps.compute_hash(key);
      auto expected_len = ps.slot_key_len_[slot];
      uint8x16_t stored = vld1q_u8(proto_stored16[slot]);
      uint8x16_t masked = neon_load_masked(key.data(), len);
      uint8x16_t cmp = vceqq_u8(stored, masked);
      uint8x8_t min8 = vand_u8(vget_low_u8(cmp), vget_high_u8(cmp));
      uint64_t all_eq = vget_lane_u64(vreinterpret_u64_u8(min8), 0);
      bool len_ok = (expected_len == static_cast<uint8_t>(len));
      bool key_ok = (all_eq == ~0ULL);
      sink = sink +(len_ok & key_ok);
    }
  }, shuffle_proto));

  // Keywords vceqq
  gen.seed(42);
  pp("Keywords NEON vceqq 16B (MKL=6)", N, shuffle_bench([&](){
    for (size_t i = 0; i < kw_keys.size(); i++) {
      auto key = kw_keys[i];
      auto len = key.size();
      if (len == 0 || len > 6) { continue; }
      auto slot = ks.compute_hash(key);
      auto expected_len = ks.slot_key_len_[slot];
      uint8x16_t stored = vld1q_u8(kw_stored16[slot]);
      uint8x16_t masked = neon_load_masked(key.data(), len);
      uint8x16_t cmp = vceqq_u8(stored, masked);
      uint8x8_t min8 = vand_u8(vget_low_u8(cmp), vget_high_u8(cmp));
      uint64_t all_eq = vget_lane_u64(vreinterpret_u64_u8(min8), 0);
      bool len_ok = (expected_len == static_cast<uint8_t>(len));
      bool key_ok = (all_eq == ~0ULL);
      sink = sink +(len_ok & key_ok);
    }
  }, shuffle_kw));

  // Tickers vceqq
  gen.seed(42);
  pp("Tickers NEON vceqq 16B (MKL=5,H&D)", N, shuffle_bench([&](){
    for (size_t i = 0; i < ticker_keys.size(); i++) {
      auto key = ticker_keys[i];
      auto len = key.size();
      if (len == 0 || len > 5) { continue; }
      auto slot = ts.compute_hash(key);
      auto expected_len = ts.slot_key_len_[slot];
      uint8x16_t stored = vld1q_u8(tick_stored16[slot]);
      uint8x16_t masked = neon_load_masked(key.data(), len);
      uint8x16_t cmp = vceqq_u8(stored, masked);
      uint8x8_t min8 = vand_u8(vget_low_u8(cmp), vget_high_u8(cmp));
      uint64_t all_eq = vget_lane_u64(vreinterpret_u64_u8(min8), 0);
      bool len_ok = (expected_len == static_cast<uint8_t>(len));
      bool key_ok = (all_eq == ~0ULL);
      sink = sink +(len_ok & key_ok);
    }
  }, shuffle_tickers));

  // ========================================================================
  // EXP 9: NEON EOR+UMAXV for Headers (MaxKeyLen=15)
  // Alternative reduction: XOR + max-across-vector.
  // ========================================================================
  std::println("\n=== EXP 9: NEON EOR+UMAXV for Headers (MaxKeyLen=15) ===");

  gen.seed(42);
  pp("Headers NEON EOR+UMAXV (padded)", N, shuffle_bench([&](){
    for (size_t i = 0; i < header_keys.size(); i++) {
      auto key = header_keys[i];
      auto len = key.size();
      if (len == 0 || len > 15) { continue; }
      auto slot = hs.compute_hash(key);
      auto expected_len = hs.slot_key_len_[slot];
      uint8x16_t stored = vld1q_u8(hdr_stored16[slot]);
      uint8x16_t masked = neon_load_masked(key.data(), len);
      uint8x16_t xored = veorq_u8(masked, stored);
      uint8_t max_diff = vmaxvq_u8(xored);
      bool len_ok = (expected_len == static_cast<uint8_t>(len));
      bool key_ok = (max_diff == 0);
      sink = sink +(len_ok & key_ok);
    }
  }, shuffle_hdrs));

#endif // __aarch64__

  std::println("\nDone.");
}
