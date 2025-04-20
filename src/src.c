#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#include "libs/matriz_booleana.h"
#include "libs/utils.h"

int main()
{
    srand(time(NULL));

    int tamanyo_relacion = 0;
    int trabajador_enfermo = 0;

    // Validamos el ingreso del usuario
    do
    {
        printf("Ingresa la cantidad de trabajadores por favor (60 > n => 120 ): ");
        scanf("%d", &tamanyo_relacion);
    } while (tamanyo_relacion < 60 || tamanyo_relacion > 120);

    do
    {
        printf("Ingrese el indice del trabajador enfermo por favor (0 - %d): ", tamanyo_relacion - 1);
        scanf("%d", &trabajador_enfermo);
    } while (trabajador_enfermo < 0 || trabajador_enfermo > tamanyo_relacion - 1);
    
    // Generamos la matriz y las relaciones
    matriz_booleana relacion_estudiantes = crearMatriz_booleana(tamanyo_relacion, tamanyo_relacion);
    asignar_relacion_especial(&relacion_estudiantes);
    imprimirMatriz_booleana(&relacion_estudiantes);
    printf("es matriz simetrica?: %s\n",  es_matriz_simetrica(&relacion_estudiantes) ? "si" : "no");

    // Creamos el archivo para graphviz e imagen.
    generar_archivo_dot(&relacion_estudiantes, "archivodot.dot");
    system("dot -Tpng imagenes/archivodot.dot -o imagenes/grafo.png");

    liberar_matriz(&relacion_estudiantes);
    return 0; 
}