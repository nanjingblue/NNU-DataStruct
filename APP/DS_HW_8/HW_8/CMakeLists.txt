cmake_minimum_required(VERSION 3.20)
project(HW_8)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(ALGraphTest ALGraphTest.cpp include/ALGraph.h include/CSTree.h)
add_executable(MGraphTest MGraphTest.cpp include/MGraph.h include/CSTree.h)