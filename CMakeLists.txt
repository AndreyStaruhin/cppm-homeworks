cmake_minimum_required(VERSION 3.25)
project(cppm_homeworks)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(months)
add_subdirectory(accounts)
add_subdirectory(print-structure)
add_subdirectory(CalculateTwoNumbers)
add_subdirectory(counter)
add_subdirectory(addresses)
add_subdirectory(figures-sides-count)
add_subdirectory(figures-sides-and-angles)
add_executable(cppm_homeworks main.cpp)
