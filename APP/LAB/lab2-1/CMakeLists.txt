cmake_minimum_required(VERSION 3.19)
project(20190408ZSH/lab2)

include_directories(include)

add_executable(ylx ylx.cpp)
add_executable(main main.cpp include/seq_stack.h include/seq_stack_test.h include/in_expression.h include/infix_to_suffix.h include/suffix_expression.h)