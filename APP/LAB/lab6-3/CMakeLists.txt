cmake_minimum_required(VERSION 3.20)
project(lab6_3)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(MGraph TestMGraph.cpp include/MGraph.h)
add_executable(ALGgraph TestALGgraph.cpp include/ALGraph.h)
