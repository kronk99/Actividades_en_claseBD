//#include "Node.h"
#include "Nodes.h"
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include<stdio.h>
#include "Camara.cpp"

using namespace std;

#ifndef ARBOL 

#define ARBOL 1

template <class T>

class Arbol{
    private:
        Nodes<T> *arbol; //es como un current ,tiene un previus y un next
        Nodes<T> *derecha; //tiene un previus derecha debe ser igual a next de x nodo
        Nodes<T> *izquierda; //debe ser el previus de y nodo
        //OCUPO UN POINTER A LA RAIZ POR LO QUE SE DEBE DE TENER
        //UN SETRAIZ Y UN GETRAIZ PARA QUE EL MINERO PUEDA ENTRAR A LA ESTRUCTURA.
        Nodes<T> *Raiz;
    public:
        Arbol(){
            arbol = NULL;
            derecha = NULL;
            izquierda = NULL; 
            Raiz = NULL;  
        }
        Nodes<T>* crearNode(T *pCamara){
             
            Nodes<T> *nodo = new Nodes<T>(pCamara);//aca debe de ser la camara 
            nodo->setNext(derecha);
            nodo->setPrevius(izquierda);
            return nodo;
        }//hasta aca esta bien el codigo
        void insertarMineral(T *pCamara){ 
            insertarNodo(this->arbol, pCamara ,0);
        }//acap paso el arbol y el mineral

        void mostarArbol(){
            int contador = 0;
            mostrarArbolAux(this->arbol, contador);
        }
        //TODO THIS->ARBOL DEBE SER REEMPLAZADO CON UN THIS->GETARBOL*********
        //************
        /*EL MINERO DEBE TENER UN CONTADOR TIPO INT DE CUANTO BAJA, CUANDO
        EL MINERO sube se le va restando a ese contador lo que el minero se mueve*/
        //QUITE EL &DE pArbol
        void insertarNodo(Nodes<T>  *pArbol, T *pCamara , int path){
            if(pArbol==NULL){//arbol vacio
                if(this->Raiz != NULL){
                    Nodes<T>  *nuevo_nodo = crearNode(pCamara); //aca crea el nodo
                    switch (path){
                    case 1:
                        this->arbol->setPrevius(nuevo_nodo);
                        break;
                    case 2:
                        this->arbol->setNext(nuevo_nodo);
                        break;
                    
                    default:
                        break;
                    }
                    this->arbol = nuevo_nodo;//Nodo raiz 
                }
                else{
                    Nodes<T>  *nuevo_nodo = crearNode(pCamara); //aca crea el nodo
                    this->arbol = nuevo_nodo;//Nodo raiz 
                    this->Raiz = nuevo_nodo;
                }
            }//crea la raiz
	        else{//el arbol ya tiene un nodo o mas
                if(busqueda(this->arbol, pCamara) == false){ //ARREGLAR EL BUSQUEDA.
                    Camara *valorRaiz = pArbol->getData(); //obtenemos el valor de la raiz
                    //cout << "El valor raiz es: "<< valorRaiz << " < " << n << endl;
                    if( pCamara->getPotencialMinado() < valorRaiz->getPotencialMinado()){//va al lado izquierdo pues es menor a la raiz
                        //cout <<"Se inserto por la izquierda: "<< pCamara->getPotencialMinado() << endl;
                        
                        insertarNodo(pArbol->getPrevius(),pCamara,1);//reemplazar esto sin recursividad
                    }
                    else{//Elemento es mayor a la raiz, se inserta en el lado derecho
                        //cout <<"Se inserto por la derecha: " << pCamara->getPotencialMinado()<< endl;
                        insertarNodo(pArbol->getNext(),pCamara,2);//reemplazar esto sin recursividad
                    }
                }
                else
                    cout <<"\nEl Dato ingresado ya existe" << endl;
	        }
        }

        bool busqueda(Nodes<T>  *pArbol,T *pCamara){
            //cout <<"ENTRO A LA BUSQUEDA" << endl;
            if(pArbol == NULL){//si el arbol esta vacio
                return false;
            }
            else if(pArbol->getData()->getPotencialMinado() == pCamara->getPotencialMinado()){//si el nodo es igual al elemento buscado
                return true;
            }
            else if(pCamara->getPotencialMinado() < pArbol->getData()->getPotencialMinado()){
                return busqueda(pArbol->getPrevius(),pCamara);
            }
            else{ // n>arbol->dato
                return busqueda(pArbol->getNext(),pCamara);
            }
        }

        void mostrarArbolAux(Nodes<T>  *arbol, int cont){//contador ayuda a separar un nodo del otro
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
        void setRaiz(T *pRaiz){
            this->Raiz = pRaiz;
        }
        Nodes<T> *getRaiz(){
            return this->Raiz;
        }
};
/*int main(){
    Arbol<Camara> *arbolito = new Arbol<Camara>(); 
    for(int i = 0 ; i<8 ;i++){ 
        Camara *newCamara = new Camara(rand()%20); 
        arbolito->insertarMineral(newCamara); 
    } 
    Nodes<Camara> *current = arbolito->getRaiz();
    cout<<"el nodo siguiente derecha es:"<<current->getNext()->getData()->getCantMineral()<<endl;
    cout<<"el nodo siguiente izquierda es:"<<current->getPrevius()->getData()->getCantMineral()<<endl;
}*/

#endif 