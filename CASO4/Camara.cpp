#include <iostream>
#ifndef CAMARA
#define CAMARA 1
class Camara{
    private:
        int cantidadMineral;
        int distancia;
    public:
        Camara(int minerales){
            this->cantidadMineral = minerales;
            this->distancia = rand()%80;
        }
        int getCantMineral(){
            return this->cantidadMineral;
        }
        int getDistancia(){
            return this->distancia;
        }
        int getPotencialMinado(){
            return cantidadMineral * distancia;
        }
};
#endif