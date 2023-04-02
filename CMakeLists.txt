cmake_minimum_required(VERSION 3.10)

project(MyProject)

# Add the source files for the project
add_executable(MyProject src/main.cpp)

# Set the include directories for the project
target_include_directories(MyProject PRIVATE lib)

# Add the stb library to the project
target_link_libraries(MyProject PRIVATE lib/stb)

