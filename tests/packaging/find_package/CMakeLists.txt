# Consumer smoke test: find_package against an install tree.
cmake_minimum_required(VERSION 3.20)
project(ph_find_package_consumer LANGUAGES CXX)

find_package(perfect_hash REQUIRED)

add_executable(consumer ../consumer.cpp)
target_link_libraries(consumer PRIVATE ConstexprCore::perfect_hash)
