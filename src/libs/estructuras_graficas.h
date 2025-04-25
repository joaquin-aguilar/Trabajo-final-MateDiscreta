#ifndef ESTRUCTURAS_GRAFICAS_H
#define ESTRUCTURAS_GRAFICAS_H

#include <gtk/gtk.h>

typedef struct ui_imagenes_t 
{
    GtkWidget *n_trabajadores, *trabajador_e, *imagen;
    struct matriz_booleana* matriz; 
} ui_imagenes_t;


#endif // !ESTRUCTURAS_GRAFICAS_H