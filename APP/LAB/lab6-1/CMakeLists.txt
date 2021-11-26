cmake_minimum_required(VERSION 3.20)
project(lab6_1)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(lab6_1 main.cpp include/MGraph.h include/ALGraph.h)
