
#include <string>
#include <iostream>
#include "Carro.cpp"
#include "Cola.cpp"
#include "Pila.cpp"
using namespace std;
int main() {
   Carro *carro1 = new Carro("mazda");
   Carro *carro2 =new Carro("toyota");
   Carro *carro3 = new Carro("ferrari");
   Cola<Carro> *cola = new Cola<Carro>();
   cola->enqueue(carro1);
   cola->enqueue(carro2);
   cola->enqueue(carro3); 
   cola->enqueue(carro2);//aca se genera el bucle
   //cola->enqueue(carro2);
   Carro *actual = cola->primero();
   cout<<actual->getNombre();
   //cola->dequeue();
   //cola->dequeue();
   actual = cola->primero(); 
   cout<<actual->getNombre();



}