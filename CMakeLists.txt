cmake_minimum_required(VERSION 3.0)

set(CMAKE_C_STANDARD 17)

project(aplicacion_de_relaciones)

add_subdirectory(src/libs)

add_executable(aplicacion_de_relaciones.out src/src.c)

target_link_libraries(aplicacion_de_relaciones.out 
                        libs)