//#include "List.h"
#include <string>
#include <iostream>
#include "event.h"
#include "Lista.h"

using namespace std;

int main() {
    /*
    List<Event>* listA = new List<Event>();
    List<string>* listB = new List<string>();

    Event *unEvento = new Event("Concierto Coldplay", "ITCR", "ASODEC");
    Event *otroEvento = new Event("Charla de Bill Gates", "ITCR", "ASODEC");
    Event *otroEvento2 = new Event("Evento del final", "ITCR", "ASODEC");

    listA->insert(0, otroEvento2);
    listA->insert(0, otroEvento);
    listA->add(unEvento);

    listB->insert(0, new string("Un mensaje de prueba1"));
    listB->insert(1, new string("segundo mensaje de prueba"));
    listB->add(new string("tercer mensaje de prueba"));

    for(int i=0; i<listA->getSize(); i++) {
        Event *currentEvent = listA->find(i);
        cout << currentEvent->getTitle() << endl;
    }

    cout << "==================================" << endl;
    for(int i=0; i<listB->getSize(); i++) {
        string *currentmsg = listB->find(i);
        cout << *currentmsg << endl;
    }
    */
    List<Event>* listA = new List<Event>();
    Event *unEvento = new Event("Concierto Coldplay", "ITCR", "ASODEC");
    Event *otroEvento = new Event("Charla de Bill Gates", "ITCR", "ASODEC");
    Event *otroEvento2 = new Event("Evento del final", "ITCR", "ASODEC");
    listA->add(unEvento);
    listA->add(otroEvento);
    listA->add(otroEvento2);
    for(int i=0; i<listA->getSize(); i++) {
        Node<Event> *currentEvent = listA->find(i);
        Event *e = currentEvent->getData();
        cout << e->getTitle() << endl;
    }
    listA->remove(2);
    for(int i=0; i<listA->getSize(); i++) {
    Node<Event> *currentEvent = listA->find(i);
    Event *e = currentEvent->getData();
    cout << e->getTitle() << endl;
    }




}