cmake_minimum_required(VERSION 3.26)
project(Projects_AlgoDS)

set(CMAKE_CXX_STANDARD 17)

add_executable(practical2
        application.cpp
        application.h
        main.cpp
        sortings/D_Array.cpp
        sortings/D_Array.h
        sortings/Timsort.cpp
        sortings/Timsort.h
        sortings/Quicksort.cpp
        sortings/Quicksort.h)