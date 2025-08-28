cmake_minimum_required(VERSION 3.25)
project(addresses)

set(CMAKE_CXX_STANDARD 17)
configure_file(
        ${CMAKE_SOURCE_DIR}/addresses/in.txt
        ${CMAKE_BINARY_DIR}/addresses/in.txt
        COPYONLY
)
configure_file(
        ${CMAKE_SOURCE_DIR}/addresses/out.txt
        ${CMAKE_BINARY_DIR}/addresses/out.txt
        COPYONLY
)

add_executable(addresses main.cpp)

