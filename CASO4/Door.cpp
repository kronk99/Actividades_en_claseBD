#include <iostream>
#include "Arbol.cpp"
#include "Camara.cpp"
#ifndef DOOR 
#define DOOR 1
using namespace std;
class Door{
    private:
        int id;
        bool isMainDoor;
        bool hayTunel = false; //de momento no tengo el arbol , entonces es para
        //probar las probailidades
        //Tunel tunel;
        Arbol<Camara> *tuneles;
        bool empty = false;
    public: 
        Door() {
            if (rand()%100<=66) {
                tuneles = new Arbol<Camara>();
                generateTunels();
                hayTunel = true;
            }//TAL VEZ HACE FALTA PONER UN ELSE.
        }
        void generateTunels() {
            int deep = 0;
            while(deep !=750){
                int random =rand()%20; //cantidad de mineral aleatoria.
                if(random+deep <= 750){
                    Camara *newCamara = new Camara(random);
                    tuneles->insertarMineral(newCamara);
                    deep += random;
                }
                else{
                   int limit  = 750-deep;
                   Camara *limitCamara = new Camara(limit);
                   tuneles->insertarMineral(limitCamara);
                   deep += limit;
                }
            }
            cout<<"se termina el ciclo"<<endl;
        }
        int getId(){
            return id;
        }
        void setMaindoor(){
            this->isMainDoor = true;
        }
        void setTunel(){
            this->hayTunel = true;
        }
        void setEmpty(){
            this->empty = true;
        }
        void setId(int number){
            this->id = number;
        }
        bool getTunel(){
            return this->hayTunel;
        }
        Arbol<Camara>* getArbol(){
            return this->tuneles;
        }
};
#endif