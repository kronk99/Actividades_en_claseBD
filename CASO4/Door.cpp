#include <iostream>
#ifndef DOOR 
#define DOOR 1
using namespace std;
class Door{
    private:
        int id;
        bool isMainDoor;
        bool tunel = false; //de momento no tengo el arbol , entonces es para
        //probar las probailidades
        //Tunel tunel;
        bool empty = false;
    public: 
        Door() {
            if (rand()%100<=66) {
                //tunel = new AVLTree();
                //generateTunels();
                tunel = true;
            }
        }

        void generateTunels() {
        }
        int getId(){
            return id;
        }
        void setMaindoor(){
            this->isMainDoor = true;
        }
        void setEmpty(){
            empty = true;
        }
};
#endif