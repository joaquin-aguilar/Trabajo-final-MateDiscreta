add_library(libs SHARED
                matriz_booleana.c
                utils.c
                interfaz_grafica.c
                eventos.c)

target_include_directories(libs PUBLIC 
                               ${CMAKE_CURRENT_SOURCE_DIR})
                               
target_link_libraries(libs PRIVATE ${GTK4_LIBRARIES}) 
install(TARGETS libs
               LIBRARY DESTINATION lib
               ARCHIVE DESTINATION lib
               RUNTIME DESTINATION bin)