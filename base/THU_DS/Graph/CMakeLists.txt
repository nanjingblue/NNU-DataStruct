cmake_minimum_required(VERSION 3.19)

project(DatasStructures/THU_DS/Graph)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(ThuGraph01 graph01.cpp include/Graph.h include/GraphMatrix.h)