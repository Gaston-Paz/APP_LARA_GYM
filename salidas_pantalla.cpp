#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

#include "generales.h"
#include "usuarios.h"
#include "entrenamientos.h"
#include "rlutil.h"

using namespace rlutil;


void listar_usuarios(){
    usuarios reg;
    FILE *f;
    int i=0;

    f = fopen("usuarios.dat", "rb");
    if (f == NULL){
        cout << "NO SE PUDO LEER EL ARCHIVO";
        return;
    }
    int x = 2, y = 4;
    imprimir_columnas(x,y);
    y+=2;
    while(fread(&reg, sizeof(usuarios), 1, f)){
        if(i == 11){
        i=1;
        cout<<endl<<endl;
        system("pause");
        system("cls");
        titulo("APP LARA");
        y=4;
        imprimir_columnas(x,y);
        y+=2;
        if(reg.estado == true){
        mostrar_usuarios_encolumnado(reg, x, y);
        y+=2;
        }
        }else{
        if(reg.estado == true){
        i++;
        mostrar_usuarios_encolumnado(reg, x, y);
        y+=2;
        }
        }
    }
    fclose(f);

}

void mostrar_usuarios(usuarios reg, int x, int y){
locate(x,y);
cout<<"ID                  : ";
cout<<reg.id;
locate(x, y+2);
cout<<"APELLIDO            : ";
cout<<reg.apellido;
locate(x, y+4);
cout<<"NOMBRE              : ";
cout<<reg.nombre;
locate(x, y+6);
cout<<"PESO                : ";
cout<<reg.peso;
locate(x, y+8);
cout<<"ALTURA              : ";
cout<<reg.altura;
locate(x, y+10);
cout<<"PERFIL              : ";
cout<<reg.perfil;
locate(x, y+12);
cout<<"APTO MEDICO         : ";
cout<<reg.aptoMedico;
locate(x, y+14);
cout<<"ESTADO              : ";
cout<<reg.estado;
locate(x,y+16);
cout<<"FECHA DE NACIMIENTO : ";
mostrar_fecha(reg.nacimiento);


}

void mostrar_usuario(){
int id;
FILE *p;
usuarios reg;

p = fopen("usuarios.dat", "rb");
if(p == NULL){
    cout<<"NO SE PUDO ABRIR EL ARCHIVO";
    return;
}
locate(5,7);
cout<<"INGRESAR LA ID DEL USUARIO A MOSTRAR: ";
cin>>id;

while(fread(&reg, sizeof(usuarios), 1, p)){
    if(reg.id == id){
        int x = 5;
        int y = 11;
        mostrar_usuarios(reg,x ,y);


    }
}
fclose(p);


}

void mostrar_fecha(fecha reg){
cout<<reg.dia<<"/"<<reg.mes<<"/"<<reg.anio<<endl;


}

void imprimir_columnas(int x, int y){
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

void imprimir_columnas_entrenamiento(int x, int y){

setColor(YELLOW);
locate(x,y);
cout<<"ID";
locate(x+12,y);
cout<<"ID-USUARIO";
locate(x+30,y);
cout<<"ACTIVIDAD";
locate(x+45,y);
cout<<"CALORIAS";
locate(x+55,y);
cout<<"MINUTOS";
locate(x+65,y);
cout<<"FECHA DE ENTRENAMIENTO";
setColor(WHITE);
locate(x, 5);
cout<<"---------------------------------------------------------------------------------------";
cout<<"                                                                                       ";
}

void mostrar_entrenamientos(entrenamientos reg, int x, int y){

locate(x,y);
cout<<reg.id;
locate(x+17,y);
cout<<reg.idUsuario;
locate(x+34,y);
cout<<reg.actividad;
locate(x+48,y);
cout<<reg.calorias;
locate(x+57,y);
cout<<reg.minutos;
locate(x+72,y);
mostrar_fecha(reg.entrenamiento);


}

void listar_entrenamientos(){
    entrenamientos reg;
    FILE *f;

    f = fopen("entrenamientos.dat", "rb");
    if (f == NULL){
        cout << "NO SE PUDO LEER EL ARCHIVO";
        return;
    }
    int x = 2, y = 4, i = 0;

    imprimir_columnas_entrenamiento(x,y);
    y+=2;
    while(fread(&reg, sizeof(entrenamientos), 1, f)){
        i++;
        if(i == 11){
        cout<<endl<<endl<<endl;
        system("pause");
        system("cls");
        titulo("APP LARA");
        y=4;
        imprimir_columnas_entrenamiento(x,4);
        i=1;
        y=6;
        y++;
        mostrar_entrenamientos(reg, x, y);
        y++;
        }
        else{
        y++;
        mostrar_entrenamientos(reg, x, y);
        y++;}


    }
    fclose(f);

}

void mostrar_entrenamiento(){
int id;
FILE *p;
entrenamientos reg;


p = fopen("entrenamientos.dat", "rb");
if(p == NULL){
    cout<<"NO SE PUDO ABRIR EL ARCHIVO";
    return;
}
rlutil::locate(5,7);
cout<<"INGRESAR LA ID DEL ENTRENAMIENTO A MOSTRAR: ";
cin>>id;
        bool bandera = false;
        int x = 5;
        int y = 5;
        system("cls");
        titulo("APP LARA");
        sub_titulo("         ENTRENAMIENTO POR ID          ");

while(fread(&reg, sizeof(entrenamientos), 1, p)){
    if(reg.id == id){
        y+=2;
        mostrar_entrenamiento_id(reg, x, y);
        bandera = true;
    }
}

fclose(p);

if(bandera == false){
    locate(5,9);
    msj("ID DE ENTRENAMIENTO NO REGISTRADA");
}

cout<<endl<<endl<<endl;
system("pause>nul");


}

void listar_entrenamiento_usuario(){
FILE *entrenamiento;
int id;
entrenamientos reg;
int i=0;

locate(5,7);
cout<<"INGRESAR LA ID DEL USUARIO QUE SE DESEA VER LOS ENTRENAMIENTOS: ";
cin>>id;

id = buscar_id(id);

if(id == -1){
    system("pause");
    return;
}

entrenamiento = fopen("entrenamientos.dat", "rb");

if(entrenamiento == NULL){
    cout<<endl<<endl<<"NO SE PUDO ABRIR EL ARCHIVO DE ENTRENAMIENTOS";
    return;
    }
        system("cls");
        int x = 4;
        int y = 4;
        titulo("APP LARA");
        imprimir_columnas_entrenamiento(x, y);

while(fread(&reg, sizeof(entrenamientos), 1, entrenamiento)){
    if(id == reg.idUsuario){
        i++;
        y+=2;
        if(i == 11){
        i=1;
        cout<<endl<<endl<<endl;
        system("pause");
        system("cls");
        x = 2;
        y = 5;
        titulo("APP LARA");
        imprimir_columnas_entrenamiento(x, y);
        y+=2;
        }
        mostrar_entrenamientos(reg, x, y);

    }

}

fclose(entrenamiento);
cout<<endl<<endl<<endl;
system("pause");
}

void titulo(char *cadena){
locate(0, 2);
setBackgroundColor(LIGHTRED);
cout<<"                                                                                                    ";
setColor(rlutil::WHITE);
locate(45, 1);
cout<<cadena;
setBackgroundColor(rlutil::BLACK);


}

void sub_titulo(char *cadena, int x){
locate(x, 4);
setBackgroundColor(YELLOW);
setColor(BLACK);
cout<<cadena;
setColor(WHITE);
setBackgroundColor(BLACK);
cout<<endl<<endl<<endl;

}

void sub_titulo(char *cadena){
locate(5, 4);
setBackgroundColor(YELLOW);
setColor(BLACK);
cout<<cadena;
setColor(WHITE);
setBackgroundColor(BLACK);
cout<<endl<<endl<<endl;

}

void msj(char *cadena){

if(cadena[9] == 'N' || cadena[9] == 'R' || cadena[9] == 'A'){
locate(1,40);
setBackgroundColor(RED);
cout<<"                                                                                                   ";
locate(1,40);
cout<<cadena;
locate(29,7);
setBackgroundColor(BLACK);

}
else{

locate(1,40);
setBackgroundColor(LIGHTBLUE);
cout<<"                                                                                                   ";
locate(1,40);
cout<<cadena;
locate(29,7);
setBackgroundColor(BLACK);
}

}

void mostrar_entrenamiento_id(entrenamientos reg, int x, int y){
locate(x,y);
cout << "ID                         : " << reg.id << endl;
locate(x,y+2);
cout << "ID USUARIO                 : " << reg.idUsuario<< endl;
locate(x,y+4);
cout << "FECHA DE ENTRENAMIENTO     : " << reg.entrenamiento.dia<<"/"<<reg.entrenamiento.mes<<"/"<<reg.entrenamiento.anio<< endl;
locate(x,y+6);
cout << "ACTIVIDAD                  : " << reg.actividad << endl;
locate(x,y+8);
cout << "CALORIAS                   : " <<reg.calorias <<endl;
locate(x,y+10);
cout << "MINUTOS                    : " <<reg.minutos <<endl;

}

void mostrar_usuarios_encolumnado(usuarios reg, int x, int y){

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
mostrar_fecha(reg.nacimiento);


}


