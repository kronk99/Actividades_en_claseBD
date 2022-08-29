#include <iostream>
using namespace std;
#include "dispositivo.cpp"
#include "listaAcciones.cpp"
#include "listaParametros.cpp"
int main(){
Dispositivo cafe = Dispositivo("coffemaker" ,"alo");
Dispositivo encendedor = Dispositivo("llama" , "alo");
cafe.añadirAccion("holapapa");
cafe.añadirParametro("luz");
encendedor.añadirAccion("poua");
encendedor.añadirAccion("alola");
encendedor.getAcciones();
}
