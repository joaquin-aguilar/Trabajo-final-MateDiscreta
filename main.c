#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "MatrizBooleana.h"

int main(int argc, char** argv)
{
    if (argc != 3)
    {
        printf("No se obtuvieron los parametros esperados para la matriz, programa finalizado!\n");
        return -1;
    }
    

    int filas = atoi(argv[1]);
    int columnas = atoi(argv[2]);
    bool** matriz = crearMatrizBooleana(filas, columnas);

    imprimirMatrizBooleana(matriz, filas, columnas);
    liberarMatriz(matriz, filas);
    
    return 0; 
}