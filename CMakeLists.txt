cmake_minimum_required(VERSION 3.10)

project(secondQuestion VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(second src/main.cpp)

target_include_directories(second PUBLIC "${CMAKE_SOURCE_DIR}/include")

add_compile_options(-g)