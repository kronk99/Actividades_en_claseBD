#include <iostream>
#include <chrono>
#include <thread>
#include <string>
#ifndef MINER

#define MINER 1
using namespace std;

class Miner{
    private:
        int cantidadMax; //cantidad maxima de minerales que puede extraer
        int velocidad; //velocidad con la que el minero camina
        string nombre; //nombre del minero
        bool ready; //FLAG para el ciclo del movimiento.
    public:
    //constructor de la clase mineros
        Miner(int pVelocidad , string name , int maxminerales){
            velocidad = pVelocidad;
            nombre = name;
            cantidadMax = maxminerales;
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
        int moveMinerExplorer(){
            int randomMineral = 0;
            int randomNumber = 0;
            int caminadaIda;
            int caminadaRegreso;
            while(ready ==true){ //creo que este ciclo es innecesario
                randomNumber = rand() % 80; //Genera la distancia que debe de caminar
                //caminadaIda=randomNumber;
                //caminadaRegreso=randomNumber;
                //este for de abajo se debe ejecutar por segundo
                for(int i=0 ; i<=randomNumber; i+=velocidad){
                    cout<<"El " <<nombre<< " esta yendo a la mina"<<endl;
                    this_thread::sleep_for (std::chrono::seconds(1));
                }
                randomMineral = rand() % cantidadMax;
                //explorer->cantminada(randomMineral);
                for(int z=0 ; z<=randomNumber; z+=velocidad){
                    cout<<"El "<<nombre<< " esta caminando de regreso"<<endl;
                    this_thread::sleep_for (std::chrono::seconds(1));
                }
                offReady();
                //digamos que aca hay un return
            }
            return randomMineral;
        }
        string getName(){
            return nombre;
        }
};
#endif