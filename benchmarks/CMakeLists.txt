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

FetchContent_Declare(
    unordered_dense
    GIT_REPOSITORY https://github.com/martinus/unordered_dense.git
    GIT_TAG v4.5.0
)
FetchContent_MakeAvailable(unordered_dense)

set(ABSL_PROPAGATE_CXX_STD ON)
set(ABSL_BUILD_TESTING OFF)
set(ABSL_BUILD_TEST_HELPERS OFF)
FetchContent_Declare(
    abseil-cpp
    GIT_REPOSITORY https://github.com/abseil/abseil-cpp.git
    GIT_TAG 20240722.0
)
FetchContent_MakeAvailable(abseil-cpp)

FetchContent_Declare(
    frozen
    GIT_REPOSITORY https://github.com/serge-sans-paille/frozen.git
    GIT_TAG master
)
FetchContent_MakeAvailable(frozen)

FetchContent_Declare(
    constexpr_phf
    GIT_REPOSITORY https://github.com/Kronuz/constexpr-phf.git
    GIT_TAG master
)
FetchContent_Populate(constexpr_phf)

add_executable(bench_protocol
    bench_protocol.cpp
)

target_include_directories(bench_protocol PRIVATE
    ${constexpr_phf_SOURCE_DIR}
)

target_link_libraries(bench_protocol PRIVATE
    ConstexprCore::perfect_hash
    counters::counters
    unordered_dense::unordered_dense
    absl::flat_hash_map
    frozen::frozen
)

add_executable(simd_experiments ../perf_viz/simd_experiments.cpp)
target_link_libraries(simd_experiments PRIVATE
    ConstexprCore::perfect_hash counters::counters)
if(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    target_compile_options(simd_experiments PRIVATE -fconstexpr-steps=2147483647)
endif()

add_executable(phf_bench bench_lookup.cpp)
target_link_libraries(phf_bench PRIVATE
    ConstexprCore::perfect_hash
    benchmark::benchmark_main
)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    message(WARNING "Building benchmarks in debug mode may affect performance measurements.")
endif()
if(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    target_compile_options(phf_bench PRIVATE -fconstexpr-steps=500000000)
    target_compile_options(bench_protocol PRIVATE -fconstexpr-steps=2147483647)
endif()
