#include <iostream>
#include <string>

#ifndef NODESINT 

#define NODESINT 1

using namespace std;

// 1. pasar este nodo a doblemente enlazado
template <class T>
class Nodesint {
    private:
        Nodesint *next;
        Nodesint *previus;
        T data;
        //BORRRE NOMBREMINERO
        //AVL *camPrincip; //puntero al arbol avl con la cámara principal.
        //haria falta un metodo que diga addAVL para añadir el arbol aca y
        //el metodo getAVL    
    public:
        Nodesint() {
            data = NULL;
            next = NULL;
            previus = NULL;
        }

        Nodesint(T pData ) {
            this->data = pData;
            next = NULL;
        }
        void setData(T pData){
            this->data = pData;
        }

        T getData() {
            //printf("el minero trajo : s%" ; nomMinero);
            return data;
        }
        Nodesint* getNext() { // esta linea se agrega para quiz #4 #5
            return next;
        }
        Nodesint* getPrevius(){
            return previus;
        }
        void setNext(Nodesint<T> *pValue) {
            this->next = pValue;
        }
        void setPrevius(Nodesint<T> *pValue){
            this->previus = pValue;
        }
        //AÑADI UN GETPREVIUS SET PREVIUS Y UN ATRIBUTO PREVIUS
};

#endif