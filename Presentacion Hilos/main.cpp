#include <iostream>
#include <cstdlib>
#include <iostream>
#include <mutex>
#include <thread>
#include <chrono>
#include "Cola.h"
#include "Miner.cpp"
using namespace std;
bool ready = false; //flag global
Cola<int> *bodega = new Cola<int>(); //cola global.
//esto se podria hacer en una clase con insertar y con el consumir.
//*************codigo en alpha phase*********************************
int moveMinerExplorer(){
    int randomMineral = 0;
    int randomNumber = 0;
    int caminadaIda;
    int caminadaRegreso;
    cout<<"entro a la funcion "<<endl;
    while(ready ==true){ //creo que este ciclo es innecesario
    cout<<"entro al 1 ciclo"<<endl;
        randomNumber = rand() % 80; //Genera la distancia que debe de caminar
        caminadaIda=randomNumber;
        caminadaRegreso=randomNumber;
        //este for de abajo se debe ejecutar por segundo
        for(caminadaIda ; caminadaIda>=0; caminadaIda-=20){
            cout<<"el explorer esta caminando"<<endl;
            this_thread::sleep_for (std::chrono::seconds(1)); //funcion del thread que 
            //congela por una cantidad de tiempo (1s)
        }
        randomMineral = rand() % 20;
        //explorer->cantminada(randomMineral);
        for(caminadaRegreso ; caminadaRegreso>=0; caminadaRegreso-=20){
            cout<<"el explorer  esta caminando de regreso"<<endl;
            this_thread::sleep_for (std::chrono::seconds(1));
        }
        ready = false;
        //digamos que aca hay un return
    }
    return randomMineral;
}
//**********************************************************//
void explorer(){ //hilo de movimiento de explorer
    int i = 0;
    Miner *explorer = new Miner(20 , "explorer" , 8);
    while(i<3){
        explorer->turnReady();
        int data = explorer->moveMinerExplorer();
        cout<< "la catidad de mineral insertada es:"<<data<<endl;
        bodega->enqueue(&data , explorer->getName());
        cout<<"se inserto minerales en la bodega"<<endl;
        i++;
    }
}
void topo(){ //hilo del movimiento del topo
    int i = 0;
    Miner *topo = new Miner(7 , "topo" , 15);
    while(i<3){
        topo->turnReady();
        int data = topo->moveMinerExplorer();
        cout<< "la catidad de mineral insertada es:"<<data<<endl;
        bodega->enqueue(&data , topo->getName());
        cout<<"se inserto minerales en la bodega"<<endl;
        i++;
    }
}
void carguero(){//hilo del movimiento del carguero
    int i = 0;
    Miner *carguero = new Miner(10 , "carguero" , 40);
    while(i<3){
        carguero->turnReady();
        int data = carguero->moveMinerExplorer();
        cout<< "la catidad de mineral insertada es:"<<data<<endl;
        bodega->enqueue(&data , carguero->getName());
        cout<<"se inserto minerales en la bodega"<<endl;
        i++;
    }
}
void Jefe(){//hilo del "lector (el consumidor"
    int i=0;
    Node<int> *cuentasJefe;
    while(i<2){
        this_thread::sleep_for (chrono::seconds(10));
        cuentasJefe = bodega->dequeue();
        cout<<" el jefe revisa la lista y se extrajo"<<cuentasJefe->getData()<<endl;
        i++;
    }
}
int main(){
    thread t1(explorer);
    thread t2(carguero);
    thread t3(topo);
    thread t4(Jefe);
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    /*
    asi se podria meter 
    el hilo con parametros
    Topo miTopo = new Topo( aqui podrian ir parametros);
miTopo.setVelocity(37);
miTopo.setTiming(100);
Thread hilo(miTopo.procesar);
hilo.join();
    */
}