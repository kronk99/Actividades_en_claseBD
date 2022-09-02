#include "Node.h"
#include "event.h"
using namespace std; //añadi esto ver si da error.

#ifndef LIST 

#define LIST 1

template <class T>
class List {
    private:
        Node<T> *first;
        Node<T> *last;
        int quantity;
        bool empty;

    public:
        List() {
            first = NULL;
            last = NULL;
            quantity = 0;
            empty = true;
        }

        void add(T *pData) {
            Node<T> *newNode = new Node<T>(pData);

            if (quantity>0) {
                this->last->setNext(newNode);
                newNode->setPrevious(this->last);//añade el puntero al anterior
                this->last = newNode;
            } else {
                this->first = newNode;
                this->last = newNode;
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

        T* find(int pPosition) { //buscador de posiciones.
            T* result = NULL; //puntero al datatype de t., debe regresar lo que tenga t
            Node<T>* search = this->first;

            if (pPosition<getSize()) {
                while(pPosition>0) {
                    search = search->getNext();
                    pPosition--;
                }
                result = search->getData();
            }

            return result;
        }
        void revSearch(){
            Node<T> *current = this->last;
            T* result = NULL;
            int pos = 0;
            while(pos<quantity){
                result =current->getData();
                current = current->getPrevious();
                cout << result->getTitle();
            }
        }

        // es que si el position es mayor a la cantidad, entonces inserto al final
        void insert(int pPosition, T *pEvent) {
            
            if (pPosition<getSize() && first!=NULL) {
                Node<T> *newNodo = new Node<T>(pEvent);//nuevo nodo con referencia tipo t
                Node<T> *searchPosition = this->first;
                Node<T> *searchBehind = NULL;

                while(pPosition>0) {
                    pPosition--;
                    searchBehind = searchPosition;
                    searchPosition = searchPosition->getNext();
                }
                
                newNodo->setNext(searchPosition);
                if (searchBehind!=NULL) {
                    searchBehind->setNext(newNodo);
                    newNodo->setPrevious(searchBehind); //el previus a añadir es el behind de dicho nodo.
                } else {
                    this->first = newNodo;
                }
                
                quantity++;
            } else { //si no , añada el nodito.
                add(pEvent);
            }
        }

};

#endif