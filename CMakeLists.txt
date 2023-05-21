cmake_minimum_required(VERSION 3.23)
project(course_C1 C)

set(CMAKE_C_STANDARD 99)

add_executable(course_C1 main.c libs/algorithms/array/array.c libs/algorithms/array/array.h libs/algorithms/algorithm.c libs/algorithms/algorithm.h libs/data_structures/bitset/bitset.c libs/data_structures/bitset/bitset.h libs/data_structures/UNORDERED_ARRAY_SET/UNORDERED_ARRAY_SET.h)

add_subdirectory(libs)
target_link_libraries(course_C1 data_structures)
target_link_libraries(course_C1 algorithms)
