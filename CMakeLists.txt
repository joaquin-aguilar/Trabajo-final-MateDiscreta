cmake_minimum_required(VERSION 3.21)

set(CMAKE_C_STANDARD 17)

set(CMAKE_BUILD_TYPE RELEASE)

set(CMAKE_INSTALL_PREFIX "${CMAKE_SOURCE_DIR}/instalacion" CACHE PATH "Installation directory")

# Obtenemos informacion detallada y convertimos los logs de advertencia en errores al compilar
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror")

project(aplicacion_de_relaciones)

add_subdirectory(src/libs)

add_executable(aplicacion_de_relaciones src/src.c)

target_link_libraries(aplicacion_de_relaciones PRIVATE libs)

set_target_properties(aplicacion_de_relaciones PROPERTIES
    INSTALL_RPATH "$ORIGIN/../lib"
)

install(TARGETS aplicacion_de_relaciones
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib)
