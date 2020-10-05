#ifndef CONFIGURACION_H_INCLUDED
#define CONFIGURACION_H_INCLUDED

#include "struct.h"
void menu_configuracion();
void pintar_opciones_config(int opc);
int realizar_o_restaurar(int key, int x, int y);
int cantidad_usuarios();
int cantidad_usuarios_bkp();
int cantidad_entrenamientos();
int cantidad_entrenamientos_bkp();
void realizar_copia();
void copiar_usuarios();
void copiar_entrenamientos();
void restaurar_copia();
void restaurar_usuarios();
void restaurar_entrenamientos();


#endif // CONFIGURACION_H_INCLUDED
