#include <iostream>
#include <string>
using namespace std;
#define CapacidadM 20
#define Vagones 7
#define libre 1
#define ocupado 0
//*****CODE MADE BY LUIS ALFREDO GONZÁLEZ SÁNCHEZ 2021024482***************
/*struct de vagones, contiene 7 vagones que seran incluidos en un array para recorrerlos
el propio array es de tipo struct vagones
es importante denotar que el array debe ser escrito previamente.
*/
struct vagones{
    int asientos[5];
}vagon1 ,vagon2,vagon3,vagon4,vagon5,vagon6,vagon7 , tren[7];
//***********************************************************************
//funcion que recorre el array de vagones y busca los asientos libres
void trencito(vagones tren[]){
    
    for( int val = 0 ; val < Vagones ; val++){
        
        for( int valo = 0 ; valo < 5 ; valo++){
           
            if (tren[val].asientos[valo] == libre){
                printf("el asiento: %d en el vagon %d esta libre ", valo ,val);cout << endl;
            }
        }
    }
} 
//*********************************************************
int main(){
    vagon1.asientos[0]=ocupado;
    vagon1.asientos[1]=libre;
    vagon1.asientos[2]=ocupado;
    vagon1.asientos[3]=libre;
    vagon1.asientos[4]= libre;
    vagon2.asientos[0]= ocupado;
    vagon2.asientos[1]= libre;
    vagon2.asientos[2]= libre;
    vagon2.asientos[3]= libre;
    vagon2.asientos[4]= ocupado;
    vagon3.asientos[0]= ocupado;
    vagon3.asientos[1]= libre;
    vagon3.asientos[2]= libre;
    vagon3.asientos[3]= libre;
    vagon3.asientos[4]= libre;
    vagon4.asientos[0]= ocupado;
    vagon4.asientos[1]= libre;
    vagon4.asientos[2]= ocupado;
    vagon4.asientos[3]= ocupado;
    vagon4.asientos[4]= libre;
    vagon5.asientos[0]= ocupado;
    vagon5.asientos[1]= libre;
    vagon5.asientos[2]= libre;
    vagon5.asientos[3]= libre;
    vagon5.asientos[4]= ocupado;
    vagon6.asientos[0]= ocupado;
    vagon6.asientos[1]= libre;
    vagon6.asientos[2]= ocupado;
    vagon6.asientos[3]= libre;
    vagon6.asientos[4]= ocupado;
    vagon7.asientos[0]= libre;
    vagon7.asientos[1]= libre;
    vagon7.asientos[2]= libre;
    vagon7.asientos[3]= ocupado;
    vagon7.asientos[4]= ocupado;
    tren[0]=vagon1;
    tren[1] = vagon2;
    tren[2]=vagon3;
    tren[3]=vagon4;
    tren[4] = vagon5;
    tren[5]=vagon6;
    tren[6]=vagon7;
    trencito(tren);
}