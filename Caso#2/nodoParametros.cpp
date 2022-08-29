#include <iostream>
#include <string>
using namespace std;
#ifndef NODOP
#define NODOP 1
class nodoParametros{
    private:
        nodoParametros *linker;
        string parametros;
    public:
        nodoParametros(){
            linker = NULL;
            parametros = "";

        }
        void setNext(nodoParametros *nodo){
            this->linker=nodo;
        }
        nodoParametros* getNext(){ //retorna el puntero
            return linker;
        }
        void setData(string parametro){
            parametros = parametro;
        }
        string getData(){
            return this->parametros;
        }
        //VER VIDEO DE COMO HACER LISTAS EN C++
        //ACA NO SIRVE HACERLAS COMO EN JAVA
};
#endif