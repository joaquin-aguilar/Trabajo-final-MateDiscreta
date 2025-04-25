#include <sys/stat.h>
#include <string.h>

#ifdef _WIN32
    #include <direct.h>
#endif

#include "utils.h"

void asignar_relacion_especial(struct matriz_booleana* matriz)
{
    short n = matriz->filas;
    // Validar que la matriz sea valida (por lo menos 2x2)
    if (n <= 1) 
        return;
    // Metodo por fuerza bruta
    for (short i = 0; i < n; ++i)
    {
        int intentos_globales = 0;

        while (grado_interno(matriz, i) < 5 && intentos_globales < 100)
        {
            short j = rand() % n;
            intentos_globales++;

            if (j == i || matriz->matriz[i][j])
                continue;

            if (grado_interno(matriz, j) >= 5)
                continue;

            matriz->matriz[i][j] = true;
            matriz->matriz[j][i] = true;
        }
    }
}

int dias_para_infectar_todos(const struct matriz_booleana* matriz, short paciente_cero)
{
    if (paciente_cero >= matriz->filas) return -1;

    // Inicializa a todos como no infectados
    bool* infectados = calloc(matriz->filas, sizeof(bool));
    if (!infectados) return -1;

    infectados[paciente_cero] = true;
    int total_infectados = 1;
    int dias = 0;

    while (total_infectados < matriz->filas)
    {
        // Crear una lista temporal de nuevos infectados
        bool* nuevos = calloc(matriz->filas, sizeof(bool));
        if (!nuevos) {
            free(infectados);
            return -1;
        }

        // Recorremos cada empleado
        for (short i = 0; i < matriz->filas; i++)
        {
            if (!infectados[i]) continue;

            // Infecta a sus contactos
            for (short j = 0; j < matriz->filas; j++)
            {
                if (matriz->matriz[i][j] && !infectados[j])
                    nuevos[j] = true;
            }
        }

        // Aplicamos los nuevos contagios
        int nuevos_infectados = 0;
        for (short i = 0; i < matriz->filas; i++)
        {
            if (nuevos[i]) {
                infectados[i] = true;
                nuevos_infectados++;
            }
        }

        free(nuevos);

        if (nuevos_infectados == 0) {
            // No se puede propagar más (grafo desconectado)
            free(infectados);
            return -1;
        }

        total_infectados += nuevos_infectados;
        dias++;
    }

    free(infectados);
    return dias;
}

short infectados_en_dia(const struct matriz_booleana* matriz, short paciente_cero, short dia_objetivo) 
{
    // Validar matriz 
    if (paciente_cero >= matriz->filas || dia_objetivo <= 0)
        return -1;

    bool infectados[matriz->filas];
    for (short i = 0; i < matriz->filas; i++)
        infectados[i] = false;

    infectados[paciente_cero] = true;
    short total_infectados = 1;
    short dia_actual = 0;

    while (total_infectados < matriz->filas) 
    {
        short nuevos_enfermos = 0;
        bool infectados_hoy[matriz->filas];

        for (short i = 0; i < matriz->filas; i++)
            infectados_hoy[i] = false;

        for (short i = 0; i < matriz->filas; i++) 
        {
            if (!infectados[i])
                continue;

            for (short j = 0; j < matriz->filas; j++) 
            {
                if (matriz->matriz[i][j] && !infectados[j] && !infectados_hoy[j]) 
                {
                    infectados_hoy[j] = true;
                    nuevos_enfermos++;
                }
            }
        }

        if (nuevos_enfermos == 0)
            return 0; // ya no se puede contagiar más

        for (short i = 0; i < matriz->filas; i++) 
        {
            if (infectados_hoy[i]) 
            {
                infectados[i] = true;
                total_infectados++;
            }
        }

        dia_actual++;

        if (dia_actual == dia_objetivo)
            return nuevos_enfermos;
    }
    return 0;
}

void generar_archivo_dot(const struct matriz_booleana* matriz, const char* nombre_archivo)
{
    struct stat st = {0};
    if (stat("imagenes", &st) == -1) 
    {
        #ifdef _WIN32
            if(mkdir("imagenes") != 0)
        #else
            if (mkdir("imagenes", 0777) != 0) 
                
        #endif
        {
            printf("No se pudo crear la carpeta correctamente!");
            return;
        }

    }

    // buffer de la ruta
    char ruta[30] = "imagenes/";
    strcat(ruta, nombre_archivo); 

    FILE* archivo = fopen(ruta, "w");
    if (!archivo) 
    {
        printf("No se pudo crear el archivo!\n");
        return;
    }

    fprintf(archivo, "digraph G {\n");

    for (short i = 0; i < matriz->filas; ++i) 
    {
        for (short j = 0; j < matriz->filas; ++j) 
        {
            if(j== 0)
                fprintf(archivo, "    %d;\n", i);
            if (matriz->matriz[i][j]) 
                fprintf(archivo, "    %d -> %d;\n", i, j);
            
        }
    }

    fprintf(archivo, "}\n");
    fclose(archivo);
}