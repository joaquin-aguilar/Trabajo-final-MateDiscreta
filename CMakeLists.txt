cmake_minimum_required(VERSION 3.21)

set(CMAKE_C_STANDARD 17)

set(CMAKE_BUILD_TYPE )

set(CMAKE_INSTALL_PREFIX "${CMAKE_SOURCE_DIR}/instalacion" CACHE PATH "Installation directory")

set(CMAKE_C_FLAGS ${CMAKE_C_FLAGS} -Wall)

project(aplicacion_de_relaciones)

add_subdirectory(src/libs)

add_executable(aplicacion_de_relaciones.out src/src.c)

target_link_libraries(aplicacion_de_relaciones.out PRIVATE libs)

set_target_properties(aplicacion_de_relaciones.out PROPERTIES
    INSTALL_RPATH "$ORIGIN/../lib"
)

install(TARGETS aplicacion_de_relaciones.out
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib)

install(PROGRAMS ${CMAKE_CURRENT_LIST_DIR}/script.sh
        DESTINATION bin)
