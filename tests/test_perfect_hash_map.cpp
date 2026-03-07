#include <doctest/doctest.h>
#include <ConstexprCore/perfect_hash.h>

TEST_SUITE("perfect_hash_map") {

    TEST_CASE("construction and size") {
        constexpr auto status_map = ConstexprCore::make_perfect_map<
            ConstexprCore::kv<"OK", 200>,
            ConstexprCore::kv<"Not Found", 404>,
            ConstexprCore::kv<"Internal Server Error", 500>
        >();
        static_assert(status_map.size() == 3);
        CHECK(status_map.size() == 3);
    }

    TEST_CASE("lookup positive") {
        constexpr auto status_map = ConstexprCore::make_perfect_map<
            ConstexprCore::kv<"OK", 200>,
            ConstexprCore::kv<"Not Found", 404>,
            ConstexprCore::kv<"Internal Server Error", 500>
        >();
        static_assert(status_map.lookup("OK") == 200);
        static_assert(status_map.lookup("Not Found") == 404);
        static_assert(status_map.lookup("Internal Server Error") == 500);
        CHECK(status_map.lookup("OK") == 200);
        CHECK(status_map.lookup("Not Found") == 404);
        CHECK(status_map.lookup("Internal Server Error") == 500);
    }

    TEST_CASE("lookup negative") {
        constexpr auto status_map = ConstexprCore::make_perfect_map<
            ConstexprCore::kv<"OK", 200>,
            ConstexprCore::kv<"Not Found", 404>
        >();
        static_assert(!status_map.lookup("Bad Request").has_value());
        static_assert(!status_map.lookup("").has_value());
        CHECK_FALSE(status_map.lookup("Bad Request").has_value());
        CHECK_FALSE(status_map.lookup("").has_value());
    }

    TEST_CASE("contains") {
        constexpr auto status_map = ConstexprCore::make_perfect_map<
            ConstexprCore::kv<"OK", 200>,
            ConstexprCore::kv<"Not Found", 404>
        >();
        static_assert(status_map.contains("OK"));
        static_assert(status_map.contains("Not Found"));
        static_assert(!status_map.contains("Gone"));
        CHECK(status_map.contains("OK"));
        CHECK(status_map.contains("Not Found"));
        CHECK_FALSE(status_map.contains("Gone"));
    }

}
