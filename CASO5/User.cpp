#include <iostream>
#include <string>
#include <cstring>
#ifndef USER 
#define USER 1
using namespace std;
class User{
    private: 
        string texto;
        int numero;
    public:
        User(string text , int number){
            this->texto = text;
            this->numero = number;
        }
        string getext(){
            return this->texto;
        }
        int getNumber(){
            return this->numero ;
        }
        void setnumber(int number){
            this->numero = number;
        }
};
#endif