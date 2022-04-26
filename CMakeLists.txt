cmake_minimum_required(VERSION 3.21)
project(app1 C)

set(CMAKE_C_STANDARD 99)

add_executable(app1 main.c Libros.c Libros.h)