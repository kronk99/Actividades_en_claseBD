#include <iostream>
#include <string>
#include <ctime>

using namespace std;

// Quiz #6
// 1. Utilizando esta classe agregue los atributos del vuelo: aerolinea, numero de vuelo, cantidad de pasajeros
// 2. Complete el constructor de la clase, de tal forma que se pueda modificar el flightTime para una hora y minutos específicos
// 3. Implementar alguna forma de convertir el time a un número entero de tal forma que entre menor la hora menor el número, eso en getIntTimeValue()
// 4. En el test.cpp, implementar la función fillFlights()
// fecha de entrega: jueves 8 de setiembre antes de las 10pm
// entrega al asistente al correo: kevinqj.2002@gmail.com
// subject: estructuras de datos - quiz #6
// adjuntan el archivo test.cpp y Flight.h

class Flight {

    private: 
        time_t flightTime; //creo que es parte de la funcion
        string aerolinea;
        int numVuelo;
        int cantPasajeros;
        time_t timer; //adicional
        tm *currentTime; //current time lo pase aca en los atributos privados

    public: 
        Flight(int pHour, int pMinutes) {
            timer = ((pHour)*60 + pMinutes)*60;
            cout<<"el tiempo es aa" << timer << endl;
            flightTime = time(NULL); //time solo acepta segundos
            currentTime = localtime(&flightTime); //no se que hace
            timer = (currentTime->tm_hour) *60*60 + currentTime->tm_min * 60 + currentTime->tm_sec;
            cout<<timer<<endl;
            flightTime = (flightTime - timer) +((pHour)*60 + pMinutes)*60;
            currentTime = localtime(&flightTime);

        }

        char* flightTimeString() {
            char* result = ctime(&flightTime); //ctime retona fecha leible
            return result;
        }
        void printTime(){
            cout<<"la hora es:"<<currentTime->tm_sec  <<endl;
        }

        double getIntTimeValue() {
            double result = currentTime->tm_hour + (currentTime->tm_min)/100;
            return result;

        }
        //lo otro que podria hacer es que fileflight pase a segundos
};
