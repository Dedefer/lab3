
cmake_minimum_required(VERSION 3.8)
project(lab3)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES src/main.cpp src/lab3_namespace.hpp src/graphs/GraphInterface.hpp src/graphs/Graph.cpp src/graphs/Graph.hpp "src/dijkstra's algorithm/DijkstraClass.cpp" "src/dijkstra's algorithm/DijkstraClass.hpp")

add_executable(lab3 ${SOURCE_FILES})