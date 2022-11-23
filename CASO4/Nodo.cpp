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
        // sera que el array necesita cambiar el datatype?
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
        T* getDoor() {
            return door;
        }
        void setCardinal(int number, Nodo<T> *pData){
            switch (number){
            case 0:
                cardinals[0] = pData;
                break;
            case 1:
                cardinals[1] = pData;
                break;
            case 2:
                cardinals[2] = pData;
                break;
            default:
                cardinals[3] = pData;
                break;
            }
        }
        Nodo<T>* getNodo(int number){
            switch (number){
            case 0:
                return cardinals[0];
                break;
            case 1:
                return cardinals[1];
                break;
            case 2:
                return cardinals[2];
                break;
            default:
                return cardinals[3];
                break;
            }
        } 
        Nodo<T>* getPrev() { 
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