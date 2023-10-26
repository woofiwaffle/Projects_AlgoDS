cmake_minimum_required(VERSION 3.26)
project(Projects_AlgoDS)

set(CMAKE_CXX_STANDARD 17)

add_executable(practical1 main.cpp
        Structures/DL_List.cpp
        Structures/DL_List.h
        Structures/D_Array.cpp
        Structures/D_Array.h
        Structures/Stack.cpp
        Structures/Stack.h
        application.cpp
        application.h
        RPN/RPN.cpp
        RPN/RPN.h
        ../practical2/sortings/D_Array.cpp
        ../practical2/sortings/D_Array.h
        ../practical2/sortings/Quicksort.cpp
        ../practical2/sortings/Quicksort.h
        ../practical2/sortings/Timsort.cpp
        ../practical2/sortings/Timsort.h
        ../practical2/application.cpp
        ../practical2/application.h)