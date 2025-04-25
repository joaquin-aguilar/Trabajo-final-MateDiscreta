#include "matriz_booleana.h"

struct matriz_booleana crearMatriz_booleana(const short filas, const short columnas)
{
    matriz_booleana _matriz;
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

void liberar_matriz(struct matriz_booleana* matriz)
{
    for (int i = 0; i < matriz->filas; i++) 
        free(matriz->matriz[i]); 
    if(matriz->filas != 0)
        free(matriz->matriz); 
}

void imprimirMatriz_booleana(const struct matriz_booleana* matriz)
{
    for(short i = 0; i < matriz->filas; i++)
    {
        printf("| ");
        for(short j = 0; j < matriz->columnas; j++)
            printf("%d ", matriz->matriz[i][j]);   
        printf("|\n");
    }
}

void auto_asignar_matriz_booleana(struct matriz_booleana* matriz)
{
    for(short i = 0; i < matriz->filas; i++)
    {
        for(short j = 0; j < matriz->columnas; j++)
            matriz->matriz[i][j] = rand() % 2;
    }
}

struct matriz_booleana obtener_traspuesta(const struct matriz_booleana* matriz)
{
    struct matriz_booleana matrizTraspuesta = crearMatriz_booleana(matriz->columnas, matriz->filas);
    for(short i = 0; i < matriz->columnas; i++)
        for (short j = 0; j < matriz->filas; j++)
                matrizTraspuesta.matriz[i][j] = matriz->matriz[j][i];

    return matrizTraspuesta;
}

struct matriz_booleana conjuncion_matriz_booleana(const struct matriz_booleana* matriz_a, const struct matriz_booleana* matriz_b)
{
    matriz_booleana matriz_c;
    if(matriz_a->filas != matriz_b->filas || matriz_a->columnas != matriz_b->columnas)
    {
        printf("El numero de filas o columnas de las matrices no coincide");
        
        matriz_c.filas = 0;
        matriz_c.columnas = 0;
        return matriz_c;
    }

    matriz_c = crearMatriz_booleana(matriz_a->filas, matriz_b->columnas);
    for(int i = 0; i < matriz_a->filas; i++)
        for(int j = 0; j < matriz_a->columnas; j++)
            matriz_c.matriz[i][j] = (matriz_a->matriz[i][j] && matriz_b->matriz[i][j]);
    
    
    matriz_c.filas = matriz_a->filas;
    matriz_c.columnas = matriz_b->columnas;
    return matriz_c;
}

struct matriz_booleana disyuncion_matriz_booleana(const struct matriz_booleana* matriz_a, const struct matriz_booleana* matriz_b)
{
    matriz_booleana matriz_c;
    if(matriz_a->filas != matriz_b->filas || matriz_a->columnas != matriz_b->columnas)
    {
        printf("El numero de filas o columnas de las matrices no coincide");
        
        matriz_c.filas = 0;
        matriz_c.columnas = 0;
        return matriz_c;
    }

    matriz_c = crearMatriz_booleana(matriz_a->filas, matriz_b->columnas);
    for(int i = 0; i < matriz_a->filas; i++)
        for(int j = 0; j < matriz_a->columnas; j++)
            matriz_c.matriz[i][j] = (matriz_a->matriz[i][j] || matriz_b->matriz[i][j]);
    
    
    matriz_c.filas = matriz_a->filas;
    matriz_c.columnas = matriz_b->columnas;
    return matriz_c;
}

bool es_matriz_simetrica(const struct matriz_booleana* matriz)
{
    if (matriz->filas != matriz->columnas)
    {
        printf("la matriz no es cuadrada!\n");
        return false;
    }

    for(int a = 0; a < matriz->filas; a++)
        for (int b = 0; b < matriz->columnas; b++)
            if(matriz->matriz[a][b] != matriz->matriz[b][a])
                return false;

    return true;
}
bool es_matriz_reflexiva(const struct matriz_booleana* matriz)
{
    if (matriz->filas != matriz->columnas)
    {
        printf("la matriz no es cuadrada!\n");
        return false;
    }

    for (int i = 0; i < matriz->filas; i++)
        if(matriz->matriz[i][i] == 0)
            return false;     
              
    return true;
}

bool es_antisimetrica(const struct matriz_booleana* matriz)
{
    if (matriz->filas != matriz->columnas)
    {
        printf("la matriz no es cuadrada!\n");
        return false;
    }

    for (int i = 0; i < matriz->filas; i++)
        for (int j = i + 1; j < matriz->columnas; j++)
            if (matriz->matriz[i][j] && matriz->matriz[j][i])
                return false;
    
    return true;
}

short grado_externo(const struct matriz_booleana* matriz, short indice)
{
    if (!matriz || indice < 0 || indice >= matriz->filas || matriz->filas != matriz->columnas)
        return -1;
    
    short res = 0;
    for (int i = 0; i < matriz->filas; i++)
    {
        if (matriz->matriz[i][indice])
            res++;
    }
    return res;
}

short grado_interno(const struct matriz_booleana* matriz, short indice)
{
    if (!matriz || indice < 0 || indice >= matriz->filas || matriz->filas != matriz->columnas)
        return -1;
    
    short res = 0;
    for (int i = 0; i < matriz->filas; i++)
    {
        if (matriz->matriz[indice][i])
            res++;
    }
    return res;
}
