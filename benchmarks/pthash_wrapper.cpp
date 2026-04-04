#include "pthash_wrapper.h"
#include <pthash.hpp>

using pthash_type = pthash::single_phf<pthash::xxhash_128, pthash::skew_bucketer, pthash::dictionary, true>;

struct PthashWrapper::Impl {
  pthash_type phf;
};

PthashWrapper::PthashWrapper() : impl_(std::make_unique<Impl>()) {}
PthashWrapper::~PthashWrapper() = default;
PthashWrapper::PthashWrapper(PthashWrapper &&) noexcept = default;
PthashWrapper &PthashWrapper::operator=(PthashWrapper &&) noexcept = default;

void PthashWrapper::build(const std::vector<std::string_view> &keys) {
  std::vector<std::string> keyset(keys.begin(), keys.end());
  pthash::build_configuration config;
  config.seed = 1234567890;
  config.lambda = 4;
  config.alpha = 0.95;
  config.verbose = false;
  config.avg_partition_size = 1000;
  config.num_threads = 1;
  config.dense_partitioning = false;
  impl_->phf.build_in_internal_memory(keyset.begin(), keyset.size(), config);
}

uint64_t PthashWrapper::operator()(const std::string &key) const {
  return impl_->phf(key);
}

uint64_t PthashWrapper::num_keys() const {
  return impl_->phf.num_keys();
}
