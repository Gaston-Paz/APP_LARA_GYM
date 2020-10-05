#ifndef STRUCT_H_INCLUDED
#define STRUCT_H_INCLUDED
struct fecha{

int dia;
int mes;
int anio;

};

struct usuarios{

int id;           ///positivo y unico
char nombre[50]{};   ///con espacio y no puede ser vacia
char apellido[50];  ///con espacio y no puede ser vacia
fecha nacimiento;   ///fecha valida mayor a 13 años
float altura;       ///numero real no negativo. expresado en centimetros
float peso;         ///numero real no negativo. en kilos
char perfil;        ///A, B o C. minuscula o mayuscula.
int aptoMedico;    /// 1 o 0
bool estado;        /// true o false

};

struct entrenamientos{
int id;
int idUsuario;
fecha entrenamiento;
int actividad;
float calorias;
int minutos;

};



#endif // STRUCT_H_INCLUDED
