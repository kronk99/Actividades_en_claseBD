#include <iostream>
#include <string>
#include "listaAcciones.cpp"
#include  "listaParametros.cpp"
using namespace std; //esto permite usar strings
#ifndef DISPOSITIVO
#define DISPOSITIVO 0
class Dispositivo{
    private:
        string estado;
        string tipo;
        listaAcciones *acciones;
        listaParametros *parametros;
    public:
        Dispositivo(string nombre , string tipo ){
            estado = nombre;
            tipo = tipo;
            } //constructor de la clase
        string getestado(){
            return this->estado;
            printf("el estado es %s" , estado.c_str());
        }
        void setestado(string hola){
            estado = hola;
        }
        void getTipo(){
            printf("el tipo de dispositivo es %s" , tipo.c_str());
        }
        void añadirAccion(string accion){
            if(acciones != nullptr){
            acciones->insertFirst(accion);
            }
            else{
                acciones = new listaAcciones();
            }
        }
        void getAcciones(){
            acciones->read();
        }
        void añadirParametro(string parametro){
            if(parametros != nullptr){
            parametros->insertFirst(parametro);
            }
            else{
                parametros = new listaParametros();
            }
        }
        void getParametros(){
            parametros->read();
        }

};
#endif