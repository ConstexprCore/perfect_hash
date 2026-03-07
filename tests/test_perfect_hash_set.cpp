#include <doctest/doctest.h>
#include <ConstexprCore/perfect_hash.h>

TEST_SUITE("perfect_hash_set") {

    TEST_CASE("construction and size") {
        constexpr auto greek_set = ConstexprCore::make_perfect_set<"alpha", "beta", "gamma">();
        static_assert(greek_set.size() == 3);
        CHECK(greek_set.size() == 3);
    }

    TEST_CASE("contains positive") {
        constexpr auto greek_set = ConstexprCore::make_perfect_set<"alpha", "beta", "gamma">();
        static_assert(greek_set.contains("alpha"));
        static_assert(greek_set.contains("beta"));
        static_assert(greek_set.contains("gamma"));
        CHECK(greek_set.contains("alpha"));
        CHECK(greek_set.contains("beta"));
        CHECK(greek_set.contains("gamma"));
    }

    TEST_CASE("contains negative") {
        constexpr auto greek_set = ConstexprCore::make_perfect_set<"alpha", "beta", "gamma">();
        static_assert(!greek_set.contains("delta"));
        static_assert(!greek_set.contains(""));
        static_assert(!greek_set.contains("alph"));
        static_assert(!greek_set.contains("alphaa"));
        CHECK_FALSE(greek_set.contains("delta"));
        CHECK_FALSE(greek_set.contains(""));
        CHECK_FALSE(greek_set.contains("alph"));
        CHECK_FALSE(greek_set.contains("alphaa"));
    }

    TEST_CASE("index_of returns declaration order") {
        constexpr auto greek_set = ConstexprCore::make_perfect_set<"alpha", "beta", "gamma">();
        static_assert(greek_set.index_of("alpha") == 0);
        static_assert(greek_set.index_of("beta") == 1);
        static_assert(greek_set.index_of("gamma") == 2);
        CHECK(greek_set.index_of("alpha") == 0);
        CHECK(greek_set.index_of("beta") == 1);
        CHECK(greek_set.index_of("gamma") == 2);
    }

    TEST_CASE("index_of returns nullopt for missing keys") {
        constexpr auto greek_set = ConstexprCore::make_perfect_set<"alpha", "beta", "gamma">();
        static_assert(!greek_set.index_of("delta").has_value());
        static_assert(!greek_set.index_of("").has_value());
        CHECK_FALSE(greek_set.index_of("delta").has_value());
        CHECK_FALSE(greek_set.index_of("").has_value());
    }

    TEST_CASE("key_at") {
        constexpr auto greek_set = ConstexprCore::make_perfect_set<"alpha", "beta", "gamma">();
        static_assert(greek_set.key_at(0) == "alpha");
        static_assert(greek_set.key_at(1) == "beta");
        static_assert(greek_set.key_at(2) == "gamma");
        CHECK(greek_set.key_at(0) == "alpha");
        CHECK(greek_set.key_at(1) == "beta");
        CHECK(greek_set.key_at(2) == "gamma");
    }

    TEST_CASE("single element set") {
        constexpr auto single_set = ConstexprCore::make_perfect_set<"only">();
        static_assert(single_set.size() == 1);
        static_assert(single_set.contains("only"));
        static_assert(!single_set.contains("other"));
        static_assert(single_set.index_of("only") == 0);
        CHECK(single_set.contains("only"));
        CHECK_FALSE(single_set.contains("other"));
    }

}
