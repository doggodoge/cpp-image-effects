cmake_minimum_required(VERSION 3.10)

project(MyProject)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(MyProject src/main.cpp)

add_library(stb INTERFACE)
target_include_directories(stb INTERFACE lib/stb)
target_link_libraries(MyProject stb)
