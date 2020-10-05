#ifndef VALIDACIONES_H_INCLUDED
#define VALIDACIONES_H_INCLUDED
#include "struct.h"

int validar_id(int id);
char validar_nombre(usuarios reg);
float validar_altura(float altura);
float validar_peso(float peso);
char validar_perfil(char perfil);
int validar_apto(int apto);
void validar_Nombre(usuarios *punt);
void validar_Apellido(usuarios  *punt);
void validar_anio(usuarios *punt);
void validar_mes(usuarios *punt);
void validar_dia(usuarios *punt);
char validar_eleccion(char eleccion, int x, int y);
char validar_eleccion(char eleccion);
void validar_anio_entrenamiento(entrenamientos *p);
void validar_mes_entrenamiento(entrenamientos *p);
void validar_dia_entrenamiento(entrenamientos *p);
int validar_idusuario(int idusuario);
int validar_calorias(int calorias);
int validar_calorias(int calorias, int x, int y);
int validar_minutos(int minutos);
int validar_minutos(int minutos, int x, int y);
int validar_actividad(int key, int x, entrenamientos *p);
bool validar_actividad_apto(entrenamientos *p);
void verificar_dia_Xmes(entrenamientos *p);
void verificar_dia_Xmes(usuarios *p);


#endif // VALIDACIONES_H_INCLUDED
