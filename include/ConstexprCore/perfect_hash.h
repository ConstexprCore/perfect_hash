#ifndef CONSTEXPRCORE_PERFECT_HASH_H
#define CONSTEXPRCORE_PERFECT_HASH_H

#include <ConstexprCore/fixed_string.h>
#include <ConstexprCore/detail/gperf_generator.h>
#include <array>
#include <string_view>
#include <optional>
#include <tuple>
#include <cstddef>

namespace ConstexprCore {

// ============================================================================
// perfect_hash_set
// ============================================================================

template <std::size_t N, std::size_t TableSize = N>
struct perfect_hash_set {
    std::array<std::size_t, 256> asso_values_{};
    std::size_t num_positions_{};
    std::array<std::size_t, detail::MAX_POSITIONS> positions_{};
    std::array<std::size_t, TableSize> slot_to_key_{};   // hash_slot -> declaration-order index
    std::array<std::string_view, N> keys_;

    // Direct constructor: runs full PHF generation.
    consteval perfect_hash_set(const std::array<std::string_view, N>& keys)
        : keys_{keys}
    {
        detail::generate_gperf<N, TableSize>(keys_, asso_values_, num_positions_, positions_, slot_to_key_);
    }

    // Pre-computed constructor: copies data from a phf_result (no recomputation).
    consteval perfect_hash_set(
        const std::array<std::string_view, N>& keys,
        const detail::phf_result<N>& data)
        : asso_values_{data.asso_values}
        , num_positions_{data.num_positions}
        , positions_{data.positions}
        , keys_{keys}
    {
        for (std::size_t i = 0; i < TableSize; ++i) {
            slot_to_key_[i] = data.slot_to_key[i];
        }
    }

    [[nodiscard]] constexpr std::size_t size() const noexcept { return N; }

    [[nodiscard]] constexpr std::size_t table_size() const noexcept { return TableSize; }

    [[nodiscard]] constexpr std::string_view key_at(std::size_t i) const noexcept {
        return keys_[i];
    }

    [[nodiscard]] constexpr bool contains(std::string_view key) const noexcept {
        return index_of(key).has_value();
    }

    [[nodiscard]] constexpr std::size_t compute_hash(std::string_view key) const noexcept {
        std::size_t h = key.size();
        for (std::size_t i = 0; i < num_positions_; ++i) {
            std::size_t ch = detail::char_at(key, positions_[i]);
            if (ch < 256) {
                h += asso_values_[ch];
            }
        }
        return h % TableSize;
    }

    [[nodiscard]] constexpr std::optional<std::size_t> index_of(std::string_view key) const noexcept {
        std::size_t slot = compute_hash(key);
        std::size_t key_idx = slot_to_key_[slot];
        if (key_idx < N && keys_[key_idx] == key) {
            return key_idx;
        }
        return std::nullopt;
    }
};

// ============================================================================
// perfect_hash_map
// ============================================================================

template <std::size_t N, typename ValueT, std::size_t TableSize = N>
struct perfect_hash_map {
    perfect_hash_set<N, TableSize> set_;
    std::array<ValueT, N> values_{};

    consteval perfect_hash_map(
        const std::array<std::string_view, N>& keys,
        const std::array<ValueT, N>& values)
        : set_{keys}, values_{values}
    {}

    consteval perfect_hash_map(
        const std::array<std::string_view, N>& keys,
        const std::array<ValueT, N>& values,
        const detail::phf_result<N>& data)
        : set_{keys, data}, values_{values}
    {}

    [[nodiscard]] constexpr std::size_t size() const noexcept { return N; }

    [[nodiscard]] constexpr std::size_t table_size() const noexcept { return TableSize; }

    [[nodiscard]] constexpr bool contains(std::string_view key) const noexcept {
        return set_.contains(key);
    }

    [[nodiscard]] constexpr std::optional<ValueT> lookup(std::string_view key) const noexcept {
        auto idx = set_.index_of(key);
        if (idx.has_value()) {
            return values_[*idx];
        }
        return std::nullopt;
    }
};

// ============================================================================
// kv helper
// ============================================================================

template <fixed_string Key, auto Value>
struct kv {
    static constexpr std::string_view key = Key.view();
    static constexpr decltype(Value) value = Value;
};

// ============================================================================
// make_perfect_set
// ============================================================================

template <fixed_string... Keys>
consteval auto make_perfect_set() {
    constexpr std::size_t N = sizeof...(Keys);
    static_assert(N > 0, "make_perfect_set requires at least one key");

    constexpr std::array<std::string_view, N> keys{Keys.view()...};

    // Validate no duplicates
    for (std::size_t i = 0; i < N; ++i) {
        for (std::size_t j = i + 1; j < N; ++j) {
            if (keys[i] == keys[j]) {
                throw "Duplicate key in make_perfect_set";
            }
        }
    }

    // Compute PHF once (determines table size + all data)
    constexpr auto data = detail::compute_phf<N>(keys);
    constexpr std::size_t M = data.table_size;
    return perfect_hash_set<N, M>{keys, data};
}

// ============================================================================
// make_perfect_map
// ============================================================================

template <typename... KVs>
consteval auto make_perfect_map() {
    constexpr std::size_t N = sizeof...(KVs);
    static_assert(N > 0, "make_perfect_map requires at least one entry");

    constexpr std::array<std::string_view, N> keys{KVs::key...};

    // Validate no duplicates
    for (std::size_t i = 0; i < N; ++i) {
        for (std::size_t j = i + 1; j < N; ++j) {
            if (keys[i] == keys[j]) {
                throw "Duplicate key in make_perfect_map";
            }
        }
    }

    using first_kv = typename std::tuple_element<0, std::tuple<KVs...>>::type;
    using ValueT = decltype(first_kv::value);

    constexpr std::array<ValueT, N> values{static_cast<ValueT>(KVs::value)...};

    // Compute PHF once (determines table size + all data)
    constexpr auto data = detail::compute_phf<N>(keys);
    constexpr std::size_t M = data.table_size;
    return perfect_hash_map<N, ValueT, M>{keys, values, data};
}

} // namespace ConstexprCore

#endif // CONSTEXPRCORE_PERFECT_HASH_H
