cmake_minimum_required(VERSION 3.20)
project(lab2_2)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(lab2_2 main.cpp include/seq_queue.h include/test_seq_queue.h include/test_seq_queue.h include/see_a_doctor.h)
