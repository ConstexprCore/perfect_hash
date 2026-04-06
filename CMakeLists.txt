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

# Enable NEON/SSE2 two-pass comparison for MaxKeyLen 17-32 on supported platforms.
target_compile_definitions(perfect_hash INTERFACE
    $<$<BOOL:$<PLATFORM_ID:Darwin>>:CONSTEXPRCORE_USE_NEON_FOR_32_BYTE_COMPARE=1>
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
