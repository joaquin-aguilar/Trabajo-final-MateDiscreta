add_library(libs SHARED
                matriz_booleana.c
                utils.c)

target_include_directories(libs PUBLIC 
                               ${CMAKE_CURRENT_SOURCE_DIR})

install(TARGETS libs
               LIBRARY DESTINATION lib
               ARCHIVE DESTINATION lib)