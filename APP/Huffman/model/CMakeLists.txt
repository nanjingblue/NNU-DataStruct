SET(CMAKE_CXX_COMPILER C:/env/mingw64/bin/g++)
set( src
    ${CMAKE_CURRENT_SOURCE_DIR}/Huffman.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Huffman.cpp
)

add_library(model ${src})