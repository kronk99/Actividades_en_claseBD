#include "Nodes.h"
#include "Door.cpp"
#include "Nodo.cpp"
#ifndef PILA

#define PILA 1

template <typename T> 
class Pila  {
    private:
        Nodes<T> *first;
        Nodes<T> *Empty;
        int size;
    public:
        Pila() {
            first = NULL;
            Door *emptyDoor = new Door;
            Nodo<Door> *empty = new Nodo<Door>();
            emptyDoor->setEmpty();
            Empty = new Nodes<T>(empty); //el empty no sirve arreglar esto
        }
        void Push(T *pData) { //hay que modificar el add para que añada a cada
        //nodo otro nodo con las probalilidades.
            Nodes<T> *newNode = new Nodes<T>(pData);
            if (size>0) {
                newNode->setNext(first);
                first->setPrevius(newNode);
                first=newNode;
                size++;
                cout<<"se creo un nodo nuevo"<<endl;
            }
            else {
                this->first = newNode;
                size++;
                cout<<"se creo un nodo first"<<endl;

            }
            //size++;
        }

        Nodes<T>* Peak() { //tal vez hacer un codicional si el first no es nulo.
            if(size >=1){
                Nodes<T> *result= this->first;
                return result;
            }
            else{
                cout<<"la lista esta vacia"<<endl;
                return NULL; //VERIFICAR SI ESTE RETURN NULL NO DAÑA EL PROGRAMA
                //SI LO DAÑA CAMBIELO POR EMPTY.
            }
        }
        bool searchNode(Nodo<Door> *pValuetoSearch){
            Nodes<T> *current = first;
            bool result = false;
            while(current != NULL){
                if (current->getData()==pValuetoSearch){
                    result = true;
                    break;
                }
                current = current->getNext();
            }
            cout<<"RETORNO:"<<result<<endl;
            return result;
        }
        int getSize() {
            return size;
        }
        bool isEmpty() {
            return !size;
        }
        void Pop(){
            if(size >1){
                
                Nodes<T> *current = first;
                first = current->getNext(); 
                first->setPrevius(NULL);
                current->setNext(NULL); 
                size-=1;
            }
            else if(size==1){
                first = NULL;
                size-=1;
                cout<<"el size es :"<<size<<endl;
            }
            else{
                cout<<"la pila esta vacia";
            }
        }
        // si el position es mayor a la cantidad, entonces inserto al final
        //creo que el search debe de decirme, en que cuadrante (0,1,2,3) entrar y un n
        //que ese n es cuantas veces debe entrar por esa puerta.
        //hacer un clear a la cola.
};

#endif