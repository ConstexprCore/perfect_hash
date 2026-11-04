// Inputs that end near the end of a 4 KB block. The SIMD compares load 16
// bytes at a time, so for an input that starts in the last 15 bytes of a
// block, page_safe_load_16 must not read into the next block: it may not be
// mapped. These tests cover every key length at every such offset.
#include <ostream>
#include <doctest/doctest.h>
#include <ConstexprCore/perfect_hash.h>

#include <algorithm>
#include <array>
#include <cstddef>
#include <cstring>
#include <optional>
#include <string_view>
#if defined(__unix__) || defined(__APPLE__)
#include <sys/mman.h>
#include <unistd.h>
#endif

TEST_CASE("16-byte chunk loads are exact at every offset around a 4 KB boundary") {
    // Inputs end in the first block or cross into the second. The second
    // block is mapped, so a crossing input may be loaded in place.
    alignas(4096) static std::array<char, 8192> buffer{};
    for (std::size_t i = 0; i < buffer.size(); ++i)
        buffer[i] = static_cast<char>((i * 151 + 7) & 255);
    for (std::size_t len = 0; len <= 16; ++len) {
        for (std::size_t offset = 4064; offset <= 4096; ++offset) {
            CAPTURE(len);
            CAPTURE(offset);
            const char* p = buffer.data() + offset;
            const auto chunk = ConstexprCore::detail::load_chunk16(p, len);
            CHECK(ConstexprCore::detail::lane0(chunk) == ConstexprCore::detail::key_lane(p, len, 0));
            CHECK(ConstexprCore::detail::lane1(chunk) == ConstexprCore::detail::key_lane(p, len, 1));
        }
    }
}

#if defined(__unix__) || defined(__APPLE__)
namespace {

// MaxKeyLen 5, 15 and 16: the 8-byte compare, and the 16-byte compare with
// and without the key length in byte 15.
constexpr auto protocol_set = ConstexprCore::make_perfect_set<
    "http", "https", "ftp", "ws", "wss", "file">();
constexpr auto header_set = ConstexprCore::make_perfect_set<
    "Accept", "Accept-Encoding", "Authorization", "Cache-Control", "Connection",
    "Content-Encoding", "Content-Length", "Content-Type", "Cookie", "Date",
    "Host", "If-None-Match", "Location", "Origin", "Referer", "Server",
    "Set-Cookie", "User-Agent", "Vary", "Via">();
constexpr auto header15_set = ConstexprCore::make_perfect_set<
    "Accept", "Accept-Encoding", "Authorization", "Cache-Control", "Connection",
    "Content-Length", "Content-Type", "Cookie", "Date", "Host",
    "If-None-Match", "Location", "Origin", "Referer", "Server",
    "Set-Cookie", "User-Agent", "Vary", "Via", "X-Forwarded-For">();

// MaxKeyLen 17..32: the two-chunk compare (branch-free on targets with a byte
// shuffle), with keys both shorter and longer than 16 bytes.
constexpr auto counter_set = ConstexprCore::make_perfect_set<
    "total_items", "successful_operations", "failed_operations", "warnings", "errors",
    "retries", "bytes_processed", "records_read", "records_matched", "records_written">();

template <typename Set>
std::optional<std::size_t> expected_index(const Set& set, std::string_view probe) {
    for (std::size_t i = 0; i < set.size(); ++i)
        if (set.key_at(i) == probe) return i;
    return std::nullopt;
}

// Every prefix of every key, and every key followed by 1, 2 or 16 more
// bytes, ending 0..16 bytes before `end`, and each of those with one byte
// flipped. The probes that start in the last 15 bytes of the block take the
// page-safe path.
template <typename Set>
void check_probes_before(const Set& set, char* end) {
    for (std::size_t k = 0; k < set.size(); ++k) {
        const std::string_view key = set.key_at(k);
        auto check_len = [&](std::size_t len) {
            for (std::size_t gap = 0; gap <= 16; ++gap) {
                char* p = end - gap - len;
                std::memcpy(p, key.data(), std::min(len, key.size()));
                for (std::size_t i = key.size(); i < len; ++i)
                    p[i] = static_cast<char>(i == key.size() ? 0 : key.size());
                const std::string_view probe(p, len);
                CAPTURE(probe);
                CAPTURE(gap);
                CHECK(set.contains(probe) == expected_index(set, probe).has_value());
                CHECK(set.index_of(probe) == expected_index(set, probe));
                for (std::size_t i = 0; i < len; ++i) {
                    p[i] ^= 0x01;
                    CHECK(set.index_of(probe) == expected_index(set, probe));
                    p[i] ^= 0x01;
                }
            }
        };
        for (std::size_t len = 1; len <= key.size() + 2; ++len) check_len(len);
        check_len(key.size() + 16);
    }
}

} // namespace

TEST_CASE("classic lookups are exact for inputs that end at a protected page") {
    const long page_size = sysconf(_SC_PAGESIZE);
    REQUIRE(page_size > 0);
    const std::size_t bytes = static_cast<std::size_t>(page_size) * 2;
    void* mapping = mmap(nullptr, bytes, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANON, -1, 0);
    REQUIRE(mapping != MAP_FAILED);
    struct unmap_on_exit {
        void* mapping;
        std::size_t bytes;
        ~unmap_on_exit() { munmap(mapping, bytes); }
    } cleanup{mapping, bytes};
    // Reading any byte at or past `end` faults.
    char* end = static_cast<char*>(mapping) + page_size;
    REQUIRE(mprotect(end, static_cast<std::size_t>(page_size), PROT_NONE) == 0);
    check_probes_before(protocol_set, end);
    check_probes_before(header_set, end);
    check_probes_before(header15_set, end);
    check_probes_before(counter_set, end);
}
#endif
