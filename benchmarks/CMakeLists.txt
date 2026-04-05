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

FetchContent_Declare(
    pthash
    GIT_REPOSITORY https://github.com/jermp/pthash.git
    GIT_TAG master
)
FetchContent_Populate(pthash)

# Create our own target to avoid pthash's INTERFACE compile options
# (e.g. -march=native, -ggdb, -Wall) from propagating to our targets.
find_package(Threads REQUIRED)
add_library(pthash_headers INTERFACE)
target_include_directories(pthash_headers SYSTEM INTERFACE
    ${pthash_SOURCE_DIR}/include
    ${pthash_SOURCE_DIR}/external/mm_file/include
    ${pthash_SOURCE_DIR}/external/xxHash
    ${pthash_SOURCE_DIR}/external/bits/include
    ${pthash_SOURCE_DIR}/external/bits/external/essentials/include
)
target_compile_features(pthash_headers INTERFACE cxx_std_17)
target_link_libraries(pthash_headers INTERFACE Threads::Threads)

add_executable(bench_protocol
    bench_protocol.cpp
    pthash_wrapper.cpp
)

target_include_directories(bench_protocol PRIVATE
    ${constexpr_phf_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/gperf
)

target_link_libraries(bench_protocol PRIVATE
    ConstexprCore::perfect_hash
    counters::counters
    unordered_dense::unordered_dense
    pthash_headers
    absl::flat_hash_map
    frozen::frozen
)

add_executable(simd_experiments ../perf_viz/simd_experiments.cpp)
target_link_libraries(simd_experiments PRIVATE
    ConstexprCore::perfect_hash counters::counters)
if(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    target_compile_options(simd_experiments PRIVATE -fconstexpr-steps=2147483647)
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_compile_options(simd_experiments PRIVATE -fconstexpr-ops-limit=2147483647)
endif()

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    message(WARNING "Building benchmarks in debug mode may affect performance measurements.")
endif()
if(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    target_compile_options(bench_protocol PRIVATE -fconstexpr-steps=2147483647)
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_compile_options(bench_protocol PRIVATE -fconstexpr-ops-limit=2147483647)
endif()
