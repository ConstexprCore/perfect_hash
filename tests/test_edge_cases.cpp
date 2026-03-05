#include <doctest/doctest.h>
#include <ConstexprCore/perfect_hash.h>

TEST_SUITE("edge_cases") {

    TEST_CASE("prefix strings") {
        constexpr auto set = ConstexprCore::make_perfect_set<"a", "ab", "abc", "abcd">();
        static_assert(set.contains("a"));
        static_assert(set.contains("ab"));
        static_assert(set.contains("abc"));
        static_assert(set.contains("abcd"));
        static_assert(!set.contains("abcde"));
        static_assert(!set.contains(""));
        static_assert(!set.contains("b"));
        CHECK(set.contains("a"));
        CHECK(set.contains("ab"));
        CHECK(set.contains("abc"));
        CHECK(set.contains("abcd"));
        CHECK_FALSE(set.contains("abcde"));
        CHECK_FALSE(set.contains(""));
        CHECK_FALSE(set.contains("b"));
    }

    TEST_CASE("similar strings") {
        constexpr auto set = ConstexprCore::make_perfect_set<
            "foo", "fop", "foq", "goo", "boo"
        >();
        static_assert(set.contains("foo"));
        static_assert(set.contains("fop"));
        static_assert(set.contains("foq"));
        static_assert(set.contains("goo"));
        static_assert(set.contains("boo"));
        static_assert(!set.contains("for"));
        static_assert(!set.contains("zoo"));
        CHECK(set.contains("foo"));
        CHECK(set.contains("fop"));
        CHECK(set.contains("foq"));
        CHECK(set.contains("goo"));
        CHECK(set.contains("boo"));
        CHECK_FALSE(set.contains("for"));
        CHECK_FALSE(set.contains("zoo"));
    }

    TEST_CASE("26 single-char strings") {
        constexpr auto letters = ConstexprCore::make_perfect_set<
            "a", "b", "c", "d", "e", "f", "g", "h", "i", "j",
            "k", "l", "m", "n", "o", "p", "q", "r", "s", "t",
            "u", "v", "w", "x", "y", "z"
        >();
        static_assert(letters.size() == 26);
        static_assert(letters.contains("a"));
        static_assert(letters.contains("m"));
        static_assert(letters.contains("z"));
        static_assert(!letters.contains("A"));
        static_assert(!letters.contains("1"));
        static_assert(!letters.contains(""));
        CHECK(letters.size() == 26);
        CHECK(letters.contains("a"));
        CHECK(letters.contains("m"));
        CHECK(letters.contains("z"));
        CHECK_FALSE(letters.contains("A"));
        CHECK_FALSE(letters.contains("1"));
        CHECK_FALSE(letters.contains(""));
    }

    TEST_CASE("single-char strings small set") {
        constexpr auto set = ConstexprCore::make_perfect_set<"x", "y", "z">();
        static_assert(set.contains("x"));
        static_assert(set.contains("y"));
        static_assert(set.contains("z"));
        static_assert(!set.contains("w"));
        static_assert(set.index_of("x") == 0);
        static_assert(set.index_of("y") == 1);
        static_assert(set.index_of("z") == 2);
        CHECK(set.contains("x"));
        CHECK(set.contains("y"));
        CHECK(set.contains("z"));
        CHECK_FALSE(set.contains("w"));
    }

    TEST_CASE("two element set") {
        constexpr auto set = ConstexprCore::make_perfect_set<"true", "false">();
        static_assert(set.size() == 2);
        static_assert(set.contains("true"));
        static_assert(set.contains("false"));
        static_assert(!set.contains("maybe"));
        static_assert(set.index_of("true") == 0);
        static_assert(set.index_of("false") == 1);
        CHECK(set.size() == 2);
        CHECK(set.contains("true"));
        CHECK(set.contains("false"));
        CHECK_FALSE(set.contains("maybe"));
    }

}
