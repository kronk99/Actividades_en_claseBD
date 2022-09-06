#include "Pila.h"
#include <string>
#include <iostream>
#include "event.h"

using namespace std;

int main() {
    Pila<Event>* listA = new Pila<Event>();
    Pila<string>* listB = new Pila<string>();

    Event *unEvento = new Event("Concierto Coldplay", "ITCR", "ASODEC");
    Event *otroEvento = new Event("Charla de Bill Gates", "ITCR", "ASODEC");
    Event *otroEvento2 = new Event("Evento del final", "ITCR", "ASODEC");
    listA->Push(unEvento);
    listA->Push(otroEvento);
    listA->Push(otroEvento2);
    Event *eventoAc = listA->Top();
    cout<<"el evento es : " <<eventoAc->getTitle() <<endl;
    listA->Pop();
    eventoAc = listA->Top();
    cout<< "el evento es:" <<eventoAc->getTitle() <<endl;
    listA->isEmpty();


}