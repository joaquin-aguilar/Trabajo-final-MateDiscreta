#ifndef UTILS_H
#define UTILS_H

#include "matriz_booleana.h"

void asignar_relacion_especial(struct matriz_booleana*);
short* generar_array_unico_aleatorio(short*, const short);
void generar_archivo_dot(const struct matriz_booleana*, const char*);
int dias_para_infectar_todos(const struct matriz_booleana*, short);
short infectados_en_dia(const struct matriz_booleana*, short, short);

#endif // !UTILS_H