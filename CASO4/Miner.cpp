#include <iostream>
#include <chrono>
#include <thread>
#include <string>
#include "Nodo.cpp"
#include "Door.cpp"
#include "Pila.h"
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

    public:
    //constructor de la clase mineros
        Miner(int pVelocidad , string name , int maxminerales , Nodo<Door> *entrada , int ptotalDoors){
            velocidad = pVelocidad;
            nombre = name;
            cantidadMax = maxminerales;
            current = entrada; //**AÑADIDO NUEVO
            mapa = new Pila<Nodo<Door>>;
            totalDoors = ptotalDoors;
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
            int counterBacks;
            mapa->Push(current);
            while(totalDoors !=0){
                int number = rand()%4-1;
                if(counterBacks !=4){
//si el nodo no es nulo, y si el nodo no esta en la lista donde me meti
                    if(current->getNodo(number)!= NULL && current->getNodo(number)!=/*aca va el selection sort*/){
                        current =current->getNodo(number);
                    }
                }
                totalDoors--;
            }
        }
        string getName(){
            return nombre;
        }
            //van a tener 3 formas de buscar, improvisacion que va a ser con randoms
            //y va a guardar esos randoms
            //conocedor , ya sabe cuantas puertas hay 
            //borracho , va a usar randoms para acceder a puertas

};
#endif