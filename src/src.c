#include <gtk/gtk.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#include "libs/eventos.h"
#include "libs/matriz_booleana.h"
#include "libs/utils.h"
#include "libs/interfaz_grafica.h"

int main(int argc, char **argv)
{
    srand(time(NULL));
    GtkApplication *aplicacion;
    int status;

    aplicacion = gtk_application_new("org.joaquinaguilar.gtk", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(aplicacion, "activate", G_CALLBACK(inicializar_aplicacion), NULL);
    status = g_application_run(G_APPLICATION(aplicacion), argc, argv);
    g_object_unref(aplicacion);

    return status;
}
