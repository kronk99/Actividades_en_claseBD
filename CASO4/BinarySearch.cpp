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
secuencial.*/