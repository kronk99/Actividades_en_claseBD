#include <iostream>
#include <cstdlib>
#include <iostream>
#include <mutex>
#include <thread>
#include <chrono>
#include "Miner.h"
#include "Cola.h"
using namespace std;
bool ready = false; //flag global
void moveTopo(Miner *topos){
    Miner *topo = topos;

}
void moveCarguero(Miner * cargueros){
    Miner *carguero = cargueros;
}
int moveMinerExplorer(){
    int randomMineral = 0;
    int randomNumber = 0;
    int caminadaIda;
    int caminadaRegreso;
    while(!ready){ //esto debe cambiar a un flag
        randomNumber = rand() % 80; //Genera la distancia que debe de caminar
        caminadaIda=randomNumber;
        caminadaRegreso=randomNumber;
        //este for de abajo se debe ejecutar por segundo
        for(caminadaIda ; caminadaIda=0; caminadaIda-20){
            cout<<"el explorer esta caminando";
            this_thread::sleep_for (std::chrono::seconds(1));
        }
        randomMineral = rand() % 20;
        //explorer->cantminada(randomMineral);
        for(caminadaIda ; caminadaIda=0; caminadaIda-20){
            cout<<"el explorer  esta caminando de regreso";
            this_thread::sleep_for (std::chrono::seconds(1));
        }
        ready = false;
        //digamos que aca hay un return
    }
    return randomMineral;
}
void game(){
    Cola<int> *bodega = new Cola<int>();
    int i = 0;
    while(i<3){
        int data = moveMinerExplorer();
        bodega->enqueue(&data , "puta");
    }
}
int main(){
    thread t1(game);
    t1.join();
}