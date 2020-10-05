#ifndef USUARIOS_H_INCLUDED
#define USUARIOS_H_INCLUDED
#include "struct.h"

void menu_usuarios();
void sub_menu_usuarios(int opc);
void pintar_opciones_usuarios(int opc, int cursorX, int cursorY);
usuarios cargar_usuario();
bool guardar_usuario(usuarios nuevo);
void listar_usuarios();
void mostrar_usuarios(usuarios reg, int x, int y);
void mostrar_fecha(fecha reg);
void imprimir_columnas(int x, int y);
int buscar_usuario(int id);
bool modificar_usuario();
bool guardar_usuario(int pos, usuarios reg);
void mostrar_usuario();
bool baja_logica();
bool alta_logica(FILE *p,int id);


#endif // USUARIOS_H_INCLUDED
