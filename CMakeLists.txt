cmake_minimum_required(VERSION 3.20)
project(perfect_hash
    VERSION 0.1.0
    DESCRIPTION "Compile-time perfect hashing for C++"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release CACHE STRING "Choose the type of build." FORCE)
endif()

option(CONSTEXPRCORE_SANITIZE "Enable address sanitizer" OFF)
if(CONSTEXPRCORE_SANITIZE)
    if(MSVC)
        add_compile_options(/fsanitize=address)
        add_link_options(/fsanitize=address)
    else()
        add_compile_options(-fsanitize=address -fno-omit-frame-pointer)
        add_link_options(-fsanitize=address)
    endif()
endif()

include(FetchContent)

set(UA_BUILD_TESTS OFF CACHE BOOL "" FORCE)

FetchContent_Declare(
    useful_abstractions
    GIT_REPOSITORY https://github.com/ConstexprCore/useful_abstractions.git
    GIT_TAG        master
)
FetchContent_MakeAvailable(useful_abstractions)

find_package(Python3 COMPONENTS Interpreter QUIET)

set(PH_SINGLEHEADER_AVAILABLE OFF)
if(Python3_Interpreter_FOUND)
    set(PH_SINGLEHEADER_OUTPUT_DIR "${CMAKE_CURRENT_BINARY_DIR}/singleheader")
    set(PH_SINGLEHEADER_OUTPUT "${PH_SINGLEHEADER_OUTPUT_DIR}/perfect_hash.h")
    set(PH_SINGLEHEADER_GENERATOR "${CMAKE_CURRENT_SOURCE_DIR}/tools/generate_singleheader.py")
    set(PH_FIXED_STRING_HEADER
        "${useful_abstractions_SOURCE_DIR}/include/ConstexprCore/fixed_string.h")

    add_custom_command(
        OUTPUT "${PH_SINGLEHEADER_OUTPUT}"
        COMMAND ${CMAKE_COMMAND} -E make_directory "${PH_SINGLEHEADER_OUTPUT_DIR}"
        COMMAND ${Python3_EXECUTABLE} "${PH_SINGLEHEADER_GENERATOR}"
            --output "${PH_SINGLEHEADER_OUTPUT}"
            --fixed-string "${PH_FIXED_STRING_HEADER}"
            --gperf-generator "${CMAKE_CURRENT_SOURCE_DIR}/include/ConstexprCore/detail/gperf_generator.h"
            --neon-compare "${CMAKE_CURRENT_SOURCE_DIR}/include/ConstexprCore/detail/neon_compare.h"
            --sse2-compare "${CMAKE_CURRENT_SOURCE_DIR}/include/ConstexprCore/detail/sse2_compare.h"
            --lsx-compare "${CMAKE_CURRENT_SOURCE_DIR}/include/ConstexprCore/detail/lsx_compare.h"
            --simd16 "${CMAKE_CURRENT_SOURCE_DIR}/include/ConstexprCore/detail/simd16.h"
            --wide-generator "${CMAKE_CURRENT_SOURCE_DIR}/include/ConstexprCore/detail/wide_generator.h"
            --perfect-hash "${CMAKE_CURRENT_SOURCE_DIR}/include/ConstexprCore/perfect_hash.h"
            --wide-perfect-hash "${CMAKE_CURRENT_SOURCE_DIR}/include/ConstexprCore/wide_perfect_hash.h"
        DEPENDS
            "${PH_SINGLEHEADER_GENERATOR}"
            "${PH_FIXED_STRING_HEADER}"
            "${CMAKE_CURRENT_SOURCE_DIR}/include/ConstexprCore/detail/gperf_generator.h"
            "${CMAKE_CURRENT_SOURCE_DIR}/include/ConstexprCore/detail/neon_compare.h"
            "${CMAKE_CURRENT_SOURCE_DIR}/include/ConstexprCore/detail/sse2_compare.h"
            "${CMAKE_CURRENT_SOURCE_DIR}/include/ConstexprCore/detail/lsx_compare.h"
            "${CMAKE_CURRENT_SOURCE_DIR}/include/ConstexprCore/detail/simd16.h"
            "${CMAKE_CURRENT_SOURCE_DIR}/include/ConstexprCore/detail/wide_generator.h"
            "${CMAKE_CURRENT_SOURCE_DIR}/include/ConstexprCore/perfect_hash.h"
            "${CMAKE_CURRENT_SOURCE_DIR}/include/ConstexprCore/wide_perfect_hash.h"
        VERBATIM
        COMMENT "Generating single-header perfect_hash.h"
    )

    add_custom_target(perfect_hash_singleheader DEPENDS "${PH_SINGLEHEADER_OUTPUT}")
    install(FILES "${PH_SINGLEHEADER_OUTPUT}" DESTINATION include OPTIONAL)
    set(PH_SINGLEHEADER_AVAILABLE ON)
else()
    message(STATUS "Python3 interpreter not found; skipping single-header generation target")
endif()

# Header-only library
add_library(perfect_hash INTERFACE)
add_library(ConstexprCore::perfect_hash ALIAS perfect_hash)

target_include_directories(perfect_hash INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

target_link_libraries(perfect_hash INTERFACE
    ConstexprCore::useful_abstractions
)

# Tests
option(PH_BUILD_TESTS "Build tests" ON)
if(PH_BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()

# Benchmarks
option(PH_BUILD_BENCHMARKS "Build benchmarks" ON)
if(PH_BUILD_BENCHMARKS)
    add_subdirectory(benchmarks)
endif()

# Examples (requires C++26 reflection support)
option(PH_BUILD_EXAMPLES "Build examples (requires C++26 -freflection)" ON)
if(PH_BUILD_EXAMPLES)
    add_subdirectory(examples/reflect)
endif()
