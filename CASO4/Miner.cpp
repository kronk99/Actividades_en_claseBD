#include <iostream>
#include <chrono>
#include <thread>
#include <string>
#include "Nodo.cpp"
#include "Nodes.h"
#include "Door.cpp"
#include "Pila.h"
#include "InsertionSort.cpp"
#include "Camara.cpp"
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
        Nodes<Camara> *camActual; //camara actual del arbol.
        //Nodes<Camara> *cpositionTree;
        int totalDoors;
        int cantRecorrida;
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
            cantRecorrida = 0;
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
            while(totalDoors !=0){ //while flag = true .
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
                        //checkea si tiene un arbol
                        checkTunel(current); //OJITO CON ESTO.
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
        void checkTunel(Nodo<Door> *pCurrent){
            if(pCurrent->getDoor()->getTunel() ==true){
                camActual= pCurrent->getDoor()->getArbol()->getRaiz();
                moverseCamara();
            }
            else{
                cout<<"no hay tunel en esta puerta."<<endl;
            }
        }
        void moverseCamara(){
            int i = 0;
            int cantBajar;
            int desicion;
            while(i <=3){
                cantBajar = rand()%720+1;
                //esto esta en un ciclo()if current->getNext != null{
                    //int bajada  = current->getNext->getData->getDistancia
                    //while(bajada >0){
                        //bajada - velocidad
                        //cantquebajo+=velocidad;
                    }
                    //
                    //current = current->getNext
                    //checke si el nodo tiene minerales
                    //si tiene minerales , extraiga
                    //si no tiene minerales, entonces haga delete
                    
                }
                while(cantRecorrida<cantBajar){
                    desicion = rand()%2;
                    cantRecorrida+=velocidad;
                    if(camActual->)
                }
                cout<<"llegue al nodo"
            }
            //invertanos un movimiento borrachillo.
            //este movimiento acaba cuando raiz previus y next de la raiz es nulo
            //necesitamos el eliminar nodos
            //ocupamos editar la cantidad de minerales en una camara , para eso
            //se necesita un metodo que quite minerales
            //cuando entra a una camara pregunta cuantos minerales hay
            //y si no hay minerales ,borra dicho nodo
            //cuando el minero extrae minerales se debe de devolver, por lo que el 
            //minero tiene un contador de cuanto ha bajado en la raiz, cada vez que hace
            //next debe sumarle a su propio contador 
            //aca se borran nodos cuando se saca la cantidad de minerales.
        }
        string getName(){
            return nombre;
        }

};
#endif