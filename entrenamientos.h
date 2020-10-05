#ifndef ENTRENAMIENTOS_H_INCLUDED
#define ENTRENAMIENTOS_H_INCLUDED

#include "struct.h"

void menu_entrenamientos();
void sub_menu_entrenamientos(int opc);
void pintar_opciones_entrenamientos(int opc, int cursorX, int cursorY);
entrenamientos cargar_entrenamiento();
bool guardar_entrenamiento(entrenamientos nuevo);
bool modificar_entrenamiento();
void imprimir_columnas_entrenamiento(int x, int y);
void listar_entrenamientos();
void mostrar_entrenamientos(entrenamientos reg, int x, int y);
void mostrar_entrenamiento();
int buscar_id(int id);
void listar_entrenamiento_usuario();
bool cambiar_apto(entrenamientos *p);
void mostrar_entrenamiento_id(entrenamientos reg, int x, int y);
void eleccion_modificar_entrenamiento(int key, int y, bool *eleccion);
void eleccion_modificar_entrenamiento2(int key, int y, bool *eleccion);
char elegir_actividad1(int key);
char elegir_actividad(int key, int y);
bool elegir_apto(int key, int x, int y);
int cant_entrenamientos();

#endif // ENTRENAMIENTOS_H_INCLUDED
