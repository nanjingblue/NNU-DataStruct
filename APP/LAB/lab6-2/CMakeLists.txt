cmake_minimum_required(VERSION 3.20)
project(lab6_2)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(lab6_2 main.cpp include/MGraph.h)
