#include <iostream>
#include <chrono>
#include <thread>
#include <string>
#ifndef MINER

#define MINER 1
using namespace std;

class Miner{
    private:
        int cantidadMax;
        int velocidad;
        string nombre;
        bool ready;
    public:
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
        void turnReady(){
            this->ready=true;
        }
        void offReady(){
            this->ready=false;
        }
        int moveMinerExplorer(){
            int randomMineral = 0;
            int randomNumber = 0;
            int caminadaIda;
            int caminadaRegreso;
            while(ready ==true){ //creo que este ciclo es innecesario
                randomNumber = rand() % 80; //Genera la distancia que debe de caminar
                caminadaIda=randomNumber;
                caminadaRegreso=randomNumber;
                //este for de abajo se debe ejecutar por segundo
                for(caminadaIda ; caminadaIda>=0; caminadaIda-=velocidad){
                    cout<<"El " <<nombre<< " esta yendo a la mina"<<endl;
                    this_thread::sleep_for (std::chrono::seconds(1));
                }
                randomMineral = rand() % cantidadMax;
                //explorer->cantminada(randomMineral);
                for(caminadaRegreso ; caminadaRegreso>=0; caminadaRegreso-=velocidad){
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