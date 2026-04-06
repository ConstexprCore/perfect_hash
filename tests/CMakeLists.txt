include(FetchContent)

FetchContent_Declare(
    doctest
    GIT_REPOSITORY https://github.com/doctest/doctest.git
    GIT_TAG v2.4.12
)
FetchContent_MakeAvailable(doctest)

add_executable(phf_tests
    main.cpp
    test_perfect_hash_set.cpp
    test_perfect_hash_map.cpp
    test_url_protocols.cpp
    test_http_methods.cpp
    test_edge_cases.cpp
)

target_link_libraries(phf_tests PRIVATE
    ConstexprCore::perfect_hash
    doctest::doctest
)

target_compile_options(phf_tests PRIVATE
    $<$<CXX_COMPILER_ID:GNU,Clang,AppleClang>:-Wall -Wextra -Wpedantic>
    $<$<CXX_COMPILER_ID:GNU>:-fconstexpr-ops-limit=1000000000>
    $<$<CXX_COMPILER_ID:Clang,AppleClang>:-fconstexpr-steps=1000000000>
    $<$<CXX_COMPILER_ID:MSVC>:/W4 /constexpr:steps1000000000>
)

include(${doctest_SOURCE_DIR}/scripts/cmake/doctest.cmake)
doctest_discover_tests(phf_tests)

if(PH_SINGLEHEADER_AVAILABLE)
    add_executable(phf_singleheader_smoke
        test_singleheader_smoke.cpp
    )

    target_include_directories(phf_singleheader_smoke PRIVATE
        "${PH_SINGLEHEADER_OUTPUT_DIR}"
    )

    target_compile_features(phf_singleheader_smoke PRIVATE cxx_std_23)
    target_compile_options(phf_singleheader_smoke PRIVATE
        $<$<CXX_COMPILER_ID:GNU,Clang,AppleClang>:-Wall -Wextra -Wpedantic>
        $<$<CXX_COMPILER_ID:GNU>:-fconstexpr-ops-limit=1000000000>
        $<$<CXX_COMPILER_ID:Clang,AppleClang>:-fconstexpr-steps=1000000000>
        $<$<CXX_COMPILER_ID:MSVC>:/W4 /constexpr:steps1000000000>
    )

    add_dependencies(phf_singleheader_smoke perfect_hash_singleheader)
    add_test(NAME phf_singleheader_smoke COMMAND phf_singleheader_smoke)
endif()
