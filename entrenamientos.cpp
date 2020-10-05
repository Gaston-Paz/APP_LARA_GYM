#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <ctime>

using namespace std;

#include "generales.h"
#include "entrenamientos.h"
#include "validaciones.h"
#include "rlutil.h"

using namespace rlutil;

///MENUES

void menu_entrenamientos(){
int key, opc, cursorX, cursorY;

while(0<1){
cls();
cursorX=32;
cursorY=8;
opc=1;

titulo("APP LARA");
sub_titulo("           MENU ENTRENAMIENTOS          ",32);

locate(cursorX, cursorY);
setBackgroundColor(BLUE);
cout<<"                                        ";
setBackgroundColor(BLACK);
locate(cursorX, cursorY+2);
setColor(LIGHTGREEN);
cout<<"1 - NUEVO ENTRENAMIENTO";
locate(cursorX, cursorY+4);
setColor(WHITE);
cout<<"2 - MODIFICAR ENTRENAMIENTO";
locate(cursorX, cursorY+6);
cout<<"3 - LISTAR ENTRENAMIENTO POR ID";
locate(cursorX, cursorY+8);
cout<<"4 - LISTAR ENTRENAMIENTOS POR ID-USUARIO";
locate(cursorX, cursorY+10);
cout<<"5 - LISTAR TODOS LOS ENTRENAMIENTOS";
locate(cursorX, cursorY+12);
setBackgroundColor(BLUE);
cout<<"                                        ";
setBackgroundColor(BLACK);
locate(cursorX, cursorY+14);
cout<<"0 - VOLVER AL MENU PRINCIPAL";
locate(cursorX-2,cursorY+2);
setColor(LIGHTGREEN);
cout<<">";
setColor(WHITE);

key = getkey();

      while(key != KEY_ENTER){

            locate(cursorX-2,cursorY+2);
            cout<<"  ";
                switch(key){
                case KEY_DOWN:
                    if(opc <= 5){
                        if(opc == 5){
                            opc=0;

                        }
                        else{
                            if(opc == 0){
                                opc=1;

                            }
                            else{
                            opc++;

                            }
                            }
                    }
                    else{
                    opc=1;

                    }

                break;

                case KEY_UP:
                    if(opc > 1){
                        opc--;

                    }
                    else{
                        if(opc == 0){
                            opc=5;

                        }
                        else{
                            opc=0;

                        }
                    }

                break;
                }

            pintar_opciones_entrenamientos(opc, cursorX, cursorY);

            key = getkey();

        }

    sub_menu_entrenamientos(opc);

    if(opc == 0){return;}


}
}

void sub_menu_entrenamientos(int opc){

entrenamientos nuevo;

switch(opc){

    case 1:
    system("cls");
    titulo("APP LARA");
    sub_titulo("   ENTRENAMIENTO NUEVO   ");
    nuevo = cargar_entrenamiento();
    if(guardar_entrenamiento(nuevo)){
        msj("ENTRENAMIENTO CARGADO");
        cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
        system("pause>nul");
    }
    break;

    case 2:
    system("cls");
    titulo("APP LARA");
    sub_titulo("   MODIFICAR ENTRENAMIENTO   ");
    if(modificar_entrenamiento()){
        locate(5,19);
        msj("ENTRENAMIENTO MODIFICADO");
        ///cout<<"ENTRENAMIENTO MODIFICADO";
        system("pause>nul");
    }
    else{
        msj("NO SE PUDO MODIFICAR");
        ///cout<<"NO SE PUDO MODIFICAR";
        system("pause>nul");
    }
    break;

    case 3:
    system("cls");
    titulo("APP LARA");
    sub_titulo("   ENTRENAMIENTOS POR ID   ");
    mostrar_entrenamiento();
    break;

    case 4:
    system("cls");
    titulo("APP LARA");
    sub_titulo("   ENTRENAMIENTOS POR ID USUARIO   ");
    listar_entrenamiento_usuario();
    break;

    case 5:
    system("cls");
    titulo("APP LARA");
    listar_entrenamientos();
    cout<<endl<<endl<<endl;
    system("pause");
    break;

    case 0:
    return;
    break;



}



}

///cargar y guardar usuarios

entrenamientos cargar_entrenamiento(){
entrenamientos reg, *p;
p = &reg;
int key, x;


setColor(WHITE);

reg.id = cant_entrenamientos();

if(reg.id > -1){
   reg.id++;
}
else{
    cout<<"NO SE PUDO GENERAR LA ID";
    }

locate(5,7);
cout<<"ID DE ENTRENAMIENTO: "<<reg.id;

locate(5,9);
cout<<"INGRESAR ID DE USUARIO: ";
cin>>reg.idUsuario;
reg.idUsuario = validar_idusuario(reg.idUsuario);

locate(5,11);
cout<<"INGRESAR LA FECHA DEL ENTRENAMIENTO: ";
locate(45,11);
cout<<"/";
locate(48,11);
cout<<"/";
locate(49,11);
cin>>reg.entrenamiento.anio;
validar_anio_entrenamiento(p);

locate(46,11);
cin>>reg.entrenamiento.mes;
validar_mes_entrenamiento(p);

locate(43,11);
cin>>reg.entrenamiento.dia;
validar_dia_entrenamiento(p);

x=26;
locate(5,13);
cout<<"INGRESAR ACTIVIDAD: ";
locate(26,13);
setColor(LIGHTGREEN);
cout<<"CAMINATA ";
setColor(WHITE);
locate(x+11,13);
cout<<"CORRER ";
locate(x+20,13);
cout<<"BICICLETA ";
locate(x+32,13);
cout<<"NATACION ";
locate(x+43,13);
cout<<"PESAS";

key = getkey();

reg.actividad = validar_actividad(key, x, p);


locate(5,15);
cout<<"INGRESAR CALORIAS QUEMADAS: ";
cin>>reg.calorias;
reg.calorias = validar_calorias(reg.calorias);

locate(5,17);
cout<<"INGRESAR EL TIEMPO, EN MINUTOS, DEL ENTRENAMIENTO: ";
cin>>reg.minutos;
reg.minutos = validar_minutos(reg.minutos);



return reg;


}

bool guardar_entrenamiento(entrenamientos nuevo){
    bool grabo;
    FILE *f;
    f = fopen("entrenamientos.dat", "ab");

    if (f == NULL){
        return false;
    }

    grabo = fwrite(&nuevo, sizeof(entrenamientos), 1, f);
    fclose(f);

    return grabo;
}

bool modificar_entrenamiento(){
entrenamientos reg;
int pos;
FILE *p;
int id, y=7;
bool eleccion = true;
int key;
bool retorno;

locate(5,y);
cout<<"INGRESAR LA ID DEL ENTRENAMIENTO A MODIFICAR: ";
cin>>id;



p = fopen("entrenamientos.dat", "rb+");
if(p == NULL){
    cout<<endl<<endl<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
}

y=9;

while(fread(&reg, sizeof(entrenamientos), 1, p)){
    if(id == reg.id){
        locate(5,y);
        cout<<"DESEA MODIFICAR EL TIEMPO?";
        locate(34,y);
        setColor(LIGHTGREEN);
        cout<<"SI";
        setColor(WHITE);
        locate(37,y);
        cout<<"NO";

        key = getkey();

        eleccion_modificar_entrenamiento(key, y, &eleccion);

        if(eleccion){
        retorno = true;
        y=11;
        locate(5,y);
        cout<<"INGRESAR EL TIEMPO DE ENTRENAMIENTO: ";
        cin>>reg.minutos;

        reg.minutos = validar_minutos(reg.minutos, 42, 11);

        fseek(p, (-1)*sizeof(entrenamientos), SEEK_CUR);
        fwrite(&reg, sizeof(entrenamientos), 1, p);
        y+=2;
        }
        else{
            retorno = false;
            y=11;
        }

        locate(5,y);
        cout<<"DESEA MODIFICAR LAS CALORIAS QUEMADAS?";
        locate(46,y);
        setColor(LIGHTGREEN);
        cout<<"SI";
        setColor(WHITE);
        locate(49,y);
        cout<<"NO";


        key = getkey();

        eleccion = true;

        eleccion_modificar_entrenamiento2(key, y, &eleccion);

        if(eleccion){
        retorno = true;
        y+=2;
        locate(5,y);
        cout<<"INGRESAR LA CALORIAS QUEMADAS: ";
        cin>>reg.calorias;

        reg.calorias = validar_calorias(reg.calorias, 36, y);

        fseek(p, (-1)*sizeof(entrenamientos), SEEK_CUR);
        fwrite(&reg, sizeof(entrenamientos), 1, p);
        }

        fclose(p);
        return retorno;
    }


}

fclose(p);
return retorno;


}

bool cambiar_apto(entrenamientos *p){
FILE *usu;
usuarios reg;
bool eleccion;
int key;
bool retorno;

usu = fopen("usuarios.dat", "rb+");
if(usu == NULL){
    cout<<"NO SE PUDO ABRIR EL ARCHIVO";
    return false;
}

while(fread(&reg, sizeof(usuarios),1, usu)){
    if(p->idUsuario == reg.id){
    locate(5,15);
    cout<<"DESEA MODIFICAR EL APTO MEDICO? ";
    locate(37,15);
    setColor(LIGHTGREEN);
    cout<<"SI";
    setColor(WHITE);
    locate(41,15);
    cout<<"NO";
    key=getkey();


    eleccion = elegir_apto(key,37,15);


    if(eleccion){

    msj("APTO MEDICO MODIFICADO A: APROBADO");
    reg.aptoMedico = true;
    fseek(usu, (-1)*sizeof(usuarios), SEEK_CUR);
    fwrite(&reg, sizeof(usuarios), 1, usu);
    fclose(usu);
    return reg.aptoMedico;
    }


    }
}
fclose(usu);

locate(5,15);
cout<<"                                                   ";
return false;
}

void pintar_opciones_entrenamientos(int opc, int cursorX, int cursorY){
            switch(opc){
            case 1:
                setColor(LIGHTGREEN);
                locate(cursorX-2,cursorY+2);
                cout<<">";
                locate(cursorX, cursorY+2);
                cout<<"1 - NUEVO ENTRENAMIENTO";
                setColor(WHITE);
                locate(cursorX-2,cursorY+4);
                cout<<"  ";
                locate(cursorX, cursorY+4);
                cout<<"2 - MODIFICAR ENTRENAMIENTO";
                locate(cursorX-2,cursorY+6);
                cout<<"  ";
                locate(cursorX, cursorY+6);
                cout<<"3 - LISTAR ENTRENAMIENTO POR ID";
                locate(cursorX-2,cursorY+8);
                cout<<"  ";
                locate(cursorX, cursorY+8);
                cout<<"4 - LISTAR ENTRENAMIENTOS POR ID-USUARIO";
                locate(cursorX-2,cursorY+10);
                cout<<"  ";
                locate(cursorX, cursorY+10);
                cout<<"5 - LISTAR TODOS LOS ENTRENAMIENTOS";
                locate(cursorX-2,cursorY+14);
                cout<<"  ";
                locate(cursorX, cursorY+14);
                cout<<"0 - VOLVER AL MENU PRINCIPAL";
            break;
            case 2:
                locate(cursorX-2,cursorY+2);
                cout<<"  ";
                locate(cursorX, cursorY+2);
                cout<<"1 - NUEVO ENTRENAMIENTO";
                setColor(LIGHTGREEN);
                locate(cursorX-2,cursorY+4);
                cout<<">";
                locate(cursorX, cursorY+4);
                cout<<"2 - MODIFICAR ENTRENAMIENTO";
                setColor(WHITE);
                locate(cursorX-2,cursorY+6);
                cout<<"  ";
                locate(cursorX, cursorY+6);
                cout<<"3 - LISTAR ENTRENAMIENTO POR ID";
                locate(cursorX-2,cursorY+8);
                cout<<"  ";
                locate(cursorX, cursorY+8);
                cout<<"4 - LISTAR ENTRENAMIENTOS POR ID-USUARIO";
                locate(cursorX-2,cursorY+10);
                cout<<"  ";
                locate(cursorX, cursorY+10);
                cout<<"5 - LISTAR TODOS LOS ENTRENAMIENTOS";
                locate(cursorX-2,cursorY+14);
                cout<<"  ";
                locate(cursorX, cursorY+14);
                cout<<"0 - VOLVER AL MENU PRINCIPAL";
            break;
            case 3:
                locate(cursorX-2,cursorY+2);
                cout<<"  ";
                locate(cursorX, cursorY+2);
                cout<<"1 - NUEVO ENTRENAMIENTO";
                locate(cursorX-2,cursorY+4);
                cout<<"  ";
                locate(cursorX, cursorY+4);
                cout<<"2 - MODIFICAR ENTRENAMIENTO";
                setColor(LIGHTGREEN);
                locate(cursorX-2,cursorY+6);
                cout<<">";
                locate(cursorX, cursorY+6);
                cout<<"3 - LISTAR ENTRENAMIENTO POR ID";
                setColor(WHITE);
                locate(cursorX-2,cursorY+8);
                cout<<"  ";
                locate(cursorX, cursorY+8);
                cout<<"4 - LISTAR ENTRENAMIENTOS POR ID-USUARIO";
                locate(cursorX-2,cursorY+10);
                cout<<"  ";
                locate(cursorX, cursorY+10);
                cout<<"5 - LISTAR TODOS LOS ENTRENAMIENTOS";
                locate(cursorX-2,cursorY+14);
                cout<<"  ";
                locate(cursorX, cursorY+14);
                cout<<"0 - VOLVER AL MENU PRINCIPAL";
            break;
            case 4:
                locate(cursorX-2,cursorY+2);
                cout<<"  ";
                locate(cursorX, cursorY+2);
                cout<<"1 - NUEVO ENTRENAMIENTO";
                locate(cursorX-2,cursorY+4);
                cout<<"  ";
                locate(cursorX, cursorY+4);
                cout<<"2 - MODIFICAR ENTRENAMIENTO";
                locate(cursorX-2,cursorY+6);
                cout<<"  ";
                locate(cursorX, cursorY+6);
                cout<<"3 - LISTAR ENTRENAMIENTO POR ID";
                setColor(LIGHTGREEN);
                locate(cursorX-2,cursorY+8);
                cout<<">";
                locate(cursorX, cursorY+8);
                cout<<"4 - LISTAR ENTRENAMIENTOS POR ID-USUARIO";
                setColor(WHITE);
                locate(cursorX-2,cursorY+10);
                cout<<"  ";
                locate(cursorX, cursorY+10);
                cout<<"5 - LISTAR TODOS LOS ENTRENAMIENTOS";
                locate(cursorX-2,cursorY+14);
                cout<<"  ";
                locate(cursorX, cursorY+14);
                cout<<"0 - VOLVER AL MENU PRINCIPAL";
            break;
            case 5:
                locate(cursorX-2,cursorY+2);
                cout<<"  ";
                locate(cursorX, cursorY+2);
                cout<<"1 - NUEVO ENTRENAMIENTO";
                locate(cursorX-2,cursorY+4);
                cout<<"  ";
                locate(cursorX, cursorY+4);
                cout<<"2 - MODIFICAR ENTRENAMIENTO";
                locate(cursorX-2,cursorY+6);
                cout<<"  ";
                locate(cursorX, cursorY+6);
                cout<<"3 - LISTAR ENTRENAMIENTO POR ID";
                locate(cursorX-2,cursorY+8);
                cout<<"  ";
                locate(cursorX, cursorY+8);
                cout<<"4 - LISTAR ENTRENAMIENTOS POR ID-USUARIO";
                setColor(LIGHTGREEN);
                locate(cursorX-2,cursorY+10);
                cout<<">";
                locate(cursorX, cursorY+10);
                cout<<"5 - LISTAR TODOS LOS ENTRENAMIENTOS";
                setColor(WHITE);
                locate(cursorX-2,cursorY+14);
                cout<<"  ";
                locate(cursorX, cursorY+14);
                cout<<"0 - VOLVER AL MENU PRINCIPAL";
            break;
            case 0:
                locate(cursorX-2,cursorY+2);
                cout<<"  ";
                locate(cursorX, cursorY+2);
                cout<<"1 - NUEVO ENTRENAMIENTO";
                locate(cursorX-2,cursorY+4);
                cout<<"  ";
                locate(cursorX, cursorY+4);
                cout<<"2 - MODIFICAR ENTRENAMIENTO";
                locate(cursorX-2,cursorY+6);
                cout<<"  ";
                locate(cursorX, cursorY+6);
                cout<<"3 - LISTAR ENTRENAMIENTO POR ID";
                locate(cursorX-2,cursorY+8);
                cout<<"  ";
                locate(cursorX, cursorY+8);
                cout<<"4 - LISTAR ENTRENAMIENTOS POR ID-USUARIO";
                locate(cursorX-2,cursorY+10);
                cout<<"  ";
                locate(cursorX, cursorY+10);
                cout<<"5 - LISTAR TODOS LOS ENTRENAMIENTOS";
                setColor(LIGHTGREEN);
                locate(cursorX-2,cursorY+14);
                cout<<">";
                locate(cursorX, cursorY+14);
                cout<<"0 - VOLVER AL MENU PRINCIPAL";
                setColor(WHITE);



            }


}

void eleccion_modificar_entrenamiento(int key, int y, bool *eleccion){
while(key != KEY_ENTER){
            switch(key){

                case KEY_RIGHT:
                if(*eleccion){
                    *eleccion = false;
                }
                else{
                    *eleccion = true;
                }

                break;

                case KEY_LEFT:
                if(*eleccion){
                    *eleccion = false;
                }
                else{
                    *eleccion = true;
                }

                break;
            }



            if(*eleccion){

                locate(34,y);
                setColor(LIGHTGREEN);
                cout<<"SI";
                setColor(WHITE);
                locate(37,y);
                cout<<"NO";
            }
            else{
                locate(34,y);
                setColor(WHITE);
                cout<<"SI";
                setColor(LIGHTGREEN);
                locate(37,y);
                cout<<"NO";
                setColor(WHITE);
            }


            key = getkey();

        }



}

void eleccion_modificar_entrenamiento2(int key, int y, bool *eleccion){
while(key != KEY_ENTER){
            switch(key){

                case KEY_RIGHT:
                if(*eleccion){
                    *eleccion = false;
                }
                else{
                    *eleccion = true;
                }

                break;

                case KEY_LEFT:
                if(*eleccion){
                    *eleccion = false;
                }
                else{
                    *eleccion = true;
                }

                break;
            }



            if(*eleccion){

                locate(46,y);
                setColor(LIGHTGREEN);
                cout<<"SI";
                setColor(WHITE);
                locate(49,y);
                cout<<"NO";
            }
            else{
                locate(46,y);
                setColor(WHITE);
                cout<<"SI";
                setColor(LIGHTGREEN);
                locate(49,y);
                cout<<"NO";
                setColor(WHITE);
            }


            key = getkey();

        }



}

int cant_entrenamientos(){
FILE *p;
entrenamientos reg;
int cant = 0;
int bytes;

p = fopen("entrenamientos.dat", "rb");
if(p == NULL){
    return 0;
}

fseek(p, sizeof(entrenamientos), SEEK_END);
bytes = ftell(p);
cant = bytes / sizeof(entrenamientos);
return cant-1;


}





