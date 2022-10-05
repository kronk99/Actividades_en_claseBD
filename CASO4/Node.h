#include <iostream>
#include <string>

#ifndef NODE 

#define NODE 1

using namespace std;

// 1. pasar este nodo a doblemente enlazado
template <class T>
class Node {
    private:
        int cantPuertas;
        T *data;
        Node *north;
        Node *south;
        Node *east;
        Node *west;
        Node *prev; 
        //AVL *camPrincip; //puntero al arbol avl con la cámara principal.
        //haria falta un metodo que diga addAVL para añadir el arbol aca y
        //el metodo getAVL
    
    public:
        Node() {
            data = NULL;
            next = NULL;
            prev = NULL; // esta linea se agrega para quiz #4 #5
        }

        Node(T *pData) {
            this->data = pData;
            next = NULL;
            prev = NULL;
            this->nombreCueva = name;
        }

        T* getData() {
            return data;
        }

        Node* getNort() {
            return north;
        }
        Node* getSouth() {
            return south;
        }
        Node* getEast() {
            return east;
        }
        Node* getWest() {
            return west;
        }
        //setters de las direcciones de las posibles puertas.
        void setNorth(Node *pValue) {
            this->north = pValue;
        }
        void setSouth(Node *pValue) {
            this->south = pValue;
        }
        void setEast(Node *pValue) {
            this->east = pValue;
        }
        void setWest(Node *pValue) {
            this->west = pValue;
        }

        Node* getPrev() { // esta linea se agrega para quiz #4 #5
            return prev;
        }

        void setPrev(Node *pValue) {// esta linea se agrega para quiz #4 #5
            this->prev = pValue;
        }
        void setCantPuertas(int number){ //inserta la cantidad de habitaciones
        //de una determinada puerta o cuarto.
            this->cantPuertas = number;
        }
};

#endif