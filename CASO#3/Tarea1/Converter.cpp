#include "Pila.h"
#include <string>
#include <iostream>
#include "event.h"
class Converter{//clase que convierte una operacion infija a postfija
    private: //atributos privados 
        Pila<char> *plistaNum;
        Pila<char> *pSimbolo;
        char *resultado;
        string aConvertir;
        int largoString;
    public:
        Converter(string operacion){ //constructor de la clase converter
            this->pSimbolo = new Pila<char>;
            this->plistaNum = new Pila<char>;
            //this->aConvertir = operacion;
        }
        void convert(string operacion){//funcion que va a "armar" el resultado
            resultado = new char[operacion.length()];
            largoString = operacion.length();
            for(int i = 0 ;largoString ; i++){
                checkChar(operacion[i] , i); /*
                checkea si el valor es operador o numero y lo inserta en la pila*/
                if(checkTop() == true){
                    
                }
            }
        }
        bool checkTop(){ //funcion que checkea el codigo 

        }
        void checkChar(char letra , int valor){
            switch(letra){
                case '+':
                   pSimbolo->Push(letra);
                   break;
                case '-':
                   pSimbolo->Push(letra);
                   break;
                case '*':
                   pSimbolo->Push(letra);
                   break;
                case '/':
                   pSimbolo->Push(letra);
                   break;
                case '&':
                   pSimbolo->Push(letra);
                   break;
                case '(':
                   pSimbolo->Push(letra);
                   break;
                case ')':
                   pSimbolo->Push(letra);
                   break;
                default :
                    resultado[valor] =letra; 
            }     
        }
};