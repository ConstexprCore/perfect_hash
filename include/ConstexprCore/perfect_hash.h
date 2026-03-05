#ifndef CONSTEXPRCORE_PERFECT_HASH_H
#define CONSTEXPRCORE_PERFECT_HASH_H

#include <ConstexprCore/fixed_string.h>
#include <ConstexprCore/detail/seeded_hash.h>
#include <ConstexprCore/detail/seed_or_index.h>
#include <ConstexprCore/detail/phf_generator.h>
#include <array>
#include <string_view>
#include <optional>
#include <tuple>
#include <cstddef>

namespace ConstexprCore {

// ============================================================================
// perfect_hash_set
// ============================================================================

template <std::size_t N>
struct perfect_hash_set {
    std::size_t seed0_{};
    std::array<detail::seed_or_index, N> G_{};
    std::array<std::size_t, N> slots_{};          // slot -> declaration-order index
    std::array<std::string_view, N> keys_{};      // declaration-order keys

    consteval perfect_hash_set(const std::array<std::string_view, N>& keys)
        : keys_{keys}
    {
        detail::generate_phf<N>(keys_, seed0_, G_, slots_);
    }

    [[nodiscard]] constexpr std::size_t size() const noexcept { return N; }

    [[nodiscard]] constexpr std::string_view key_at(std::size_t i) const noexcept {
        return keys_[i];
    }

    [[nodiscard]] constexpr bool contains(std::string_view key) const noexcept {
        return index_of(key).has_value();
    }

    [[nodiscard]] constexpr std::optional<std::size_t> index_of(std::string_view key) const noexcept {
        std::size_t bucket = seeded_fnv1a(key, seed0_) % N;
        auto entry = G_[bucket];
        std::size_t slot;
        if (entry.is_seed()) {
            slot = seeded_fnv1a(key, entry.seed()) % N;
        } else {
            slot = entry.index();
        }
        std::size_t key_idx = slots_[slot];
        if (key_idx < N && keys_[key_idx] == key) {
            return key_idx;
        }
        return std::nullopt;
    }
};

// ============================================================================
// perfect_hash_map
// ============================================================================

template <std::size_t N, typename ValueT>
struct perfect_hash_map {
    perfect_hash_set<N> set_;
    std::array<ValueT, N> values_{};

    consteval perfect_hash_map(
        const std::array<std::string_view, N>& keys,
        const std::array<ValueT, N>& values)
        : set_{keys}, values_{values}
    {}

    [[nodiscard]] constexpr std::size_t size() const noexcept { return N; }

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

    return perfect_hash_set<N>{keys};
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

    return perfect_hash_map<N, ValueT>{keys, values};
}

} // namespace ConstexprCore

#endif // CONSTEXPRCORE_PERFECT_HASH_H
