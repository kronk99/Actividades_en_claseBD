#include "Node.h"
#include "event.h"
#include <string>
using namespace std;
#ifndef LIST 

#define LIST 1

// 2. ajustar a que esta lista sea doblemente enlazada, cambia el add, find, insert y el remove
template <class T>
class List {
    private:
        Node<T> *first;
        Node<T> *last;
        int quantity;
        bool empty;
        Node<T> *searchPosition = NULL;
        //Node<T> *searchBehind = NULL;

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
                newNode->setPrevious(this->last);
            } else {
                this->first = newNode;
            }
            this->last = newNode;

            empty = false;
            quantity++; //esto inicia en 0 y le sumo 1.
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
//tuve que cambiar esto a node para que regrese el nodo
        Node<T>* find(int pPosition) { //hay que modificar el find para quitar
        //el searchBehid
            Node<T>* result = NULL;
            searchPosition = this->first;
            //searchBehind = NULL;

            if (pPosition<getSize()) {
                cout << getSize();
                while(pPosition>0) {
                    //searchBehind = searchPosition;
                    searchPosition = searchPosition->getNext();
                    pPosition--;
                }
                result = searchPosition;
            }
            return result;
        }

        // es que si el position es mayor a la cantidad, entonces inserto al final
        void insert(int pPosition, T *pData) {
            
            if (pPosition<getSize() && first!=NULL) {
                Node<T> *newNodo = new Node<T>(pData);

                Node<T> *current = find(pPosition);
                
                newNodo->setNext(current);
                if(current->getPrevious() != NULL){
                    current->getPrevious()->setNext(newNodo);
                    newNodo->setPrevious( current->getPrevious());
                    current->setPrevious(newNodo);
                }
                else{
                    newNodo->setPrevious(NULL);
                    current->setPrevious(newNodo);
                    first = newNodo;
                }
                /*
                if (searchBehind!=NULL) {
                    searchBehind->setNext(newNodo);
                } else {
                    this->first = newNodo;
                }
                */
                
                quantity++;
            } else {
                add(pData);
            }
        }
        bool remove(int pPosition) { //esto debe de eliminar el num-1
            bool result = false;
            Node<T> *search = first;;
            if (first!=NULL && pPosition<getSize()) {
                if (pPosition!=0) {
                    cout<<"por aqui pase"<<endl;
                    search = find(pPosition);
                    Event *e = search->getData();
                    cout<< e->getTitle(); //hasta aca esta bien
                    cout<<"por aqui pase2"<<endl;
                    search->getNext()->setPrevious(search->getPrevious());
                    search->getPrevious()->setNext(search->getNext());
                    result=true;
                    }
                } 
                else {
                    first = first->getNext();
                    first->setPrevious(NULL);
                    search->setNext(NULL); //puse esto
                    result = true;
                }
                quantity--;
            return result;
        } 
};
#endif