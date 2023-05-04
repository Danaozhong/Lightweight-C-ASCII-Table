
cmake_minimum_required(VERSION 3.1)

project(
  LibTableExample
  VERSION 1.0
  LANGUAGES CXX)

add_executable(LibTableExample simple_example.cpp)
target_link_libraries(LibTableExample PRIVATE libtable)

