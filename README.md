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

### Constexpr perfect hash set

```cpp
#include <ConstexprCore/perfect_hash.h>

using namespace ConstexprCore;

constexpr auto methods = make_constexpr_perfect_set<"GET", "POST", "PUT", "DELETE", "PATCH">();

bool is_valid_method(std::string_view s) {
    return methods.contains(s);
}
```

### Constexpr perfect hash map

```cpp
#include <ConstexprCore/perfect_hash.h>

using namespace ConstexprCore;

enum class Method { GET, POST, PUT, DELETE, PATCH };

constexpr auto methods = make_constexpr_perfect_map<
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
./build/benchmarks/phf_bench
```

#### Benchmark design

The benchmark suite compares four lookup strategies across key sets of increasing size:

| Key set | N | Notes |
|---|---|---|
| Booleans | 2 | Tiny set |
| RGB colors | 3 | Small set |
| Protocols | 5 | Short prefixes |
| HTTP methods | 7 | Typical use case |
| C++ keywords | 15 | Medium set |
| Letters a-z | 26 | All same length — stresses asso_values |
| HTTP headers | 50 | Realistic large set |

Each key set is tested with three query mixes (positive-only, negative-only, 50/50 mixed) against:

- **PHF** — this library's `perfect_hash_set::contains()`
- **gperf** — GNU `gperf`-generated lookup (where applicable)
- **`std::unordered_set`** — stdlib hash table
- **Binary search** — `std::binary_search` over a sorted array

The gperf `.inc` baselines are pre-generated from the `.gperf` input files in `benchmarks/` using `gperf <file>.gperf > <file>_gperf.inc`.

#### Preventing constant-folding

Because PHF objects and key arrays are `constexpr`, the compiler can resolve every lookup at compile time if not careful. The benchmarks use `benchmark::DoNotOptimize(key)` on each key *before* the lookup call, which forces the compiler to treat the key as potentially modified and prevents it from constant-folding the result.

## Dependencies

- [ConstexprCore/useful_abstractions](https://github.com/ConstexprCore/useful_abstractions) — fetched automatically via CMake `FetchContent`
- [doctest](https://github.com/doctest/doctest) v2.4.12 (tests only)
- [Google Benchmark](https://github.com/google/benchmark) v1.8.3 (benchmarks only)

## License

MIT
