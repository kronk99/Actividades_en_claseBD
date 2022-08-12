#include <iostream>
#include <string>
using namespace std;
#define CapacidadM 20
#define Vagones 7
//*****CODE MADE BY LUIS ALFREDO GONZÁLEZ SÁNCHEZ 2021024482***************
/* funcion que lee la cantidad de espacios llenos en el tren 
e imprime los espacios vacios de cada vagon en el tren , es importante
denotar que cada vagon tiene como maximo 10 asientos */
void contarAsientos(int tren[]){
    int libres = 0;
    for( int val = 0 ; val < Vagones ; val++){
        if(libres + (10-tren[val]) < 20){
            libres = 10- tren[val] ;
            printf("el vagon: %d tiene %d asientos libres" , val , libres);cout << endl;

        }
        else{ //si los ultimos vagones llenan
            libres = 20-libres;
            printf("el vagon: %d tiene %d asientos libres, habian mas pero se llenaron :c", val ,libres);cout << endl;
        }
        
    }
}
int main(){
    int tren[Vagones];
    tren[0] = 5;
    tren[1] = 8;
    tren[2] = 7;
    tren[3] = 7;
    tren[4] = 9;
    tren[5] = 7;
    tren[6] = 7;
    contarAsientos(tren);
}