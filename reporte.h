#ifndef REPORTE_H_INCLUDED
#define REPORTE_H_INCLUDED
#include "struct.h"


void menu_reportes();
int eleccion_reporte(int key);
void pintar_opciones_reporte(int opc);
void reporte(int opc);
void reporte1();
float peso_promedio();
void listar_peso_mayor_promedio(float promedio);
void mostrar_usuarios_encolumnado2(usuarios reg, int x, int y);
void imprimir_columnas2(int x, int y);
void mostrar_fecha2(fecha reg);
void reporte2();
void mostrar_usuario_actividad(int usuario, bool *actividades, int y, int a);
int cantidad_usuarios2();
int cantidad_entrenamientos2();

#endif // REPORTE_H_INCLUDED
