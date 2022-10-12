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
        void generateDoor(int pTotaldoors){
            Door *maindoor = new Door();
            maindoor->setMaindoor();
            mainEntrance = new Nodo<Door>(maindoor); 
            colaControl->enqueue(mainEntrance);
            //este while y for esta sus de momento, arreglar luego
            int iteraciones = 0;
            while (colaControl->getSize()!=0 && pTotaldoors>0) {
                cout<<"entra al ciclo while"<<endl;
                Nodes<Nodo<Door>> *queueNode = colaControl->dequeue(); 
                cout<<"hace dequeue"<<endl;
                Nodo<Door> *currentDoor = queueNode->getData();
                int cantidad = rand()%4 + 1;
                cout<<"hace el random"<<endl;
            //esto de abajo es el total de puertas aleatorias que 
            //crea (norte,sur,este,oeste) y pTotaldoors es la cantidad
            //de puertas que el usuario inserta.
                for(cantidad && pTotaldoors;cantidad>0 && pTotaldoors>0; cantidad--) {
                    cout<<"entra al ciclo for"<<endl;
                    pTotaldoors--;
                    Door *newDoor = new Door();
                    Nodo<Door> *newNode = new Nodo<Door>(newDoor);
                    newNode->setPrev(currentDoor); //LINEA EXPERIMENTAL
                    cout<<"pone un previus"<<endl;
                    currentDoor->getCardinals()[cantidad-1] =newDoor;
                    cout<<"pone el nodo en los cardenales"<<endl;
                    colaControl->enqueue(newNode);
                    cout<<"se inserto la puerta"<<cantidad<<" en el nodo"<<endl;
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



