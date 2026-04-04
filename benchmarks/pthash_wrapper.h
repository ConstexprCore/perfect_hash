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

private:
  struct Impl;
  std::unique_ptr<Impl> impl_;
};
