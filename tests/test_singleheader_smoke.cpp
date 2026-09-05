#include "perfect_hash.h"

#include <optional>
#include <string>

enum class HttpMethod {
    get,
    post,
    put,
};

constexpr auto methods = ConstexprCore::make_perfect_map<
    ConstexprCore::kv<"GET", HttpMethod::get>,
    ConstexprCore::kv<"POST", HttpMethod::post>,
    ConstexprCore::kv<"PUT", HttpMethod::put>
>();

static_assert(methods.contains("GET"));
static_assert(!methods.contains("PATCH"));
static_assert(methods.lookup("POST") == HttpMethod::post);
static_assert(!methods.lookup("DELETE").has_value());

constexpr auto short_keys = ConstexprCore::make_perfect_set<
    "one", "two", "three", "four", "five", "six", "seven", "eight">();
static_assert(short_keys.contains("eight"));
static_assert(!short_keys.contains("nine"));

inline constexpr std::array<std::string_view, 2> long_keys{
    "first key longer than thirty-two bytes",
    "second key longer than thirty-two bytes"};
constexpr auto long_map = ConstexprCore::make_wide_perfect_index_map<long_keys>();
static_assert(long_map.lookup(long_keys[1]) == 1);
static_assert(!long_map.contains(std::string_view{}));

int main() {
    auto post = methods.lookup("POST");
    if (!post || *post != HttpMethod::post) {
        return 1;
    }
    if (methods.contains("DELETE")) {
        return 1;
    }
    if (!short_keys.contains(std::string("eight")) ||
        long_map.lookup(std::string(long_keys[1])) != 1) {
        return 1;
    }
    return 0;
}
