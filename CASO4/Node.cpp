#include <iostream>
#include <string>

#ifndef NODE 

#define NODE 1

using namespace std;

// 1. pasar este nodo a doblemente enlazado
template <class T>
class Node {
    private:
        T *door;
        Node *prev //debe de ser un array de nodos
        Node *cardinals[4] //CREO QUE ESTO DEBE LLEVAR UN DATATYPE T.
    public:
        Node() {
            door = NULL;
            prev = NULL; // esta linea se agrega para quiz #4 #5
        }
        Node(T *data) {
            this->door = pData;
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
        Node* getCardinals(){ //con esto podre añadir directamente?
            return this->cardinals;
        }
        Node* getPrev() { 
            return prev;
        }
        void setPrev(Node *pValue) {
            this->prev = pValue;
        }
        void setCantPuertas(int number){ //inserta la cantidad de puertas
        //de una determinada habitacion(nodo).
            this->cantPuertas = number;
        }

};

#endif