#ifndef CONSTEXPRCORE_DETAIL_SEEDED_HASH_H
#define CONSTEXPRCORE_DETAIL_SEEDED_HASH_H

#include <ConstexprCore/constexpr_hash.h>
#include <string_view>
#include <cstddef>

namespace ConstexprCore {

template <typename CharT = char, typename SizeT = std::size_t>
[[nodiscard]] constexpr SizeT
seeded_fnv1a(std::basic_string_view<CharT> str, SizeT seed) noexcept {
    using constants = detail::fnv1a_constants<SizeT>;
    SizeT hash = constants::offset_basis ^ seed;
    for (CharT c : str) {
        hash ^= static_cast<SizeT>(static_cast<unsigned char>(c));
        hash *= constants::prime;
    }
    return hash;
}

} // namespace ConstexprCore

#endif // CONSTEXPRCORE_DETAIL_SEEDED_HASH_H
