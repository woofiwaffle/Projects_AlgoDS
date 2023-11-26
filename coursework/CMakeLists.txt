cmake_minimum_required(VERSION 3.26)
project(Projects_AlgoDS)

set(CMAKE_CXX_STANDARD 17)

add_executable(coursework main.cpp
        application.cpp
        application.h
        KruskalsAlgorithm/KruskalsAlgorithm.cpp
        KruskalsAlgorithm/KruskalsAlgorithm.h
)