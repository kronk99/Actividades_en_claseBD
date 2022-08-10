//Estructuras de datos grupo #3
//Elaborado por Kenneth Rojas y Luis Gonzalez
//Ultima modificación 04/08/2022

#include <iostream>
using namespace std;

int main()
{
    //---------------------Operaciones con números en octal y hexadecimal------------------

    int numHex = 0x4E;          //78 en decimal
    int numOct = 0105;          //69 en decimal
    int numDec = 138;            
    //----------------------operaciones--------------------------
    int operacion = numDec + numOct;      //82 + 69 = 207
    int operacion1 = numHex * numOct;     //78 * 69 = 35382
    int operacion2 = numDec / numOct  ;   //138 / 69 = 2
    
    //Se concatenan y muestran los valores por pantalla con cout<<
    cout << "Resultado de la operación 1: " << operacion << "\n";
    cout << "Resultado de la operación 2: " << operacion1 << "\n";
    cout << "Resultado de la operación 3: " << operacion2 << "\n";

    //---------------------Uso_del_#define-------------------------
    #define palabra "una casa"
    #define palabra2 "un camión"
    #define palabra3 "una bola verde"
    #define palabra4 "café"
    //----------------------Impresion de las frases----------------
    cout << "\nEn " << palabra << " tengo " << palabra2 << " " <<palabra4 <<  " y " << palabra3 << "\n";
    cout << "En " << palabra2 << " tengo " << palabra3 <<  " y una " << palabra << " " << palabra4 << "\n";
    cout << "En " << palabra3 << " tengo " << palabra2 << " " << palabra4 <<  " y " << palabra << "\n";

    return 0;
}