
#include <string>
#include <iostream>
using namespace std;
int main() {
    /*nota : para mi codigo siempre se debe iniciar con una operacion entre 
    parentesis como los ejemplos de abajo, si no genera error, las operaciones
    despues del primer parentesis pueden ir sin parentesis.
    */
    string a = "(1*(2-3))/(4+5)";
    //vea para este programa la cosa es hacer lo siguiente usar 2 pilas
    /* el primer movimiento inserto en un lado de la lista,
    el segundo insert inserto en la otra lista
    el tercer movmiento , primero muevo el primer elemento al otro lado
    e inserto en la lista que deje vacia
    para el cuarto movimiento muevo el tercer elemento a la siguiente lista , inserto
    el cuarto en la lista vacia, e inserto el 3 de vuelta a la lista anterior.
    y asi sucesivamente , asi se resuelve este problema
    */
}