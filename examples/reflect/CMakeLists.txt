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

# C++26 with reflection support
target_compile_features(constexprcore_reflect INTERFACE cxx_std_26)
target_compile_options(constexprcore_reflect INTERFACE
    $<$<CXX_COMPILER_ID:Clang,AppleClang>:-freflection>
    $<$<CXX_COMPILER_ID:GNU>:-freflection>
)

# Constexpr step limits for compile-time PHF generation
target_compile_options(constexprcore_reflect INTERFACE
    $<$<CXX_COMPILER_ID:Clang,AppleClang>:-fconstexpr-steps=100000000>
    $<$<CXX_COMPILER_ID:GNU>:-fconstexpr-ops-limit=100000000>
)

# Demo executable
add_executable(reflect_demo examples/basic_usage.cpp)
target_link_libraries(reflect_demo PRIVATE ConstexprCore::reflect)

# Tests (only if doctest is available)
if(TARGET doctest::doctest OR TARGET doctest_with_main)
    add_executable(reflect_tests tests/test_reflect.cpp)
    target_link_libraries(reflect_tests PRIVATE
        ConstexprCore::reflect
    )
    # doctest is included directly in the test file via DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
    target_include_directories(reflect_tests PRIVATE
        ${doctest_SOURCE_DIR}/doctest
    )
    add_test(NAME reflect_tests COMMAND reflect_tests)
endif()
