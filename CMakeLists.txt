cmake_minimum_required(VERSION 3.20)
project(perfect_hash
    VERSION 0.2.0
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

# ---------------------------------------------------------------------------
# Single-header amalgamation
#
# singleheader/perfect_hash.h is checked in so that users can grab it straight
# from the repository; this target regenerates it from include/ plus the
# dependency headers. The script walks the include graph itself, so new headers
# are picked up without touching this file.
# ---------------------------------------------------------------------------
set(PH_SINGLEHEADER_SOURCE "${CMAKE_CURRENT_SOURCE_DIR}/singleheader/perfect_hash.h")
set(PH_SINGLEHEADER_AVAILABLE OFF)
if(Python3_Interpreter_FOUND)
    set(PH_SINGLEHEADER_OUTPUT_DIR "${CMAKE_CURRENT_BINARY_DIR}/singleheader")
    set(PH_SINGLEHEADER_OUTPUT "${PH_SINGLEHEADER_OUTPUT_DIR}/perfect_hash.h")
    set(PH_AMALGAMATE "${CMAKE_CURRENT_SOURCE_DIR}/singleheader/amalgamate.py")

    file(GLOB_RECURSE PH_PUBLIC_HEADERS CONFIGURE_DEPENDS
        "${CMAKE_CURRENT_SOURCE_DIR}/include/ConstexprCore/*.h")

    add_custom_command(
        OUTPUT "${PH_SINGLEHEADER_OUTPUT}"
        COMMAND ${CMAKE_COMMAND} -E make_directory "${PH_SINGLEHEADER_OUTPUT_DIR}"
        COMMAND ${Python3_EXECUTABLE} "${PH_AMALGAMATE}"
            --output "${PH_SINGLEHEADER_OUTPUT}"
            --demo "${PH_SINGLEHEADER_OUTPUT_DIR}/amalgamation_demo.cpp"
            --include-dir "${useful_abstractions_SOURCE_DIR}/include"
            --quiet
        DEPENDS "${PH_AMALGAMATE}" ${PH_PUBLIC_HEADERS}
            "${useful_abstractions_SOURCE_DIR}/include/ConstexprCore/fixed_string.h"
        VERBATIM
        COMMENT "Generating single-header perfect_hash.h"
    )

    add_custom_target(perfect_hash_singleheader DEPENDS "${PH_SINGLEHEADER_OUTPUT}")
    set(PH_SINGLEHEADER_AVAILABLE ON)

    # Refresh the checked-in copy under singleheader/ from a build tree.
    add_custom_target(perfect_hash_singleheader_update
        COMMAND ${Python3_EXECUTABLE} "${PH_AMALGAMATE}"
            --include-dir "${useful_abstractions_SOURCE_DIR}/include"
        COMMENT "Updating singleheader/perfect_hash.h in the source tree"
        VERBATIM
    )
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
option(PH_BUILD_TESTS "Build tests" ${PROJECT_IS_TOP_LEVEL})
if(PH_BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()

# Benchmarks
option(PH_BUILD_BENCHMARKS "Build benchmarks" ${PROJECT_IS_TOP_LEVEL})
if(PH_BUILD_BENCHMARKS)
    add_subdirectory(benchmarks)
endif()

# ---------------------------------------------------------------------------
# Install / export
#
# What gets installed is the amalgamated header, placed at the same include
# path the sources use, so `#include <ConstexprCore/perfect_hash.h>` works the
# same whether the library was consumed from source or from an install tree —
# and an installed copy needs no dependency, because the amalgamation bundles
# it. See README.md ("Using it as a CMake dependency").
# ---------------------------------------------------------------------------
option(PH_INSTALL "Generate the install target" ${PROJECT_IS_TOP_LEVEL})
if(PH_INSTALL)
    include(GNUInstallDirs)
    include(CMakePackageConfigHelpers)

    add_library(perfect_hash_installed INTERFACE)
    target_compile_features(perfect_hash_installed INTERFACE cxx_std_23)
    target_include_directories(perfect_hash_installed INTERFACE
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)
    set_target_properties(perfect_hash_installed PROPERTIES EXPORT_NAME perfect_hash)

    install(TARGETS perfect_hash_installed EXPORT perfect_hashTargets)

    # Prefer a freshly generated amalgamation when Python is available, and
    # fall back to the copy checked in under singleheader/.
    if(PH_SINGLEHEADER_AVAILABLE)
        set(PH_INSTALLED_HEADER "${PH_SINGLEHEADER_OUTPUT}")
        install(CODE "execute_process(COMMAND \"${CMAKE_COMMAND}\" --build \"${CMAKE_BINARY_DIR}\" --target perfect_hash_singleheader)")
    else()
        set(PH_INSTALLED_HEADER "${PH_SINGLEHEADER_SOURCE}")
    endif()
    install(FILES "${PH_INSTALLED_HEADER}"
        DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/ConstexprCore")
    install(FILES "${PH_INSTALLED_HEADER}"
        DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}")

    write_basic_package_version_file(
        "${CMAKE_CURRENT_BINARY_DIR}/perfect_hashConfigVersion.cmake"
        VERSION ${PROJECT_VERSION}
        COMPATIBILITY SameMajorVersion
        ARCH_INDEPENDENT)

    configure_package_config_file(
        "${CMAKE_CURRENT_SOURCE_DIR}/cmake/perfect_hashConfig.cmake.in"
        "${CMAKE_CURRENT_BINARY_DIR}/perfect_hashConfig.cmake"
        INSTALL_DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/perfect_hash")

    install(EXPORT perfect_hashTargets
        FILE perfect_hashTargets.cmake
        NAMESPACE ConstexprCore::
        DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/perfect_hash")

    install(FILES
        "${CMAKE_CURRENT_BINARY_DIR}/perfect_hashConfig.cmake"
        "${CMAKE_CURRENT_BINARY_DIR}/perfect_hashConfigVersion.cmake"
        DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/perfect_hash")
endif()

# Examples (requires C++26 reflection support)
option(PH_BUILD_EXAMPLES "Build examples (requires C++26 -freflection)" ${PROJECT_IS_TOP_LEVEL})
if(PH_BUILD_EXAMPLES)
    add_subdirectory(examples/reflect)
endif()
