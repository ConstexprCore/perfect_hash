FetchContent_Declare(
    benchmark
    GIT_REPOSITORY https://github.com/google/benchmark.git
    GIT_TAG v1.9.1
)
set(BENCHMARK_ENABLE_TESTING OFF CACHE BOOL "" FORCE)
set(BENCHMARK_ENABLE_INSTALL OFF CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(benchmark)

add_executable(phf_bench bench_lookup.cpp)
target_link_libraries(phf_bench PRIVATE
    ConstexprCore::perfect_hash
    benchmark::benchmark
    benchmark::benchmark_main
)
target_compile_options(phf_bench PRIVATE -fconstexpr-steps=100000000)
