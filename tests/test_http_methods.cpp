#include <doctest/doctest.h>
#include <ConstexprCore/perfect_hash.h>

TEST_SUITE("http_methods") {

    constexpr auto methods = ConstexprCore::make_perfect_set<
        "GET", "POST", "PUT", "DELETE", "PATCH", "HEAD", "OPTIONS"
    >();

    TEST_CASE("all methods found") {
        static_assert(methods.contains("GET"));
        static_assert(methods.contains("POST"));
        static_assert(methods.contains("PUT"));
        static_assert(methods.contains("DELETE"));
        static_assert(methods.contains("PATCH"));
        static_assert(methods.contains("HEAD"));
        static_assert(methods.contains("OPTIONS"));
        CHECK(methods.contains("GET"));
        CHECK(methods.contains("POST"));
        CHECK(methods.contains("PUT"));
        CHECK(methods.contains("DELETE"));
        CHECK(methods.contains("PATCH"));
        CHECK(methods.contains("HEAD"));
        CHECK(methods.contains("OPTIONS"));
    }

    TEST_CASE("unknown methods rejected") {
        static_assert(!methods.contains("CONNECT"));
        static_assert(!methods.contains("TRACE"));
        static_assert(!methods.contains("get"));
        static_assert(!methods.contains(""));
        static_assert(!methods.contains("GETS"));
        CHECK_FALSE(methods.contains("CONNECT"));
        CHECK_FALSE(methods.contains("TRACE"));
        CHECK_FALSE(methods.contains("get"));
        CHECK_FALSE(methods.contains(""));
        CHECK_FALSE(methods.contains("GETS"));
    }

    TEST_CASE("indices match declaration order") {
        static_assert(methods.index_of("GET") == 0);
        static_assert(methods.index_of("POST") == 1);
        static_assert(methods.index_of("PUT") == 2);
        static_assert(methods.index_of("DELETE") == 3);
        static_assert(methods.index_of("PATCH") == 4);
        static_assert(methods.index_of("HEAD") == 5);
        static_assert(methods.index_of("OPTIONS") == 6);
        CHECK(methods.index_of("GET") == 0);
        CHECK(methods.index_of("POST") == 1);
        CHECK(methods.index_of("PUT") == 2);
        CHECK(methods.index_of("DELETE") == 3);
        CHECK(methods.index_of("PATCH") == 4);
        CHECK(methods.index_of("HEAD") == 5);
        CHECK(methods.index_of("OPTIONS") == 6);
    }

}
