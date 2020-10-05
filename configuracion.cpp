#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <ctime>

using namespace std;

#include "generales.h"
#include "entrenamientos.h"
#include "configuracion.h"
#include "rlutil.h"

using namespace rlutil;

void menu_configuracion(){
int key;
int opcion;

system("cls");
titulo("APP LARA");
sub_titulo("       MENU CONFIGURACION       ",35);
locate(35,7);
setBackgroundColor(BLUE);
cout<<"                                ";
setBackgroundColor(BLACK);
locate(35,9);
setColor(LIGHTGREEN);
cout<<"1 - REALIZAR COPIA DE SEGURIDAD";
locate(35,11);
setColor(WHITE);
cout<<"2 - RESTAURAR COPIA DE SEGURIDAD";
locate(35,15);
cout<<"3 - VOLVER AL MENU PRINCIPAL";
setBackgroundColor(BLUE);
locate(35,13);
cout<<"                                ";
setBackgroundColor(BLACK);
key = getkey();

opcion = realizar_o_restaurar(key,5,7);

if(opcion == 1){
system("cls");
titulo("APP LARA");
sub_titulo("      MENU CONFIGURACION       ",35);
realizar_copia();
}
else{
if(opcion == 2){
system("cls");
titulo("APP LARA");
sub_titulo("      MENU CONFIGURACION       ",35);
restaurar_copia();
}


}

}

int realizar_o_restaurar(int key, int x, int y){
int opc = 1;

while(key != KEY_ENTER){

        switch(key){
        case KEY_DOWN:
                if(opc == 1){
                    opc = 2;
                        }
                else{ if(opc == 2){
                        opc = 3;
                    }
                    else{
                        opc = 2;
                    }

                        }
        break;

        case KEY_UP:
                if(opc == 1){
                    opc = 3;
                        }
                else{ if(opc == 2){
                        opc = 1;
                    }
                    else{
                        opc = 2;
                    }

                        }
        break;
                }


        pintar_opciones_config(opc);


            key = getkey();

        }

return opc;

}

void pintar_opciones_config(int opc){

if(opc == 1){
locate(35,7);
setBackgroundColor(BLUE);
cout<<"                                ";
setBackgroundColor(BLACK);
locate(35,9);
setColor(LIGHTGREEN);
cout<<"1 - REALIZAR COPIA DE SEGURIDAD";
locate(35,11);
setColor(WHITE);
cout<<"2 - RESTAURAR COPIA DE SEGURIDAD";
locate(35,15);
cout<<"3 - VOLVER AL MENU PRINCIPAL";
setBackgroundColor(BLUE);
locate(35,13);
cout<<"                                ";
setBackgroundColor(BLACK);
}
else{if(opc == 2){
locate(35,7);
setBackgroundColor(BLUE);
cout<<"                                ";
setBackgroundColor(BLACK);
locate(35,9);
cout<<"1 - REALIZAR COPIA DE SEGURIDAD";
locate(35,11);
setColor(LIGHTGREEN);
cout<<"2 - RESTAURAR COPIA DE SEGURIDAD";
locate(35,15);
setColor(WHITE);
cout<<"3 - VOLVER AL MENU PRINCIPAL";
setBackgroundColor(BLUE);
locate(35,13);
cout<<"                                ";
setBackgroundColor(BLACK);
}
else{
locate(35,7);
setBackgroundColor(BLUE);
cout<<"                                ";
setBackgroundColor(BLACK);
locate(35,9);
cout<<"1 - REALIZAR COPIA DE SEGURIDAD";
locate(35,11);
cout<<"2 - RESTAURAR COPIA DE SEGURIDAD";
locate(35,15);
setColor(LIGHTGREEN);
cout<<"3 - VOLVER AL MENU PRINCIPAL";
setBackgroundColor(BLUE);
setColor(WHITE);
locate(35,13);
cout<<"                                ";
setBackgroundColor(BLACK);
}

}


}

void realizar_copia(){
int key;
bool opc;
locate(15,7);
cout<<"ESTA SEGURO QUE DESEA REALIZAR UNA COPIA DE SEGURIDAD DE LOS ARCHIVOS?";
setColor(LIGHTGREEN);
locate(47,9);
cout<<"SI";
setColor(WHITE);
locate(51,9);
cout<<"NO";

key = getkey();

opc = elegir_apto(key, 47, 9);

if(opc){
    copiar_usuarios();
    copiar_entrenamientos();
}



return;

}

void copiar_usuarios(){
FILE *p, *a;
usuarios *vec;
int bytes, cant, x;

cant = cantidad_usuarios();

p = fopen("usuarios.dat", "rb");
if(p == NULL){
    cout<<"NO SE PUDO ABRIR EL ARCHIVO";
    return;
}

vec = (usuarios *) malloc(cant * sizeof(usuarios));

if(vec == NULL){
    cout<<"NO HAY MEMORIA DISPONIBLE";
    return;
}

fread(vec, sizeof(usuarios), cant, p);
fclose(p);

a = fopen("usuarios.bkp", "wb");

if(a == NULL){
    cout<<"NO SE PUDO ABRIR EL ARCHIVO";
    return;
}

fwrite(vec, sizeof(usuarios), cant, a);

free(vec);
fclose(a);


}

void copiar_entrenamientos(){
FILE *p, *a;
entrenamientos *vec;
int bytes, cant, x;

cant = cantidad_entrenamientos();

p = fopen("entrenamientos.dat", "rb");

if(p == NULL){
    cout<<"NO SE PUDO ABRIR EL ARCHIVO";
    return;
}

vec = (entrenamientos *) malloc(cant * sizeof(entrenamientos));

if(vec == NULL){
    cout<<"NO HAY MEMORIA DISPONIBLE";
    return;
}

fread(vec, sizeof(entrenamientos), cant, p);

fclose(p);

a = fopen("entrenamientos.bkp", "wb");

if(a == NULL){
    cout<<"NO SE PUDO ABRIR EL ARCHIVO";
    return;
}

fwrite(vec, sizeof(entrenamientos), cant, a);

free(vec);
fclose(a);




}

void restaurar_copia(){
int key;
bool opc;
locate(15,7);
cout<<"ESTA SEGURO QUE DESEA RESTAURAR UNA COPIA DE SEGURIDAD DE LOS ARCHIVOS?";
setColor(LIGHTGREEN);
locate(47,9);
cout<<"SI";
setColor(WHITE);
locate(51,9);
cout<<"NO";

key = getkey();

opc = elegir_apto(key, 47, 9);

if(opc){
    restaurar_usuarios();
    restaurar_entrenamientos();
}



return;


}

void restaurar_usuarios(){
FILE *p, *a;
usuarios *vec;
int bytes, cant, x;

cant = cantidad_usuarios_bkp();

p = fopen("usuarios.bkp", "rb");
if(p == NULL){
    cout<<"NO SE PUDO ABRIR EL ARCHIVO";
    return;
}

vec = (usuarios *) malloc(cant * sizeof(usuarios));

if(vec == NULL){
    cout<<"NO HAY MEMORIA DISPONIBLE";
   return;
}

fread(vec, sizeof(usuarios), cant, p);
fclose(p);

a = fopen("usuarios.dat", "wb");

if(a == NULL){
    cout<<"NO SE PUDO ABRIR EL ARCHIVO";
    return;
}

fwrite(vec, sizeof(usuarios), cant, a);

free(vec);
fclose(a);


}

void restaurar_entrenamientos(){
FILE *p, *a;
entrenamientos *vec;
int bytes, cant, x;
cant = cantidad_entrenamientos_bkp();

p = fopen("entrenamientos.bkp", "rb");
if(p == NULL){
    cout<<"NO SE PUDO ABRIR EL ARCHIVO";
    return;
}

vec = (entrenamientos *) malloc(cant * sizeof(entrenamientos));
if(vec == NULL){
    cout<<"NO HAY MEMORIA DISPONIBLE";
    return;
}

fread(vec, sizeof(entrenamientos), cant, p);
fclose(p);

a = fopen("entrenamientos.dat", "wb");

if(a == NULL){
    cout<<"NO SE PUDO ABRIR EL ARCHIVO";
    return;
}


fwrite(vec, sizeof(entrenamientos), cant, a);
free(vec);
fclose(a);




}

int cantidad_usuarios(){
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

int cantidad_usuarios_bkp(){
FILE *p;
int bytes, con = 0;
usuarios reg;

p = fopen("usuarios.bkp", "rb");
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

int cantidad_entrenamientos(){
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

int cantidad_entrenamientos_bkp(){
FILE *p;
int bytes, con = 0;
entrenamientos reg;

p = fopen("entrenamientos.bkp", "rb");
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


