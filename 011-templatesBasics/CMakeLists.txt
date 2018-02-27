cmake_minimum_required(VERSION 3.1.0)
project(templates)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -fPIC -std=c++14")
set(CMAKE_CXX_STANDARD 14)

add_executable(templates templates.cpp)
