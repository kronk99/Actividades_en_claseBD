#include "Pila.h"
#include <string>
#include <iostream>
#include "event.h"
using namespace std;

class Converter{//clase que convierte una operacion infija a postfija
    private: //atributos privados 
        Pila<char> *pSimbolo;
        int largoString;
        int counter;
    public:
        Converter(){ //constructor de la clase converter
            this->pSimbolo = new Pila<char>;
           
        }
        void convert(string operacion){
            largoString = operacion.length();
            for(int i = 0 ;i<largoString; i++){ 
                checkChar(operacion[i] , i); 
                if(checkTop() == true){
                    pSimbolo->Pop(); //hace un pop para quitar a ")"
        
                    while(pSimbolo->getFirst()->getData() != '('){
                        cout<< pSimbolo->getFirst()->getData();
                        pSimbolo->Pop();
                    }
                    pSimbolo->Pop(); //aca es quite "(" de la pila
                    //por que ya inserto los operadores que habian
                    /* este if es por la notacion de la funcion
                    toda operacion debe inicar con un parentesis (
                    pero dentro de la operacion no tiene sentido hacer tipo
                    (1+2)(+)3
                    si no debe ser  (1+2) + 3;
                    */
                    if (i == largoString-1){
                    while(pSimbolo->getSize()!=0){
                        cout<< pSimbolo->getFirst()->getData();
                        pSimbolo->Pop();
                        }
                    }
                }
            }
        }
        bool checkTop(){ //funcion que checkea el top de la pila, si es
        //el parentesis de cierre, devuelve true. 
            if(pSimbolo->getFirst()->getData() !=')'){
                return false;
            }
            else{
                return true;
            }
        }
        /*funcion que checkea si el char es un numero o un operador
        si es numero lo imprime, si no , lo inserta a la pila.
        */
        void checkChar(char letra , int valor){
            switch(letra){ //estos switch se puede hacer en un mismo case.
            /*
                case ('+'||'-'||'*'||'/'||'&'): //este case no esta sirviendo.
                    pSimbolo->Push(letra);
                    resultado[valor] =' '; //caso donde numero tenga 2 cifras o más
                    counter+=1;
                    cout<<"se inserto un simbolo2"<<endl;
                    break;
                    */
                case '+':
                case '-':
                case '*':
                case '/':
                case '&':
                    pSimbolo->Push(letra);
                    cout<< ' '; //caso donde numero tenga 2 cifras o más
                    //se coloca un espacio para separar numeros de 2 cifras 
                    //o mas de los numeros de 1 cifra.
                    counter+=1;
                    break;
                case '(': //estos 2 case evitan tantos espacios en el array
                    pSimbolo->Push(letra);
                    //cout<<"se inserto un simbolo"<<endl;
                    break;
                case ')'://estos 2 case evitan tantos espacios en el array
                    pSimbolo->Push(letra);
                    //cout<<"se inserto un simbolo"<<endl;
                    break;
                default:
                    cout<<letra;
                    counter+=1;
                    //cout<<"se inserto un numero"<<endl;
                    break;
            }     
        }
};