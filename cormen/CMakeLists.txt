cmake_minimum_required(VERSION 3.20)
project(algorithms C)

set(CMAKE_C_STANDARD 99)

add_executable(algorithms main.c helper/array.c test/assertions.c)
