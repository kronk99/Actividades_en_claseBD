#include <iostream>
#include <string>
using namespace std;
#ifndef NODOA
#define NODOA 1
class nodoAcciones{
    private:
        nodoAcciones *linker;
        string acciones;
    public:
        nodoAcciones(){
            linker = NULL;
            acciones = "";

        }
        void setNext(nodoAcciones *nodo){
            this->linker=nodo;
        }
        nodoAcciones* getNext(){ //retorna el puntero
            return linker;
        }
        void setData(string accion){
            acciones = accion;
        }
        void getData(){
            cout << acciones;
        }
        //VER VIDEO DE COMO HACER LISTAS EN C++
        //ACA NO SIRVE HACERLAS COMO EN JAVA
};
#endif