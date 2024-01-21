set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


add_executable(LibTableExample simple_example.cpp)
target_link_libraries(LibTableExample 
PRIVATE 
  libtable
)

