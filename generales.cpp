#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <ctime>

using namespace std;

#include "generales.h"
#include "usuarios.h"
#include "entrenamientos.h"
#include "configuracion.h"
#include "reporte.h"
#include "rlutil.h"

using namespace rlutil;

///MENUES

void menu_principal(){
int key, opc, cursorX, cursorY;

while(0<1){
cls();
cursorX=38;
cursorY=8;
opc=1;

titulo("APP LARA");
sub_titulo("    MENU PRINCIPAL    ", 38);

locate(cursorX, cursorY);
setBackgroundColor(BLUE);
cout<<"                      ";
setBackgroundColor(BLACK);
///cout<<"----------------------";
setColor(LIGHTGREEN);
locate(cursorX, cursorY+2);
cout<<"1 - USUARIOS";
setColor(WHITE);
locate(cursorX, cursorY+4);
cout<<"2 - ENTRENAMIENTOS";
locate(cursorX, cursorY+6);
cout<<"3 - REPORTES";
locate(cursorX, cursorY+8);
cout<<"4 - CONFIGURACION";
locate(cursorX, cursorY+10);
cout<<"5 - CREDITOS";
locate(cursorX, cursorY+12);
setBackgroundColor(BLUE);
cout<<"                      ";
setBackgroundColor(BLACK);
///cout<<"----------------------";
locate(cursorX, cursorY+14);
cout<<"0 - CERRAR";

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


                pintar_opciones(opc, cursorX, cursorY);

                key = getkey();

        }

    menu_principal(opc);
    if(opc == 0){
        cout<<endl<<endl<<endl;
        return;
    }

}
}

void menu_principal(int opc){

switch(opc){
    case 1:
    menu_usuarios();
    break;

    case 2:
    menu_entrenamientos();
    break;

    case 3:
    menu_reportes();
    break;

    case 4:
    menu_configuracion();
    break;

    case 5:
    creditos();
    break;

    case 0:
    return;
    break;

}


}

void pintar_opciones(int opc, int cursorX, int cursorY){

            switch(opc){
            case 1:
                setColor(LIGHTGREEN);
                locate(cursorX-2,cursorY+2);
                cout<<">";
                locate(cursorX, cursorY+2);
                cout<<"1 - USUARIOS";
                setColor(WHITE);
                locate(cursorX-2,cursorY+4);
                cout<<"  ";
                locate(cursorX, cursorY+4);
                cout<<"2 - ENTRENAMIENTOS";
                locate(cursorX-2,cursorY+6);
                cout<<"  ";
                locate(cursorX, cursorY+6);
                cout<<"3 - REPORTES";
                locate(cursorX-2,cursorY+8);
                cout<<"  ";
                locate(cursorX, cursorY+8);
                cout<<"4 - CONFIGURACION";
                locate(cursorX,cursorY+10);
                cout<<"5 - CREDITOS";
                locate(cursorX-2,cursorY+10);
                cout<<"  ";
                locate(cursorX, cursorY+14);
                cout<<"0 - CERRAR";
                locate(cursorX-2,cursorY+14);
                cout<<"  ";
            break;

            case 2:
                locate(cursorX-2,cursorY+2);
                cout<<"  ";
                locate(cursorX, cursorY+2);
                cout<<"1 - USUARIOS";
                setColor(LIGHTGREEN);
                locate(cursorX-2,cursorY+4);
                cout<<">";
                locate(cursorX, cursorY+4);
                cout<<"2 - ENTRENAMIENTOS";
                setColor(WHITE);
                locate(cursorX-2,cursorY+6);
                cout<<"  ";
                locate(cursorX, cursorY+6);
                cout<<"3 - REPORTES";
                locate(cursorX-2,cursorY+8);
                cout<<"  ";
                locate(cursorX, cursorY+8);
                cout<<"4 - CONFIGURACION";
                locate(cursorX,cursorY+10);
                cout<<"5 - CREDITOS";
                locate(cursorX-2,cursorY+10);
                cout<<"  ";
                locate(cursorX, cursorY+14);
                cout<<"0 - CERRAR";
                locate(cursorX-2,cursorY+14);
                cout<<"  ";
            break;

            case 3:
                locate(cursorX-2,cursorY+2);
                cout<<"  ";
                locate(cursorX, cursorY+2);
                cout<<"1 - USUARIOS";
                locate(cursorX-2,cursorY+4);
                cout<<"  ";
                locate(cursorX, cursorY+4);
                cout<<"2 - ENTRENAMIENTOS";
                setColor(LIGHTGREEN);
                locate(cursorX-2,cursorY+6);
                cout<<">";
                locate(cursorX, cursorY+6);
                cout<<"3 - REPORTES";
                setColor(WHITE);
                locate(cursorX-2,cursorY+8);
                cout<<"  ";
                locate(cursorX, cursorY+8);
                cout<<"4 - CONFIGURACION";
                locate(cursorX,cursorY+10);
                cout<<"5 - CREDITOS";
                locate(cursorX-2,cursorY+10);
                cout<<"  ";
                locate(cursorX, cursorY+14);
                cout<<"0 - CERRAR";
                locate(cursorX-2,cursorY+14);
                cout<<"  ";
            break;

            case 4:
                locate(cursorX-2,cursorY+2);
                cout<<"  ";
                locate(cursorX, cursorY+2);
                cout<<"1 - USUARIOS";
                locate(cursorX-2,cursorY+4);
                cout<<"  ";
                locate(cursorX, cursorY+4);
                cout<<"2 - ENTRENAMIENTOS";
                locate(cursorX-2,cursorY+6);
                cout<<"  ";
                locate(cursorX, cursorY+6);
                cout<<"3 - REPORTES";
                setColor(LIGHTGREEN);
                locate(cursorX-2,cursorY+8);
                cout<<">";
                locate(cursorX, cursorY+8);
                cout<<"4 - CONFIGURACION";
                setColor(WHITE);
                locate(cursorX,cursorY+10);
                cout<<"5 - CREDITOS";
                locate(cursorX-2,cursorY+10);
                cout<<"  ";
                locate(cursorX, cursorY+14);
                cout<<"0 - CERRAR";
                locate(cursorX-2,cursorY+14);
                cout<<"  ";
            break;

            case 5:
                locate(cursorX-2,cursorY+2);
                cout<<"  ";
                locate(cursorX, cursorY+2);
                cout<<"1 - USUARIOS";
                locate(cursorX-2,cursorY+4);
                cout<<"  ";
                locate(cursorX, cursorY+4);
                cout<<"2 - ENTRENAMIENTOS";
                locate(cursorX-2,cursorY+6);
                cout<<"  ";
                locate(cursorX, cursorY+6);
                cout<<"3 - REPORTES";
                locate(cursorX-2,cursorY+8);
                cout<<"  ";
                locate(cursorX, cursorY+8);
                cout<<"4 - CONFIGURACION";
                setColor(LIGHTGREEN);
                locate(cursorX,cursorY+10);
                cout<<"5 - CREDITOS";
                locate(cursorX-2,cursorY+10);
                cout<<">";
                setColor(WHITE);
                locate(cursorX, cursorY+14);
                cout<<"0 - CERRAR";
                locate(cursorX-2,cursorY+14);
                cout<<"  ";

            break;

            case 0:
                locate(cursorX-2,cursorY+2);
                cout<<"  ";
                locate(cursorX, cursorY+2);
                cout<<"1 - USUARIOS";
                locate(cursorX-2,cursorY+4);
                cout<<"  ";
                locate(cursorX, cursorY+4);
                cout<<"2 - ENTRENAMIENTOS";
                locate(cursorX-2,cursorY+6);
                cout<<"  ";
                locate(cursorX, cursorY+6);
                cout<<"3 - REPORTES";
                locate(cursorX-2,cursorY+8);
                cout<<"  ";
                locate(cursorX, cursorY+8);
                cout<<"4 - CONFIGURACION";
                locate(cursorX,cursorY+10);
                cout<<"5 - CREDITOS";
                locate(cursorX-2,cursorY+10);
                cout<<"  ";
                setColor(LIGHTGREEN);
                locate(cursorX-2, cursorY+14);
                cout<<">";
                locate(cursorX, cursorY+14);
                cout<<"0 - CERRAR";
                setColor(WHITE);
            break;



            }


}

