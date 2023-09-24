cmake_minimum_required(VERSION 3.10)
project(asd)


set(CMAKE_EXPORT_COMPILE_COMMANDS on)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
add_subdirectory(numifier)
add_subdirectory(demo)
add_subdirectory(tests)
