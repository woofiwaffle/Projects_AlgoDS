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
        RPN/RPN.h)