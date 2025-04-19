cmake_minimum_required(VERSION 3.0)

set(CMAKE_C_STANDARD 17)

project(aplicacion_de_relaciones)

include_directories(src/libs)

add_executable(aplicacion_de_relaciones.out src/src.c)