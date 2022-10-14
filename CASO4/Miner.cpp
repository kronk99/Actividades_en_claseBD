#include <iostream>
#include <chrono>
#include <thread>
#include <string>
#include "Nodo.cpp"
#include "Door.cpp"
#ifndef MINER
#define MINER 1

using namespace std; //AÑADIDO NUEVO**
class Miner{
    private:
        int cantidadMax; //cantidad maxima de minerales que puede extraer
        int velocidad; //velocidad con la que el minero camina
        string nombre; //nombre del minero
        bool ready; //FLAG para el ciclo del movimiento.
        Nodo<Door> *current; //se va a probae hacer nodo generic ***AÑADIDO NUEVO**
    public:
    //constructor de la clase mineros
        Miner(int pVelocidad , string name , int maxminerales , Nodo<Door> *entrada){
            velocidad = pVelocidad;
            nombre = name;
            cantidadMax = maxminerales;
            current = entrada; //**AÑADIDO NUEVO
        }
        void cantminer(int pMinerales){
            cantidadMax = pMinerales;
        }
        int getMinerales(){
            return this->cantidadMax;
        }
        //enciende la flag
        void turnReady(){
            this->ready=true;
        }
        //apaga la flag
        void offReady(){
            this->ready=false;
        }//funcion encargada del movimiento de los mineros.
        /*
        void moveMinerExplorer(){
            //por ahora se va a mover 3 veces, luego se tiene que 
            //mover con pilas de direccion de hacia adonde habia entrado.
            int a= 0;
            while(a !=3){ //TODO ESTO SE AÑADIO NUEVO
                Door *currentDorr =current->getDoor();
                cout<<"el minero "<<nombre<<"esta en la puerta: " << currentDorr->getId()<<endl;
                int selectedDoor = rand() % 4; 
                if (current->getCardinals()[selectedDoor] != NULL){
                    current = current->getCardinals()[selectedDoor];
                    cout<<"se entra aca"<<endl;
                }
                else{
                    current = current->getPrev();
                    cout<<"se devolvio"<<endl;
                }
                a+=1;
            }
        }
        string getName(){
            return nombre;
        }
        */
};
#endif