cmake_minimum_required(VERSION 3.21)
project(proj1)

set(CMAKE_CXX_STANDARD 14)

add_executable(proj1 main.cpp Van.cpp Van.h Delivery.cpp Delivery.h algorithms.cpp Combination.cpp Combination.h algorithms.h)
