FetchContent_Declare(
    benchmark
    GIT_REPOSITORY https://github.com/google/benchmark.git
    GIT_TAG v1.9.1
)
set(BENCHMARK_ENABLE_TESTING OFF CACHE BOOL "" FORCE)
set(BENCHMARK_ENABLE_INSTALL OFF CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(benchmark)

FetchContent_Declare(
    counters
    GIT_REPOSITORY https://github.com/lemire/counters.git
    GIT_TAG v3.0.0
)
FetchContent_MakeAvailable(counters)


add_executable(bench_protocol
    bench_protocol.cpp
)

target_link_libraries(bench_protocol PRIVATE
    ConstexprCore::perfect_hash
    counters::counters
)

add_executable(phf_bench bench_lookup.cpp)
target_link_libraries(phf_bench PRIVATE
    ConstexprCore::perfect_hash
    benchmark::benchmark
    benchmark::benchmark_main
)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    message(WARNING "Building benchmarks in debug mode may affect performance measurements.")
endif()
if(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    target_compile_options(phf_bench PRIVATE -fconstexpr-steps=500000000)
endif()
