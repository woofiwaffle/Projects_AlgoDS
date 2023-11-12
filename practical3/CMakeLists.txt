cmake_minimum_required(VERSION 3.26)
project(Projects_AlgoDS)

set(CMAKE_CXX_STANDARD 17)

add_executable(practical3
        main.cpp
        application.cpp
        application.h
        Trees/BinaryTree.cpp
        Trees/BinaryTree.h
        Trees/AVLTree.cpp
        Trees/AVLTree.h)