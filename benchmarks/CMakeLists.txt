include(FetchContent)

FetchContent_Declare(
    benchmark
    GIT_REPOSITORY https://github.com/google/benchmark.git
    GIT_TAG v1.8.3
)
set(BENCHMARK_ENABLE_TESTING OFF CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(benchmark)

add_executable(phf_benchmarks
    bench_lookup.cpp
)

target_link_libraries(phf_benchmarks PRIVATE
    ConstexprCore::perfect_hash
    benchmark::benchmark
    benchmark::benchmark_main
)

target_compile_options(phf_benchmarks PRIVATE
    $<$<CXX_COMPILER_ID:GNU,Clang,AppleClang>:-Wall -Wextra -O2>
    $<$<CXX_COMPILER_ID:MSVC>:/W4 /O2>
)
