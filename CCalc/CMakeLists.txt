cmake_minimum_required(VERSION 3.21)
project(CCalc C)

set(CMAKE_C_STANDARD 23)

add_executable(CCalc main.c calc_funcs.c funcsdef.h header_includes.h)

target_link_libraries(CCalc m)