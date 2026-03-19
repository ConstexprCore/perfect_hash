#ifndef CONSTEXPRCORE_PERFECT_HASH_H
#define CONSTEXPRCORE_PERFECT_HASH_H

#include <ConstexprCore/fixed_string.h>
#include <ConstexprCore/detail/gperf_generator.h>
#include <array>
#include <string_view>
#include <optional>
#include <tuple>
#include <cstddef>
#include <cstdint>

namespace ConstexprCore {

// ============================================================================
// perfect_hash_set
// ============================================================================

template <std::size_t N, std::size_t TableSize = N, std::size_t MaxKeyLen = 64>
struct perfect_hash_set {
    static_assert(N <= 255, "N must be <= 255 for uint8_t key indices");
    static_assert(TableSize <= 255, "TableSize must be <= 255 for uint8_t asso_values");
    static_assert(MaxKeyLen >= 1 && MaxKeyLen < 255,
                  "MaxKeyLen must be in [1, 254] to reserve 0xFF as empty sentinel");
    static_assert(detail::MAX_POSITIONS <= 255, "MAX_POSITIONS must fit in uint8_t");

    static constexpr std::uint8_t POS_LAST_CHAR = 255;
    static constexpr bool TABLE_SIZE_IS_POW2 = (TableSize & (TableSize - 1)) == 0;

    // --- hot data (accessed every lookup) ---
    std::array<std::uint8_t, 256> asso_values_{};
    std::uint8_t num_positions_{};
    std::array<std::uint8_t, detail::MAX_POSITIONS> positions_{};
    std::uint8_t min_key_len_{};
    std::array<std::uint8_t, TableSize> slot_key_len_{};                    // key length (0xFF = empty)
    std::array<std::array<char, MaxKeyLen>, TableSize> slot_key_data_{};    // inline key bytes

    // --- packed keys for branchless comparison (first 8 bytes) ---
    std::array<std::uint64_t, TableSize> packed_keys_{};

    // --- cold data (rarely accessed) ---
    std::array<std::uint8_t, TableSize> slot_to_key_{};     // hash_slot -> declaration-order index
    std::array<std::uint8_t, N> key_to_slot_{};             // declaration-order index -> slot

    // Shared init logic for both constructors.
    consteval void init_inline_data_(const std::array<std::string_view, N>& keys) {
        // Compute min key length
        std::size_t mn = keys[0].size();
        for (std::size_t i = 1; i < N; ++i)
            if (keys[i].size() < mn) mn = keys[i].size();
        min_key_len_ = static_cast<std::uint8_t>(mn);

        // Populate inline key data (0xFF = empty sentinel)
        for (std::size_t s = 0; s < TableSize; ++s)
            slot_key_len_[s] = 0xFF;
        for (std::size_t s = 0; s < TableSize; ++s) {
            if (slot_to_key_[s] < N) {
                auto k = keys[slot_to_key_[s]];
                slot_key_len_[s] = static_cast<std::uint8_t>(k.size());
                for (std::size_t c = 0; c < k.size(); ++c)
                    slot_key_data_[s][c] = k[c];
                key_to_slot_[slot_to_key_[s]] = static_cast<std::uint8_t>(s);
            }
        }

        // Build packed keys for branchless comparison
        for (std::size_t s = 0; s < TableSize; ++s) {
            packed_keys_[s] = 0;
            if (slot_to_key_[s] < N) {
                auto k = keys[slot_to_key_[s]];
                for (std::size_t j = 0; j < k.size() && j < 8; ++j)
                    packed_keys_[s] |= static_cast<std::uint64_t>(
                        static_cast<unsigned char>(k[j])) << (j * 8);
            }
        }
    }

    // Direct constructor: runs full PHF generation.
    consteval perfect_hash_set(const std::array<std::string_view, N>& keys) {
        for (std::size_t i = 0; i < N; ++i) {
            if (keys[i].size() > MaxKeyLen)
                throw "Key length exceeds MaxKeyLen";
        }

        std::array<std::size_t, 256> full_asso{};
        std::size_t wide_num_positions{};
        std::array<std::size_t, detail::MAX_POSITIONS> wide_positions{};
        std::array<std::size_t, TableSize> wide_slot_to_key{};
        detail::generate_gperf<N, TableSize>(keys, full_asso, wide_num_positions, wide_positions, wide_slot_to_key);

        for (std::size_t i = 0; i < 256; ++i)
            asso_values_[i] = static_cast<std::uint8_t>(full_asso[i] % TableSize);
        num_positions_ = static_cast<std::uint8_t>(wide_num_positions);
        for (std::size_t i = 0; i < wide_num_positions; ++i)
            positions_[i] = (wide_positions[i] == detail::LAST_CHAR)
                ? POS_LAST_CHAR
                : static_cast<std::uint8_t>(wide_positions[i]);
        for (std::size_t i = 0; i < TableSize; ++i)
            slot_to_key_[i] = static_cast<std::uint8_t>(wide_slot_to_key[i]);

        // Verify the reduction didn't break the perfect hash
        for (std::size_t i = 0; i < N; ++i) {
            if (slot_to_key_[compute_hash(keys[i])] != i)
                throw "asso_value reduction broke perfect hash mapping";
        }

        init_inline_data_(keys);
    }

    // Pre-computed constructor: copies data from a phf_result (no recomputation).
    consteval perfect_hash_set(
        const std::array<std::string_view, N>& keys,
        const detail::phf_result<N>& data)
    {
        for (std::size_t i = 0; i < N; ++i) {
            if (keys[i].size() > MaxKeyLen)
                throw "Key length exceeds MaxKeyLen";
        }

        for (std::size_t i = 0; i < 256; ++i)
            asso_values_[i] = static_cast<std::uint8_t>(data.asso_values[i] % TableSize);
        num_positions_ = static_cast<std::uint8_t>(data.num_positions);
        for (std::size_t i = 0; i < data.num_positions; ++i)
            positions_[i] = (data.positions[i] == detail::LAST_CHAR)
                ? POS_LAST_CHAR
                : static_cast<std::uint8_t>(data.positions[i]);
        for (std::size_t i = 0; i < TableSize; ++i)
            slot_to_key_[i] = static_cast<std::uint8_t>(data.slot_to_key[i]);

        // Verify the reduction didn't break the perfect hash
        for (std::size_t i = 0; i < N; ++i) {
            if (slot_to_key_[compute_hash(keys[i])] != i)
                throw "asso_value reduction broke perfect hash mapping";
        }

        init_inline_data_(keys);
    }

    [[nodiscard]] constexpr std::size_t size() const noexcept { return N; }

    [[nodiscard]] constexpr std::size_t table_size() const noexcept { return TableSize; }

    [[nodiscard]] constexpr std::string_view key_at(std::size_t i) const noexcept {
        std::uint8_t slot = key_to_slot_[i];
        return std::string_view(slot_key_data_[slot].data(), slot_key_len_[slot]);
    }

    [[nodiscard]] static constexpr std::uint64_t safe_byte_(
        const char* p, std::size_t len, std::size_t idx) noexcept {
        const std::size_t has_it = static_cast<std::size_t>(idx < len);
        const std::size_t safe_idx = idx & -has_it;
        const std::uint64_t byte_val = static_cast<unsigned char>(p[safe_idx]);
        return byte_val & -static_cast<std::uint64_t>(has_it);
    }

    [[nodiscard]] static constexpr std::uint64_t pack_input_(
        const char* p, std::size_t len) noexcept {
        std::uint64_t v = static_cast<unsigned char>(p[0]);
        if constexpr (MaxKeyLen >= 2) v |= safe_byte_(p, len, 1) << 8;
        if constexpr (MaxKeyLen >= 3) v |= safe_byte_(p, len, 2) << 16;
        if constexpr (MaxKeyLen >= 4) v |= safe_byte_(p, len, 3) << 24;
        if constexpr (MaxKeyLen >= 5) v |= safe_byte_(p, len, 4) << 32;
        if constexpr (MaxKeyLen >= 6) v |= safe_byte_(p, len, 5) << 40;
        if constexpr (MaxKeyLen >= 7) v |= safe_byte_(p, len, 6) << 48;
        if constexpr (MaxKeyLen >= 8) v |= safe_byte_(p, len, 7) << 56;
        return v;
    }

    [[nodiscard]] constexpr bool compare_key_(
        const char* p, std::size_t len, std::size_t slot) const noexcept {
        if consteval {
            const char* a = slot_key_data_[slot].data();
            for (std::size_t i = 0; i < len; ++i)
                if (a[i] != p[i]) return false;
            return true;
        } else {
            std::uint64_t input_val = pack_input_(p, len);
            if constexpr (MaxKeyLen <= 8) {
                return input_val == packed_keys_[slot];
            } else {
                if (input_val != packed_keys_[slot]) return false;
                const char* a = slot_key_data_[slot].data();
                for (std::size_t i = 8; i < len; ++i)
                    if (a[i] != p[i]) return false;
                return true;
            }
        }
    }

    [[nodiscard]] constexpr bool contains(std::string_view key) const noexcept {
        auto len = key.size();
        if (len < min_key_len_ || len > MaxKeyLen) return false;
        std::size_t slot = compute_hash(key);
        if (slot_key_len_[slot] != static_cast<std::uint8_t>(len)) return false;
        return compare_key_(key.data(), len, slot);
    }

    [[nodiscard]] constexpr std::size_t compute_hash(std::string_view key) const noexcept {
        std::size_t h = key.size();
        for (std::uint8_t i = 0; i < num_positions_; ++i) {
            std::uint8_t pos = positions_[i];
            std::size_t ch;
            if (pos == POS_LAST_CHAR) {
                ch = key.empty() ? 256 : static_cast<unsigned char>(key.back());
            } else {
                ch = (pos < key.size()) ? static_cast<unsigned char>(key[pos]) : 256;
            }
            if (ch < 256) h += asso_values_[ch];
        }
        if constexpr (TABLE_SIZE_IS_POW2)
            return h & (TableSize - 1);
        else
            return h % TableSize;
    }

    [[nodiscard]] constexpr std::optional<std::size_t> index_of(std::string_view key) const noexcept {
        auto len = key.size();
        if (len < min_key_len_ || len > MaxKeyLen) return std::nullopt;
        std::size_t slot = compute_hash(key);
        if (slot_key_len_[slot] != static_cast<std::uint8_t>(len)) return std::nullopt;
        if (!compare_key_(key.data(), len, slot)) return std::nullopt;
        return static_cast<std::size_t>(slot_to_key_[slot]);
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
    static constexpr std::size_t EMPTY_SENTINEL = static_cast<std::size_t>(-1);

    static constexpr auto make_lengths() noexcept {
        std::array<std::size_t, TableSize> lens{};
        for (std::size_t i = 0; i < TableSize; ++i)
            lens[i] = (KeyIndex[i] < N) ? Keys[i].length : EMPTY_SENTINEL;
        return lens;
    }

    static constexpr auto lengths = make_lengths();

    static constexpr auto make_packed_keys() noexcept {
        std::array<uint64_t, TableSize> result{};
        for (std::size_t i = 0; i < TableSize; ++i) {
            if (KeyIndex[i] < N) {
                for (std::size_t j = 0; j < Keys[i].length; ++j)
                    result[i] |= static_cast<uint64_t>(static_cast<unsigned char>(Keys[i].data[j])) << (j * 8);
            }
        }
        return result;
    }

    static constexpr auto packed_keys_ = make_packed_keys();

    // Load byte at index idx if idx < len, otherwise 0, without branching.
    // Always loads from a valid address (falls back to p[0] when out of range).
    // Load byte at index idx if idx < len, otherwise 0, without branching.
    [[nodiscard]] inline __attribute__((always_inline)) static constexpr uint64_t safe_byte(const char* p, std::size_t len, std::size_t idx) noexcept {
        const std::size_t has_it = static_cast<std::size_t>(idx < len);   // 0 or 1
        const std::size_t safe_idx = idx & -has_it;                       // idx or 0
        const uint64_t byte_val = static_cast<unsigned char>(p[safe_idx]);
        return byte_val & -static_cast<uint64_t>(has_it);                 // byte or 0
    }


    [[nodiscard]] inline __attribute__((always_inline)) static constexpr bool compare_key(const char* p, std::size_t len, std::size_t slot) noexcept {
        if consteval {
            for (std::size_t i = 0; i < len; ++i)
                if (p[i] != Keys[slot].data[i]) return false;
            return true;
        } else {
            uint64_t input_val = static_cast<unsigned char>(p[0]);
            if constexpr (MaxKeyLen >= 2) input_val |= safe_byte(p, len, 1) << 8;
            if constexpr (MaxKeyLen >= 3) input_val |= safe_byte(p, len, 2) << 16;
            if constexpr (MaxKeyLen >= 4) input_val |= safe_byte(p, len, 3) << 24;
            if constexpr (MaxKeyLen >= 5) input_val |= safe_byte(p, len, 4) << 32;
            if constexpr (MaxKeyLen >= 6) input_val |= safe_byte(p, len, 5) << 40;
            if constexpr (MaxKeyLen >= 7) input_val |= safe_byte(p, len, 6) << 48;
            if constexpr (MaxKeyLen >= 8) input_val |= safe_byte(p, len, 7) << 56;
            if constexpr (MaxKeyLen <= 8) {
                return input_val == packed_keys_[slot];
            } else {
                if(len <= 8) {
                    return input_val == packed_keys_[slot];
                }
                if(input_val != packed_keys_[slot]) {
                    return false;
                }
                if(len > 8) {
                    for (std::size_t i = 8; i < len; ++i)
                        if (p[i] != Keys[slot].data[i]) return false;
                }
                return true;
            }
        }
    }

public:
    [[nodiscard]] inline __attribute__((always_inline)) constexpr bool contains(std::string_view key) const noexcept {
        std::size_t slot = compute_hash(key);
        if (slot >= TableSize || key.size() != lengths[slot]) return false;
        return compare_key(key.data(), key.size(), slot);
    }

    [[nodiscard]] inline __attribute__((always_inline)) constexpr std::optional<std::size_t> index_of(std::string_view key) const noexcept {
        std::size_t slot = compute_hash(key);
        if (slot >= TableSize || key.size() != lengths[slot]) return std::nullopt;
        if (!compare_key(key.data(), key.size(), slot)) return std::nullopt;
        return static_cast<std::size_t>(KeyIndex[slot]);
    }

    [[nodiscard]] inline __attribute__((always_inline)) constexpr std::optional<std::size_t> lookup(std::string_view key) const noexcept {
        return index_of(key);
    }
};

// ============================================================================
// perfect_hash_map
// ============================================================================

template <std::size_t N, typename ValueT, std::size_t TableSize = N, std::size_t MaxKeyLen = 64>
struct perfect_hash_map {
    perfect_hash_set<N, TableSize, MaxKeyLen> set_;
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
    static constexpr std::size_t EMPTY_SENTINEL = static_cast<std::size_t>(-1);

    static constexpr auto make_lengths() noexcept {
        std::array<std::size_t, TableSize> lens{};
        for (std::size_t i = 0; i < TableSize; ++i)
            lens[i] = (KeyIndex[i] < N) ? Keys[i].length : EMPTY_SENTINEL;
        return lens;
    }

    static constexpr auto lengths = make_lengths();
    // first 8 bytes of key for quick rejection of non-matching keys
    static constexpr auto make_packed_keys() noexcept {
        std::array<uint64_t, TableSize> result{};
        for (std::size_t i = 0; i < TableSize; ++i) {
            if (KeyIndex[i] < N) {
                for (std::size_t j = 0; j < Keys[i].length; ++j)
                    result[i] |= static_cast<uint64_t>(static_cast<unsigned char>(Keys[i].data[j])) << (j * 8);
            }
        }
        return result;
    }

    static constexpr auto packed_keys_ = make_packed_keys();

    // Load byte at index idx if idx < len, otherwise 0, without branching.
    [[nodiscard]] inline __attribute__((always_inline)) static constexpr uint64_t safe_byte(const char* p, std::size_t len, std::size_t idx) noexcept {
        const std::size_t has_it = static_cast<std::size_t>(idx < len);   // 0 or 1
        const std::size_t safe_idx = idx & -has_it;                       // idx or 0
        const uint64_t byte_val = static_cast<unsigned char>(p[safe_idx]);
        return byte_val & -static_cast<uint64_t>(has_it);                 // byte or 0
    }

    [[nodiscard]] inline __attribute__((always_inline)) static constexpr bool compare_key(const char* p, std::size_t len, std::size_t slot) noexcept {
        if consteval {
            for (std::size_t i = 0; i < len; ++i)
                if (p[i] != Keys[slot].data[i]) return false;
            return true;
        } else {
            uint64_t input_val = static_cast<unsigned char>(p[0]);
            if constexpr (MaxKeyLen >= 2) input_val |= safe_byte(p, len, 1) << 8;
            if constexpr (MaxKeyLen >= 3) input_val |= safe_byte(p, len, 2) << 16;
            if constexpr (MaxKeyLen >= 4) input_val |= safe_byte(p, len, 3) << 24;
            if constexpr (MaxKeyLen >= 5) input_val |= safe_byte(p, len, 4) << 32;
            if constexpr (MaxKeyLen >= 6) input_val |= safe_byte(p, len, 5) << 40;
            if constexpr (MaxKeyLen >= 7) input_val |= safe_byte(p, len, 6) << 48;
            if constexpr (MaxKeyLen >= 8) input_val |= safe_byte(p, len, 7) << 56;
            if constexpr (MaxKeyLen <= 8) {
                return input_val == packed_keys_[slot];
            } else {
                if(len <= 8) {
                    return input_val == packed_keys_[slot];
                }
                if(input_val != packed_keys_[slot]) {
                    return false;
                }
                if(len > 8) {
                    for (std::size_t i = 8; i < len; ++i)
                        if (p[i] != Keys[slot].data[i]) return false;
                }
                return true;
            }
        }
    }

public:
    [[nodiscard]] inline __attribute__((always_inline)) constexpr bool contains(std::string_view key) const noexcept {
        std::size_t slot = compute_hash(key);
        if (slot >= TableSize || key.size() != lengths[slot]) return false;
        return compare_key(key.data(), key.size(), slot);
    }

    [[nodiscard]] inline __attribute__((always_inline)) constexpr std::optional<std::size_t> index_of(std::string_view key) const noexcept {
        std::size_t slot = compute_hash(key);
        if (slot >= TableSize || key.size() != lengths[slot]) return std::nullopt;
        if (!compare_key(key.data(), key.size(), slot)) return std::nullopt;
        return static_cast<std::size_t>(KeyIndex[slot]);
    }

    [[nodiscard]] inline __attribute__((always_inline)) constexpr std::optional<ValueT> lookup(std::string_view key) const noexcept {
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
    constexpr std::size_t MaxLen = detail::max_key_length(keys) > 0 ? detail::max_key_length(keys) : 1;
    return perfect_hash_set<N, M, MaxLen>{keys, data};
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
    constexpr std::size_t MaxLen = detail::max_key_length(keys) > 0 ? detail::max_key_length(keys) : 1;
    return perfect_hash_map<N, ValueT, M, MaxLen>{keys, values, data};
}

} // namespace ConstexprCore

#endif // CONSTEXPRCORE_PERFECT_HASH_H
