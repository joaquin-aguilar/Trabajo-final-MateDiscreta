#ifndef MATRIZ_BOOLEANA_H
#define  MATRIZ_BOOLEANA_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool** crearMatrizBooleana(const short, const short);
void imprimirMatrizBooleana(bool**, const short, const short);
void liberarMatriz(bool**, const short);
void autoAsignarMatrizBooleana(bool**, const short, const short);
bool** obtenerTraspuesta(bool**, const short, const short);

bool** crearMatrizBooleana(short filas, const short columnas)
{
    bool** matriz = (bool**) malloc(sizeof(void*) * filas);
    for(short i = 0; i < filas; i++)
        matriz[i] = (bool*) malloc(sizeof(void*) * columnas);
    
    for(short i = 0; i < filas; i++)
        for(short j = 0; j < columnas; j++)
            matriz[i][j] = 0;
    return matriz;
}

void liberarMatriz(bool** matriz, const short filas)
{
    for (int i = 0; i < filas; i++) 
        free(matriz[i]); 

    free(matriz); 
}

void imprimirMatrizBooleana(bool** matriz, const short filas, const short columnas)
{
    for(short i = 0; i < filas; i++)
    {
        printf("| ");
        for(short j = 0; j < columnas; j++)
            printf("%d ", matriz[i][j]);   
        printf("|\n");
    }
}

void autoAsignarMatrizBooleana(bool** matriz, const short filas, const short columnas)
{
    for(short i = 0; i < filas; i++)
    {
        for(short j = 0; j < columnas; j++)
            matriz[i][j] = rand() % 2;
    }
}

bool** obtenerTraspuesta(bool** matriz, const short filas, const short columnas)
{
    bool** matrizTraspuesta = crearMatrizBooleana(columnas, filas);
    for(short i = 0; i < columnas; i++)
        for (short j = 0; j < filas; j++)
        {
                matrizTraspuesta[i][j] = matriz [j][i];
        }
    return matrizTraspuesta;
}

#endif // !MATRIZ_BOOLEANA_H