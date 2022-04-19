cmake_minimum_required(VERSION 3.21)
project(proj1)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

add_subdirectory(src)
add_subdirectory(tst)
add_subdirectory(lib/googletest)

add_executable(proj1 src/main.cpp src/Van.cpp src/Van.h src/Delivery.cpp src/Delivery.h src/algorithms.cpp src/algorithms.h src/Combination.cpp src/Combination.h src/Menu.cpp src/Menu.h)