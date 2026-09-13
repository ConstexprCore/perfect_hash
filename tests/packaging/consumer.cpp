// Consumed the CMake way: the include path is the same whether perfect_hash
// came from add_subdirectory/FetchContent or from an installed package.
#include <ConstexprCore/perfect_hash.h>

#include <cstdio>

constexpr auto colors = ConstexprCore::make_perfect_map<
    ConstexprCore::kv<"red", 0>, ConstexprCore::kv<"green", 1>,
    ConstexprCore::kv<"blue", 2>, ConstexprCore::kv<"cyan", 3>>();

static_assert(*colors.lookup("green") == 1);
static_assert(!colors.lookup("puce").has_value());

int main() {
    if (!colors.contains("blue") || colors.contains("puce")) return 1;
    std::printf("ok: %zu keys, %s\n", colors.size(), colors.algorithm_name().data());
    return 0;
}
