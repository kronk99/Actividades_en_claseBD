#include "Pila.h"
#include <string>
#include <iostream>
#include "event.h"
class Converter{
    private:
        Pila<char> *plistaNum;
        Pila<char> *pSimbolo;
        char *resultado;
        string aConvertir;
        int largoString;
    public:
        Converter(string operacion){
            this->pSimbolo = new Pila<char>;
            this->plistaNum = new Pila<char>;
            this->aConvertir = operacion;
        }
        void convert(string operacion){
            resultado = new char[operacion.length()];
            largoString = operacion.length();
            for(int i = 0 ;largoString ; i++){
                checkChar(operacion[i] , i);
                insert(); alo

            }
        }
        bool checkTop(){ //para que esto funcione si o si debo modificar la lista.
            char valor = pSimbolo->getFirst() 
            if( == '+'||'-' ||'*'||'/'||'&'||'('||')'){

            }
        }
        void checkChar(char letra , int valor){
            switch(letra){
                case '+':
                   pSimbolo->Push(&letra);
                   break;
                case '-':
                   pSimbolo->Push(&letra);
                   break;
                case '*':
                   pSimbolo->Push(&letra);
                   break;
                case '/':
                   pSimbolo->Push(&letra);
                   break;
                case '&':
                   pSimbolo->Push(&letra);
                   break;
                case '(':
                   pSimbolo->Push(&letra);
                   break;
                case ')':
                   pSimbolo->Push(&letra);
                   break;
                default :
                    resultado[valor] =letra; 
            }     

        }
};