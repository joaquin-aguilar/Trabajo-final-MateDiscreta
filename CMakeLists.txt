cmake_minimum_required(VERSION 3.21)

project(aplicacion_de_relaciones C)

set(CMAKE_C_STANDARD 17)
set(CMAKE_BUILD_TYPE Release)
set(CMAKE_INSTALL_PREFIX "${CMAKE_SOURCE_DIR}/instalacion" CACHE PATH "Installation directory")

# Flags de compilación
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror")

# Dependencia a GTK 4
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK4 REQUIRED gtk4)

# Incluir directorios
include_directories(${GTK4_INCLUDE_DIRS})
link_directories(${GTK4_LIBRARY_DIRS})
add_definitions(${GTK4_CFLAGS_OTHER})

# Añadir subdirectorio con bibliotecas locales
add_subdirectory(src/libs)

# Ejecutable principal
add_executable(aplicacion_de_relaciones src/src.c)

# Enlazar bibliotecas: locales + GTK4
target_link_libraries(aplicacion_de_relaciones PRIVATE libs ${GTK4_LIBRARIES})

# Instalación
set_target_properties(aplicacion_de_relaciones PROPERTIES
    INSTALL_RPATH "$ORIGIN/../lib"
)

install(TARGETS aplicacion_de_relaciones
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib)
