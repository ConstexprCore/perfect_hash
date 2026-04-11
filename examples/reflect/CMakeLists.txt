# ConstexprCore::reflect — Runtime struct field access via C++26 reflection + perfect hashing
#
# Requires a compiler with C++26 reflection support (P2996):
#   - Clang 20+ with -freflection
#   - GCC 15+ with -freflection

add_library(constexprcore_reflect INTERFACE)
add_library(ConstexprCore::reflect ALIAS constexprcore_reflect)

target_include_directories(constexprcore_reflect INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

target_link_libraries(constexprcore_reflect INTERFACE
    ConstexprCore::perfect_hash
)

# C++26 with reflection support.
# Bloomberg Clang P2996 fork: -freflection -fexpansion-statements -stdlib=libc++
# Best configured via CMAKE_CXX_FLAGS="-std=c++26 -freflection" at cmake configure time.
if(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    target_compile_options(constexprcore_reflect INTERFACE
        -freflection -fexpansion-statements -stdlib=libc++)
    target_link_options(constexprcore_reflect INTERFACE -stdlib=libc++)
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_compile_options(constexprcore_reflect INTERFACE -freflection)
endif()

# Constexpr step limits for compile-time PHF generation
target_compile_options(constexprcore_reflect INTERFACE
    $<$<CXX_COMPILER_ID:Clang,AppleClang>:-fconstexpr-steps=100000000>
    $<$<CXX_COMPILER_ID:GNU>:-fconstexpr-ops-limit=100000000>
)

# Demo executable
add_executable(reflect_demo examples/basic_usage.cpp)
target_link_libraries(reflect_demo PRIVATE ConstexprCore::reflect)

# Tests
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
