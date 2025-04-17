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
    matriz_boolena matriz_a;
    matriz_a = crearMatriz_booleana(filas, columnas);
    auto_asignar_matriz_booleana(&matriz_a);    

    matriz_boolena matriz_a_traspuesta;
    matriz_a_traspuesta = obtenerTraspuesta(&matriz_a);

    printf("matriz generada:\n");
    imprimirMatriz_booleana(matriz_a);
    printf("\ntraspuesta:\n");
    imprimirMatriz_booleana(matriz_a_traspuesta);

    liberar_matriz(&matriz_a);
    liberar_matriz(&matriz_a_traspuesta);

    return 0; 
}