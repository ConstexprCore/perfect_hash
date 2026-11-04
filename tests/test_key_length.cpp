// Lookups of inputs that differ from a key only in length. Short keys keep
// their length next to the key bytes (perfect_hash_set::KEY_COMPARE_CHECKS_LEN
// and LEN_IN_DATA_BYTE15), and the comparison picks its mask row with
// len & 15 or len & 31. The probes target both: keys followed by zero bytes,
// inputs 16 or 32 bytes longer than a key, inputs longer than every key,
// inputs whose own byte at a length position holds a key's length, and
// 255-byte inputs, the length an empty slot was once marked with. Every key
// set mixes in keys with zero bytes.
#include <ostream>
#include <doctest/doctest.h>
#include <ConstexprCore/perfect_hash.h>

#include <algorithm>
#include <array>
#include <cstddef>
#include <optional>
#include <string>
#include <string_view>
#include <vector>

using namespace std::string_view_literals;

namespace {

template <const auto& Keys>
consteval auto set_of() {
    constexpr auto plan = ConstexprCore::compute_phf(Keys);
    constexpr std::size_t K = std::max<std::size_t>(ConstexprCore::detail::max_key_length(Keys), 1);
    return ConstexprCore::make_perfect_set_from_phf<Keys.size(), plan.table_size, K>(Keys, plan);
}

template <const auto& Keys>
consteval auto map_of() {
    constexpr auto plan = ConstexprCore::compute_phf(Keys);
    constexpr std::size_t K = std::max<std::size_t>(ConstexprCore::detail::max_key_length(Keys), 1);
    std::array<int, Keys.size()> values{};
    for (std::size_t i = 0; i < Keys.size(); ++i) values[i] = static_cast<int>(100 + i);
    return ConstexprCore::perfect_hash_map<Keys.size(), int, plan.table_size, K>{Keys, values, plan};
}

// One key set per comparison layout, plus the two lengths around it that
// keep the separate length test.
constexpr std::array k1_keys{""sv, "a"sv, "\0"sv};                                  // direct table
constexpr std::array k4_keys{"a"sv, "ab"sv, "abc"sv, "abcd"sv, "\0"sv, "a\0"sv,
                             "a\0c"sv, "\0\0\0\0"sv};                               // overlap encoding
constexpr std::array k5_keys{"http"sv, "https"sv, "ftp"sv, "ws"sv, "wss"sv,
                             "a\0b\0c"sv};                                          // byte 7
constexpr std::array k7_keys{"abcdefg"sv, "abcdef"sv, "a"sv, "\0\0\0\0\0\0\0"sv,
                             "ab\0\0\0\0g"sv, "\x07"sv};                            // byte 7, full row
constexpr std::array k8_keys{"abcdefgh"sv, "abcdefg"sv, "a"sv,
                             "\0\0\0\0\0\0\0\0"sv, "abc\0\0\0\0h"sv};               // byte 15
constexpr std::array k15_keys{"Accept-Encoding"sv, "Accept"sv, "Accept-Encodin\0"sv,
                              "\0"sv, "Content-Type"sv, "\x0f"sv,
                              "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"sv};                  // byte 15, full row
constexpr std::array k16_keys{"application/json"sv, "text/html"sv, "a\0"sv,
                              "application/jso\0"sv};                               // separate test
constexpr std::array k17_keys{"application/json5"sv, "text/html"sv, "a\0"sv,
                              "application/json\0"sv};                              // separate test
constexpr std::array empty2_keys{""sv, "ab"sv, "ac"sv};
constexpr std::array empty7_keys{""sv, "abcdefg"sv, "\0"sv};
constexpr std::array empty10_keys{""sv, "abcdefghij"sv, "\0\0"sv};

template <std::size_t N>
std::optional<std::size_t> reference_index(const std::array<std::string_view, N>& keys, std::string_view probe) {
    const auto it = std::find(keys.begin(), keys.end(), probe);
    if (it == keys.end()) return std::nullopt;
    return static_cast<std::size_t>(it - keys.begin());
}

template <std::size_t N>
std::vector<std::string> probes_for(const std::array<std::string_view, N>& keys) {
    std::size_t max_len = 0;
    for (auto k : keys) max_len = std::max(max_len, k.size());
    // 255 bytes: the length an empty slot was once marked with.
    std::vector<std::string> probes{"", std::string(1, '\0'), std::string(255, '\0'),
                                    std::string(255, 'a'), std::string(256, '\0'),
                                    std::string(300, 'x')};
    for (auto k : keys) {
        const std::string key(k);
        probes.push_back(key);
        for (std::size_t len = 0; len < key.size(); ++len)
            probes.push_back(key.substr(0, len));
        // One byte more: zero, the stored length bytes, the sentinel 0xFF.
        for (int b : {0, 1, 0x7f, 0x80, 0xff, static_cast<int>(key.size()),
                      static_cast<int>(max_len), static_cast<int>(max_len + 1)})
            probes.push_back(key + static_cast<char>(b));
        // 16 and 32 bytes longer: the same mask row as the key itself when
        // the row index is len & 15 or len & 31.
        for (std::size_t extra : {std::size_t{16}, std::size_t{32}})
            for (char fill : {'\0', 'a'})
                probes.push_back(key + std::string(extra, fill));
        // Zero-padded to the lengths around each layout's length byte.
        for (std::size_t len : {max_len, max_len + 1, std::size_t{7}, std::size_t{8},
                                std::size_t{9}, std::size_t{15}, std::size_t{16},
                                std::size_t{17}, std::size_t{32}, std::size_t{33}})
            if (len > key.size()) probes.push_back(key + std::string(len - key.size(), '\0'));
        // The input's own byte at a length position holds a key's length.
        for (std::size_t pos : {std::size_t{7}, std::size_t{15}}) {
            if (pos < key.size()) continue;
            for (auto other : keys) {
                std::string forged = key + std::string(pos - key.size(), '\0');
                forged.push_back(static_cast<char>(other.size()));
                probes.push_back(forged);
                probes.push_back(forged + 'x');
            }
        }
        for (std::size_t i = 0; i < key.size(); ++i) {
            for (char flip : {'\x01', '\x80'}) {
                std::string t = key;
                t[i] = static_cast<char>(t[i] ^ flip);
                probes.push_back(t);
            }
        }
    }
    return probes;
}

template <const auto& Keys>
void check_lookups() {
    static constexpr auto set = set_of<Keys>();
    static constexpr auto map = map_of<Keys>();
    for (const std::string& probe : probes_for(Keys)) {
        CAPTURE(probe.size());
        CAPTURE(probe);
        const auto expected = reference_index(Keys, probe);
        CHECK(set.contains(probe) == expected.has_value());
        CHECK(set.index_of(probe) == expected);
        CHECK(map.contains(probe) == expected.has_value());
        const auto value = map.lookup(probe);
        CHECK(value.has_value() == expected.has_value());
        if (value && expected) CHECK(*value == static_cast<int>(100 + *expected));
    }
    for (std::size_t i = 0; i < Keys.size(); ++i)
        CHECK(set.key_at(i) == Keys[i]);
}

// The compile-time comparison takes the byte loop; check it agrees.
constexpr auto k15_set = set_of<k15_keys>();
static_assert(k15_set.contains("Accept-Encoding"sv));
static_assert(k15_set.contains("Accept-Encodin\0"sv));
static_assert(!k15_set.contains("Accept-Encoding\0"sv));
static_assert(!k15_set.contains("Accept-Encoding\x0f"sv));
static_assert(!k15_set.contains("Accept\0"sv));
static_assert(k15_set.index_of("\x0f"sv) == 5);
constexpr auto k5_set = set_of<k5_keys>();
static_assert(k5_set.contains("a\0b\0c"sv));
static_assert(!k5_set.contains("a\0b\0c\0"sv));
static_assert(!k5_set.contains("http\0\0\0\x04"sv));

} // namespace

TEST_CASE("lookups compare the key length: MaxKeyLen 1") { check_lookups<k1_keys>(); }
TEST_CASE("lookups compare the key length: MaxKeyLen 4") { check_lookups<k4_keys>(); }
TEST_CASE("lookups compare the key length: MaxKeyLen 5") { check_lookups<k5_keys>(); }
TEST_CASE("lookups compare the key length: MaxKeyLen 7") { check_lookups<k7_keys>(); }
TEST_CASE("lookups compare the key length: MaxKeyLen 8") { check_lookups<k8_keys>(); }
TEST_CASE("lookups compare the key length: MaxKeyLen 15") { check_lookups<k15_keys>(); }
TEST_CASE("lookups compare the key length: MaxKeyLen 16") { check_lookups<k16_keys>(); }
TEST_CASE("lookups compare the key length: MaxKeyLen 17") { check_lookups<k17_keys>(); }
TEST_CASE("lookups compare the key length: sets that contain the empty key") {
    check_lookups<empty2_keys>();
    check_lookups<empty7_keys>();
    check_lookups<empty10_keys>();
}
