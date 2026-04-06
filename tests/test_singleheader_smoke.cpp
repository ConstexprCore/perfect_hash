#include "perfect_hash.h"

#include <optional>

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

int main() {
    auto post = methods.lookup("POST");
    if (!post || *post != HttpMethod::post) {
        return 1;
    }
    if (methods.contains("DELETE")) {
        return 1;
    }
    return 0;
}