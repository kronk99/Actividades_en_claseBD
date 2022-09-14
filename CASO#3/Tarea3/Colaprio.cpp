#include "Nodeprio.cpp"
#ifndef COLA 

#define COLA 1

template <class T>
class Colaprio {
    private:
        Nodeprio<T> *first;
        Nodeprio<T> *last;
        int quantity;
        bool empty;

    public:
        Colaprio() {
            first = NULL;
            last = NULL;
            quantity = 0;
            empty = true;
        }
        void dequeue(){
            Nodeprio<T> *current = first->getNext();
            first->setNext(current);
        }

        void add(T *pData , int prioridad) {
            Nodeprio<T> *newNode = new Nodeprio<T>(pData , prioridad);
            Nodeprio<T> *current = first;
            if (quantity>0) {
                int posicion = search(prioridad);
                if(posicion = 0){
                    newNode->setNext(first);
                    first->setNext(newNode);
                }
                else{
                    for(int i = 0; i<posicion-1 ; i++){
                        current = current->getNext();
                    }
                    newNode->setNext(current->getNext());
                    current->setNext(newNode);
                }
            } 
            else {
                this->first = newNode;
                this->last = newNode;
            }
            empty = false;
            quantity++;
        }
        int search(int valor){
            Nodeprio<T> *current = first;
            int resultado = 0;
            bool check = false;
            while(check ==false ){
                if(valor<current->getPriority()){
                    current = current->getNext();
                    resultado+=1;
                }
                else{
                    check = true;
                }
            }
            return resultado;
        }

        Nodeprio<T>* getFirst() {
            return this->first;
        }

        int getSize() {
            return quantity;
        }

        bool isEmpty() {
            return !quantity;
        }

        int find(int pPosition) {
            T* result = NULL;
            Nodeprio<T>* search = this->first;
            for(int i=0;i<=pPosition;i++){
                search = search->getNext();
            }
            result = search->getPriority();
            return result;
        }

        // es que si el position es mayor a la cantidad, entonces inserto al final
//puedo hacer un find comparando posiciones y retornando 
//el valor de la posicion en la lista para insertarlo, luego inserto segun la 
//condicion de la prioridad
};
#endif