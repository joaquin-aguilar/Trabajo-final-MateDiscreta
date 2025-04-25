#include <gtk/gtk.h>
#include <stdbool.h>

#include "interfaz_grafica.h"

void inicializar_aplicacion(GtkApplication *aplicacion)
{
    GtkWidget* ventana1;
    GtkWidget* contenedor_principal;
    GtkWidget* contenedor_izquierdo;
    GtkWidget* contenedor_derecho;
    GtkWidget* cantidad_trabajadores_label;
    GtkWidget* cantidad_trabajadores_input;
    GtkWidget* trabajador_enfermo_label;
    GtkWidget* trabajador_enfermo_input;
    GtkWidget* boton;
    GtkWidget* label_imagen;
    GtkWidget* imagen;
    GtkWidget* resumen_label;

    // Creacion de la ventana
    ventana1 = gtk_application_window_new(aplicacion);
    gtk_window_set_title(GTK_WINDOW(ventana1), "Mate discreta Trabajo Final");
    gtk_window_set_default_size(GTK_WINDOW(ventana1), 800, 400);

    // Creacion de contenedores

    contenedor_principal = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 10);
    contenedor_izquierdo = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
    contenedor_derecho = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);

    // Inicializacion de variables

    cantidad_trabajadores_label = gtk_label_new("Ingresa la cantidad de trabajadores (60 <= n <= 120)");
    cantidad_trabajadores_input = gtk_entry_new();
    gtk_entry_set_input_purpose(GTK_ENTRY(cantidad_trabajadores_input), GTK_INPUT_PURPOSE_NUMBER);

    trabajador_enfermo_label = gtk_label_new("Ingresa el índice del trabajador enfermo (menor al número de trabajadores)");
    trabajador_enfermo_input = gtk_entry_new();
    gtk_entry_set_input_purpose(GTK_ENTRY(trabajador_enfermo_input), GTK_INPUT_PURPOSE_NUMBER);

    boton = gtk_button_new_with_label("Confirmar Datos");

    imagen = gtk_image_new();
    label_imagen = gtk_label_new("Representación del grafo dirigido:");

    resumen_label = gtk_label_new("");

    struct ui_imagenes_t* _mis_entradas = malloc(sizeof(struct ui_imagenes_t));
    _mis_entradas->n_trabajadores = cantidad_trabajadores_input;
    _mis_entradas->trabajador_e = trabajador_enfermo_input;
    _mis_entradas->imagen = imagen;
    _mis_entradas->matriz = NULL;
    _mis_entradas-> resumen_label = resumen_label;

    // Incluir widgets a contenedores

    gtk_box_append(GTK_BOX(contenedor_izquierdo), cantidad_trabajadores_label);
    gtk_box_append(GTK_BOX(contenedor_izquierdo), cantidad_trabajadores_input);
    gtk_box_append(GTK_BOX(contenedor_izquierdo), trabajador_enfermo_label);
    gtk_box_append(GTK_BOX(contenedor_izquierdo), trabajador_enfermo_input);
    gtk_box_append(GTK_BOX(contenedor_izquierdo), boton);
    gtk_box_append(GTK_BOX(contenedor_izquierdo), resumen_label);

    gtk_box_append(GTK_BOX(contenedor_derecho), label_imagen);
    gtk_box_append(GTK_BOX(contenedor_derecho), imagen);

    // Aplicar estilos graficos

    gtk_widget_set_hexpand(imagen, TRUE);
    gtk_widget_set_vexpand(imagen, TRUE);
    gtk_widget_set_halign(imagen, GTK_ALIGN_FILL);
    gtk_widget_set_valign(imagen, GTK_ALIGN_FILL);

    gtk_widget_set_margin_top(label_imagen, 10);
    gtk_widget_set_margin_bottom(label_imagen, 10);
    gtk_widget_set_margin_start(label_imagen, 20);
    gtk_widget_set_margin_end(label_imagen, 20);

    gtk_widget_set_margin_top(cantidad_trabajadores_label, 10);
    gtk_widget_set_margin_bottom(cantidad_trabajadores_label, 10);
    gtk_widget_set_margin_start(cantidad_trabajadores_label, 20);
    gtk_widget_set_margin_end(cantidad_trabajadores_label, 20);

    gtk_widget_set_halign(label_imagen, GTK_ALIGN_CENTER);
    gtk_widget_set_valign(label_imagen, GTK_ALIGN_CENTER);

    // Incluir los sub contenedores al contenedor principal

    gtk_box_append(GTK_BOX(contenedor_principal), contenedor_izquierdo);
    gtk_box_append(GTK_BOX(contenedor_principal), contenedor_derecho);

    // Suscribir los widgets a eventos.

    g_signal_connect(cantidad_trabajadores_input, "notify::text", G_CALLBACK(al_escribir_filtro), NULL);
    g_signal_connect(trabajador_enfermo_input, "notify::text", G_CALLBACK(al_escribir_filtro), NULL);
    g_signal_connect(boton, "clicked", G_CALLBACK(al_pulsar_boton), _mis_entradas);
    g_signal_connect(ventana1, "close-request", G_CALLBACK(al_cerrar_ventana), _mis_entradas);


    // Incluir el cotenedor principal a la ventana

    gtk_window_set_child(GTK_WINDOW(ventana1), contenedor_principal);
    gtk_window_present(GTK_WINDOW(ventana1));
}