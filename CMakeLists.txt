cmake_minimum_required(VERSION 3.27)
project(Lab03v04)

set(CMAKE_CXX_STANDARD 23)

add_executable(Lab03v04 main.cpp
        ray.cpp
        quad.cpp
        geometry.cpp
        math.cpp
        math.h)
