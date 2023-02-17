cmake_minimum_required(VERSION 3.0)

project(CH04)

include_directories($(CMAKE_SOURCE_DIR)/include)

add_executable(my_cmake_exe Triangular.cpp 05_static.cpp )