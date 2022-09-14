#include <iostream>
#include "Node.cpp"
using namespace std;
#ifndef PILA 

#define PILA 1

template <class T>
class Pila {
    private:
        Node<T> *first;
        Node<T> *last;
        int quantity;
        bool empty;

    public:
        Pila() {
            first = NULL;
            last = NULL; //no tengo un last/tail en la pila simple.
            quantity = 0;
            empty = true;
        }

        void Push(T *pData) { //añade al inicio de la pila
            Node<T> *newNode = new Node<T>(pData);
            if (quantity>0) {
                newNode->setNext(getFirst());
                first = newNode;
                //cout<<"se ha anadido un nodo cualquiera"<<endl;
            } else {
                newNode->setNext(NULL);
                first = newNode;
                //cout<<"se ha anadido un nodo como cabeza"<<endl;
            }
            empty = false;
            quantity++;
        }

        Node<T>* getFirst() {
            return this->first;
        }

        int getSize() {
            return quantity;
        }

        bool isEmpty() {
            return !quantity;
        }
        T* Top() { //retorno lo contenido en el nodo, no el nodo como tal.
            T* result = NULL;
            if (first != NULL){
            Node<T>* search = this->first;
            result = search->getData();
            }
            else{
                cout<<"la lista esta vaciaaa"<< endl;
            }
            return result;
        }
        void Pop(){ //funcion que elimina el primer elemento de la pila
            if(first !=NULL){
                Node<T> *current = NULL;
                current = first->getNext();
                first->setNext(NULL);
                this->first = current;
                quantity-=1;
            }
            else if(quantity == 1){
                first = NULL;
                quantity-=1;
            }
            else{
                printf("la lista esta vacia");
            }
        }
};

#endif