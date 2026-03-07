# ConstexprCore/perfect_hash

Compile-time perfect hashing for C++23. Build zero-collision hash sets and maps entirely at compile time — only flat arrays survive to runtime.

Uses a gperf-style association-value algorithm computed entirely in `consteval` context, producing `O(1)` lookups with no runtime construction cost.

## How it works

The generator runs at compile time in two phases:

1. **Position selection** — choose a minimal set of character positions that distinguish all keys. Positions are ranked by discriminating power and selected via a bounded backtracking search.
2. **Association-value solving** — assign a value to each character such that `h(key) = len(key) + sum(asso[key[pos]])` maps every key to a unique slot. Collisions are resolved iteratively by bumping the least-frequent character's association value.

At runtime, only the flat `asso_values` table, the selected positions, and a slot-to-key mapping survive — the lookup is a few additions and a single string comparison.

## Usage

### Perfect hash set

```cpp
#include <ConstexprCore/perfect_hash.h>

using namespace ConstexprCore;

constexpr auto methods = make_perfect_set<"GET", "POST", "PUT", "DELETE", "PATCH">();

bool is_valid_method(std::string_view s) {
    return methods.contains(s);
}
```

### Perfect hash map

```cpp
#include <ConstexprCore/perfect_hash.h>

using namespace ConstexprCore;

enum class Method { GET, POST, PUT, DELETE, PATCH };

constexpr auto methods = make_perfect_map<
    kv<"GET",    Method::GET>,
    kv<"POST",   Method::POST>,
    kv<"PUT",    Method::PUT>,
    kv<"DELETE", Method::DELETE>,
    kv<"PATCH",  Method::PATCH>
>();

std::optional<Method> parse_method(std::string_view s) {
    return methods.lookup(s);
}
```

## Building

Requires a C++23 compiler and CMake 3.20+.

```bash
cmake -B build
cmake --build build
```

### Tests

Tests are built by default (`PH_BUILD_TESTS=ON`):

```bash
ctest --test-dir build --output-on-failure
```

### Benchmarks

```bash
cmake -B build -DPH_BUILD_BENCHMARKS=ON
cmake --build build
./build/benchmarks/phf_benchmarks
```

## Dependencies

- [ConstexprCore/useful_abstractions](https://github.com/ConstexprCore/useful_abstractions) — fetched automatically via CMake `FetchContent`
- [doctest](https://github.com/doctest/doctest) v2.4.12 (tests only)
- [Google Benchmark](https://github.com/google/benchmark) v1.8.3 (benchmarks only)

## License

MIT
