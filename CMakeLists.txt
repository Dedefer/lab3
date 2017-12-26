
cmake_minimum_required(VERSION 3.8)
project(lab3)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES src/main.cpp src/lab3_namespace.hpp src/graphs/GraphInterface.hpp src/graphs/Graph.cpp src/graphs/Graph.hpp)

add_executable(lab3 ${SOURCE_FILES})