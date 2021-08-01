cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# set the project name
project(Lox)

# add the executable
add_executable(Lox src/main.cpp src/scanner.cpp src/token.cpp)
