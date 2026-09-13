// Compile with:  c++ -std=c++23 -I. amalgamation_demo.cpp -o demo
#include "perfect_hash.h"

#include <cstdio>

using namespace ConstexprCore;

static constexpr auto methods = make_perfect_map<
    kv<"GET", 0>, kv<"PUT", 1>, kv<"POST", 2>, kv<"HEAD", 3>,
    kv<"PATCH", 4>, kv<"TRACE", 5>, kv<"DELETE", 6>, kv<"OPTIONS", 7>>();

static_assert(*methods.lookup("POST") == 2);
static_assert(!methods.lookup("BREW").has_value());

int main() {
    for (const char* probe : {"GET", "OPTIONS", "BREW"}) {
        auto hit = methods.lookup(probe);
        std::printf("%-8s -> %s\n", probe, hit ? "found" : "not found");
    }
    std::printf("built with %s\n", methods.algorithm_name().data());
    return 0;
}
