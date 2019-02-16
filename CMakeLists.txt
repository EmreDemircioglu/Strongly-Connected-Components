cmake_minimum_required(VERSION 2.8)
project(project3)

set(CMAKE_CXX_STANDARD 11)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_executable(project3 main.cpp Graph.cpp Graph.h)