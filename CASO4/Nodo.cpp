#include <iostream>
#include <string>

#ifndef NODO 

#define NODO 1

using namespace std;

// 1. pasar este nodo a doblemente enlazado
template <class T>
class Nodo {
    private:
        T *door;
        Nodo *prev; //debe de ser un array de nodos
        Nodo *cardinals[4] ;//CREO QUE ESTO DEBE LLEVAR UN DATATYPE T.
    public:
        Nodo() {
            door = NULL;
            prev = NULL; // esta linea se agrega para quiz #4 #5
        }
        Nodo(T *data) {
            this->door = data;
            prev = NULL;
            cardinals[0] = NULL;
            cardinals[1] = NULL;
            cardinals[2] = NULL;
            cardinals[3] = NULL;
        }
        void addDoor(T *datas){
            this->door = datas;
        }
        T* getData() {
            return data;
        }
        Nodo* getCardinals(){ //con esto podre añadir directamente?
            return cardinals[4]; //esto esta mal no se por que
        }
        Nodo* getPrev() { 
            return prev;
        }
        void setPrev(Nodo *pValue) {
            this->prev = pValue;
        }
        void setCantPuertas(int number){ //inserta la cantidad de puertas
        //de una determinada habitacion(nodo).
            this->cantPuertas = number;
        }

};

#endif