cmake_minimum_required(VERSION 3.20)

project(MyProject)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(lib/stb)
add_executable(MyProject src/main.cpp src/images.cpp src/images.h src/effects.cpp src/effects.h)
target_compile_features(MyProject PRIVATE cxx_std_20)
