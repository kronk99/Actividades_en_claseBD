#include <iostream>

#ifndef NODEP 

#define NODEP 1

using namespace std;

template <class T>
class Nodeprio {
    private:
        T *data;
        Nodeprio *next;
        int prioridad;
    
    public:
        Nodeprio() {
            data = NULL;
            next = NULL;
        }

        Nodeprio(T *pData , int valor) {
            this->data = pData;
            next = NULL;
            prioridad = valor;
        }

        T* getData() {
            return data;
        }

        Nodeprio* getNext() {
            return next;
        }

        void setNext(Nodeprio *pValue) {
            this->next = pValue;
        }
        int getPriority(){
            return prioridad;
        }
};
#endif