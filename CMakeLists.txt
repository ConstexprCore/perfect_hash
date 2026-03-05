cmake_minimum_required(VERSION 3.20)
project(perfect_hash
    VERSION 0.1.0
    DESCRIPTION "Compile-time perfect hashing for C++"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

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

# Tests
option(PHF_BUILD_TESTS "Build tests" ON)
if(PHF_BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()

# Benchmarks
option(PHF_BUILD_BENCHMARKS "Build benchmarks" OFF)
if(PHF_BUILD_BENCHMARKS)
    add_subdirectory(benchmarks)
endif()
