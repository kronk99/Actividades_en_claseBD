#include <iostream>
#include "Cola.h"
#include "doorManager.h"
int main(){
    doorManager *constructor = new doorManager();
    constructor->generateDoor(10);
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

