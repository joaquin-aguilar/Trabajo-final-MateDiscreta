add_library(libs SHARED
                matriz_booleana.h
                matriz_booleana.c
                utils.h
                utils.c)
target_include_directories(libs PUBLIC 
                               $(CMAKE_CURRENT_LIST_DIR))