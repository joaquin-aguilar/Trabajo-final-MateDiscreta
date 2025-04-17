#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#include "libs/matriz_boolena.h"

int main(int argc, char** argv)
{
    srand(time(NULL));
    if (argc != 3)
    {
        printf("No se obtuvieron los parametros esperados para la matriz, programa finalizado!\n");
        return -1;
    }
    

    int filas = atoi(argv[1]);
    int columnas = atoi(argv[2]);
    bool** matriz = crearMatrizBooleana(filas, columnas);
    autoAsignarMatrizBooleana(matriz, filas, columnas);    
    bool** matrizTraspuesta = obtenerTraspuesta(matriz, filas, columnas);


    imprimirMatrizBooleana(matriz, filas, columnas);
    printf("\ntraspuesta:\n");
    imprimirMatrizBooleana(matrizTraspuesta, columnas, filas);

    liberarMatriz(matriz, filas);
    liberarMatriz(matrizTraspuesta, filas);
    return 0; 
}