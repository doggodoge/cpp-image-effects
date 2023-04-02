cmake_minimum_required(VERSION 3.10)

project(MyProject)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(lib/stb)
add_executable(MyProject src/main.cpp src/images.cpp src/images.h)
