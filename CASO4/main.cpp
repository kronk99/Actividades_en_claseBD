#include <iostream>
#include <cstdlib>
#include <iostream>
#include <mutex>
#include <thread>
#include <chrono>
#include "Miner.h"
#include "Cola.h"
using namespace std;
void moveTopo(Miner *topos){
    Miner *topo = topos;

}
void moveCarguero(Miner * cargueros){
    Miner *carguero = cargueros;
}
void moveMinerExplorer(Miner *exploradors , Cola<int> *colas){
    Cola<int> *cola = colas;
    Miner *explorer  =exploradors;
    int i = 0;
    int randomMineral = 0;
    int randomNumber = 0;
    int caminadaIda;
    int caminadaRegreso;
    while(i<10){
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
        cola->enqueue(&randomMineral , "explorer");
        i++;
    }
}
int main(){
    Cola<int> *bodega = new Cola<int>();
    Miner *miner = new Miner(20);
    thread t1(moveMinerExplorer);

}