#include "Flight.h"
#include "List.h"


// debe llenar una lista de pCantidad vuelos aleatorios cuya hora y minutos de partida esten entre pStartHour y pEndHour
// tomando en cuenta las restricciones de los minutos de salida segun el ejercicio 3 del caso #3
//NOTA PERSONAL , el codigo es una base, no es el mejor codigo pero es como 
//se pudo hacer en el poco tiempo que me quedaba.
void fillFlights(int pCantidad, int pStartHour, int pEndHour) {
    int minutos = 0;
    int horas = 0;
    List<Flight> *pVuelos = new List<Flight>();
    for(int cantVuelos= 0 ; pCantidad ;cantVuelos++){
        if(minutos < 60 && pStartHour+horas <pEndHour ){
        Flight vuelo(pStartHour , minutos , "lumaca" , 2 ,150);
        pVuelos->add(&vuelo); 
        minutos+=17;
        }
        else{
            horas+=1;
            minutos = 0;
            Flight vuelo(pStartHour , minutos , "lumaca" , 2 , 150);
            pVuelos->add(&vuelo); 
            minutos+=17;
        }
    }
} 


int main() {
    Flight vuelo(4,35 ,"lumaca" , 2 , 150);
    cout << vuelo.flightTimeString() << "y el entero es: " << vuelo.getIntTimeValue() << endl;

    Flight otroVuelo(14,20,"lumaca" , 2 , 150);
    //vuelo.printTime();
    cout << otroVuelo.flightTimeString() << "y el entero es: " << otroVuelo.getIntTimeValue() << endl;

}

//ocupo sacar el time a las 00 horas.