#include <doctest/doctest.h>
#include <ConstexprCore/detail/simd16.h>

#include <array>
#include <cstddef>
#include <cstdint>
#include <cstring>

namespace {

template <std::size_t MaxKeyLen>
void check_chunk_comparisons() {
    constexpr std::size_t span = ((MaxKeyLen + 15) / 16) * 16;
    alignas(4096) std::array<char, 8192> input{};
    alignas(16) std::array<char, span> stored{};
    // Exercise both sides of the conservative 4 KB guard, including keys
    // that end exactly at the boundary and keys that cross it.
    constexpr std::array<std::size_t, 13> offsets{
        0, 1, 7, 15, 31, 4048, 4063, 4079, 4080, 4081, 4094, 4095, 4096};

    for (std::size_t len = 0; len <= MaxKeyLen; ++len) {
        stored.fill(0);
        for (std::size_t i = 0; i < len; ++i)
            stored[i] = static_cast<char>((i * 73 + len * 11) & 255);
        for (std::size_t offset : offsets) {
            CAPTURE(MaxKeyLen);
            CAPTURE(len);
            CAPTURE(offset);
            char* p = input.data() + offset;
            std::memset(p, 0xA5, span);
            std::memcpy(p, stored.data(), len);
            REQUIRE(ConstexprCore::detail::compare_chunks<MaxKeyLen>(p, len, stored.data()));
            // Every chunk boundary, plus the final byte, must contribute to
            // equality even when the two NEON windows overlap.
            for (std::size_t pos = 0; pos < len; ++pos) {
                if (pos % 16 != 0 && pos % 16 != 15 && pos + 1 != len) continue;
                CAPTURE(pos);
                p[pos] ^= 0x55;
                CHECK_FALSE(ConstexprCore::detail::compare_chunks<MaxKeyLen>(p, len, stored.data()));
                p[pos] ^= 0x55;
            }
        }
    }
}

} // namespace

TEST_CASE("SIMD chunk lanes match the compile-time little-endian definition") {
    alignas(16) std::array<char, 16> bytes{};
    for (std::size_t i = 0; i < bytes.size(); ++i)
        bytes[i] = static_cast<char>((i * 73 + 129) & 255);
    for (std::size_t len = 0; len <= bytes.size(); ++len) {
        CAPTURE(len);
        const auto chunk = ConstexprCore::detail::load_chunk16(bytes.data(), len);
        CHECK(ConstexprCore::detail::lane0(chunk) == ConstexprCore::detail::key_lane(bytes.data(), len, 0));
        CHECK(ConstexprCore::detail::lane1(chunk) == ConstexprCore::detail::key_lane(bytes.data(), len, 1));
    }
}

TEST_CASE("chunk comparisons cover short tails, binary bytes, and page offsets") {
    check_chunk_comparisons<17>();
    check_chunk_comparisons<32>();
    check_chunk_comparisons<33>();
    check_chunk_comparisons<64>();
    check_chunk_comparisons<254>();
}

TEST_CASE("SIMD loads preserve short inputs with known object bounds") {
    alignas(16) constexpr std::array<char, 32> stored{'s', 'h', 'o', 'r', 't'};
    const auto chunk = ConstexprCore::detail::load_chunk16("short", 5);
    CHECK(ConstexprCore::detail::lane0(chunk) == ConstexprCore::detail::key_lane("short", 5, 0));
    CHECK(ConstexprCore::detail::lane1(chunk) == 0);
    CHECK(ConstexprCore::detail::compare_chunks<32>("short", 5, stored.data()));
#if CONSTEXPRCORE_HAS_SSE2
    CHECK(ConstexprCore::detail::sse2_compare_8("short", 5,
        ConstexprCore::detail::key_lane("short", 5, 0)));
    CHECK(ConstexprCore::detail::sse2_compare_16("short", 5, stored.data()));
#endif
}

#if !CONSTEXPRCORE_HAS_NEON && !CONSTEXPRCORE_HAS_SSE2 && !CONSTEXPRCORE_HAS_LSX
TEST_CASE("an empty scalar chunk needs no readable input bytes") {
    const auto chunk = ConstexprCore::detail::load_chunk16(nullptr, 0);
    CHECK(ConstexprCore::detail::lane0(chunk) == 0);
    CHECK(ConstexprCore::detail::lane1(chunk) == 0);
}
#endif
