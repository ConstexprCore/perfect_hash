#include <doctest/doctest.h>
#include <ConstexprCore/perfect_hash.h>

TEST_SUITE("perfect_hash_map") {

    TEST_CASE("construction and size") {
        constexpr auto map = ConstexprCore::make_perfect_map<
            ConstexprCore::kv<"OK", 200>,
            ConstexprCore::kv<"Not Found", 404>,
            ConstexprCore::kv<"Internal Server Error", 500>
        >();
        static_assert(map.size() == 3);
        CHECK(map.size() == 3);
    }

    TEST_CASE("lookup positive") {
        constexpr auto map = ConstexprCore::make_perfect_map<
            ConstexprCore::kv<"OK", 200>,
            ConstexprCore::kv<"Not Found", 404>,
            ConstexprCore::kv<"Internal Server Error", 500>
        >();
        static_assert(map.lookup("OK") == 200);
        static_assert(map.lookup("Not Found") == 404);
        static_assert(map.lookup("Internal Server Error") == 500);
        CHECK(map.lookup("OK") == 200);
        CHECK(map.lookup("Not Found") == 404);
        CHECK(map.lookup("Internal Server Error") == 500);
    }

    TEST_CASE("lookup negative") {
        constexpr auto map = ConstexprCore::make_perfect_map<
            ConstexprCore::kv<"OK", 200>,
            ConstexprCore::kv<"Not Found", 404>
        >();
        static_assert(!map.lookup("Bad Request").has_value());
        static_assert(!map.lookup("").has_value());
        CHECK_FALSE(map.lookup("Bad Request").has_value());
        CHECK_FALSE(map.lookup("").has_value());
    }

    TEST_CASE("contains") {
        constexpr auto map = ConstexprCore::make_perfect_map<
            ConstexprCore::kv<"OK", 200>,
            ConstexprCore::kv<"Not Found", 404>
        >();
        static_assert(map.contains("OK"));
        static_assert(map.contains("Not Found"));
        static_assert(!map.contains("Gone"));
        CHECK(map.contains("OK"));
        CHECK(map.contains("Not Found"));
        CHECK_FALSE(map.contains("Gone"));
    }

}
