#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#include "libs/matriz_booleana.h"

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
    matriz_booleana matriz_a;
    matriz_a = crearMatriz_booleana(filas, columnas);
    
    do
    {
        auto_asignar_matriz_booleana(&matriz_a);
    } 
    while (!es_matriz_simetrica(&matriz_a));
    
    imprimirMatriz_booleana(matriz_a);
    liberar_matriz(&matriz_a);

    return 0; 
}