#include <iostream>
#include <string>

#ifndef NODES 

#define NODES 1

using namespace std;

// 1. pasar este nodo a doblemente enlazado
template <class T>
class Nodes {
    private:
        Nodes *next;
        Nodes *previus;
        T *data;
        string nomMinero;
        //AVL *camPrincip; //puntero al arbol avl con la cámara principal.
        //haria falta un metodo que diga addAVL para añadir el arbol aca y
        //el metodo getAVL
    
    public:
        Nodes() {
            data = NULL;
            next = NULL;
            previus = NULL;
        }

        Nodes(T *pData ) {
            this->data = pData;
            next = NULL;
        }
        void setData(T *pData){
            this->data = pData;
        }

        T* getData() {
            //printf("el minero trajo : s%" ; nomMinero);
            return data;
        }
        Nodes* getNext() { // esta linea se agrega para quiz #4 #5
            return next;
        }
        Nodes* getPrevius(){
            return previus;
        }
        void setNext(Nodes *pValue) {
            this->next = pValue;
        }
        void setPrevius(Nodes *pValue){
            this->previus = pValue;
        }
        //AÑADI UN GETPREVIUS SET PREVIUS Y UN ATRIBUTO PREVIUS
};

#endif