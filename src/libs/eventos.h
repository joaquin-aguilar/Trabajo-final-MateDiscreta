#ifndef EVENTOS_H
#define EVENTOS_H

#include <gtk/gtk.h>
#include <stdbool.h>
#include "estructuras_graficas.h"

void cerrar_ventana(GtkButton*, gpointer);
void mostrar_alerta(GtkWindow*,  const char *);
void al_pulsar_boton(GtkButton*, gpointer);
void al_escribir_filtro(GtkEditable*, gpointer);
gboolean al_cerrar_ventana(GtkWindow*, gpointer ) ;

#endif // !EVENTOS_H