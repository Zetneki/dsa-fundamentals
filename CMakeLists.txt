cmake_minimum_required(VERSION 4.3)
project(dsa_fundamentals)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(data-structures/arrays/dynamic-array)
include_directories(data-structures/arrays/static-array)
include_directories(data-structures/graphs/adjacency-list)

# Dynamic Array
add_executable(dynamic_array_demo
        data-structures/arrays/dynamic-array/main.cpp
)

add_executable(dynamic_array_tests
        data-structures/arrays/dynamic-array/tests.cpp
)

# Static Array
add_executable(static_array_demo
        data-structures/arrays/static-array/main.cpp
)

add_executable(static_array_tests
        data-structures/arrays/static-array/tests.cpp
)

# Adjacency List
add_executable(adjacency_list_demo
        data-structures/graphs/adjacency-list/main.cpp
)

add_executable(adjacency_list_tests
        data-structures/graphs/adjacency-list/tests.cpp
)
