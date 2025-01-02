cmake_minimum_required(VERSION 3.10)
project(SortingAlgorithms)

set(CMAKE_CXX_STANDARD 11)

include_directories(src)
include_directories(src/sorting)

add_executable(SortingAlgorithms
    src/main.cpp
    src/utils.cpp
    src/sorting/bubble_sort.cpp
    src/sorting/quick_sort.cpp
    src/sorting/merge_sort.cpp
)