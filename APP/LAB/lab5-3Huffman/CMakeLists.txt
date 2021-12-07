cmake_minimum_required(VERSION 3.20)
project(lab5_3Huffman)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(lab5_3Huffman main.cpp include/HuffmanTree.h include/Huffmantree.cpp)
