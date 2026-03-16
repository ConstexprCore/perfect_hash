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
    std::array<std::size_t, TableSize> key_index_{};   // hash_slot -> declaration-order index
    std::array<std::string_view, N> original_keys_;  // keys in declaration order
    std::array<std::string_view, TableSize> keys_;  // keys in hash order, empty slots are empty string_view

    // Direct constructor: runs full PHF generation.
    consteval perfect_hash_set(const std::array<std::string_view, N>& keys)
        : original_keys_{keys}
    {
        std::array<std::size_t, TableSize> temp_slot_to_key{};
        detail::generate_gperf<N, TableSize>(keys, asso_values_, num_positions_, positions_, temp_slot_to_key);
        // Populate keys_ and key_index_
        for (std::size_t i = 0; i < TableSize; ++i) {
            key_index_[i] = temp_slot_to_key[i];
            if (temp_slot_to_key[i] != N) {
                keys_[i] = original_keys_[temp_slot_to_key[i]];
            } else {
                keys_[i] = std::string_view{};
            }
        }
    }

    // Pre-computed constructor: copies data from a phf_result (no recomputation).
    consteval perfect_hash_set(
        const std::array<std::string_view, N>& keys,
        const detail::phf_result<N>& data)
        : asso_values_{data.asso_values}
        , num_positions_{data.num_positions}
        , positions_{data.positions}
        , original_keys_{keys}
    {
        for (std::size_t i = 0; i < TableSize; ++i) {
            key_index_[i] = data.slot_to_key[i];
            if (data.slot_to_key[i] != N) {
                keys_[i] = original_keys_[data.slot_to_key[i]];
            } else {
                keys_[i] = std::string_view{};
            }
        }
    }

    [[nodiscard]] constexpr std::size_t size() const noexcept { return N; }

    [[nodiscard]] constexpr std::size_t table_size() const noexcept { return TableSize; }

    [[nodiscard]] constexpr std::string_view key_at(std::size_t i) const noexcept {
        return original_keys_[i];
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
        if (slot < TableSize && keys_[slot] == key) {
            return key_index_[slot];
        }
        return std::nullopt;
    }
};

// ============================================================================
// constexpr_perfect_hash_set
// PHF parameters are baked into the type as non-type template parameters.
// ============================================================================

template <std::size_t MaxLen>
struct fixed_string_view {
    std::array<char, MaxLen> data{};
    std::size_t length{};

    constexpr fixed_string_view() = default;

    constexpr fixed_string_view(std::string_view sv) : length{sv.size()} {
        for (std::size_t i = 0; i < sv.size(); ++i)
            data[i] = sv[i];
    }

    [[nodiscard]] constexpr std::string_view view() const noexcept {
        return {data.data(), length};
    }

    [[nodiscard]] constexpr bool operator==(std::string_view sv) const noexcept {
        return view() == sv;
    }
};

template <
    std::size_t N,
    std::size_t TableSize,
    std::size_t NumPositions,
    std::array<std::size_t, detail::MAX_POSITIONS> Positions,
    std::array<std::size_t, 256> AssoValues,
    std::size_t MaxKeyLen,
    std::array<fixed_string_view<MaxKeyLen>, TableSize> Keys,
    std::array<std::size_t, TableSize> KeyIndex
>
struct constexpr_perfect_hash_set {
    std::array<std::string_view, N> original_keys_;

    consteval constexpr_perfect_hash_set(
        const std::array<std::string_view, N>& keys)
        : original_keys_{keys}
    {}

    [[nodiscard]] constexpr std::size_t size() const noexcept { return N; }

    [[nodiscard]] constexpr std::size_t table_size() const noexcept { return TableSize; }

    [[nodiscard]] constexpr std::string_view key_at(std::size_t i) const noexcept {
        return original_keys_[i];
    }

    [[nodiscard]] constexpr std::size_t compute_hash(std::string_view key) const noexcept {
        std::size_t h = key.size();
        for (std::size_t i = 0; i < NumPositions; ++i) {
            std::size_t ch = detail::char_at(key, Positions[i]);
            if (ch < 256) {
                h += AssoValues[ch];
            }
        }
        if constexpr (detail::is_power_of_two(TableSize)) {
            return h & (TableSize - 1);
        } else {
            return h % TableSize;
        }
    }

private:
    template <std::size_t Slot>
    [[nodiscard]] static constexpr bool compare_content(const char* p) noexcept {
        constexpr auto& expected = Keys[Slot];
        bool matches = true;
        for (std::size_t i = 0; i < expected.length; ++i) {
            matches &= (p[i] == expected.data[i]);
        }
        return matches;
    }

    static constexpr auto make_lengths() noexcept {
        std::array<std::size_t, TableSize> lens{};
        for (std::size_t i = 0; i < TableSize; ++i)
            lens[i] = Keys[i].length;
        return lens;
    }

    static constexpr auto lengths = make_lengths();

    template <std::size_t... Is>
    [[nodiscard]] inline __attribute__((always_inline)) constexpr bool contains_impl(std::string_view key, std::size_t slot, std::index_sequence<Is...>) const noexcept {
        bool result = false;
        (void)((slot == Is ? (result = compare_content<Is>(key.data()), true) : false) || ...);
        return result;
    }

    template <std::size_t... Is>
    [[nodiscard]] constexpr std::optional<std::size_t> index_of_impl(std::string_view key, std::size_t slot, std::index_sequence<Is...>) const noexcept {
        std::optional<std::size_t> result = std::nullopt;
        (void)((slot == Is ? (compare_content<Is>(key.data()) ? (result = KeyIndex[Is], true) : true) : false) || ...);
        return result;
    }

public:
    [[nodiscard]] constexpr bool contains(std::string_view key) const noexcept {
        std::size_t slot = compute_hash(key);
        if (slot >= TableSize || key.size() != lengths[slot]) return false;
        return contains_impl(key, slot, std::make_index_sequence<TableSize>{});
    }

    [[nodiscard]] constexpr std::optional<std::size_t> index_of(std::string_view key) const noexcept {
        std::size_t slot = compute_hash(key);
        if (slot >= TableSize || key.size() != lengths[slot]) return std::nullopt;
        return index_of_impl(key, slot, std::make_index_sequence<TableSize>{});
    }

    [[nodiscard]] constexpr std::optional<std::size_t> lookup(std::string_view key) const noexcept {
        return index_of(key);
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
// constexpr_perfect_hash_map
// ============================================================================

template <
    std::size_t N,
    typename ValueT,
    std::size_t TableSize,
    std::size_t NumPositions,
    std::array<std::size_t, detail::MAX_POSITIONS> Positions,
    std::array<std::size_t, 256> AssoValues,
    std::size_t MaxKeyLen,
    std::array<fixed_string_view<MaxKeyLen>, TableSize> Keys,
    std::array<std::size_t, TableSize> KeyIndex,
    std::array<ValueT, N> Values
>
struct constexpr_perfect_hash_map {
    std::array<std::string_view, N> original_keys_;

    consteval constexpr_perfect_hash_map(
        const std::array<std::string_view, N>& keys)
        : original_keys_{keys}
    {}

    [[nodiscard]] constexpr std::size_t size() const noexcept { return N; }

    [[nodiscard]] constexpr std::size_t table_size() const noexcept { return TableSize; }

    [[nodiscard]] constexpr std::string_view key_at(std::size_t i) const noexcept {
        return original_keys_[i];
    }

    [[nodiscard]] constexpr std::size_t compute_hash(std::string_view key) const noexcept {
        std::size_t h = key.size();
        for (std::size_t i = 0; i < NumPositions; ++i) {
            std::size_t ch = detail::char_at(key, Positions[i]);
            if (ch < 256) {
                h += AssoValues[ch];
            }
        }
        if constexpr (detail::is_power_of_two(TableSize)) {
            return h & (TableSize - 1);
        } else {
            return h % TableSize;
        }
    }

private:
    template <std::size_t Slot>
    [[nodiscard]] static constexpr bool compare_content(const char* p) noexcept {
        constexpr auto& expected = Keys[Slot];
        bool matches = true;
        for (std::size_t i = 0; i < expected.length; ++i) {
            matches &= (p[i] == expected.data[i]);
        }
        return matches;
    }

    static constexpr auto make_lengths() noexcept {
        std::array<std::size_t, TableSize> lens{};
        for (std::size_t i = 0; i < TableSize; ++i)
            lens[i] = Keys[i].length;
        return lens;
    }

    static constexpr auto lengths = make_lengths();

    template <std::size_t... Is>
    [[nodiscard]] inline __attribute__((always_inline)) constexpr bool contains_impl(std::string_view key, std::size_t slot, std::index_sequence<Is...>) const noexcept {
        bool result = false;
        (void)((slot == Is ? (result = compare_content<Is>(key.data()), true) : false) || ...);
        return result;
    }

    template <std::size_t... Is>
    [[nodiscard]] constexpr std::optional<std::size_t> index_of_impl(std::string_view key, std::size_t slot, std::index_sequence<Is...>) const noexcept {
        std::optional<std::size_t> result = std::nullopt;
        (void)((slot == Is ? (compare_content<Is>(key.data()) ? (result = KeyIndex[Is], true) : true) : false) || ...);
        return result;
    }

public:
    [[nodiscard]] constexpr bool contains(std::string_view key) const noexcept {
        std::size_t slot = compute_hash(key);
        if (slot >= TableSize || key.size() != lengths[slot]) return false;
        return contains_impl(key, slot, std::make_index_sequence<TableSize>{});
    }

    [[nodiscard]] constexpr std::optional<std::size_t> index_of(std::string_view key) const noexcept {
        std::size_t slot = compute_hash(key);
        if (slot >= TableSize || key.size() != lengths[slot]) return std::nullopt;
        return index_of_impl(key, slot, std::make_index_sequence<TableSize>{});
    }

    [[nodiscard]] constexpr std::optional<ValueT> lookup(std::string_view key) const noexcept {
        auto idx = index_of(key);
        if (idx.has_value()) {
            return Values[*idx];
        }
        return std::nullopt;
    }
};

// ============================================================================
// build_hash_keys / build_key_index helpers
// ============================================================================

template <std::size_t MaxLen, std::size_t M, auto N>
consteval std::array<fixed_string_view<MaxLen>, M> build_hash_keys(
    const std::array<std::string_view, N>& keys,
    const detail::phf_result<N>& data)
{
    std::array<fixed_string_view<MaxLen>, M> hkeys{};
    for (std::size_t i = 0; i < M; ++i) {
        if (data.slot_to_key[i] != N) {
            hkeys[i] = fixed_string_view<MaxLen>(keys[data.slot_to_key[i]]);
        }
    }
    return hkeys;
}

template <std::size_t M, auto N>
consteval std::array<std::size_t, M> build_key_index(const detail::phf_result<N>& data)
{
    std::array<std::size_t, M> ki{};
    for (std::size_t i = 0; i < M; ++i) {
        ki[i] = data.slot_to_key[i];
    }
    return ki;
}

// ============================================================================
// make_constexpr_perfect_map
// ============================================================================

template <typename... KVs>
consteval auto make_constexpr_perfect_map() {
    constexpr std::size_t N = sizeof...(KVs);
    static_assert(N > 0, "make_constexpr_perfect_map requires at least one entry");

    constexpr std::array<std::string_view, N> keys{KVs::key...};

    // Validate no duplicates
    for (std::size_t i = 0; i < N; ++i) {
        for (std::size_t j = i + 1; j < N; ++j) {
            if (keys[i] == keys[j]) {
                throw "Duplicate key in make_constexpr_perfect_map";
            }
        }
    }

    using first_kv = typename std::tuple_element<0, std::tuple<KVs...>>::type;
    using ValueT = decltype(first_kv::value);

    constexpr std::array<ValueT, N> values{static_cast<ValueT>(KVs::value)...};

    constexpr auto data    = detail::compute_phf<N>(keys);
    constexpr std::size_t M  = data.table_size;
    static_assert(M > 0, "Failed to generate perfect hash function");
    constexpr std::size_t NP = data.num_positions;
    constexpr auto Pos       = data.positions;
    constexpr auto Asso      = data.asso_values;
    constexpr std::size_t MaxLen = detail::max_key_length(keys);
    constexpr auto HashKeys  = build_hash_keys<MaxLen, data.table_size>(keys, data);
    constexpr auto KeyIndex  = build_key_index<data.table_size>(data);

    return constexpr_perfect_hash_map<N, ValueT, data.table_size, NP, Pos, Asso, MaxLen, HashKeys, KeyIndex, values>{keys};
}

// ============================================================================// make_perfect_set
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
// make_constexpr_perfect_set
// ============================================================================

template <fixed_string... Keys>
consteval auto make_constexpr_perfect_set() {
    constexpr std::size_t N = sizeof...(Keys);
    static_assert(N > 0, "make_constexpr_perfect_set requires at least one key");

    constexpr std::array<std::string_view, N> keys{Keys.view()...};

    // Validate no duplicates
    for (std::size_t i = 0; i < N; ++i) {
        for (std::size_t j = i + 1; j < N; ++j) {
            if (keys[i] == keys[j]) {
                throw "Duplicate key in make_constexpr_perfect_set";
            }
        }
    }

    constexpr auto data    = detail::compute_phf<N>(keys);
    constexpr std::size_t M  = data.table_size;
    static_assert(M > 0, "Failed to generate perfect hash function");
    constexpr std::size_t NP = data.num_positions;
    constexpr auto Pos       = data.positions;
    constexpr auto Asso      = data.asso_values;
    constexpr std::size_t MaxLen = detail::max_key_length(keys);
    constexpr auto HashKeys  = build_hash_keys<MaxLen, data.table_size>(keys, data);
    constexpr auto KeyIndex  = build_key_index<data.table_size>(data);

    return constexpr_perfect_hash_set<N, data.table_size, NP, Pos, Asso, MaxLen, HashKeys, KeyIndex>{keys};
}

} // namespace ConstexprCore

#endif // CONSTEXPRCORE_PERFECT_HASH_H
