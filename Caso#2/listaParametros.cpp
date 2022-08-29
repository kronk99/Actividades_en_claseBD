#include <iostream>
#include "nodoParametros.cpp"
using namespace std;
#ifndef LISTA2
#define LISTA2 1
class listaParametros{
    private:
        nodoParametros *cabeza;
        int size;
    public:
         listaParametros(){
        this->cabeza = NULL;
        size = 0;
        }
        void setSize(){
            size+=1;
        }
        void insertFirst(string accion){
            nodoParametros *nuevonodo = new nodoParametros();
            nuevonodo->setData(accion);
            nuevonodo->setNext(cabeza);
            this->cabeza = nuevonodo;//setNext(nuevonodo); //aca es el next de cabeza o 
            //directamente cabeza = nuevonodo.
            setSize();
        }
        void read(){
            nodoParametros*temp = cabeza;
            string data= NULL;
            for(int a = 0 ; a<size ; a++) {
               data=temp->getData();
               printf("imprimir , s%" , data.c_str());
                temp = temp->getNext();
            }
        } 
        //crear metodo search para sacar parametros de objetos.
};
#endif