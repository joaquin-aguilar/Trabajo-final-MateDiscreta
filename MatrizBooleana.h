#ifndef MATRIZ_BOOLEANA_H
#define  MATRIZ_BOOLEANA_H

#include <stdlib.h>
#include <stdbool.h>

bool** crearMatrizBooleana(short, short);
void imprimirMatrizBooleana(bool**, short, short);

bool** crearMatrizBooleana(short filas, short columnas)
{
    bool** matriz = (bool**) malloc(sizeof(void*) * filas);
    for(short i = 0; i < filas; i++)
        matriz[i] = (bool*) malloc(sizeof(void*) * columnas);
    
    for(short i = 0; i < filas; i++)
        for(short j = 0; j < filas; j++)
            matriz[i][j] = 0;
    return matriz;
}

void liberarMatriz(bool** matriz, short filas)
{
    for (int i = 0; i < filas; i++) 
        free(matriz[i]); 

    free(matriz); 
}

void imprimirMatrizBooleana(bool** matriz, short filas, short columnas)
{
    for(short i = 0; i < filas; i++)
    {
        printf("|");
        for(short j = 0; j < filas; j++)
            printf("%d ", matriz[i][j]);   
        printf("|\n");
    }
}

#endif // !MATRIZ_BOOLEANA_H