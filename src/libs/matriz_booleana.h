#ifndef MATRIZ_BOOLEANA_H
#define  MATRIZ_BOOLEANA_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct matriz_booleana
{
    bool** matriz;
    short filas, columnas;
} matriz_booleana;


struct matriz_booleana crearMatriz_booleana(const short, const short);
void liberar_matriz(struct matriz_booleana*);
void imprimirMatriz_booleana(const struct matriz_booleana*);
void auto_asignar_matriz_booleana(struct matriz_booleana*);

struct matriz_booleana obtener_traspuesta(const struct matriz_booleana*);
struct matriz_booleana conjuncion_matriz_booleana(const struct matriz_booleana*, const struct matriz_booleana*);
struct matriz_booleana disyuncion_matriz_booleana(const struct matriz_booleana*, const struct matriz_booleana*);

bool es_matriz_simetrica(const struct matriz_booleana*);
bool es_matriz_reflexiva(const struct matriz_booleana*);
bool es_antisimetrica(const struct matriz_booleana*);

short grado_externo(const struct matriz_booleana*, short);
short grado_interno(const struct matriz_booleana*, short);


#endif // !MATRIZ_BOOLEANA_H