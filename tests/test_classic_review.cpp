#include <doctest/doctest.h>
#include <ConstexprCore/perfect_hash.h>

#include <array>
#include <string>
#include <string_view>

namespace {

// All three interior positions are needed. With a smaller position budget,
// generation must fall through to whole-key hashing instead of exceeding it.
constexpr std::array<std::string_view, 8> interior_keys{
    "baseaaa_z", "baseaab_z", "baseaba_z", "baseabb_z",
    "basebaa_z", "basebab_z", "basebba_z", "basebbb_z",
};
constexpr auto interior_plan = ConstexprCore::detail::compute_phf(interior_keys);
constexpr ConstexprCore::perfect_hash_set<8, interior_plan.table_size, 9>
    interior_set{interior_keys, interior_plan};
static_assert(ConstexprCore::detail::MAX_POSITIONS >= 3 ||
              interior_plan.num_positions == ConstexprCore::detail::FULLHASH_SENTINEL);

// Exercise H&D directly so the position-budget configurations also verify
// that its hash-variant metadata fits, independently of the gperf solver.
constexpr std::array<std::string_view, 6> method_keys{
    "GET", "PUT", "POST", "PATCH", "DELETE", "HEAD",
};
constexpr auto method_plan = []() consteval {
    ConstexprCore::detail::phf_result<method_keys.size()> plan{};
    if (!ConstexprCore::detail::try_compute_phf_hd<method_keys.size(), 16>(method_keys, plan))
        throw "H&D test key set must fit";
    return plan;
}();
constexpr ConstexprCore::perfect_hash_set<method_keys.size(), 16, 6>
    method_set{method_keys, method_plan};
static_assert(method_set.algorithm_name() == "H&D");

constexpr auto empty_long_set = ConstexprCore::make_perfect_set<
    "", "abcdefghijklmnopqa", "abcdefghijklmnopqb">();
constexpr auto empty_short_set = ConstexprCore::make_perfect_set<"", "ab", "ac">();
constexpr auto empty_medium_set = ConstexprCore::make_perfect_set<"", "abcde", "abcdf">();
constexpr auto empty_long_map = ConstexprCore::make_perfect_map<
    ConstexprCore::kv<"", 11>,
    ConstexprCore::kv<"abcdefghijklmnopqa", 22>,
    ConstexprCore::kv<"abcdefghijklmnopqb", 33>>();

static_assert(empty_long_set.contains(std::string_view{}));
static_assert(empty_long_set.index_of(std::string_view{}) == 0);
static_assert(empty_long_map.lookup(std::string_view{}) == 11);

template <std::size_t Length>
consteval auto long_factory_key(char last) {
    ConstexprCore::fixed_string<char, Length> key{};
    for (std::size_t i = 0; i < Length; ++i)
        key[i] = static_cast<char>('a' + i % 26);
    key.back() = last;
    return key;
}

template <std::size_t Length>
void check_long_factories() {
    static constexpr auto first = long_factory_key<Length>('1');
    static constexpr auto second = long_factory_key<Length>('2');
    static constexpr auto set = ConstexprCore::make_perfect_set<first, second>();
    static constexpr auto map = ConstexprCore::make_perfect_map<
        ConstexprCore::kv<first, 11>, ConstexprCore::kv<second, 22>>();
    static_assert(set.contains(first.view()));
    static_assert(set.index_of(second.view()) == 1);
    static_assert(map.lookup(first.view()) == 11);
    static_assert(map.lookup(second.view()) == 22);

    std::string input{first.view()};
    CHECK(set.contains(input));
    CHECK(set.index_of(input) == 0);
    CHECK(set.key_at(0) == input);
    CHECK(map.lookup(input) == 11);
    input.back() = '2';
    CHECK(set.contains(input));
    CHECK(map.lookup(input) == 22);
    input[Length / 2] = '!';
    CHECK_FALSE(set.contains(input));
    CHECK_FALSE(map.lookup(input).has_value());
    input[Length / 2] = first[Length / 2];
    input.pop_back();
    CHECK_FALSE(set.contains(input));
    CHECK_FALSE(map.lookup(input).has_value());
}

} // namespace

TEST_CASE("classic position budget bounds search and retains fallback hashing") {
    for (std::size_t i = 0; i < interior_keys.size(); ++i) {
        const std::string key{interior_keys[i]};
        CHECK(interior_set.contains(key));
        CHECK(interior_set.index_of(key) == i);
        CHECK(interior_set.key_at(i) == key);
    }
    CHECK_FALSE(interior_set.contains("baseaac_z"));
    CHECK_FALSE(interior_set.contains("baseaaa_x"));
}

TEST_CASE("classic H&D hash variant fits the configured position budget") {
    for (std::size_t i = 0; i < method_keys.size(); ++i) {
        const std::string key{method_keys[i]};
        CHECK(method_set.contains(key));
        CHECK(method_set.index_of(key) == i);
    }
    CHECK_FALSE(method_set.contains("OPTIONS"));
    CHECK_FALSE(method_set.contains("BAD"));
}

TEST_CASE("classic sets and maps accept null empty string views") {
    const std::string_view empty;
    CHECK(empty_long_set.contains(empty));
    CHECK(empty_long_set.index_of(empty) == 0);
    CHECK(empty_long_set.slot_match(empty).has_value());
    CHECK(empty_short_set.contains(empty));
    CHECK(empty_medium_set.contains(empty));
    CHECK(empty_long_map.contains(empty));
    CHECK(empty_long_map.lookup(empty) == 11);
    CHECK_FALSE(empty_long_set.contains("abcdefghijklmnopqc"));
    CHECK_FALSE(empty_long_map.lookup("abcdefghijklmnopqc").has_value());
}

TEST_CASE("ordinary factories support the full wide key-length range") {
    check_long_factories<255>();
    check_long_factories<4080>();
}
