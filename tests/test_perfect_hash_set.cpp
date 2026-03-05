#include <doctest/doctest.h>
#include <ConstexprCore/perfect_hash.h>

TEST_SUITE("perfect_hash_set") {

    TEST_CASE("construction and size") {
        constexpr auto set = ConstexprCore::make_perfect_set<"alpha", "beta", "gamma">();
        static_assert(set.size() == 3);
        CHECK(set.size() == 3);
    }

    TEST_CASE("contains positive") {
        constexpr auto set = ConstexprCore::make_perfect_set<"alpha", "beta", "gamma">();
        static_assert(set.contains("alpha"));
        static_assert(set.contains("beta"));
        static_assert(set.contains("gamma"));
        CHECK(set.contains("alpha"));
        CHECK(set.contains("beta"));
        CHECK(set.contains("gamma"));
    }

    TEST_CASE("contains negative") {
        constexpr auto set = ConstexprCore::make_perfect_set<"alpha", "beta", "gamma">();
        static_assert(!set.contains("delta"));
        static_assert(!set.contains(""));
        static_assert(!set.contains("alph"));
        static_assert(!set.contains("alphaa"));
        CHECK_FALSE(set.contains("delta"));
        CHECK_FALSE(set.contains(""));
        CHECK_FALSE(set.contains("alph"));
        CHECK_FALSE(set.contains("alphaa"));
    }

    TEST_CASE("index_of returns declaration order") {
        constexpr auto set = ConstexprCore::make_perfect_set<"alpha", "beta", "gamma">();
        static_assert(set.index_of("alpha") == 0);
        static_assert(set.index_of("beta") == 1);
        static_assert(set.index_of("gamma") == 2);
        CHECK(set.index_of("alpha") == 0);
        CHECK(set.index_of("beta") == 1);
        CHECK(set.index_of("gamma") == 2);
    }

    TEST_CASE("index_of returns nullopt for missing keys") {
        constexpr auto set = ConstexprCore::make_perfect_set<"alpha", "beta", "gamma">();
        static_assert(!set.index_of("delta").has_value());
        static_assert(!set.index_of("").has_value());
        CHECK_FALSE(set.index_of("delta").has_value());
        CHECK_FALSE(set.index_of("").has_value());
    }

    TEST_CASE("key_at") {
        constexpr auto set = ConstexprCore::make_perfect_set<"alpha", "beta", "gamma">();
        static_assert(set.key_at(0) == "alpha");
        static_assert(set.key_at(1) == "beta");
        static_assert(set.key_at(2) == "gamma");
        CHECK(set.key_at(0) == "alpha");
        CHECK(set.key_at(1) == "beta");
        CHECK(set.key_at(2) == "gamma");
    }

    TEST_CASE("single element set") {
        constexpr auto set = ConstexprCore::make_perfect_set<"only">();
        static_assert(set.size() == 1);
        static_assert(set.contains("only"));
        static_assert(!set.contains("other"));
        static_assert(set.index_of("only") == 0);
        CHECK(set.contains("only"));
        CHECK_FALSE(set.contains("other"));
    }

}
