#ifndef GENERALES_H_INCLUDED
#define GENERALES_H_INCLUDED
#include "struct.h"

void menu_principal(int opc);
void menu_principal();
void pintar_opciones(int opc, int cursorX, int cursorY);
void creditos();
void titulo(char *);
void sub_titulo(char *);
void sub_titulo(char *, int x);
void msj(char *cadena);
void mostrar_usuarios_encolumnado(usuarios reg, int x, int y);


#endif // GENERALES_H_INCLUDED
