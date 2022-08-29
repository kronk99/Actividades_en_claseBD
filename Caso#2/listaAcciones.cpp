#include <iostream>
#include "nodoAcciones.cpp"
using namespace std;
#ifndef LISTAA
#define LISTAA 1
class listaAcciones{
    private:
        nodoAcciones *cabeza;
        int size;
    public:
         listaAcciones(){
        this->cabeza = NULL;
        size = 0;
        }
        void setSize(){
            size+=1;
        }
        void insertFirst(string accion){
            nodoAcciones *nuevonodo = new nodoAcciones();
            nuevonodo->setData(accion);
            nuevonodo->setNext(cabeza);
            this->cabeza = nuevonodo;//setNext(nuevonodo); //aca es el next de cabeza o 
            //directamente cabeza = nuevonodo.
            setSize();
        }
        void read(){
            nodoAcciones *temp = cabeza;
            for(int a = 0 ; a<size ; a++) {
                temp->getData();
                //temp = temp->getNext();
            }
        } 
        //crear metodo search para sacar parametros de objetos.
};
#endif