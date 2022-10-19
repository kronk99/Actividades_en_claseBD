#include <iostream>
#include "Nodes.h"
#include "Pila.h"
#ifndef SORT
#define SORT1
using namespace std;
template <class T>
class InsertionSort{
    private:
        int interchanges = 0;
        int compares = 0; 
    
    public:
        Pila<T>* sort(Pila<T>* pNumberList) {
            //metodo que ordena con el insertion sort
            Nodes<T> *front = pNumberList->Peak();
            Nodes<T> *back = NULL;
            
            while(front != NULL) {
                //se guarda el siguiente para la siguiente iteracion
                back = front->getNext();
                //mientras que esten dos desordenados, y aun no se haya llegado al final:

                while((back != NULL) && (back->getPrevius() != NULL) && back->getData()->getDoor()->getId() > back->getPrevius()->getData()->getDoor()->getId()) {
                    //incrementamos contador de comparaciones
                    compares++;

                    //darle la vuelta a los nodos change1 y change2
                    Nodes<T> *change1 = back;
                    Nodes<T> *change2 = back->getPrevius();
                    Nodes<T> *change3 = back;
                    //hasta aca voy bien 
                    //int valor = *change1->getData();
                    change1->setData(change2->getData());
                    change2->setData(change3->getData());
                    //incrementamos contador de intercambios
                    interchanges++;

                    //vamos al nodo previo
                    back = back->getPrevius();
                }
                if((back != NULL) && (back->getPrevius() != NULL)) {
                    //incrementamos contador de comparaciones
                    compares++;
                } 
                front = front->getNext();
            }
            return pNumberList;
        }

        string getName() {
            return "InsertionSort";
        }

        int getComparisions() {
            //metodo que retorna contador de comparaciones
            return compares;
        }

        int getInterchanges() {
            //metodo que retorna contador de intercambios
            return interchanges;
        }
};
#endif