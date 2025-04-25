#include "eventos.h"
#include "matriz_booleana.h"
#include "utils.h"

void cerrar_ventana(GtkButton* boton, gpointer informacion)
{
    gtk_window_close(GTK_WINDOW(informacion));
}

void mostrar_alerta(GtkWindow* padre, const char* mensaje)
{
    GtkWidget* ventana_dialogo = g_object_new(GTK_TYPE_WINDOW, NULL);
    gtk_window_set_title(GTK_WINDOW(ventana_dialogo), "Alerta");
    gtk_window_set_modal(GTK_WINDOW(ventana_dialogo), TRUE);
    gtk_window_set_transient_for(GTK_WINDOW(ventana_dialogo), padre);

    GtkWidget* contenedor = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
    gtk_widget_set_margin_top(contenedor, 20);
    gtk_widget_set_margin_bottom(contenedor, 20);
    gtk_widget_set_margin_start(contenedor, 20);
    gtk_widget_set_margin_end(contenedor, 20);

    GtkWidget* mensaje_etiqueta = gtk_label_new(mensaje);
    gtk_box_append(GTK_BOX(contenedor), mensaje_etiqueta);

    GtkWidget* boton_ok = gtk_button_new_with_label("Aceptar");
    gtk_box_append(GTK_BOX(contenedor), boton_ok);

    gtk_window_set_child(GTK_WINDOW(ventana_dialogo), contenedor);

    g_signal_connect(boton_ok, "clicked", G_CALLBACK(cerrar_ventana), ventana_dialogo);

    gtk_window_present(GTK_WINDOW(ventana_dialogo));
}
gboolean al_cerrar_ventana(GtkWindow *ventana, gpointer user_data) 
{
    struct ui_imagenes_t* retorno = (ui_imagenes_t*) user_data;
    if(retorno->matriz != NULL)
    {
        liberar_matriz(retorno->matriz);
        free(retorno->matriz);
        g_print("Matriz Limpia!\n");
    }
    free(retorno);
    g_print("struct ui limpia!\n");
    return FALSE;
}

void al_pulsar_boton(GtkButton* boton, gpointer informacion)
{
    struct ui_imagenes_t* mis_entradas = (struct ui_imagenes_t*) informacion;
    // NOTA: es importante hacer un duplicado del string recuperado!!
    const char* cantidad_trabajadores_str = g_strdup(gtk_editable_get_text(GTK_EDITABLE(mis_entradas->n_trabajadores)));
    const char* trabajador_enfermo_str = g_strdup(gtk_editable_get_text(GTK_EDITABLE(mis_entradas->trabajador_e)));

    char texto_error[135] = "";
    bool error = false;

    int cantidad_trabajadores_int = atoi(cantidad_trabajadores_str);
    if (cantidad_trabajadores_int < 60 || cantidad_trabajadores_int > 120)
    {
        sprintf(texto_error, "La cantidad trabajadores solo permite números entre 60 y 120 !\n");
        error = true;
    }

    int trabajador_enfermo_int = atoi(trabajador_enfermo_str);
    if (trabajador_enfermo_int < 0 || trabajador_enfermo_int > cantidad_trabajadores_int - 1)
    {
        char error_trabajador[100];
        snprintf(error_trabajador, sizeof(error_trabajador), "El índice de trabajador solo permite números entre 0 y %d !\n", cantidad_trabajadores_int - 1);
        strcat(texto_error, error_trabajador);
        error = true;
    }

    if (error)
    {
        mostrar_alerta(GTK_WINDOW(gtk_widget_get_root(GTK_WIDGET(boton))), texto_error);
        return;
    }

    // TODO: Validar el funcionamiento correcto de allocs y frees en la matriz y quitar los debuggers
    g_print("n: %d, x: %d\n", cantidad_trabajadores_int, trabajador_enfermo_int);
    g_print("Turno de las matrices!\n");
    if(mis_entradas->matriz == NULL)
    {
        g_print("Es nula\n");
        mis_entradas->matriz = (struct matriz_booleana*) malloc(sizeof(struct matriz_booleana));
    }
    else
    { 
        g_print("No es nula!\n");
        liberar_matriz(mis_entradas->matriz);
        free(mis_entradas->matriz);
        
        mis_entradas->matriz = (struct matriz_booleana*) malloc(sizeof(struct matriz_booleana));
    }
    *mis_entradas->matriz = crearMatriz_booleana(cantidad_trabajadores_int, cantidad_trabajadores_int);
    asignar_relacion_especial(mis_entradas->matriz);


    int dias = dias_para_infectar_todos(mis_entradas->matriz, trabajador_enfermo_int);
    short total_infectados = 1;
    short nuevos_infectados = 0;

    // Crear el string de respuesta para el albel
    GString *cadena = g_string_new("Resumen:\n");
    
    for (int i = 1; i <= dias; i++)
    {
        nuevos_infectados = infectados_en_dia(mis_entradas->matriz, trabajador_enfermo_int, i);
        total_infectados += nuevos_infectados;
        g_string_append_printf(cadena, "Dia: %d. Nuevos infectados: %d, total: %d\n", i, nuevos_infectados, total_infectados);
    }
    g_string_append_printf(cadena,"Total de dias para la infeccion: %d\n", dias);
    g_string_append_printf(cadena,"La relacion es reflexiva?: %s\n", (es_matriz_reflexiva(mis_entradas->matriz) ? "si" : "no") );
    g_string_append_printf(cadena,"La relacion es simetrica?: %s\n", (es_matriz_simetrica(mis_entradas->matriz) ? "si" : "no"));
    g_string_append_printf(cadena,"La relacion es antisimetrica?: %s\n", (es_antisimetrica(mis_entradas->matriz) ? "si" : "no"));
    
    gtk_label_set_text(GTK_LABEL(mis_entradas->resumen_label), cadena->str);

    g_string_free(cadena, TRUE);

    // Generar imagen con graphviz
    generar_archivo_dot(mis_entradas->matriz, "grafo.dot");
    system("dot -Tpng imagenes/grafo.dot -o imagenes/grafo.png");

    // Cargar imagen en la ventana

    if (g_file_test("imagenes/grafo.png", G_FILE_TEST_EXISTS))
    {
        gtk_image_set_from_file(GTK_IMAGE(mis_entradas->imagen), "imagenes/grafo.png");
    }
    else
    {
        g_print("No se pudo cargar la imagen\n");
    }
}

void al_escribir_filtro(GtkEditable *editable, gpointer informacion)
{
    const char *texto = gtk_editable_get_text(editable);
    GString *nuevo_texto = g_string_new("");

    // Validar por cada caracter e incluir unicamente los ascii numericos
    for (int i = 0; texto[i] != '\0'; i++)
    {
        if (g_ascii_isdigit(texto[i]))
            g_string_append_c(nuevo_texto, texto[i]);
    }

    if (g_strcmp0(texto, nuevo_texto->str) != 0)
    {   
        g_signal_handlers_block_by_func(editable, al_escribir_filtro, informacion); // Gestionar la exclusividad de escritura del input para evitar bucles
        gtk_editable_set_text(editable, nuevo_texto->str);
        g_signal_handlers_unblock_by_func(editable, al_escribir_filtro, informacion);   // Gestionar la exclusividad de escritura del input para evitar bucles
    }

    // eliminar el alloc del string dinamico
    g_string_free(nuevo_texto, TRUE);
}