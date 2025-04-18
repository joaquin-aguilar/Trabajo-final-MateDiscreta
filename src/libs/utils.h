#ifndef UTILS_H
#define UTILS_H

#include "matriz_booleana.h"

void asignar_relacion_especial(struct matriz_booleana*);
short* generar_array_unico_aleatorio(short*, const short);


void asignar_relacion_especial(struct matriz_booleana* matriz)
{

    for(int i = 0; i < matriz->filas; i++)
    {
        short tamanyo = 0;
        short* array_rel = generar_array_unico_aleatorio(&tamanyo, matriz->filas);
        for (int j = 0; j < tamanyo; j++)
        {
            // evitamos los bucles
            if(array_rel[j] != i)
            {
                matriz->matriz[i][array_rel[j]] = true;
                matriz->matriz[array_rel[j]][i] = true;
            }
        }
        free(array_rel);
    }
}

short* generar_array_unico_aleatorio(short* tamanyo, const short max) 
{
    if (max <= 0 || tamanyo == NULL)
        return NULL;

    *tamanyo = 1 + rand() % 5;

    short* pool = (short*) malloc(max * sizeof(short));

    for (short i = 0; i < max; i++) 
        pool[i] = i;

    // Fisher-Yates
    for (short i = max - 1; i > 0; i--) 
    {
        short j = rand() % (i + 1);
        short temp = pool[i];
        pool[i] = pool[j];
        pool[j] = temp;
    }

    short* resultado = (short*) malloc((*tamanyo) * sizeof(short));

    for (int i = 0; i < *tamanyo; i++) 
        resultado[i] = pool[i];

    free(pool);
    return resultado;
}


#endif // !UTILS_H