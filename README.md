# Billion-query-per-second lookup tables in C++ 
[![CI](https://github.com/ConstexprCore/perfect_hash/actions/workflows/ci.yml/badge.svg)](https://github.com/ConstexprCore/perfect_hash/actions/workflows/ci.yml)



Compile-time perfect hashing for C++. Build zero-collision hash sets and maps entirely at compile time — only flat arrays survive to runtime. Optimized for speed ! 


   * [Ridiculously fast](#ridiculously-fast)
   * [Usage](#usage)
      + [Perfect hash set](#perfect-hash-set)
      + [Perfect hash map](#perfect-hash-map)
   * [Building](#building)
      + [Single-header bundle](#single-header-bundle)
      + [Precompiled headers (PCH) for faster compiles](#precompiled-headers-pch-for-faster-compiles)
      + [Tests](#tests)
      + [Benchmarks](#benchmarks)
         - [Benchmark design](#benchmark-design)
   * [How it works](#how-it-works)
   * [License](#license)


## Ridiculously fast

We use an association-value algorithm computed entirely in `consteval` context, producing `O(1)` lookups with no runtime construction cost. You can precompile your header files for fast compile time.

Using an Apple M4 processor, with the URL protocol keys (`http`, `https`, `ftp`, `ws`, `wss`, `file`), we classify them as over 1 billion keys per second. It is four times faster than our closest competitor and ten times faster than the standard `std::unordered_map`.

| Method                    | billion queries/s  |
|---------------------------|-------|
| **ours**  | 1.08  |
| gperf  (command line)     | 0.23  |
| kronuz::phf               | 0.22  |
| frozen::unordered_map     | 0.16  |
| absl::flat_hash_map       | 0.14  |
| pthash                    | 0.14  |
| naive                     | 0.19  |
| std::unordered_map        | 0.10  |
| ankerl::dense_hash_map    | 0.10  |

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

### Large key sets (more than 255 keys)

The same two factories keep working past 255 entries: they switch to the *wide* container
(`wide_perfect_hash_set` / `wide_perfect_hash_map`, header `wide_perfect_hash.h`), which
replaces gperf's chosen byte positions with a whole-key multiplicative hash plus a small
per-bucket pilot table — a compile-time PTHash. Every lookup is one multiply, one 16-bit
pilot load and one key load; values that fit in the spare bytes of a short key are stored
inside the key word itself. For generated key lists, pass a static-storage array by
reference:

```cpp
#include <ConstexprCore/wide_perfect_hash.h>

inline constexpr std::array<std::string_view, 5581> nasdaq_symbols = { "AAAP", "AACG", /* ... */ };

// values = declaration index, in the smallest integer type that fits
constexpr auto tickers = ConstexprCore::make_wide_perfect_index_map<nasdaq_symbols>();

// or with your own values
inline constexpr std::array<int, 5581> ids = { /* ... */ };
constexpr auto tickers2 = ConstexprCore::make_wide_perfect_map<nasdaq_symbols, ids>();

std::optional<std::uint16_t> id = tickers.lookup("AAPL");   // ~1.7 ns on an M3 Max
```

Measured (Apple M3 Max, shuffled hits): S&P 500 (503 symbols) **1.2 ns**, all Nasdaq-listed
symbols (5 581) **1.7 ns** — versus 2.4 / 3.0 ns for packing the symbol into a `uint64_t`
and probing `absl::flat_hash_map`, 4.8 / 5.9 ns for a 27-ary array trie, and 7.6 / 6.6 ns
for `absl::flat_hash_map<std::string_view, int>`. Building the 5 581-key map takes ~5 s of
compile time; raise `-fconstexpr-steps` (clang) / `-fconstexpr-ops-limit` (GCC) as the
benchmarks' `CMakeLists.txt` does.

### Long keys (more than 32 bytes)

Keys of any length up to 4 080 bytes are verified with a fixed number of 16-byte SIMD
chunk compares — no loop over characters, no branch on the length; 17–32-byte keys are
compared fully branch-free (shift-realigned loads, safe for any input address). 40
fully-qualified Java class names (24–54 bytes): **2.05 ns** per lookup, where the
previous scalar byte loop took 23 ns. Short keys (≤ 7 bytes) in sets of 8+ keys also
route to the wide container automatically — the S&P 100 drops from 1.77 to 1.32 ns.


## Building

Requires a C++23 compiler and CMake 3.20+.

```bash
cmake -B build
cmake --build build
```

### Single-header bundle

If Python 3 is available when you run CMake configure, the build exposes a
target that bundles the library into a single distributable header.

Generate it with:

```bash
cmake -S . -B build
cmake --build build --target perfect_hash_singleheader
```

The generated file is:

```text
build/singleheader/perfect_hash.h
```

You can then ship that file directly and include it as:

```cpp
#include "perfect_hash.h"
```

The single header contains, in order:

- `fixed_string.h`
- `detail/gperf_generator.h`
- `detail/neon_compare.h`
- `detail/sse2_compare.h`
- `perfect_hash.h`

During bundling, the corresponding internal `#include <ConstexprCore/...>` lines
inside `perfect_hash.h` are commented out so the generated file is self-contained.

If the `perfect_hash_singleheader` target does not exist, re-run configure after
installing Python 3 so CMake can detect it:

```bash
cmake -S . -B build
cmake --build build --target perfect_hash_singleheader
```

A smoke test for the generated header is also included in the test suite and can
be run with:

```bash
ctest --test-dir build --output-on-failure -R phf_singleheader_smoke
```

### Precompiled headers (PCH) for faster compiles

Calling `make_constexpr_perfect_map` on large sets of keys can require relatively long compile time (more than milliseconds). The solution is to use precompiled headers.

If you are experimenting with a heavy header like `fun.h`, a precompiled header
can significantly reduce incremental compile time for `fun.cpp`.

For example, use the following as your `fun.h` header, it contains the call to `make_perfect_map`.

```cpp
#pragma once
#include "perfect_hash.h"

#include <optional>

enum class HttpMethod {
    get,
    post,
    put,
    patch,
    head,
    options_,
    trace,
    connect,
    propfind,
    proppatch,
    mkcol,
    copy,
    move,
    lock,
    unlock,
    report,
    mkactivity,
    checkout,
    merge,
    msearch,
    notify,
    subscribe,
    unsubscribe,
    purge,
    link,
    unlink
};

constexpr auto methods = ConstexprCore::make_perfect_map<
    ConstexprCore::kv<"GET", HttpMethod::get>,
    ConstexprCore::kv<"POST", HttpMethod::post>,
    ConstexprCore::kv<"PUT", HttpMethod::put>,
    ConstexprCore::kv<"PATCH", HttpMethod::patch>,
    ConstexprCore::kv<"HEAD", HttpMethod::head>,
    ConstexprCore::kv<"OPTIONS", HttpMethod::options_>,
    ConstexprCore::kv<"TRACE", HttpMethod::trace>,
    ConstexprCore::kv<"CONNECT", HttpMethod::connect>,
    ConstexprCore::kv<"PROPFIND", HttpMethod::propfind>,
    ConstexprCore::kv<"PROPPATCH", HttpMethod::proppatch>,
    ConstexprCore::kv<"MKCOL", HttpMethod::mkcol>,
    ConstexprCore::kv<"COPY", HttpMethod::copy>,
    ConstexprCore::kv<"MOVE", HttpMethod::move>,
    ConstexprCore::kv<"LOCK", HttpMethod::lock>,
    ConstexprCore::kv<"UNLOCK", HttpMethod::unlock>,
    ConstexprCore::kv<"REPORT", HttpMethod::report>,
    ConstexprCore::kv<"MKACTIVITY", HttpMethod::mkactivity>,
    ConstexprCore::kv<"CHECKOUT", HttpMethod::checkout>,
    ConstexprCore::kv<"MERGE", HttpMethod::merge>,
    ConstexprCore::kv<"MSEARCH", HttpMethod::msearch>,
    ConstexprCore::kv<"NOTIFY", HttpMethod::notify>,
    ConstexprCore::kv<"SUBSCRIBE", HttpMethod::subscribe>,
    ConstexprCore::kv<"UNSUBSCRIBE", HttpMethod::unsubscribe>,
    ConstexprCore::kv<"PURGE", HttpMethod::purge>,
    ConstexprCore::kv<"LINK", HttpMethod::link>,
    ConstexprCore::kv<"UNLINK", HttpMethod::unlink>
>();
```

and `fun.cpp` might be as follows.


```cpp
#include "fun.h"
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
```

As long as you do not change the header, the map will remained precomputed and your compile
times will be fast.

Using GCC from the command line:

```bash
g++ -std=c++23 -O2 -x c++-header fun.h -o fun.h.gch
g++ -std=c++23 -O2 fun.cpp -o fun
```


With CMake, the equivalent is `target_precompile_headers`:

```cmake
add_executable(fun_demo fun.cpp)
target_precompile_headers(fun_demo PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/fun.h"
)
target_compile_features(fun_demo PRIVATE cxx_std_23)
```

Then build as usual:

```bash
cmake -S . -B build
cmake --build build --target fun_demo
```

This lets CMake manage the compiler-specific PCH details automatically.





### Tests

Tests are built by default (`PH_BUILD_TESTS=ON`):

```bash
ctest --test-dir build --output-on-failure
```

### Benchmarks

```bash
cmake -B build -DPH_BUILD_BENCHMARKS=ON
cmake --build build
./build/benchmarks/bench_protocol
```

Run a filtered subset with `--filter`:

```bash
./build/benchmarks/bench_protocol --filter hits,make_perfect_map,protocol
./build/benchmarks/bench_protocol --filter hits,misses,stock
./build/benchmarks/bench_protocol --verify
```

#### Benchmark design

The benchmark suite compares multiple lookup strategies across key sets of varying size and key length:

| Key set | Filter token | N | MaxKeyLen | Notes |
|---|---|---|---|---|
| URL Protocols | `protocol` | 6 | 5 | Short keys, small set |
| S&P 100 Tickers | `stock` | 100 | 5 | 100 short keys — H&D algorithm |
| C++ Keywords | `keyword` | 15 | 6 | Medium-sized set |
| HTTP Headers | `header` | 20 | 17 | Long keys — H&D algorithm |
| MIME Types | `mime` | 15 | 24 | Long keys, slashes |
| Letters a-z | `letters` | 26 | 1 | All same length — direct lookup fast path |
| HTTP Headers 50 | `headers50` | 50 | 19 | Realistic large header set |
| JavaScript Reserved Words | `jsreserved` | 45 | 10 | Medium keys, dense set |

Each key set is tested with three query mixes (positive-only, negative-only, 50/50 mixed) against:

- **`make_perfect_map`** — this library's compile-time PHF
- **`gperf`** — GNU `gperf`-generated lookup
- **`std::unordered_map`** — stdlib hash table
- **`ankerl::unordered_dense`** — fast flat hash map
- **`absl::flat_hash_map`** — Google's SwissTable
- **`frozen::unordered_map`** — compile-time perfect hash
- **`kronuz::phf`** — hash-based perfect hash
- **`pthash`** — PTHash minimal perfect hash
- **Naive** — if/else chain (binary search for the 100-key ticker set)

The gperf `.inc` baselines are pre-generated from the `.gperf` input files in `benchmarks/` using `gperf <file>.gperf > <file>_gperf.inc`.


## How it works

The generator runs at compile time in two phases:

1. **Position selection** — choose a minimal set of character positions that distinguish all keys. Positions are ranked by discriminating power and selected via a bounded backtracking search.
2. **Association-value solving** — assign a value to each character such that `h(key) = len(key) + sum(asso[key[pos]])` maps every key to a unique slot. Collisions are resolved iteratively by bumping the least-frequent character's association value.

At runtime, only the flat `asso_values` table, the selected positions, and a slot-to-key mapping survive — the lookup is a few additions and a single string comparison.


## License

MIT
