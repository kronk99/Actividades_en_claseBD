/*
#include "Node.cpp"

#ifndef LIST 

#define LIST 1

// 2. ajustar a que esta lista sea doblemente enlazada, cambia el add, find, insert y el remove
template <typename T> 
class List  {
    private:
        Node<T> *first;
       // Node<T> *last; //perhaps unnecesary for this game.
        Node<T> *searchPosition;
        int size;
        Node<T> *last;
    public:
        List() {
            first = NULL;
            last = NULL;
            size = 0;
        }
        void add(T *pData , int cantidad , int position) { 
            //aca se crea un array de 3 (norte sur este oeste + la probailidad
            //de una cueva)
            Node<T> *newNode = new Node<T>[cantidad];
            if (size>0) {
                Node *current = first->getNext();
                for(i = 0 ; i<position ; i++){
                    for (x = 0; x<cantidad ; x++){
                        if (current[i]->getNext() == NULL){
                            //aca revisa si no son nulos 
                            //entonces se mete ahi
                            x = position;
                        }
                    }
                }
            } else {
                this->first = newNode;
            }
            //this->last = newNode;
            size++;
        }
        Node<T>* getFirst() {
            return this->first;
        }
        int getSize() {
            return size;
        }
        bool isEmpty() {
            return !size;
        }
        // si el position es mayor a la cantidad, entonces inserto al final
        //creo que el search debe de decirme, en que cuadrante (0,1,2,3) entrar y un n
        //que ese n es cuantas veces debe entrar por esa puerta.
        //se podria hacer una constante como 0 = north , 1 = south etc
};

#endif
*/