/**
 * Optimization hunting experiments.
 * Each experiment modifies one aspect of the PHF lookup to measure impact.
 * Run with: sudo ./build/benchmarks/hunting_experiments
 */
#include <algorithm>
#include <cstdint>
#include <cstring>
#include <optional>
#include <print>
#include <random>
#include <string>
#include <vector>

#include "ConstexprCore/perfect_hash.h"
#include "counters/bench.h"
#ifdef __aarch64__
#include <arm_neon.h>
#endif

// ============================================================================
// Infrastructure (same as bench_protocol)
// ============================================================================

template <class F1, class F2>
counters::event_aggregate shuffle_bench(F1 &&f1, F2 &&f2, size_t n = 300) {
  static thread_local counters::event_collector collector;
  counters::event_aggregate agg{};
  for (size_t i = 0; i < n; i++) {
    collector.start();
    f1();
    agg << collector.end();
    f2();
  }
  return agg;
}

void pp(const std::string &name, size_t n, counters::event_aggregate agg) {
  std::print("  {:<42s} : ", name);
  std::print("{:5.3f} ns ", agg.fastest_elapsed_ns() / double(n));
  if (counters::has_performance_counters()) {
    std::print(" {:5.2f} c  {:5.0f} i  {:4.2f} i/c  {:4.2f} bm",
               agg.fastest_cycles() / double(n),
               agg.fastest_instructions() / double(n),
               agg.fastest_instructions() / double(agg.fastest_cycles()),
               agg.fastest_branch_misses() / double(n));
  }
  std::print("\n");
}

// ============================================================================
// Key sets
// ============================================================================

static constexpr auto proto = ConstexprCore::make_perfect_map<
    ConstexprCore::kv<"http",0>,ConstexprCore::kv<"https",1>,
    ConstexprCore::kv<"ftp",2>,ConstexprCore::kv<"ws",3>,
    ConstexprCore::kv<"wss",4>,ConstexprCore::kv<"file",5>>();

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

// ============================================================================
// Experiments
// ============================================================================

int main() {
  if (!counters::has_performance_counters())
    std::println("No perf counters — run with sudo.");

  constexpr size_t N = 200000;

  auto proto_keys = make_input({"http","https","ftp","ws","wss","file"}, N);
  auto mime_keys = make_input({"text/html","text/plain","text/css",
    "application/json","application/xml","application/pdf","application/zip",
    "image/png","image/jpeg","image/gif","image/webp","audio/mpeg",
    "video/mp4","font/woff2","font/woff"}, N);

  std::mt19937_64 gen(42);
  auto shuffle_proto = [&]() { std::shuffle(proto_keys.begin(), proto_keys.end(), gen); };
  auto shuffle_mime = [&]() { std::shuffle(mime_keys.begin(), mime_keys.end(), gen); };
  std::vector<int> results(N, 0);
  volatile uint64_t sink = 0;

  // --- BASELINE ---
  std::println("=== BASELINE ===");

  gen.seed(42);
  auto base_proto = [&]() {
    for (size_t i = 0; i < proto_keys.size(); i++) {
      auto opt = proto.lookup(proto_keys[i]);
      if (opt) results[i] = *opt; sink += results[i];
    }
  };
  pp("Protocols (baseline)", N, shuffle_bench(base_proto, shuffle_proto));

  gen.seed(42);
  auto base_mime = [&]() {
    for (size_t i = 0; i < mime_keys.size(); i++) {
      auto opt = mime.lookup(mime_keys[i]);
      if (opt) results[i] = *opt; sink += results[i];
    }
  };
  pp("MIME (baseline)", N, shuffle_bench(base_mime, shuffle_mime));

  // --- EXPERIMENT A: Skip optional<> wrapping ---
  // Use contains() + manual slot lookup instead of lookup() → optional<>
  std::println("\n=== EXP A: contains() + direct slot (skip optional) ===");

  gen.seed(42);
  auto expA_proto = [&]() {
    for (size_t i = 0; i < proto_keys.size(); i++) {
      if (proto.contains(proto_keys[i])) results[i] = 1; sink += 1;
    }
  };
  pp("Protocols (contains only)", N, shuffle_bench(expA_proto, shuffle_proto));

  gen.seed(42);
  auto expA_mime = [&]() {
    for (size_t i = 0; i < mime_keys.size(); i++) {
      if (mime.contains(mime_keys[i])) results[i] = 1; sink += 1;
    }
  };
  pp("MIME (contains only)", N, shuffle_bench(expA_mime, shuffle_mime));

  // --- EXPERIMENT B: Manual inline lookup for protocols ---
  // Hardcode the gperf hash + overlap comparison, no struct access
  std::println("\n=== EXP B: Fully inlined manual lookup (protocols) ===");

  // Pre-extract the data we need from the constexpr struct
  static constexpr auto& ps = proto.set_;
  gen.seed(42);
  auto expB_proto = [&]() {
    for (size_t i = 0; i < proto_keys.size(); i++) {
      auto key = proto_keys[i];
      auto len = key.size();
      if (len < 2 || len > 5) continue;
      // Inline hash: asso_values[key[0]] + len, AND 7
      std::size_t slot = (ps.asso_values_[static_cast<unsigned char>(key[0])] + len) & 7;
      if (ps.slot_key_len_[slot] != static_cast<uint8_t>(len)) continue;
      // Inline overlap comparison
      uint16_t lo, hi;
      __builtin_memcpy(&lo, key.data(), 2);
      __builtin_memcpy(&hi, key.data() + len - 2, 2);
      uint64_t encoded = lo | (static_cast<uint64_t>(hi) << 16)
                        | (static_cast<uint64_t>(len) << 32);
      if (encoded == ps.packed_keys_[slot]) results[i] = 1; sink += 1;
    }
  };
  pp("Protocols (manual inline)", N, shuffle_bench(expB_proto, shuffle_proto));

  // --- EXPERIMENT C: Fused hash+compare for MIME (memcpy 8 bytes) ---
  // Since min_key_len=8 for MIME, we can always memcpy 8 bytes
  std::println("\n=== EXP C: Fused 8-byte load for MIME ===");

  static constexpr auto& ms = mime.set_;
  gen.seed(42);
  auto expC_mime = [&]() {
    for (size_t i = 0; i < mime_keys.size(); i++) {
      auto key = mime_keys[i];
      auto len = key.size();
      if (len < 8 || len > 16) continue;
      // Gperf hash (1 position)
      std::size_t slot = (ms.asso_values_[static_cast<unsigned char>(key[0])] + len) & 15;
      if (ms.slot_key_len_[slot] != static_cast<uint8_t>(len)) continue;
      // Direct 8-byte load (safe: min_key_len=8)
      uint64_t input_val;
      __builtin_memcpy(&input_val, key.data(), 8);
      if (input_val != ms.packed_keys_[slot]) continue;
      // Tail bytes
      const char* a = ms.slot_key_data_[slot].data();
      bool ok = true;
      for (size_t j = 8; j < len; j++)
        ok &= (a[j] == key[j]);
      if (ok) { results[i] = 1; sink += 1; }
    }
  };
  pp("MIME (fused 8B load)", N, shuffle_bench(expC_mime, shuffle_mime));

  // --- EXPERIMENT D: NEON 16-byte load + compare for MIME ---
  // Load 16 bytes from both key and slot, compare in NEON
#ifdef __aarch64__
  std::println("\n=== EXP D: NEON 16-byte compare for MIME ===");

  gen.seed(42);
  auto expD_mime = [&]() {
    for (size_t i = 0; i < mime_keys.size(); i++) {
      auto key = mime_keys[i];
      auto len = key.size();
      if (len < 8 || len > 16) continue;
      std::size_t slot = (ms.asso_values_[static_cast<unsigned char>(key[0])] + len) & 15;
      if (ms.slot_key_len_[slot] != static_cast<uint8_t>(len)) continue;
      // Load 16 bytes from slot data (always safe: slot_key_data is 16 bytes)
      uint8x16_t stored = vld1q_u8(reinterpret_cast<const uint8_t*>(ms.slot_key_data_[slot].data()));
      // Load 16 bytes from key — safe if len >= 16, otherwise partial
      // For len < 16, use safe loads for remaining bytes
      uint64_t lo, hi = 0;
      __builtin_memcpy(&lo, key.data(), 8);
      if (len > 8) {
        // Load up to 8 more bytes from key[8..len-1], zero-padded
        size_t tail = len - 8;
        __builtin_memcpy(&hi, key.data() + 8, tail);
      }
      uint8x16_t input = vcombine_u8(
        vcreate_u8(lo), vcreate_u8(hi));
      // Compare all 16 bytes at once
      uint8x16_t cmp = vceqq_u8(stored, input);
      // Check that all bytes in [0, MaxKeyLen) match
      // (stored is zero-padded beyond key length, input is too)
      uint64x2_t cmp64 = vreinterpretq_u64_u8(cmp);
      if (vgetq_lane_u64(cmp64, 0) == ~0ULL && vgetq_lane_u64(cmp64, 1) == ~0ULL)
        results[i] = 1; sink += 1;
    }
  };
  pp("MIME (NEON 16B compare)", N, shuffle_bench(expD_mime, shuffle_mime));
#endif

  // --- EXPERIMENT E: Eliminate optional wrapping entirely ---
  // Return raw int with sentinel (-1) instead of optional<int>
  std::println("\n=== EXP E: index_of + direct value (no optional) ===");

  gen.seed(42);
  auto expE_proto = [&]() {
    for (size_t i = 0; i < proto_keys.size(); i++) {
      auto idx = proto.set_.index_of(proto_keys[i]);
      if (idx.has_value()) results[i] = static_cast<int>(*idx); sink += results[i];
    }
  };
  pp("Protocols (index_of)", N, shuffle_bench(expE_proto, shuffle_proto));

  // --- EXPERIMENT F: Compute hash + pack in parallel ---
  // For gperf: hash only needs key[0], pack needs all bytes.
  // Compute hash first, use result to start slot load while packing.
  std::println("\n=== EXP F: Hash-first pipeline (gperf) ===");

  gen.seed(42);
  auto expF_proto = [&]() {
    for (size_t i = 0; i < proto_keys.size(); i++) {
      auto key = proto_keys[i];
      auto len = key.size();
      if (len < 2 || len > 5) continue;
      // Start hash immediately (only needs key[0])
      uint8_t c0 = static_cast<uint8_t>(key[0]);
      std::size_t slot = (ps.asso_values_[c0] + len) & 7;
      // Start slot_key_len load (depends on slot)
      uint8_t expected_len = ps.slot_key_len_[slot];
      // Pack key while slot loads are in flight
      uint64_t packed = ps.packed_keys_[slot];
      // Now check length (slot load should be ready)
      if (expected_len != static_cast<uint8_t>(len)) continue;
      // Overlap comparison
      uint16_t lo, hi;
      __builtin_memcpy(&lo, key.data(), 2);
      __builtin_memcpy(&hi, key.data() + len - 2, 2);
      uint64_t encoded = lo | (static_cast<uint64_t>(hi) << 16)
                        | (static_cast<uint64_t>(len) << 32);
      if (encoded == packed) { results[i] = 1; sink += 1; }
    }
  };
  pp("Protocols (hash-first)", N, shuffle_bench(expF_proto, shuffle_proto));
}
