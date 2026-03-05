#ifndef CONSTEXPRCORE_DETAIL_SEED_OR_INDEX_H
#define CONSTEXPRCORE_DETAIL_SEED_OR_INDEX_H

#include <cstddef>
#include <climits>

namespace ConstexprCore::detail {

struct seed_or_index {
    static constexpr std::size_t high_bit = std::size_t{1} << (sizeof(std::size_t) * CHAR_BIT - 1);

    std::size_t value{0};

    [[nodiscard]] static constexpr seed_or_index make_seed(std::size_t s) noexcept {
        return {s & ~high_bit};
    }

    [[nodiscard]] static constexpr seed_or_index make_index(std::size_t i) noexcept {
        return {i | high_bit};
    }

    [[nodiscard]] constexpr bool is_seed() const noexcept {
        return (value & high_bit) == 0;
    }

    [[nodiscard]] constexpr bool is_index() const noexcept {
        return (value & high_bit) != 0;
    }

    [[nodiscard]] constexpr std::size_t seed() const noexcept {
        return value;
    }

    [[nodiscard]] constexpr std::size_t index() const noexcept {
        return value & ~high_bit;
    }
};

} // namespace ConstexprCore::detail

#endif // CONSTEXPRCORE_DETAIL_SEED_OR_INDEX_H
