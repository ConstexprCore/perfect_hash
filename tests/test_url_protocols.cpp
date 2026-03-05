#include <doctest/doctest.h>
#include <ConstexprCore/perfect_hash.h>

TEST_SUITE("url_protocols") {

    constexpr auto protocols = ConstexprCore::make_perfect_set<
        "http:", "https:", "ftp:", "sftp:", "file:"
    >();

    TEST_CASE("all protocols found") {
        static_assert(protocols.contains("http:"));
        static_assert(protocols.contains("https:"));
        static_assert(protocols.contains("ftp:"));
        static_assert(protocols.contains("sftp:"));
        static_assert(protocols.contains("file:"));
        CHECK(protocols.contains("http:"));
        CHECK(protocols.contains("https:"));
        CHECK(protocols.contains("ftp:"));
        CHECK(protocols.contains("sftp:"));
        CHECK(protocols.contains("file:"));
    }

    TEST_CASE("non-protocols rejected") {
        static_assert(!protocols.contains("ssh:"));
        static_assert(!protocols.contains("telnet:"));
        static_assert(!protocols.contains("http"));
        static_assert(!protocols.contains(""));
        static_assert(!protocols.contains("HTTP:"));
        CHECK_FALSE(protocols.contains("ssh:"));
        CHECK_FALSE(protocols.contains("telnet:"));
        CHECK_FALSE(protocols.contains("http"));
        CHECK_FALSE(protocols.contains(""));
        CHECK_FALSE(protocols.contains("HTTP:"));
    }

    TEST_CASE("indices are stable") {
        static_assert(protocols.index_of("http:") == 0);
        static_assert(protocols.index_of("https:") == 1);
        static_assert(protocols.index_of("ftp:") == 2);
        static_assert(protocols.index_of("sftp:") == 3);
        static_assert(protocols.index_of("file:") == 4);
        CHECK(protocols.index_of("http:") == 0);
        CHECK(protocols.index_of("https:") == 1);
        CHECK(protocols.index_of("ftp:") == 2);
        CHECK(protocols.index_of("sftp:") == 3);
        CHECK(protocols.index_of("file:") == 4);
    }

}
