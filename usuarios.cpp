#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <ctime>

using namespace std;

#include "generales.h"
#include "usuarios.h"
#include "entrenamientos.h"
#include "validaciones.h"
#include "rlutil.h"

using namespace rlutil;


void menu_usuarios(){
int key, opc, cursorX, cursorY;

while(0<1){
cls();
cursorX=34;
cursorY=8;
opc=1;

titulo("APP LARA");
sub_titulo("      MENU DE USUARIOS       ", 34);

locate(cursorX, cursorY);
setBackgroundColor(BLUE);
cout<<"                            ";
setBackgroundColor(BLACK);
locate(cursorX, cursorY+2);
setColor(LIGHTGREEN);
cout<<"1 - NUEVO USUARIO";
locate(cursorX, cursorY+4);
setColor(WHITE);
cout<<"2 - MODIFICAR USUARIO";
locate(cursorX, cursorY+6);
cout<<"3 - LISTAR USUARIO POR ID";
locate(cursorX, cursorY+8);
cout<<"4 - LISTAR TODOS LOS USUARIOS";
locate(cursorX, cursorY+10);
cout<<"5 - ELIMINAR USUARIO";
locate(cursorX, cursorY+12);
setBackgroundColor(BLUE);
cout<<"                            ";
setBackgroundColor(BLACK);
locate(cursorX, cursorY+14);
cout<<"0 - VOLVER AL MENU PRINCIPAL";
setColor(LIGHTGREEN);
locate(cursorX-2,cursorY+2);
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

            pintar_opciones_usuarios(opc, cursorX, cursorY);

            key = getkey();

        }

    sub_menu_usuarios(opc);

    if(opc == 0){return;}


}
}

void sub_menu_usuarios(int opc){

usuarios nuevo;

switch(opc){

    case 1:
    system("cls");
    titulo("APP LARA");
    nuevo = cargar_usuario();
    if(guardar_usuario(nuevo)){
        msj("USUARIO GUARDADO");
        cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
        cout<<endl<<endl<<endl<<endl;
        system("pause>nul");
    }
    break;

    case 2:
    system("cls");
    titulo("APP LARA");
    if(modificar_usuario()){
        msj("USUARIO MODIFICADO");
    }
    else{
        msj("NO SE PUDO MODIFICAR EL USUARIO");
    }
    cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
    cout<<endl<<endl<<endl<<endl;
    system("pause>nul");
    break;

    case 3:
    system("cls");
    titulo("APP LARA");
    sub_titulo("   MOSTRAR USUARIO   ");
    mostrar_usuario();
    cout<<endl<<endl<<endl;
    system("pause>nul");
    break;

    case 4:
    system("cls");
    titulo("APP LARA");
    listar_usuarios();
    cout<<endl<<endl<<endl<<endl<<endl;
    system("pause");
    break;

    case 5:
    system("cls");
    titulo("APP LARA");
    baja_logica();

    system("pause>nul");
    break;

    case 0:
    return;
    break;




}


}

usuarios cargar_usuario(){
usuarios reg, *punt;
punt = &reg;

sub_titulo("  REGISTRO DE USUARIO  ");

reg.estado = true;
locate(5,7);
cout<<"INGRESAR ID DE USUARIO: ";
cin>>reg.id;
reg.id = validar_id(reg.id);
cin.ignore();

locate(5,9);
cout<<"INGRESAR EL NOMBRE: ";
cin.getline(reg.nombre, 50);
validar_Nombre(punt);

locate(5,11);
cout<<"INGRESAR EL APELLIDO: ";
cin.getline(reg.apellido, 50);
validar_Apellido(punt);

locate(5,13);
cout<<"INGRESAR LA FECHA DE NACIMIENTO: "<<endl;
locate(41,13);
cout<<"/";
locate(44,13);
cout<<"/";
locate(45,13);
cin>>reg.nacimiento.anio;
validar_anio(punt);
locate(42,13);
cin>>reg.nacimiento.mes;
validar_mes(punt);
locate(39,13);
cin>>reg.nacimiento.dia;
validar_dia(punt);

locate(5,15);
cout<<"INGRESAR ALTURA: ";
cin>>reg.altura;
reg.altura = validar_altura(reg.altura);

locate(5,17);
cout<<"INGRESAR PESO: ";
cin>>reg.peso;
reg.peso = validar_peso(reg.peso);

locate(5,19);
cout<<"INGRESAR PERFIL DE ACTIVIDAD: ";
locate(36,19);
setColor(LIGHTGREEN);
cout<<"A";
setColor(WHITE);
locate(38,19);
cout<<"B";
locate(40,19);
cout<<"C";
int key;
key = getkey();
reg.perfil = elegir_actividad1(key);

locate(5,21);
cout<<"INGRESAR APTO MEDICO: ";
locate(28,21);
setColor(LIGHTGREEN);
cout<<"SI";
setColor(WHITE);
locate(32,21);
cout<<"NO";
key = getkey();
int y=21;
int x=28;
reg.aptoMedico = elegir_apto(key, x, y);


return reg;


}

bool guardar_usuario(usuarios nuevo){
    bool grabo = true;
    FILE *f;
    f = fopen("usuarios.dat", "ab");

    if (f == NULL){
        return false;
    }

    grabo = fwrite(&nuevo, sizeof(usuarios), 1, f);
    fclose(f);

    return grabo;
}

int buscar_usuario(int id){
usuarios reg;
FILE *p;
int pos = 0;

p = fopen("usuarios.dat","rb");

if(p == NULL){
    return -2;
}
while(fread(&reg, sizeof(usuarios), 1, p)){
    if(id == reg.id){
        fclose(p);
        return pos;
    }
    pos++;
}
fclose(p);
return -1;
}

bool modificar_usuario(){
usuarios reg;
int pos, y=7, key, x=43, id;
FILE *p;
bool eleccion = true, retorno = false;

sub_titulo("  MODIFICAR USUARIO  ");
locate(5,7);
cout<<"INGRESAR LA ID DEL USUARIO A MODIFICAR: ";
cin>>id;



p = fopen("usuarios.dat", "rb+");
if(p == NULL){
    cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
}

while(fread(&reg, sizeof(usuarios), 1, p)){
    if(id == reg.id){
        y+=2;
        locate(5,y);
        cout<<"DESEAS MODIFICAR EL PESO DEL USUARIO? ";
        locate(43,y);
        setColor(LIGHTGREEN);
        cout<<"SI";
        setColor(WHITE);
        locate(47,y);
        cout<<"NO";

        key = getkey();

        eleccion = elegir_apto(key,x,y);

        if(eleccion){
        retorno = true;
        y+=2;
        locate(5,y);
        cout<<"INGRESAR EL PESO NUEVO: ";
        cin>>reg.peso;
        fseek(p, (-1)*sizeof(usuarios), SEEK_CUR);
        fwrite(&reg, sizeof(usuarios), 1, p);
        }

        x=50;
        y+=2;
        locate(5,y);
        cout<<"DESEAS MODIFICAR EL APTO MEDICO DEL USUARIO? ";
        locate(50,y);
        setColor(LIGHTGREEN);
        cout<<"SI";
        setColor(WHITE);
        locate(54,y);
        cout<<"NO";

        key = getkey();

        eleccion = elegir_apto(key,x,y);

        if(eleccion){
        retorno = true;
        x=29;
        y+=2;
        locate(5,y);
        cout<<"TIENE EL APTO MEDICO? ";
        locate(29,y);
        setColor(LIGHTGREEN);
        cout<<"SI";
        setColor(WHITE);
        locate(33,y);
        cout<<"NO";

        key = getkey();

        reg.aptoMedico = elegir_apto(key,x,y);

        fseek(p, (-1)*sizeof(usuarios), SEEK_CUR);
        fwrite(&reg, sizeof(usuarios), 1, p);
        }

        x=47;
        y+=2;
        locate(5,y);
        cout<<"DESEAS MODIFICAR EL PERFIL DEL USUARIO? ";
        locate(47,y);
        setColor(LIGHTGREEN);
        cout<<"SI";
        setColor(WHITE);
        locate(51,y);
        cout<<"NO";

        key = getkey();

        eleccion = elegir_apto(key,x,y);

        if(eleccion){
        retorno = true;
        y+=2;
        locate(5,y);
        cout<<"INGRESAR EL PERFIL NUEVO: ";
        locate(36,y);
        setColor(LIGHTGREEN);
        cout<<"A";
        setColor(WHITE);
        locate(38,y);
        cout<<"B";
        locate(40,y);
        cout<<"C";
        key=getkey();
        reg.perfil = elegir_actividad(key, y);

        fseek(p, (-1)*sizeof(usuarios), SEEK_CUR);
        fwrite(&reg, sizeof(usuarios), 1, p);
        }
        fclose(p);

    }


}

fclose(p);
return retorno;



}

bool guardar_usuario(int pos, usuarios reg){
bool grabo;
FILE *f;

    f = fopen("usuarios.dat", "rb+");

    if (f == NULL){
        return false;
    }

    fseek(f, pos*sizeof(usuarios),SEEK_SET);
    grabo = fwrite(&reg, sizeof(usuarios), 1, f);
    fclose(f);

    return grabo;

}

bool baja_logica(){
FILE *p;
usuarios reg;
int id, key;
bool eleccion = true;

sub_titulo("   ELIMINAR USUARIO   ");
locate(5,7);
cout<<"INGRESAR ID A DAR DE BAJA: ";
cin>>id;

p = fopen("usuarios.dat", "rb+");
if(p == NULL){
    cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
}

while(fread(&reg, sizeof(usuarios), 1, p)){
    if(id == reg.id){
        locate(5,9);
        cout<<"ESTAS SEGURO DE QUE QUERES ELIMINAR AL USUARIO CON ID "<<id<<" ? ";
        locate(67,9);
        setColor(LIGHTGREEN);
        cout<<"SI";
        setColor(WHITE);
        locate(71,9);
        cout<<"NO";

        key = getkey();

        eleccion = !elegir_apto(key, 67, 9);

        if(!eleccion){
        msj("SE DIO DE BAJA EL USUARIO");
        reg.estado = false;
        fseek(p, (-1)*sizeof(usuarios), SEEK_CUR);
        fwrite(&reg, sizeof(usuarios), 1, p);
        }
        else{
        alta_logica(p,id);
        }
        fclose(p);

    }


}

fclose(p);
return !eleccion;

}

bool alta_logica(FILE *p,int id){
usuarios reg;
int key;
bool eleccion = true;

fseek(p,sizeof(usuarios),SEEK_SET);

while(fread(&reg, sizeof(usuarios), 1, p)){
    if(id == reg.id){
        locate(5,11);
        cout<<"ESTAS SEGURO DE QUE QUERES DAR DE ALTA EL USUARIO CON ID "<<id<<" ? ";
        locate(67,11);
        setColor(LIGHTGREEN);
        cout<<"SI";
        setColor(WHITE);
        locate(71,11);
        cout<<"NO";

        key = getkey();

        eleccion = elegir_apto(key, 67, 11);

        if(eleccion){
        msj("SE DIO DE ALTA EL USUARIO");
        reg.estado = true;
        fseek(p, (-1)*sizeof(usuarios), SEEK_CUR);
        fwrite(&reg, sizeof(usuarios), 1, p);
        }


    }


}


return eleccion;

}

int buscar_id(int id){
FILE *usuario;
usuarios reg;

usuario = fopen("usuarios.dat", "rb");
if(usuario == NULL){
    cout<<endl<<endl<<"NO SE PUDO ABRIR EL ARCHIVO";
    return -1;
}

while(fread(&reg, sizeof(usuarios), 1, usuario)){
    if(id == reg.id){
        locate(5,9);
        cout<<"ID ENCONTRADA EN EL ARCHIVO";
        fclose(usuario);
        cout<<endl<<endl<<endl;
        system("pause>nul");
        return id;
    }


}
locate(5,9);
cout<<"LA ID INGRESADA NO EXISTE";
fclose(usuario);
return -1;
}

void pintar_opciones_usuarios(int opc, int cursorX, int cursorY){

            switch(opc){
            locate(cursorX-2, cursorY+2);
            cout<<"   ";

            case 1:
                setColor(LIGHTGREEN);
                locate(cursorX-2,cursorY+2);
                cout<<">";
                locate(cursorX, cursorY+2);
                cout<<"1 - NUEVO USUARIO";
                setColor(WHITE);
                locate(cursorX-2,cursorY+4);
                cout<<"  ";
                locate(cursorX, cursorY+4);
                cout<<"2 - MODIFICAR USUARIO";
                locate(cursorX-2,cursorY+6);
                cout<<"  ";
                locate(cursorX, cursorY+6);
                cout<<"3 - LISTAR USUARIO POR ID";
                locate(cursorX-2,cursorY+8);
                cout<<"  ";
                locate(cursorX, cursorY+8);
                cout<<"4 - LISTAR TODOS LOS USUARIOS";
                locate(cursorX-2,cursorY+10);
                cout<<"  ";
                locate(cursorX, cursorY+10);
                cout<<"5 - ELIMINAR USUARIO";
                locate(cursorX-2,cursorY+14);
                cout<<"  ";
                locate(cursorX, cursorY+14);
                cout<<"0 - VOLVER AL MENU PRINCIPAL";
            break;

            case 2:
                locate(cursorX-2,cursorY+2);
                cout<<"  ";
                locate(cursorX, cursorY+2);
                cout<<"1 - NUEVO USUARIO";
                setColor(LIGHTGREEN);
                locate(cursorX-2,cursorY+4);
                cout<<">";
                locate(cursorX, cursorY+4);
                cout<<"2 - MODIFICAR USUARIO";
                setColor(WHITE);
                locate(cursorX-2,cursorY+6);
                cout<<"  ";
                locate(cursorX, cursorY+6);
                cout<<"3 - LISTAR USUARIO POR ID";
                locate(cursorX-2,cursorY+8);
                cout<<"  ";
                locate(cursorX, cursorY+8);
                cout<<"4 - LISTAR TODOS LOS USUARIOS";
                locate(cursorX-2,cursorY+10);
                cout<<"  ";
                locate(cursorX, cursorY+10);
                cout<<"5 - ELIMINAR USUARIO";
                locate(cursorX-2,cursorY+14);
                cout<<"  ";
                locate(cursorX, cursorY+14);
                cout<<"0 - VOLVER AL MENU PRINCIPAL";
            break;

            case 3:
                locate(cursorX-2,cursorY+2);
                cout<<"  ";
                locate(cursorX, cursorY+2);
                cout<<"1 - NUEVO USUARIO";
                locate(cursorX-2,cursorY+4);
                cout<<"  ";
                locate(cursorX, cursorY+4);
                cout<<"2 - MODIFICAR USUARIO";
                setColor(LIGHTGREEN);
                locate(cursorX-2,cursorY+6);
                cout<<">";
                locate(cursorX, cursorY+6);
                cout<<"3 - LISTAR USUARIO POR ID";
                setColor(WHITE);
                locate(cursorX-2,cursorY+8);
                cout<<"  ";
                locate(cursorX, cursorY+8);
                cout<<"4 - LISTAR TODOS LOS USUARIOS";
                locate(cursorX-2,cursorY+10);
                cout<<"  ";
                locate(cursorX, cursorY+10);
                cout<<"5 - ELIMINAR USUARIO";
                locate(cursorX-2,cursorY+14);
                cout<<"  ";
                locate(cursorX, cursorY+14);
                cout<<"0 - VOLVER AL MENU PRINCIPAL";
            break;

            case 4:
                locate(cursorX-2,cursorY+2);
                cout<<"  ";
                locate(cursorX, cursorY+2);
                cout<<"1 - NUEVO USUARIO";
                locate(cursorX-2,cursorY+4);
                cout<<"  ";
                locate(cursorX, cursorY+4);
                cout<<"2 - MODIFICAR USUARIO";
                locate(cursorX-2,cursorY+6);
                cout<<"  ";
                locate(cursorX, cursorY+6);
                cout<<"3 - LISTAR USUARIO POR ID";
                setColor(LIGHTGREEN);
                locate(cursorX-2,cursorY+8);
                cout<<">";
                locate(cursorX, cursorY+8);
                cout<<"4 - LISTAR TODOS LOS USUARIOS";
                setColor(WHITE);
                locate(cursorX-2,cursorY+10);
                cout<<"  ";
                locate(cursorX, cursorY+10);
                cout<<"5 - ELIMINAR USUARIO";
                locate(cursorX-2,cursorY+14);
                cout<<"  ";
                locate(cursorX, cursorY+14);
                cout<<"0 - VOLVER AL MENU PRINCIPAL";
            break;

            case 5:
                locate(cursorX-2,cursorY+2);
                cout<<"  ";
                locate(cursorX, cursorY+2);
                cout<<"1 - NUEVO USUARIO";
                locate(cursorX-2,cursorY+4);
                cout<<"  ";
                locate(cursorX, cursorY+4);
                cout<<"2 - MODIFICAR USUARIO";
                locate(cursorX-2,cursorY+6);
                cout<<"  ";
                locate(cursorX, cursorY+6);
                cout<<"3 - LISTAR USUARIO POR ID";
                locate(cursorX-2,cursorY+8);
                cout<<"  ";
                locate(cursorX, cursorY+8);
                cout<<"4 - LISTAR TODOS LOS USUARIOS";
                setColor(LIGHTGREEN);
                locate(cursorX-2,cursorY+10);
                cout<<">";
                locate(cursorX, cursorY+10);
                cout<<"5 - ELIMINAR USUARIO";
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
                cout<<"1 - NUEVO USUARIO";
                locate(cursorX-2,cursorY+4);
                cout<<"  ";
                locate(cursorX, cursorY+4);
                cout<<"2 - MODIFICAR USUARIO";
                locate(cursorX-2,cursorY+6);
                cout<<"  ";
                locate(cursorX, cursorY+6);
                cout<<"3 - LISTAR USUARIO POR ID";
                locate(cursorX-2,cursorY+8);
                cout<<"  ";
                locate(cursorX, cursorY+8);
                cout<<"4 - LISTAR TODOS LOS USUARIOS";
                locate(cursorX-2,cursorY+10);
                cout<<"  ";
                locate(cursorX, cursorY+10);
                cout<<"5 - ELIMINAR USUARIO";
                setColor(LIGHTGREEN);
                locate(cursorX-2,cursorY+14);
                cout<<">";
                locate(cursorX, cursorY+14);
                cout<<"0 - VOLVER AL MENU PRINCIPAL";
                setColor(WHITE);



            }


}

char elegir_actividad1(int key){
int actividad = 1;
char letra = 'A';

while(key != KEY_ENTER){
        switch(key){

                case KEY_RIGHT:
                if(actividad == 1){
                    actividad = 2;
                }
                else{
                    if(actividad == 2){
                        actividad = 3;
                    }
                    else{
                        actividad = 1;
                    }
                }

                break;

                case KEY_LEFT:
                if(actividad ==1){
                    actividad = 3;
                }
                else{
                    if(actividad == 2){
                        actividad = 1;
                    }
                    else{
                        actividad = 2;
                    }
                }

                break;
            }



            if(actividad == 1){
                    locate(36,19);
                    setColor(LIGHTGREEN);
                    cout<<"A";
                    setColor(WHITE);
                    locate(38,19);
                    cout<<"B";
                    locate(40,19);
                    cout<<"C";
                    letra = 'A';

            }
            else{
                if(actividad == 2){
                    locate(36,19);
                    cout<<"A";
                    setColor(LIGHTGREEN);
                    locate(38,19);
                    cout<<"B";
                    setColor(WHITE);
                    locate(40,19);
                    cout<<"C";
                    letra = 'B';

                }
                else{
                    locate(36,19);
                    cout<<"A";
                    locate(38,19);
                    cout<<"B";
                    setColor(LIGHTGREEN);
                    locate(40,19);
                    cout<<"C";
                    setColor(WHITE);
                    letra = 'C';

                }
            }


            key = getkey();

        }

return letra;

}

char elegir_actividad(int key, int y){
int actividad = 1;
char letra = 'A';

while(key != KEY_ENTER){
            switch(key){

                case KEY_RIGHT:
                if(actividad == 1){
                    actividad = 2;
                }
                else{
                    if(actividad == 2){
                        actividad = 3;
                    }
                    else{
                        actividad = 1;
                    }
                }

                break;

                case KEY_LEFT:
                if(actividad == 1){
                    actividad = 3;
                }
                else{
                    if(actividad == 2){
                        actividad = 1;
                    }
                    else{
                        actividad = 2;
                    }
                }

                break;
            }



            if(actividad == 1){
                    locate(36,y);
                    setColor(LIGHTGREEN);
                    cout<<"A";
                    setColor(WHITE);
                    locate(38,y);
                    cout<<"B";
                    locate(40,y);
                    cout<<"C";
                    letra = 'A';

            }
            else{
                if(actividad == 2){
                    locate(36,y);
                    cout<<"A";
                    setColor(LIGHTGREEN);
                    locate(38,y);
                    cout<<"B";
                    setColor(WHITE);
                    locate(40,y);
                    cout<<"C";
                    letra = 'B';

                }
                else{
                    locate(36,y);
                    cout<<"A";
                    locate(38,y);
                    cout<<"B";
                    setColor(LIGHTGREEN);
                    locate(40,y);
                    cout<<"C";
                    setColor(WHITE);
                    letra = 'C';

                }
            }


            key = getkey();

        }

return letra;

}

bool elegir_apto(int key, int x, int y){
bool elegir = true;

while(key != KEY_ENTER){
            switch(key){

                case KEY_RIGHT:
                if(elegir){
                    elegir = false;
                }
                else{
                    elegir = true;
                }

                break;

                case KEY_LEFT:
                if(elegir){
                    elegir = false;
                }
                else{
                    elegir = true;
                }

                break;
            }



            if(elegir){
                locate(x,y);
                setColor(LIGHTGREEN);
                cout<<"SI";
                setColor(WHITE);
                locate(x+4,y);
                cout<<"NO";
            }
            else{
                locate(x,y);
                setColor(WHITE);
                cout<<"SI";
                setColor(LIGHTGREEN);
                locate(x+4,y);
                cout<<"NO";
                setColor(WHITE);
            }


            key = getkey();

        }

return elegir;

}


