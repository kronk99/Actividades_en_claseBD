#include <iostream>

#ifndef NODE 

#define NODE 1

using namespace std;

template <class T>
class Node {
    private:
        T *data;
        Node *next; //puntero al nodo siguiente.
        Node *previus; //puntero al nodo anterior
    
    public:
        Node() {
            data = NULL;
            next = NULL;
            previus = NULL;
        }

        Node(T *pData) {
            this->data = pData;
            next = NULL;
            previus = NULL;
        }

        T* getData() {
            return data;
        }

        Node* getNext() {
            return next;
        }

        void setNext(Node *pValue) {
            this->next = pValue;
        }
        void setPrevious(Node *pValue){
            this->previus = pValue;
        }
        Node* getPrevious(){
            return previus;
        }
};
#endif