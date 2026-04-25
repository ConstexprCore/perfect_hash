# ConstexprCore::reflect — Runtime struct field access via C++26 reflection + perfect hashing
#
# Requires a compiler with C++26 reflection support (P2996):
#   - Bloomberg Clang P2996 fork with -freflection
#   - GCC 15+ with -freflection (when available)

# ── Fetch dependencies ──────────────────────────────────────────────────────
include(FetchContent)

FetchContent_Declare(
    counters
    GIT_REPOSITORY https://github.com/lemire/counters.git
    GIT_TAG v3.0.0
)
FetchContent_MakeAvailable(counters)

# ── Detect C++26 reflection support ─────────────────────────────────────────��
# Try compiling a minimal reflection snippet. If the compiler doesn't support
# it, skip all targets with a message instead of failing the build.

if(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    set(_REFLECT_TEST_FLAGS "-std=c++26 -freflection -fexpansion-statements -stdlib=libc++")
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    set(_REFLECT_TEST_FLAGS "-std=c++26 -freflection")
else()
    set(_REFLECT_TEST_FLAGS "")
endif()

set(_REFLECT_TEST_SOURCE "
#if __has_include(<meta>)
#include <meta>
#elif __has_include(<experimental/meta>)
#include <experimental/meta>
#else
#error No reflection header found
#endif
struct S { int x; double y; };
consteval auto test() { return std::meta::nonstatic_data_members_of(^^S, std::meta::access_context::current()).size(); }
static_assert(test() == 2);
int main() {}
")

file(WRITE "${CMAKE_CURRENT_BINARY_DIR}/_reflect_check.cpp" "${_REFLECT_TEST_SOURCE}")

try_compile(HAS_CPP26_REFLECTION
    "${CMAKE_BINARY_DIR}/cmake_try_compile_reflect"
    SOURCES "${CMAKE_CURRENT_BINARY_DIR}/_reflect_check.cpp"
    COMPILE_DEFINITIONS ${_REFLECT_TEST_FLAGS}
    OUTPUT_VARIABLE REFLECTION_COMPILE_OUTPUT
)

if(NOT HAS_CPP26_REFLECTION)
    message(STATUS "reflect: C++26 reflection compilation failed. Compiler output:\n${REFLECTION_COMPILE_OUTPUT}")
    message(STATUS "reflect: C++26 reflection not supported by this compiler, skipping reflect targets")
    return()
endif()

message(STATUS "reflect: C++26 reflection support detected")

# ── Library ──────────────────────────────────────────────────────────────────
add_library(constexprcore_reflect INTERFACE)
add_library(ConstexprCore::reflect ALIAS constexprcore_reflect)

target_include_directories(constexprcore_reflect INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

target_link_libraries(constexprcore_reflect INTERFACE
    ConstexprCore::perfect_hash
)



# Compiler flags for reflection support.
# Best configured via CMAKE_CXX_FLAGS="-std=c++26 -freflection" at cmake configure time.
if(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    target_compile_options(constexprcore_reflect INTERFACE
        -freflection -fexpansion-statements -stdlib=libc++)
    target_link_options(constexprcore_reflect INTERFACE -stdlib=libc++)
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_compile_options(constexprcore_reflect INTERFACE -std=c++26 -freflection)
endif()

target_compile_options(constexprcore_reflect INTERFACE
    $<$<CXX_COMPILER_ID:Clang,AppleClang>:-fconstexpr-steps=100000000>
    $<$<CXX_COMPILER_ID:GNU>:-fconstexpr-ops-limit=100000000>
)

# ── Demo ─────────────────────────────────────────────────────────────────────
add_executable(reflect_demo examples/basic_usage.cpp)
target_link_libraries(reflect_demo PRIVATE ConstexprCore::reflect)

# ── Benchmark ────────────────────────────────────────────────────────────────
add_executable(bench_reflect bench_reflect.cpp)
target_link_libraries(bench_reflect PRIVATE ConstexprCore::reflect counters::counters)

# ── Tests ────────────────────────────────────────────────────────────────────
if(TARGET doctest::doctest)
    add_executable(reflect_tests tests/test_reflect.cpp)
    target_link_libraries(reflect_tests PRIVATE
        ConstexprCore::reflect
        doctest::doctest
    )
    add_test(NAME reflect_tests COMMAND reflect_tests)
else()
    message(STATUS "reflect: doctest not found, skipping reflect_tests")
endif()
