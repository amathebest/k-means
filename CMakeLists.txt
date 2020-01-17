cmake_minimum_required(VERSION 3.15)
project(k_means)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fopenmp")

add_executable(k_means main.cpp utils.h utils.cpp)
