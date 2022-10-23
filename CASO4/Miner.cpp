#include <iostream>
#include <chrono>
#include <thread>
#include <string>
#include "Nodo.cpp"
#include "Nodes.h"
#include "Door.cpp"
#include "Pila.h"
#include "InsertionSort.cpp"
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
        //Pila<Nodo<Door>> *mapa;
        Nodo<Door> *prevDoor;
        //Nodes<Camara> *cpositionTree;
        int totalDoors;
        //InsertionSort<Nodo<Door>> *toOrder;
        

    public:
    //constructor de la clase mineros
        Miner(int pVelocidad , string name , int maxminerales , Nodo<Door> *entrada , int ptotalDoors){
            velocidad = pVelocidad;
            nombre = name;
            cantidadMax = maxminerales;
            current = entrada; //**AÑADIDO NUEVO
            //mapa = new Pila<Nodo<Door>>();
            totalDoors = ptotalDoors;
            //toOrder = new InsertionSort<Nodo<Door>>();
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
        void buildPath(){
            //mapa->Push(current); //esto no esta sirviendo, hasta aca ejecuta el programa.
            while(totalDoors !=0){
                int ProbtoReturn = rand()%100;
                int number = rand()%4-1;
                cout<<"se saco un random, el cual es: "<<number<<endl;
                if(ProbtoReturn<=60){
                    if(current->getNodo(number+1)!= NULL && prevDoor !=current->getNodo(number+1)){
                        cout<<"se entro if que verifica si el nodo esta en la pila y no es nulo"<<endl;
                        //el true es si es true, es que esta en la pila, si no, es que no esta en la pila.
                        prevDoor = current;
                        current =current->getNodo(number+1);
                        //mapa = toOrder->sort(mapa); //muy probablemente hayan errores en este
                        //sort, revisar esto bien

                        cout<<"me meti a la puerta:"<<current->getDoor()->getId()<<endl;
                        
                    }
                    else{
                        cout<<"ya entre a esa puerta/estaba vacia! "<<endl;
                    }
                    totalDoors--;
                }
                else{//si el counterbacks es 4 , entonces devuelvase al nodo anterior.
                //hacer un if aca de que si no esta en el inicio devuelvase.
                    if(current->getPrev() != NULL){
                    current = current->getPrev();
                    cout<<"me devolvi a la puerta:"<<current->getDoor()->getId()<<endl;
                    }
                    else{
                        cout<<"ya estoy en la puerta inicial, no puedo retroceder mas"<<endl;
                    }
                    totalDoors--; 
                }
            }
        }
        string getName(){
            return nombre;
        }

};
#endif