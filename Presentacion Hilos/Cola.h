#include "Node.h"

#ifndef COLA 

#define COLA 1

// 2. ajustar a que esta lista sea doblemente enlazada, cambia el add, find, insert y el remove
template <typename T> 
class Cola  {
    private:
        Node<T> *first;
        Node<T> *last; //perhaps unnecesary for this game.
        Node<T> *searchPosition;
        int size;
    public:
        Cola() {
            first = NULL;
            last = NULL;
            size = 0;
        }
        //direccion puedo utilizarlo como indice del array
        void enqueue(T *pData , string nomMinero ) { //hay que modificar el add para que añada a cada
        //nodo otro nodo con las probalilidades.
            Node<T> *newNode = new Node<T>(pData , nomMinero);
            if (size>0) {
                this->last->setNext(newNode);
                this->last = newNode;
            }
            else {
                this->first = newNode;
                this->last = newNode;
            }
            size++;
        }
        Node<T>* dequeue() {
            return this->first;
            Pop();
        }
        int getSize() {
            return size;
        }
        bool isEmpty() {
            return !size;
        }
        void Pop(){
            if(size >1){
                Node<T> *current = first;
                first = first->getNext();
                current->setNext(NULL);
                size--;
            }
            else if(size=1){
                first = NULL;
                size--;
            }
            else{
                cout<<"no hay elementos a eliminar";
            }
        }
        // si el position es mayor a la cantidad, entonces inserto al final
        //creo que el search debe de decirme, en que cuadrante (0,1,2,3) entrar y un n
        //que ese n es cuantas veces debe entrar por esa puerta.
        //hacer un clear a la cola.
};

#endif