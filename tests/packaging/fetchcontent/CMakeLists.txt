# Consumer smoke test: pull perfect_hash in with FetchContent.
# PH_SOURCE is set by tools/test_packaging.py to this checkout; a real project
# would use GIT_REPOSITORY/GIT_TAG instead (see README.md).
cmake_minimum_required(VERSION 3.20)
project(ph_fetchcontent_consumer LANGUAGES CXX)

include(FetchContent)
FetchContent_Declare(perfect_hash SOURCE_DIR "${PH_SOURCE}")
FetchContent_MakeAvailable(perfect_hash)

add_executable(consumer ../consumer.cpp)
target_link_libraries(consumer PRIVATE ConstexprCore::perfect_hash)
target_compile_features(consumer PRIVATE cxx_std_23)
