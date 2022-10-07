#include <iostream>
#include <string>
#ifndef NODE 

#define NODE 1

using namespace std;

// 1. pasar este nodo a doblemente enlazado
template <class T>
class Node {
    private:
        Node *next;
        T *data;
        string nomMinero;
        //AVL *camPrincip; //puntero al arbol avl con la cámara principal.
        //haria falta un metodo que diga addAVL para añadir el arbol aca y
        //el metodo getAVL
    
    public:
        Node() {
            data = NULL;
            next = NULL;
        }

        Node(T *pData , string minero) {
            nomMinero = minero;
            this->data = pData;
            next = NULL;
        }

        T* getData() {
            //printf("el minero trajo : s%" , nomMinero);
            cout<<"el minero es:" <<nomMinero<<endl;
            return data;
        }
        Node* getNext() { // esta linea se agrega para quiz #4 #5
            return next;
        }
        void setNext(Node *pValue) {
            this->next = pValue;
        }
};

#endif