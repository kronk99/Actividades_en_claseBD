#include <iostream>
#include "Door.cpp"
#include "List.cpp"
#include "Cola.h"
#include "Nodo.cpp"
#ifndef DOORMANAGER 
#define DOORMAGANER 1
class doorManager{
    private:
        Nodo<Door> *mainEntrance ; //puntero al nodo de la entrada principal
        Cola<Nodo<Door>> *colaControl;
        
    public:
        doorManager(){
            mainEntrance = NULL;
            colaControl = new Cola<Nodo<Door>>();
        }
        Nodo<Door>* getEntrada(){
            return this->mainEntrance;
        }
        void generateDoor(int pTotaldoors){
            int numberDoor = 1;
            Door *maindoor = new Door();
            maindoor->setId(0); //linea de prueba
            maindoor->setMaindoor();
            mainEntrance = new Nodo<Door>(maindoor); 
            colaControl->enqueue(mainEntrance);
            //este while y for esta sus de momento, arreglar luego
            int iteraciones = 0;
            while (colaControl->getSize()!=0 && pTotaldoors>0) {
                //EL PRIMER NODO DE ENTRADA PRINCIPAL NO TIENE PUERTAS
                //ARREGLAR ESTO
                //EL ERROR DEBE DE SER ACA.
                Nodes<Nodo<Door>> *queueNode = colaControl->dequeue(); 
                
                Nodo<Door> *currentDoor = queueNode->getData(); //inserte el puntero de nodo metido
                //en el nodo de nodos puntero.
                int cantidad = rand()%4 + 1;
                for(cantidad && pTotaldoors;cantidad>0 && pTotaldoors>0; cantidad--) {
                    pTotaldoors--;
                    Door *newDoor = new Door();
                    newDoor->setId(numberDoor);
                    Nodo<Door> *newNode = new Nodo<Door>(newDoor);
                    newNode->setPrev(currentDoor); //LINEA EXPERIMENTAL
                    currentDoor->setCardinal(cantidad-1 , newNode); 
                    //MODIFIQUE ESTO****************
                    colaControl->enqueue(newNode);
                    cout<<"se inserto el id:"<<numberDoor<<"en la puerta"<<cantidad-1<<" en el nodo"<<endl;
                    numberDoor+=1;
                }
                iteraciones+=1;
                cout<<"las iteraciones son:"<<iteraciones<<endl;
                cout<<"el size es"<<colaControl->getSize()<<endl;  
            }
        }


};
#endif
/*
class Tunel {
    public:
        AVLTree tunel;
        int maxDistance;
        int totalMinerales;
}
clase tunel va conectada a clase door
class Door { 
    
    public: 
        int id;
        bool isMainDoor;
        Tunel tunel;

        Door() {
            if (rand()%100<=66) {
                tunel = new AVLTree();
                generateTunels();
            }
        }

        void generateTunels() {
        }
}

template <class T>
class Node {
    Node* prev;
    Node* cardinals[4];
    T *door; 

    Nodo(T *value) {
        door = value;
        cardinals[0] = NULL;
        cardinals[1] = NULL;
        cardinals[2] = NULL;
        cardinals[3] = NULL;
    }
}


class DoorManager {

    public:
        Node<Door> *mainEntrance = NULL;
        Queue<Node<Door>> controlQueue;


        void generateDoors(int pTotalDoors) {
            Door *main = new Door();
            main.isMainDoor = true;

            Node<Door> *start = new Node<Door>(main);
            mainEntrance = main;

            controlQueue.enqueue(main); //verificar si esto debe ser main o node<door>

            while (!controlQueue.isEmpty() && pTotalDoors>0) {
                Node<Door> *currentDoor = controlQueue.dequeue();

                int cantidad = rand()%4 + 1;
                

                for(;cantidad>0 && pTotalDoors>0; cantidad--) {
                    pTotalDoors--;
                    Door *newDoor = new Door();
                    Node<Door> *newNode = new Node<Door>(newDoor);
                    currentDoor[cantidad-1] = newNode;

                    controlQueue.enqueue(newNode);
                }   
            }
        }
}
*/



