#include <iostream>

#ifndef FLAG 
#define FLAG 1

class Flag{
    private:
        bool bandera;

    public:
        Flag(){
            this->bandera = true;
        }
        void setFlagFalse(){
            this->bandera = false;
        }
        void setFlagTrue(){
            this->bandera = true;
        }
        bool getFlag(){
            return this->bandera;
        }
};

#endif 