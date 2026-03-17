include(FetchContent)

FetchContent_Declare(
    benchmark
    GIT_REPOSITORY https://github.com/google/benchmark.git
    GIT_TAG v1.8.3
)
set(BENCHMARK_ENABLE_TESTING OFF CACHE BOOL "" FORCE)
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

# bench_lookup requires gperf .inc files; only build if they exist
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/http_methods_gperf.inc")
    add_executable(phf_benchmarks bench_lookup.cpp)
    target_link_libraries(phf_benchmarks PRIVATE
        ConstexprCore::perfect_hash
        benchmark::benchmark
        benchmark::benchmark_main
    )
endif()

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    message(WARNING "Building benchmarks in debug mode may affect performance measurements.")
endif()
