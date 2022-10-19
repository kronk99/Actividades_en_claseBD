/*
#include <iostream>
#include "Nodes.h"
#include "Pila.h"
#include "Door.cpp"
#ifndef SEARCH
#define SEARCH
using namespace std;
template <class T>
class BinarySearch{
    private:
        Nodo<Door> *midNode; //este nodo no es igual al datatype de pila, ojito
        Pila<T> *mapa;
        int pilaLenght = 0;
        Nodo<Door> *first;
        Nodo<Door> *last;
    public:
        BinarySearch(Pila<T> *pila){
            this->mapa = pila;
            midNode = pila->Peak();
        }
        bool search(Nodo<Door> *NodetoSearch){
            if (NodetoSearch->getData()->getDoor()->getId() !=

        }
        void IncreaseMidnode(){

        }

};
/*pese a que estoy haciendo un binary search , bien podria hacer busqueda
secuencial, ya que el mae se estaria metiendo y como se acomoda de mayor a menor
entre más adentro en la mina esté más rapido es la busqueda secuencial. por lo que creo que
el binary search no es necesario, intentar hacerlo con busqueda seuencial a ver que sucede
y si lo ejecuta bien , ademas el minero va a hacer un random de 1 a 5 , de 1 a 4
se mete en alguna de esas puertas, y si es 5 , checkea a ver si esta la puerta */