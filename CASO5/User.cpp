#include <iostream>
#include <string>
class User{
    private: 
        string texto;
    public:
        User(string text){
            this->texto = text;
        }
        string getext(){
            return this->texto;
        }
};