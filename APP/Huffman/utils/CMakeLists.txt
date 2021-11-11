SET(CMAKE_CXX_COMPILER C:/env/mingw64/bin/g++)
set( src
    ${CMAKE_CURRENT_SOURCE_DIR}/TreeCreatorUtils.h
    ${CMAKE_CURRENT_SOURCE_DIR}/TreeCreatorUtils.cpp
)

add_library(utils  ${src})