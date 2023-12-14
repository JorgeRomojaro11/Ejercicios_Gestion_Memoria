cmake_minimum_required(VERSION 3.17)
project(MyProject)

set(CMAKE_CXX_STANDARD 11)

add_executable(MyProject main.cpp)

target_link_libraries(MyProject PRIVATE kernel32 user32)
