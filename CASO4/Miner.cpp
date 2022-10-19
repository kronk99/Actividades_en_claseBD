#include <iostream>
#include <chrono>
#include <thread>
#include <string>
#include "Nodo.cpp"
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
        Pila<Nodo<Door>> *mapa;
        int totalDoors;
        InsertionSort<Nodo<Door>> *toOrder;
        

    public:
    //constructor de la clase mineros
        Miner(int pVelocidad , string name , int maxminerales , Nodo<Door> *entrada , int ptotalDoors){
            velocidad = pVelocidad;
            nombre = name;
            cantidadMax = maxminerales;
            current = entrada; //**AÑADIDO NUEVO
            mapa = new Pila<Nodo<Door>>();
            totalDoors = ptotalDoors;
            toOrder = new InsertionSort<Nodo<Door>>();
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
            int counterBacks=0;
            int a = 0;
            cout<<"se llego antes del push del current a la pila"<<endl;
            mapa->Push(current); //esto no esta sirviendo, hasta aca ejecuta el programa.
            cout<<"se llego despues del push del current a la pila"<<endl;
            while(totalDoors !=0){
                cout<<"se entro al ciclo while"<<endl;
                int number = rand()%4-1;
                cout<<"se saco un random, el cual es: "<<number<<endl;
                if(counterBacks !=4){
                    cout<<"se entra al if de counterbacks !=4"<<endl;
                    //probablemente ese search ese searchNode esta malo.
                    if(current->getNodo(number+1)!= NULL && mapa->searchNode(current->getNodo(number+1))!=true){
                        cout<<"se entro if que verifica si el nodo esta en la pila y no es nulo"<<endl;
                        //el true es si es true, es que esta en la pila, si no, es que no esta en la pila.
                        current =current->getNodo(number);
                        mapa->Push(current);
                        cout<<"se hace push al nuevo current"<<endl;
                        mapa = toOrder->sort(mapa); //muy probablemente hayan errores en este
                        //sort, revisar esto bien
                        cout<<"se ordena la pila"<<endl;
                        cout<<"me meti a la puerta:"<<current->getDoor()->getId()<<endl;
                        totalDoors--;
                    }
                    else{
                        counterBacks+=1;
                        cout<<"esa puerta ya la revise, counterbacks : "<<counterBacks<<endl;
                    }
                    totalDoors--;
                }
                else{//si el counterbacks es 4 , entonces devuelvase al nodo anterior.
                    counterBacks = 0;
                    current = current->getPrev();
                    cout<<"me devolvi a la puerta:"<<current->getDoor()->getId()<<endl;
                    totalDoors--;
                }
            }
        }
        string getName(){
            return nombre;
        }

};
#endif