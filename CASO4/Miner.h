#include <iostream>
using namespace std;

class Miner{
    private:
        int cantidadMin;
        int velocidad;
        
    public:
        Miner(int pVelocidad){
            velocidad = pVelocidad;
        }
        void cantminada(int pMinerales){
            cantidadMin = pMinerales;
        }
        int getMinerales(){
            return this->cantidadMin;
        }
};