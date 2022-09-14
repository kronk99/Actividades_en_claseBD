#include <iostream>
#include <string>
#ifndef CARRO 
#define CARRO 1
using namespace std;
class Carro{
    private:
        string nombreCarro;
    public:
        Carro(string name){
            nombreCarro = name;
        }
        void SetNombre(string name){
            nombreCarro = name;
        }
        string getNombre(){
            return nombreCarro;
        }
};
#endif