#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#include "libs/matriz_booleana.h"
#include "libs/utils.h"

int main()
{
    srand(time(NULL));
    int op = 0;

    // Validamos el ingreso del usuario
    do
    {
        printf("Ingresa la cantidad de estudiantes por favor (60 > n => 120 ): ");
        scanf("%d", &op);
    } while (op < 60 || op > 120);

    
    
    matriz_booleana relacion_estudiantes = crearMatriz_booleana(op, op);
    asignar_relacion_estudiantes(&relacion_estudiantes);
    imprimirMatriz_booleana(&relacion_estudiantes);
    printf("es matriz simetrica?: %s\n",  es_matriz_simetrica(&relacion_estudiantes) ? "si" : "no");

    liberar_matriz(&relacion_estudiantes);
    return 0; 
}