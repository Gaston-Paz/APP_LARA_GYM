#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <ctime>

using namespace std;

#include "generales.h"
#include "rlutil.h"

using namespace rlutil;

void creditos(){
system("cls");
titulo("APP LARA");
sub_titulo("          CREDITOS          ", 35);

locate(30,14);
cout<<"GASTON PAZ              LEGAJO 23419";
locate(30,16);
cout<<"LEANDRO FABIAN AMARILLA LEGAJO 23440";

locate(28,12);
setBackgroundColor(BLUE);
cout<<"                                         ";
setBackgroundColor(BLACK);
locate(28,18);
setBackgroundColor(BLUE);
cout<<"                                         ";
setBackgroundColor(BLACK);
cout<<endl<<endl<<endl<<endl<<endl;
system("pause>nul");


}
