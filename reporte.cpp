#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <ctime>

using namespace std;

#include "generales.h"
#include "reporte.h"
#include "rlutil.h"

using namespace rlutil;

void menu_reportes(){
int key, opc;
system("cls");
titulo("APP LARA");
sub_titulo("       MENU REPORTES        ", 35);

locate(35, 8);
setBackgroundColor(BLUE);
cout<<"                            ";
setBackgroundColor(BLACK);
setColor(LIGHTGREEN);
locate(35, 10);
cout<<"1 - REPORTE 1";
setColor(WHITE);
locate(35, 12);
cout<<"2 - REPORTE 2";
locate(35, 16);
cout<<"0 - VOLVER AL MENU PRINCIPAL";
locate(35, 14);
setBackgroundColor(BLUE);
cout<<"                            ";
setBackgroundColor(BLACK);

key = getkey();

opc = eleccion_reporte(key);

reporte(opc);


}

int eleccion_reporte(int key){
int opc = 1;
while(key != KEY_ENTER){

    switch(key){

        case KEY_UP:
        if(opc == 1){
            opc = 0;
        }
        else{
            if(opc == 2){
                opc = 1;
            }
            else{
                opc = 2;
            }
        }
        break;

        case KEY_DOWN:
        if(opc == 1){
            opc = 2;
        }
        else{
            if(opc == 2){
                opc = 0;
            }
            else{
                opc = 1;
            }
        }
        break;

    }


    pintar_opciones_reporte(opc);
    key = getkey();

}

return opc;

}

void pintar_opciones_reporte(int opc){

switch(opc){

    case 1:
    setColor(LIGHTGREEN);
    locate(35, 10);
    cout<<"1 - REPORTE 1";
    setColor(WHITE);
    locate(35, 12);
    cout<<"2 - REPORTE 2";
    locate(35, 16);
    cout<<"0 - VOLVER AL MENU PRINCIPAL";
    break;

    case 2:
    locate(35, 10);
    cout<<"1 - REPORTE 1";
    setColor(LIGHTGREEN);
    locate(35, 12);
    cout<<"2 - REPORTE 2";
    setColor(WHITE);
    locate(35, 16);
    cout<<"0 - VOLVER AL MENU PRINCIPAL";
    break;

    case 0:
    locate(35, 10);
    cout<<"1 - REPORTE 1";
    locate(35, 12);
    cout<<"2 - REPORTE 2";
    locate(35, 16);
    setColor(LIGHTGREEN);
    cout<<"0 - VOLVER AL MENU PRINCIPAL";
    setColor(WHITE);
    break;


}



}

void reporte(int opc){

switch(opc){

case 1:
reporte1();
break;

case 2:
reporte2();
break;

case 0:
return;
break;


}


}

void reporte1(){
///Listar todos los usuarios cuyo peso supere el peso promedio.
system("cls");
titulo("APP LARA");
float promedio;

promedio = peso_promedio();
listar_peso_mayor_promedio(promedio);
cout<<endl<<endl<<endl<<endl<<endl;
system("pause");
}

float peso_promedio(){
FILE *p;
usuarios reg;
float contador = 0, acumulador = 0, promedio;

p = fopen("usuarios.dat", "rb");
if(p == NULL){
    cout<<"NO SE PUDO ABRIR EL ARCHIVO";
    return 0;
}

while(fread(&reg, sizeof(usuarios), 1, p)){
        contador ++;
        acumulador += reg.peso;

}

fclose(p);

promedio = acumulador / contador;

return promedio;

}

void listar_peso_mayor_promedio(float promedio){
FILE *p;
usuarios reg;
int x = 2, y = 4;

p = fopen("usuarios.dat", "rb");
if(p == NULL){
    cout<<"NO SE PUDO ABRIR EL ARCHIVO";
    return;
}

imprimir_columnas2(x, y);
y+=2;
while(fread(&reg, sizeof(usuarios), 1, p)){
        if(reg.peso > promedio){
        mostrar_usuarios_encolumnado2(reg, x, y);
        y+=2;
        }

}
fclose(p);

}

void mostrar_usuarios_encolumnado2(usuarios reg, int x, int y){

locate(x, y);
cout<<reg.id;
locate(x+5, y);
cout<<reg.apellido;
locate(x+23, y);
cout<<reg.nombre;
locate(x+43, y);
cout<<reg.peso;
locate(x+50, y);
cout<<reg.altura;
locate(x+58, y);
cout<<reg.perfil;
locate(x+67, y);
cout<<reg.aptoMedico;
locate(x+77, y);
mostrar_fecha2(reg.nacimiento);


}

void imprimir_columnas2(int x, int y){
setColor(YELLOW);
locate(x,y);
cout<<"ID";
locate(x+5,y);
cout<<"APELLIDOS";
locate(x+23,y);
cout<<"NOMBRES";
locate(x+43,y);
cout<<"PESO";
locate(x+49,y);
cout<<"ALTURA";
locate(x+56,y);
cout<<"PERFIL";
locate(x+63,y);
cout<<"APTO MEDICO";
locate(x+77,y);
cout<<"FECHA DE NAC.";
setColor(WHITE);


locate(2, 5);
cout<<"-----------------------------------------------------------------------------------------------";
}

void mostrar_fecha2(fecha reg){
cout<<reg.dia<<"/"<<reg.mes<<"/"<<reg.anio<<endl;


}

void reporte2(){
///Por cada usuario, listar los Apellidos y nombres y los códigos de las actividades que no realizó.
system("cls");
titulo("APP LARA");

FILE *usu, *entre;
usuarios *vec;
entrenamientos reg;
int cant,x, y=7, a=45, i;
bool actividades[5];
int usuario;

for(i=0;i<5;i++){
    actividades[i] = false;
}

cant = cantidad_usuarios2();
vec = (usuarios *) malloc(cant * sizeof(usuarios));

usu = fopen("usuarios.dat", "rb");
if(usu == NULL){
    cout<<"NO SE PUDO ABRIR EL ARCHIVO";
    return;
}

fread(vec, sizeof(usuarios), cant, usu);
fclose(usu);

entre = fopen("entrenamientos.dat", "rb");
if(entre == NULL){
    cout<<"NO SE PUDO ABRIR EL ARCHIVO";
    return;
}

for(x=0;x<cant;x++){
for(i=0;i<5;i++){
    actividades[i] = false;
}

fseek(entre, sizeof(entrenamientos), SEEK_SET);
while(fread(&reg, sizeof(entrenamientos), 1, entre)){
    if(vec[x].id == reg.idUsuario){
        actividades[reg.actividad-1] = true;
        usuario = vec[x].id;
    }


}
 mostrar_usuario_actividad(usuario, actividades, y, a);


}

free(vec);
fclose(entre);
cout<<endl<<endl<<endl<<endl;
system("pause");


}

void mostrar_usuario_actividad(int usuario, bool *actividades, int y, int a){
FILE *p;
usuarios reg;
int x;

p = fopen("usuarios.dat", "rb");
if(p == NULL){
    cout<<"NO SE PUDO ABRIR EL ARCHIVO";
    return;
}

locate(5, y);
cout<<"NOMBRE";
locate(25, y);
cout<<"APELLIDO";
locate(45, y);
cout<<"ACTIVIDADES NO REALIZADAS";


while(fread(&reg, sizeof(usuarios), 1, p)){
        y+=2;
        locate(5, y);
        cout<<reg.nombre;
        locate(25, y);
        cout<<reg.apellido;

    if(usuario == reg.id){
        for(x=0;x<5;x++){
            if(actividades[x] == false){
                locate(a, y);
                cout<<x+1;
                a+=5;
            }
        }

    }

}
fclose(p);

}

int cantidad_usuarios2(){
FILE *p;
int bytes, con = 0;
usuarios reg;

p = fopen("usuarios.dat", "rb");
if(p == NULL){
    cout<<"NO SE PUDO ABRIR EL ARCHIVO";
    return 0;
}


while(fread(&reg, sizeof(usuarios), 1, p)){
      con++;
      }

fclose(p);

return con;
}

int cantidad_entrenamientos2(){
FILE *p;
int bytes, con = 0;
entrenamientos reg;

p = fopen("entrenamientos.dat", "rb");
if(p == NULL){
    cout<<"NO SE PUDO ABRIR EL ARCHIVO";
    return 0;
}


while(fread(&reg, sizeof(entrenamientos), 1, p)){
      con++;
      }

fclose(p);

return con;


}

