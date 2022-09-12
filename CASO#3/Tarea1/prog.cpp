#include "Pila.h"
#include <string>
#include <iostream>
#include "event.h"
#include "Converter.cpp"

using namespace std;

int main() {
    /*nota : para mi codigo siempre se debe iniciar con una operacion entre 
    parentesis como los ejemplos de abajo, si no genera error, las operaciones
    despues del primer parentesis pueden ir sin parentesis.
    */
    string a = "(1*(2-3))/(4+5)";
    Converter *convertir = new Converter();
    convertir->convert(a);
    Converter *convertir2 = new Converter();
}