cmake_minimum_required(VERSION 3.20)
project(lab3_1)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(main main.cpp main.cpp include/get_next.h include/sub.h include/reverse_words.h include/special_matrices.h include/ternary_matrix.h)
