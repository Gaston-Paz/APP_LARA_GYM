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

int validar_id(int id){

usuarios reg;
    FILE *f;

    f = fopen("usuarios.dat", "rb");
    if (f == NULL){
       msj("NO SE PUDO LEER EL ARCHIVO");
        return -1;
    }


    while(fread(&reg, sizeof(usuarios), 1, f)){
         if((id == reg.id) || (id <= 0)){
            msj("LA ID INGRESADA YA EXISTE O ES INCORRECTA. INGRESARLA NUEVAMENTE ");
            locate(29,7);
            cout<<"                                     ";
            locate(29,7);
            cin>>id;
            fseek(f,sizeof(usuarios),SEEK_SET);

         }

    }

   msj("INGRESO CORRECTO");
    fclose(f);
    return id;



}

float validar_altura(float altura){
    while(altura <= 0){
   msj("INGRESO INCORRECTO");
   locate(22,15);
   cout<<"   ";
   locate(22,15);
    cin>>altura;
}
 msj("INGRESO CORRECTO");
 return altura;

}

float validar_peso(float peso){
    while(peso <= 0){
    msj("INGRESO INCORRECTO");
    locate(20,17);
    cout<<"    ";
    locate(20,17);
    cin>>peso;
}
    msj("INGRESO CORRECTO");
    return peso;
}

char validar_perfil(char perfil){
    while((perfil != 'a' && perfil != 'A') &&
         (perfil != 'b' && perfil != 'B') &&
         (perfil != 'c' && perfil != 'C')){
    cin>>perfil;
}
 setColor(LIGHTGREEN);
 cout<<"PERFIL INGRESADO CORRECTAMENTE"<<endl<<endl;
 setColor(WHITE);
 return perfil;
}

int validar_apto(int apto){
while((apto != 1) && (apto != 0)){
   setColor(LIGHTRED);
   cout<<"INGRESAR APTO MEDICO CORRECTO: ";
   setColor(WHITE);
   cin>>apto;
}
 setColor(LIGHTGREEN);
 cout<<"APTO MEDICO INGRESADO CORRECTAMENTE"<<endl<<endl;
 setColor(WHITE);
 return apto;
}

void validar_Nombre(usuarios  *punt){

while((strlen(punt->nombre) == 0) || (punt->nombre[0] == ' ')){
   msj("INGRESO INCORRECTO");
   locate(5,9);
   cout<<"                                        ";
   locate(5,9);
   cin.getline(punt->nombre, 50);

}
msj("INGRESO CORRECTO");

}

void validar_Apellido(usuarios  *punt){

while((strlen(punt->apellido) == 0) || (punt->apellido[0] == ' ')){
msj("INGRESO INCORRECTO");
locate(5,11);
cout<<"                                        ";
locate(5,11);
cin.getline(punt->apellido, 50);


}
msj("INGRESO CORRECTO");
}

void validar_anio(usuarios *punt){
time_t tiempo;
char cad[80];
struct tm *tmPtr;
tiempo = time(NULL);
tmPtr = localtime(&tiempo);
strftime(cad, 80, "%A %d de %B de %Y", tmPtr);
int x = 1900+tmPtr->tm_year - punt->nacimiento.anio;

while((x < 13) || (x>100)){
msj("INGRESO INCORRECTO");
locate(45,13);
cout<<"    ";
locate(45,13);
	cin>>punt->nacimiento.anio;
    x = 1900+tmPtr->tm_year - punt->nacimiento.anio;

	}
 msj("INGRESO CORRECTO");
}

void validar_mes(usuarios *punt){
time_t tiempo;
char cad[80];
struct tm *tmPtr;
tiempo = time(NULL);
tmPtr = localtime(&tiempo);
///printf("FECHA ACTUAL \n%d/%d/%d %d:%d:%d", tmPtr->tm_mday, tmPtr->tm_mon+1, 1900+tmPtr->tm_year, tmPtr->tm_hour, tmPtr->tm_min, tmPtr->tm_sec);
strftime(cad, 80, "%A %d de %B de %Y", tmPtr);
///printf("\n\n%s", cad);
int x = 1900+tmPtr->tm_year - punt->nacimiento.anio;
int m = (tmPtr->tm_mon+1) - punt->nacimiento.mes;

if(x == 13){
    if(m < 0){
      while(punt->nacimiento.mes > (tmPtr->tm_mon+1)){
            msj("INGRESO INCORRECTO");
            locate(42,13);
            cout<<"  ";
            locate(42,13);
            cin>>punt->nacimiento.mes;
           }}}



else{
while(punt->nacimiento.mes > 12 || punt->nacimiento.mes < 1){
            msj("INGRESO INCORRECTO");
            locate(42,13);
            cout<<"  ";
            locate(42,13);
            cin>>punt->nacimiento.mes;
	}
}
msj("INGRESO CORRECTO");
}

void validar_dia(usuarios *punt){
time_t tiempo;
char cad[80];
struct tm *tmPtr;
tiempo = time(NULL);
tmPtr = localtime(&tiempo);
///printf("FECHA ACTUAL \n%d/%d/%d %d:%d:%d", tmPtr->tm_mday, tmPtr->tm_mon+1, 1900+tmPtr->tm_year, tmPtr->tm_hour, tmPtr->tm_min, tmPtr->tm_sec);
strftime(cad, 80, "%A %d de %B de %Y", tmPtr);
///printf("\n\n%s", cad);
int x = 1900+tmPtr->tm_year - punt->nacimiento.anio;
int m = (tmPtr->tm_mon+1) - punt->nacimiento.mes;
int d = tmPtr->tm_mday - punt->nacimiento.dia;
if(x == 13){
    if(m == 0){
        while(d < 0){
            msj("INGRESO INCORRECTO");
            locate(39,13);
            cout<<"  ";
            locate(39,13);
            cin>>punt->nacimiento.dia;
            d = tmPtr->tm_mday - punt->nacimiento.dia;
        }
    }
    else{
            verificar_dia_Xmes(punt);
}


}
else{
        verificar_dia_Xmes(punt);

}
    msj("INGRESO CORRECTO");

}

char validar_eleccion(char eleccion, int x, int y){

while((eleccion != 's' && eleccion != 'S') &&
   (eleccion != 'n' && eleccion != 'N')){
    locate(x,y);
    cout<<"    ";
    locate(x,y);
    cin>>eleccion;


   }
return eleccion;

}

char validar_eleccion(char eleccion){

while((eleccion != 's' && eleccion != 'S') &&
   (eleccion != 'n' && eleccion != 'N')){
    cin>>eleccion;

   }
return eleccion;

}

int validar_idusuario(int idusuario){
FILE *p;
usuarios reg;

p = fopen("usuarios.dat", "rb");
if(p == NULL){
    cout<<"NO SE PUDO ABRIR EL ARCHIVO";
    return -1;
}
///fseek(p, sizeof(usuarios), SEEK_SET);
while(0 < 1){

while(fread(&reg, sizeof(usuarios), 1, p)){
    if(idusuario == reg.id){
        fclose(p);
    msj("INGRESO CORRECTO");
        return idusuario;
    }
}
msj("INGRESO INCORRECTO");
locate(29,9);
cout<<"     ";
locate(29,9);
cin>>idusuario;
}
fclose(p);




return -1;


}

void validar_anio_entrenamiento(entrenamientos *p){
time_t tiempo;
char cad[80];
struct tm *tmPtr;
tiempo = time(NULL);
tmPtr = localtime(&tiempo);
strftime(cad, 80, "%A %d de %B de %Y", tmPtr);
int x = 1900+tmPtr->tm_year - p->entrenamiento.anio;

while((x < 0)||(x>100)){
    msj("INGRESO INCORRECTO");
	locate(49,11);
	cout<<"    ";
	locate(49,11);
	cin>>p->entrenamiento.anio;
    x = 1900+tmPtr->tm_year - p->entrenamiento.anio;
	}
    msj("INGRESO CORRECTO");
}

void validar_mes_entrenamiento(entrenamientos *p){
time_t tiempo;
char cad[80];
struct tm *tmPtr;
tiempo = time(NULL);
tmPtr = localtime(&tiempo);
///printf("FECHA ACTUAL \n%d/%d/%d %d:%d:%d", tmPtr->tm_mday, tmPtr->tm_mon+1, 1900+tmPtr->tm_year, tmPtr->tm_hour, tmPtr->tm_min, tmPtr->tm_sec);
strftime(cad, 80, "%A %d de %B de %Y", tmPtr);
///printf("\n\n%s", cad);
int x = 1900+tmPtr->tm_year - p->entrenamiento.anio;
int m = (tmPtr->tm_mon+1) - p->entrenamiento.mes;

if(x == 0){
    if(m < 0){
      while(p->entrenamiento.mes > (tmPtr->tm_mon+1)){
        msj("INGRESO INCORRECTO");
        locate(46,11);
        cout<<"  ";
        locate(46,11);
        cin>>p->entrenamiento.mes;

	}
    }
  }



else{
while(p->entrenamiento.mes > 12 || p->entrenamiento.mes < 1){
        msj("INGRESO INCORRECTO");
        locate(46,11);
        cout<<"  ";
        locate(46,11);
        cin>>p->entrenamiento.mes;
	}
}
msj("INGRESO CORRECTO");
}

void validar_dia_entrenamiento(entrenamientos *p){
time_t tiempo;
char cad[80];
struct tm *tmPtr;
tiempo = time(NULL);
tmPtr = localtime(&tiempo);
///printf("FECHA ACTUAL \n%d/%d/%d %d:%d:%d", tmPtr->tm_mday, tmPtr->tm_mon+1, 1900+tmPtr->tm_year, tmPtr->tm_hour, tmPtr->tm_min, tmPtr->tm_sec);
strftime(cad, 80, "%A %d de %B de %Y", tmPtr);
///printf("\n\n%s", cad);
int x = 1900+tmPtr->tm_year - p->entrenamiento.anio;
int m = (tmPtr->tm_mon+1) - p->entrenamiento.mes;
int d = tmPtr->tm_mday - p->entrenamiento.dia;

if(x == 0){
    if(m == 0){
        while(d < 0){
            msj("INGRESO INCORRECTO");
            locate(43,11);
            cout<<"  ";
            locate(43,11);
            cin>>p->entrenamiento.dia;
            d = tmPtr->tm_mday - p->entrenamiento.dia;
        }
    }
    else{
        verificar_dia_Xmes(p);
    }


}

else{

verificar_dia_Xmes(p);

}
msj("INGRESO CORRECTO");

}

int validar_minutos(int minutos){

while(minutos < 1){
    msj("INGRESO INCORRECTO");
    locate(56,17);
    cout<<"   ";
    locate(56,17);
    cin>>minutos;
}
msj("INGRESO CORRECTO");
return minutos;

}

int validar_minutos(int minutos, int x, int y){

while(minutos < 1){
    msj("INGRESO INCORRECTO");
    locate(x,y);
    cout<<"   ";
    locate(x,y);
    cin>>minutos;
}
msj("INGRESO CORRECTO");
return minutos;

}

int validar_calorias(int calorias){

while(calorias < 1){
    msj("INGRESO INCORRECTO");
    locate(33,15);
    cout<<"   ";
    locate(33,15);
    cin>>calorias;
}
msj("INGRESO CORRECTO");
return calorias;

}

int validar_calorias(int calorias, int x, int y){

while(calorias < 1){
    msj("INGRESO INCORRECTO");
    locate(x,y);
    cout<<"   ";
    locate(x,y);
    cin>>calorias;
}
msj("INGRESO CORRECTO");
return calorias;

}

int validar_actividad(int key, int x, entrenamientos *p){
int actividad = 1;

while(key != KEY_ENTER){
            switch(key){


                case KEY_RIGHT:
                    switch(actividad){
                        case 1:
                        actividad = 2;
                        break;
                        case 2:
                        actividad = 3;
                        break;
                        case 3:
                        actividad = 4;
                        break;
                        case 4:
                        actividad = 5;
                        break;
                        case 5:
                        actividad = 1;
                        break;


                    }

                break;

                case KEY_LEFT:
                    switch(actividad){
                        case 1:
                        actividad = 5;
                        break;
                        case 2:
                        actividad = 1;
                        break;
                        case 3:
                        actividad = 2;
                        break;
                        case 4:
                        actividad = 3;
                        break;
                        case 5:
                        actividad = 4;
                        break;


                    }
            }



                    switch(actividad){
                        case 1:
                        locate(26,13);
                        setColor(LIGHTGREEN);
                        cout<<"CAMINATA";
                        setColor(WHITE);
                        locate(x+11,13);
                        cout<<"CORRER";
                        locate(x+20,13);
                        cout<<"BICICLETA";
                        locate(x+32,13);
                        cout<<"NATACION";
                        locate(x+43,13);
                        cout<<"PESAS";
                        break;

                        case 2:
                        locate(26,13);
                        cout<<"CAMINATA";
                        setColor(LIGHTGREEN);
                        locate(x+11,13);
                        cout<<"CORRER";
                        setColor(WHITE);
                        locate(x+20,13);
                        cout<<"BICICLETA";
                        locate(x+32,13);
                        cout<<"NATACION";
                        locate(x+43,13);
                        cout<<"PESAS";
                        break;

                        case 3:
                        locate(26,13);
                        cout<<"CAMINATA";
                        locate(x+11,13);
                        cout<<"CORRER";
                        locate(x+20,13);
                        setColor(LIGHTGREEN);
                        cout<<"BICICLETA";
                        locate(x+32,13);
                        setColor(WHITE);
                        cout<<"NATACION";
                        locate(x+43,13);
                        cout<<"PESAS";
                        break;

                        case 4:
                         locate(26,13);
                        cout<<"CAMINATA";
                        locate(x+11,13);
                        cout<<"CORRER";
                        locate(x+20,13);
                        cout<<"BICICLETA";
                        locate(x+32,13);
                        setColor(LIGHTGREEN);
                        cout<<"NATACION";
                        locate(x+43,13);
                        setColor(WHITE);
                        cout<<"PESAS";
                        break;

                        case 5:
                        locate(26,13);
                        cout<<"CAMINATA";
                        locate(x+11,13);
                        cout<<"CORRER";
                        locate(x+20,13);
                        cout<<"BICICLETA";
                        locate(x+32,13);
                        cout<<"NATACION";
                        locate(x+43,13);
                        setColor(LIGHTGREEN);
                        cout<<"PESAS";
                        setColor(WHITE);
                        break;


                    }


            key = getkey();



        }

            if(actividad == 4 || actividad == 5){
                if(validar_actividad_apto(p) == false){
                    if(cambiar_apto(p)==false){
                                int x=26;
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

                                actividad = validar_actividad(key, x, p);
                    }
                }




                }


msj("INGRESO CORRECTO");
return actividad;

}

bool validar_actividad_apto(entrenamientos *p){
FILE *usu;
usuarios reg;

usu = fopen("usuarios.dat", "rb");
if(usu == NULL){
    cout<<"NO SE PUDO ABRIR EL ARCHIVO";
    return false;
}

fseek(usu, sizeof(usuarios), SEEK_SET);
while(fread(&reg, sizeof(usuarios), 1, usu)){
    if(reg.id == p->idUsuario){
        if(reg.aptoMedico == false){
            msj("NO TIENE APTO MEDICO PARA LA ACTIVIDAD");

        }
        fclose(usu);
        return reg.aptoMedico;
    }
}


fclose(usu);
return true;

}

void verificar_dia_Xmes(entrenamientos *p){

if(p->entrenamiento.mes == 2){
	if(p->entrenamiento.anio % 4 == 0){
		while((p->entrenamiento.dia > 29) || (p->entrenamiento.dia < 1)){
                msj("INGRESO INCORRECTO");
				locate(43,11);
				cout<<"  ";
				locate(43,11);
				cin>>p->entrenamiento.dia;
			}}
	else{while((p->entrenamiento.dia > 28) || (p->entrenamiento.dia < 1)){
                msj("INGRESO INCORRECTO");
				locate(43,11);
				cout<<"  ";
				locate(43,11);
				cin>>p->entrenamiento.dia;
			}}}
else{if((p->entrenamiento.mes == 1) ||
	(p->entrenamiento.mes == 3) ||
	(p->entrenamiento.mes == 5) ||
	(p->entrenamiento.mes == 7) ||
	(p->entrenamiento.mes == 8) ||
	(p->entrenamiento.mes == 10) ||
	(p->entrenamiento.mes == 12)){

	while((p->entrenamiento.dia > 31) || (p->entrenamiento.dia < 1)){
                msj("INGRESO INCORRECTO");
				locate(43,11);
				cout<<"  ";
				locate(43,11);
				cin>>p->entrenamiento.dia;
			}
	}
else{if((p->entrenamiento.mes == 4) ||
	(p->entrenamiento.mes == 6) ||
	(p->entrenamiento.mes == 9) ||
	(p->entrenamiento.mes == 11)){

	while((p->entrenamiento.dia > 30) || (p->entrenamiento.dia < 1)){
                msj("INGRESO INCORRECTO");
				locate(43,11);
				cout<<"  ";
				locate(43,11);
				cin>>p->entrenamiento.dia;
			}
	}

	}


	}



}

void verificar_dia_Xmes(usuarios *p){

if(p->nacimiento.mes == 2){
	if(p->nacimiento.anio % 4 == 0){
		while((p->nacimiento.dia > 29) || (p->nacimiento.dia < 1)){
                msj("INGRESO INCORRECTO");
				locate(39,13);
				cout<<"  ";
				locate(39,13);
				cin>>p->nacimiento.dia;
			}}
	else{while((p->nacimiento.dia > 28) || (p->nacimiento.dia < 1)){
                msj("INGRESO INCORRECTO");
				locate(39,13);
				cout<<"  ";
				locate(39,13);
				cin>>p->nacimiento.dia;
			}}}
else{if((p->nacimiento.mes == 1) ||
	(p->nacimiento.mes == 3) ||
	(p->nacimiento.mes == 5) ||
	(p->nacimiento.mes == 7) ||
	(p->nacimiento.mes == 8) ||
	(p->nacimiento.mes == 10) ||
	(p->nacimiento.mes == 12)){

	while((p->nacimiento.dia > 31) || (p->nacimiento.dia < 1)){
                msj("INGRESO INCORRECTO");
				locate(39,13);
				cout<<"  ";
				locate(39,13);
				cin>>p->nacimiento.dia;
			}
	}
else{if((p->nacimiento.mes == 4) ||
	(p->nacimiento.mes == 6) ||
	(p->nacimiento.mes == 9) ||
	(p->nacimiento.mes == 11)){

	while((p->nacimiento.dia > 30) || (p->nacimiento.dia < 1)){
                msj("INGRESO INCORRECTO");
				locate(39,13);
				cout<<"  ";
				locate(39,13);
				cin>>p->nacimiento.dia;
			}
	}

	}


	}



}












