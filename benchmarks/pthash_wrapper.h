#pragma once

#include <cstddef>
#include <cstdint>
#include <memory>
#include <string>
#include <string_view>
#include <vector>

// Opaque wrapper around pthash to isolate its headers from other translation units.
class PthashWrapper {
public:
  PthashWrapper();
  ~PthashWrapper();
  PthashWrapper(PthashWrapper &&) noexcept;
  PthashWrapper &operator=(PthashWrapper &&) noexcept;

  void build(const std::vector<std::string_view> &keys);
  uint64_t operator()(const std::string &key) const;
  uint64_t num_keys() const;

  // Runs the hot lookup loop internally so pthash calls can be inlined
  // within this translation unit.
  void bench_lookup(const std::vector<std::string_view> &input,
                    std::vector<int> &results) const;

private:
  struct Impl;
  std::unique_ptr<Impl> impl_;
};
