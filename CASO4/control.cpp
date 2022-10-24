#include <iostream>
#include "Cola.h"
#include "doorManager.h"
#include <chrono>
#include <thread>
#include "Miner.cpp"
#include <mutex>
#include <thread>
#include <chrono>
#include <stdlib.h>
#include "Colaint.cpp"
#include "flag.cpp"
doorManager *constructor = new doorManager();
Colaint<int> *bodega = new Colaint<int>();
Flag *flag = new Flag();
void moveminer(){
    Nodo<Door> *entrada = constructor->getEntrada();
    Miner *minero = new Miner(20 ,"explorador", 8, entrada , 8 , bodega , flag );
    minero->buildPath();
}
void moveminer2(){
    Nodo<Door> *entrada = constructor->getEntrada();
    Miner *minero = new Miner(10 ,"carguero", 40 , entrada , 8 , bodega , flag );
    minero->buildPath();
}
void Jefe(){//hilo del "lector (el consumidor"
    int i=0;
    int cuentasJefe;
    int cantExtraida;
    while(flag->getFlag()==true){
        this_thread::sleep_for (chrono::seconds(10));
        cantExtraida = bodega->dequeue();
        cuentasJefe+=cantExtraida;
        cout<<" el jefe revisa la lista y se extrajo"<<cantExtraida<<endl;
        i++;
    }
    cout<<"se extrajo en total:"<<cuentasJefe<<endl;
}
void reloj(){
    int segundos = 0;
    int minutos = 0;
    while(minutos != 2){
        if(segundos%10 == 0){
            cout << "0" << minutos << ":" << segundos << endl;
        }
        this_thread::sleep_for (std::chrono::seconds(1));
        segundos++;
        if(segundos == 60){
            minutos++;
            segundos = 0;
        }
    }
    flag->setFlagFalse();
}
int main(){
    //doorManager *constructor = new doorManager();
    constructor->generateDoor(8);
    //Nodo<Door> *entrada = constructor->getEntrada(); 
    //Miner *minero = new Miner(20 ,"pepe", 10 , entrada , 8 );
    //minero->buildPath();
    thread t1(moveminer);
    thread t2(moveminer2);
    thread t3(Jefe);
    thread t4(reloj);
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    //entrada = entrada->getNodo(2);
    //entrada=entrada->getNodo(1);
    //cout<<"coloque la puerta en una variable tipo puerta"<<endl;
    //cout<<"la puerta  el id:" << entrada->getDoor()->getId();
    //ESTA ES UNA CLASE PARA PROBAR LAS LISTAS Y SU CORRECTO FUNCIONAMIENTO
    /*
    Cola<int> *cola = new Cola<int>();
    int a = 3;
    cola->enqueue(&a , "pepito");
    cola->enqueue(&a , "marcela");
    cola->enqueue(&a , "rebeca");
    cola->enqueue(&a , "pedro");
    cout<< "el nombre es:  "<< cola->dequeue()->getNombre()<<endl;//da pepito y lo elimina
    cout<< "el nombre es 2:   "<<cola->dequeue()->getNombre()<<endl; //da marcela y elimina
    cout<< "el nombre es 3:  "<<cola->dequeue()->getNombre()<<endl; //da rebeca y la elimina
    cout<< "el nombre es 4:  "<<cola->dequeue()->getNombre()<<endl; //da pedro y lo elimina
    cout<< "el nombre es: 5   "<<cola->dequeue()->getNombre()<<endl; //debe de tirarme un mensaje
    cola->enqueue(&a , "cloe");
    cout<< "el nombre es: 6  "<<cola->dequeue()->getNombre()<<endl; //debe de tirarme un mensaje
    cola->enqueue(&a , "bananos");
    cola->enqueue(&a , "papas");
    cout<< "el nombre es: 6  "<<cola->dequeue()->getNombre()<<endl; //debe tirar bananos
*/
}

