#include "Node.h"
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include<stdio.h>

using namespace std;

#ifndef ARBOL 

#define ARBOL 1

template <class T>

class Arbol{
    private:
        Node<T> *arbol; //es como un current ,tiene un previus y un next
        Node<T> *derecha; //tiene un previus derecha debe ser igual a next de x nodo
        Node<T> *izquierda; //debe ser el previus de y nodo
    public:
        Arbol(){
            arbol = NULL;
            derecha = NULL;
            izquierda = NULL;   
        }
        
        Node<T>* crearNode(int n){
            Node<T> *nodo = new Node<T>(n);
            nodo->setNext(derecha);
            nodo->setPrev(izquierda);
            return nodo;
        }//hasta aca esta bien el codigo
        void insertarMineral(int n){
            insertarNodo(this->arbol, n);//ESTO GENERA EL ERROR
        }//acap paso el arbol y el mineral

        void mostarArbol(){
            int contador = 0;
            mostrarArbolAux(this->arbol, contador);
        }
                        //QUITE EL &DE pArbol
        void insertarNodo(Node<T>  *pArbol, int n){
            if(pArbol==NULL){//arbol vacio
                Node<T>  *nuevo_nodo = crearNode(n);
                this->arbol = nuevo_nodo;//Nodo raiz
            }//crea la raiz
	        else{//el arbol ya tiene un nodo o mas
                if(busqueda(this->arbol, n) == false){
                    int valorRaiz = pArbol->getData(); //obtenemos el valor de la raiz
                    //cout << "El valor raiz es: "<< valorRaiz << " < " << n << endl;
                    if( n < valorRaiz){//va al lado izquierdo pues es menor a la raiz
                        cout <<"Se insertó por la izquierda: "<< n << endl;
                        insertarNodo(pArbol->getPrev(),n);//reemplazar esto sin recursividad
                    }
                    else{//Elemento es mayor a la raiz, se inserta en el lado derecho
                        cout <<"Se inserto por la derecha: " << n << endl;
                        insertarNodo(pArbol->getNext(),n);//reemplazar esto sin recursividad
                    }
                }
                else
                    cout <<"\nEl Dato ingresado ya existe" << endl;
	        }
        }

        bool busqueda(Node<T>  *pArbol,int n){
            //cout <<"ENTRO A LA BUSQUEDA" << endl;
            if(pArbol == NULL){//si el arbol esta vacio
                return false;
            }
            else if(pArbol->getData() == n){//si el nodo es igual al elemento buscado
                return true;
            }
            else if(n < pArbol->getData()){
                return busqueda(pArbol->getPrev(),n);
            }
            else{ // n>arbol->dato
                return busqueda(pArbol->getNext(),n);
            }
}

        void mostrarArbolAux(Node<T>  *arbol, int cont){//contador ayuda a separar un nodo del otro
            //cout <<"Entro a la busqueda" << endl;
            if(arbol == NULL){
                //cout <<"Entro al primer if de busqueda" << endl;
                return;
            }
            else{
                //cout <<"Entro al else de busqueda" << endl;
                mostrarArbolAux(arbol->getNext(),cont+1);
                int i;
                for(i=0; i<cont; i++){
                    cout << "   "<< endl;
                }
                cout << arbol->getData() << endl;
                mostrarArbolAux(arbol->getPrev(),cont+1);
            }
        }
};



int main(){
    

    Arbol<int> *arbolito = new Arbol<int>();
    arbolito->insertarMineral(50);
    arbolito->insertarMineral(100);
    arbolito->insertarMineral(25);
    arbolito->insertarMineral(5);
    arbolito->insertarMineral(150);
    arbolito->insertarMineral(10000);
    arbolito->insertarMineral(0);
    arbolito->mostarArbol();
}

#endif 