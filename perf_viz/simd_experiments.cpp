/**
 * SIMD exploration experiments for ARM64 NEON.
 *
 * Target: reduce the safe_byte packing overhead for MaxKeyLen 9-16.
 * Current: 8 × safe_byte for upper bytes = ~48 ARM64 insn.
 * Goal: find NEON approaches that reduce this.
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
  std::print("  {:<45s} : {:5.3f} ns", name, agg.fastest_elapsed_ns() / double(n));
  if (counters::has_performance_counters())
    std::print("  {:5.0f} i  {:4.2f} i/c  {:4.2f} bm",
      agg.fastest_instructions() / double(n),
      agg.fastest_instructions() / double(agg.fastest_cycles()),
      agg.fastest_branch_misses() / double(n));
  std::print("\n");
}

// MIME key set (MaxKeyLen=16, min_key_len=8)
static constexpr auto mime = ConstexprCore::make_perfect_map<
    ConstexprCore::kv<"text/html",0>,ConstexprCore::kv<"text/plain",1>,
    ConstexprCore::kv<"text/css",2>,ConstexprCore::kv<"application/json",3>,
    ConstexprCore::kv<"application/xml",4>,ConstexprCore::kv<"application/pdf",5>,
    ConstexprCore::kv<"application/zip",6>,ConstexprCore::kv<"image/png",7>,
    ConstexprCore::kv<"image/jpeg",8>,ConstexprCore::kv<"image/gif",9>,
    ConstexprCore::kv<"image/webp",10>,ConstexprCore::kv<"audio/mpeg",11>,
    ConstexprCore::kv<"video/mp4",12>,ConstexprCore::kv<"font/woff2",13>,
    ConstexprCore::kv<"font/woff",14>>();

// HTTP Headers (MaxKeyLen=15, min_key_len=3)
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
  auto mime_keys = make_input({"text/html","text/plain","text/css",
    "application/json","application/xml","application/pdf","application/zip",
    "image/png","image/jpeg","image/gif","image/webp","audio/mpeg",
    "video/mp4","font/woff2","font/woff"}, N);
  auto header_keys = make_input({"Accept","Accept-Encoding","Authorization",
    "Cache-Control","Connection","Content-Length","Content-Type","Cookie",
    "Date","Host","If-None-Match","Location","Origin","Referer",
    "Server","Set-Cookie","User-Agent","Vary","Via","X-Forwarded-For"}, N);

  std::mt19937_64 gen(42);
  auto shuffle_mime = [&]() { std::shuffle(mime_keys.begin(), mime_keys.end(), gen); };
  auto shuffle_hdrs = [&]() { std::shuffle(header_keys.begin(), header_keys.end(), gen); };
  volatile uint64_t sink = 0;

  // === BASELINE ===
  std::println("=== BASELINE (library contains) ===");
  gen.seed(42);
  pp("MIME baseline", N, shuffle_bench([&](){
    for (size_t i = 0; i < mime_keys.size(); i++)
      sink += mime.contains(mime_keys[i]);
  }, shuffle_mime));

  gen.seed(42);
  pp("Headers baseline", N, shuffle_bench([&](){
    for (size_t i = 0; i < header_keys.size(); i++)
      sink += headers.contains(header_keys[i]);
  }, shuffle_hdrs));

#ifdef __aarch64__
  static constexpr auto& ms = mime.set_;
  static constexpr auto& hs = headers.set_;

  // === EXP 1: NEON TBL for safe byte masking ===
  // Use vqtbl1q_u8 to zero-pad short keys in a NEON register.
  // TBL automatically zeros bytes where the index is >= 16.
  std::println("\n=== EXP 1: NEON TBL masked 16-byte load ===");

  // Precomputed TBL index vectors for each possible length (0-16)
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

  gen.seed(42);
  pp("MIME TBL-masked 16B", N, shuffle_bench([&](){
    for (size_t i = 0; i < mime_keys.size(); i++) {
      auto key = mime_keys[i];
      auto len = key.size();
      if (len == 0 || len > 16) { continue; }
      // Compute hash (gperf: 2 positions)
      auto slot = ms.compute_hash(key);
      auto expected_len = ms.slot_key_len_[slot];
      // Page-safe 16-byte load + TBL mask
      uint8x16_t raw;
      uintptr_t addr = reinterpret_cast<uintptr_t>(key.data());
      if (__builtin_expect((addr & 16383) <= 16368, 1)) {
        raw = vld1q_u8(reinterpret_cast<const uint8_t*>(key.data()));
      } else {
        // Fallback: byte-by-byte into NEON
        alignas(16) uint8_t buf[16] = {};
        for (size_t j = 0; j < len; j++) buf[j] = key[j];
        raw = vld1q_u8(buf);
      }
      // TBL zeros bytes beyond len (index >= 16 → 0)
      uint8x16_t masked = vqtbl1q_u8(raw, tbl_masks[len]);
      // Compare as two uint64
      uint64x2_t input = vreinterpretq_u64_u8(masked);
      uint64x2_t stored = vld1q_u64(reinterpret_cast<const uint64_t*>(
          ms.slot_key_data_[slot].data()));
      uint64x2_t xored = veorq_u64(input, stored);
      uint64_t diff = vgetq_lane_u64(xored, 0) | vgetq_lane_u64(xored, 1);
      bool len_ok = (expected_len == static_cast<uint8_t>(len));
      bool key_ok = (diff == 0);
      sink += (len_ok & key_ok);
    }
  }, shuffle_mime));

  // === EXP 2: NEON 16-byte load with stored NEON key ===
  // Pre-store slot keys as 16-byte aligned NEON values, compare with vceqq.
  std::println("\n=== EXP 2: NEON vceqq against stored 16B key ===");

  gen.seed(42);
  pp("MIME NEON vceqq 16B", N, shuffle_bench([&](){
    for (size_t i = 0; i < mime_keys.size(); i++) {
      auto key = mime_keys[i];
      auto len = key.size();
      if (len == 0 || len > 16) { continue; }
      auto slot = ms.compute_hash(key);
      auto expected_len = ms.slot_key_len_[slot];
      // Load stored key as 16 bytes (slot_key_data is zero-padded)
      uint8x16_t stored = vld1q_u8(reinterpret_cast<const uint8_t*>(
          ms.slot_key_data_[slot].data()));
      // Build input from page-safe load + TBL mask
      uint8x16_t raw;
      uintptr_t addr = reinterpret_cast<uintptr_t>(key.data());
      if (__builtin_expect((addr & 16383) <= 16368, 1)) {
        raw = vld1q_u8(reinterpret_cast<const uint8_t*>(key.data()));
      } else {
        alignas(16) uint8_t buf[16] = {};
        for (size_t j = 0; j < len; j++) buf[j] = key[j];
        raw = vld1q_u8(buf);
      }
      uint8x16_t masked = vqtbl1q_u8(raw, tbl_masks[len]);
      // Compare
      uint8x16_t cmp = vceqq_u8(stored, masked);
      // Check all bytes equal: narrow to minimum
      uint8x8_t min8 = vand_u8(vget_low_u8(cmp), vget_high_u8(cmp));
      uint64_t all_eq = vget_lane_u64(vreinterpret_u64_u8(min8), 0);
      bool len_ok = (expected_len == static_cast<uint8_t>(len));
      bool key_ok = (all_eq == ~0ULL);
      sink += (len_ok & key_ok);
    }
  }, shuffle_mime));

  // === EXP 3: Direct 16-byte memcpy (MIME min_key_len=8, most keys >= 9) ===
  // For MIME where min_key_len=8: always load 16 bytes via two memcpy.
  // Compare against packed_keys_ + packed_keys2_.
  std::println("\n=== EXP 3: Two memcpy(8) + XOR (MIME only) ===");

  gen.seed(42);
  pp("MIME 2x memcpy XOR", N, shuffle_bench([&](){
    for (size_t i = 0; i < mime_keys.size(); i++) {
      auto key = mime_keys[i];
      auto len = key.size();
      if (len < 8 || len > 16) { continue; }
      auto slot = ms.compute_hash(key);
      auto expected_len = ms.slot_key_len_[slot];
      // Direct 8-byte loads (safe: min_key_len=8)
      uint64_t lo, hi = 0;
      __builtin_memcpy(&lo, key.data(), 8);
      if (len > 8) {
        // Load remaining bytes zero-padded
        uint64_t tmp = 0;
        __builtin_memcpy(&tmp, key.data() + 8, len - 8);
        hi = tmp;
      }
      uint64_t diff = (lo ^ ms.packed_keys_[slot]) | (hi ^ ms.packed_keys2_[slot]);
      bool len_ok = (expected_len == static_cast<uint8_t>(len));
      bool key_ok = (diff == 0);
      sink += (len_ok & key_ok);
    }
  }, shuffle_mime));

  // === EXP 4: Scalar two-word with branchless second load ===
  // Load first 8 bytes always. Load second 8 bytes branchlessly using safe_byte trick.
  std::println("\n=== EXP 4: Scalar 8B + branchless 8B (universal) ===");

  gen.seed(42);
  pp("Headers scalar 2-word", N, shuffle_bench([&](){
    for (size_t i = 0; i < header_keys.size(); i++) {
      auto key = header_keys[i];
      auto len = key.size();
      if (len == 0 || len > 15) { continue; }
      auto slot = hs.compute_hash(key);
      auto expected_len = hs.slot_key_len_[slot];
      // First 8 bytes: use safe_byte or memcpy depending on len
      uint64_t lo;
      if (len >= 8) {
        __builtin_memcpy(&lo, key.data(), 8);
      } else {
        lo = 0;
        for (size_t j = 0; j < len; j++)
          lo |= static_cast<uint64_t>(static_cast<unsigned char>(key[j])) << (j * 8);
      }
      // Second 8 bytes: always safe_byte (branchless)
      uint64_t hi = 0;
      if (len > 8) {
        for (size_t j = 8; j < len; j++)
          hi |= static_cast<uint64_t>(static_cast<unsigned char>(key[j])) << ((j-8) * 8);
      }
      uint64_t diff = (lo ^ hs.packed_keys_[slot]) | (hi ^ hs.packed_keys2_[slot]);
      bool len_ok = (expected_len == static_cast<uint8_t>(len));
      bool key_ok = (diff == 0);
      sink += (len_ok & key_ok);
    }
  }, shuffle_hdrs));

  // === EXP 5: NEON LD1 + EOR + UMINV reduction ===
  // Load 16 bytes, XOR with stored, check if all zero via UMINV (min across vector).
  std::println("\n=== EXP 5: NEON LD1 + EOR + UMINV ===");

  gen.seed(42);
  pp("MIME NEON EOR+UMINV", N, shuffle_bench([&](){
    for (size_t i = 0; i < mime_keys.size(); i++) {
      auto key = mime_keys[i];
      auto len = key.size();
      if (len == 0 || len > 16) { continue; }
      auto slot = ms.compute_hash(key);
      auto expected_len = ms.slot_key_len_[slot];
      // Page-safe 16B load + TBL mask
      uint8x16_t raw;
      uintptr_t addr = reinterpret_cast<uintptr_t>(key.data());
      if (__builtin_expect((addr & 16383) <= 16368, 1)) {
        raw = vld1q_u8(reinterpret_cast<const uint8_t*>(key.data()));
      } else {
        alignas(16) uint8_t buf[16] = {};
        for (size_t j = 0; j < len; j++) buf[j] = key[j];
        raw = vld1q_u8(buf);
      }
      uint8x16_t masked = vqtbl1q_u8(raw, tbl_masks[len]);
      uint8x16_t stored = vld1q_u8(reinterpret_cast<const uint8_t*>(
          ms.slot_key_data_[slot].data()));
      // XOR and check all-zero via max (if max of XOR is 0, all equal)
      uint8x16_t xored = veorq_u8(masked, stored);
      uint8_t max_diff = vmaxvq_u8(xored);
      bool len_ok = (expected_len == static_cast<uint8_t>(len));
      bool key_ok = (max_diff == 0);
      sink += (len_ok & key_ok);
    }
  }, shuffle_mime));

#endif

  std::println("\nDone.");
}
