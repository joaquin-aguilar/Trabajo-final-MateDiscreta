#ifndef MATRIZ_BOOLEANA_H
#define  MATRIZ_BOOLEANA_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct matriz_boolena
{
    bool** matriz;
    short filas, columnas;
} matriz_boolena;


struct matriz_boolena crearMatriz_booleana(const short, const short);
void liberar_matriz(struct matriz_boolena*);
void imprimirMatriz_booleana(struct matriz_boolena);
void auto_asignar_matriz_booleana(struct matriz_boolena*);
struct matriz_boolena obtenerTraspuesta(const struct matriz_boolena*);


struct matriz_boolena crearMatriz_booleana(const short filas, const short columnas)
{
    matriz_boolena _matriz;
    _matriz.filas = filas;
    _matriz.columnas = columnas;
    bool** matriz = (bool**) malloc(sizeof(bool*) * filas);
    for(short i = 0; i < filas; i++)
        matriz[i] = (bool*) malloc(sizeof(bool) * columnas);
    
    for(short i = 0; i < filas; i++)
        for(short j = 0; j < columnas; j++)
            matriz[i][j] = 0;

    _matriz.matriz = matriz;
    return _matriz;
}

void liberar_matriz(struct matriz_boolena* matriz)
{
    for (int i = 0; i < matriz->filas; i++) 
        free(matriz->matriz[i]); 

    free(matriz->matriz); 
}

void imprimirMatriz_booleana(struct matriz_boolena matriz)
{
    for(short i = 0; i < matriz.filas; i++)
    {
        printf("| ");
        for(short j = 0; j < matriz.columnas; j++)
            printf("%d ", matriz.matriz[i][j]);   
        printf("|\n");
    }
}

void auto_asignar_matriz_booleana(struct matriz_boolena* matriz)
{
    for(short i = 0; i < matriz->filas; i++)
    {
        for(short j = 0; j < matriz->columnas; j++)
            matriz->matriz[i][j] = rand() % 2;
    }
}

struct matriz_boolena obtenerTraspuesta(const struct matriz_boolena* matriz)
{
    struct matriz_boolena matrizTraspuesta = crearMatriz_booleana(matriz->columnas, matriz->filas);
    for(short i = 0; i < matriz->columnas; i++)
        for (short j = 0; j < matriz->filas; j++)
                matrizTraspuesta.matriz[i][j] = matriz->matriz[j][i];

    return matrizTraspuesta;
}

#endif // !MATRIZ_BOOLEANA_H