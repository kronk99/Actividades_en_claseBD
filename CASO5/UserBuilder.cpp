#include <iostream>
#include <string>
#include <cstring>
#include <list>
#include "User.cpp"
using namespace std;
template <class T>
class UserBuilder{
    //ok del constructor de palabras agarreme todas las palabras y metalas en una lista
    //luego esas palabras llame al metodo buildUser y recorrala, a medida que la recorre 
    /*cree usuarios con el método build user, luego llame al metodo build tree 
    que este metodo llama al hashtable para verificar si la palabra esta o no esta
    if de si no esta retorna 0 y si si esta retorna el numero que ya existe y lo modifica
    al usuario, luego con dicho numero inserta en el arbol con el numero y el usuario*/
    private:
        list<User> listaUsuario; //esto puede estar mal 
    public: //t es una lista de strings
        UserBuilder(list<string> listapalabras  , int size){
            //esto en teoria ya esta
            int i=1;
             //aca le metemos en el indice de la tabla
            auto iteracion = listapalabras.begin();
            for(iteracion;iteracion !=listapalabras.end();iteracion++){
                //User *newUser = new User(*iteracion , i , nombreusuario);
                cout<<"el dato es:"<<*iteracion<<endl;
                //cout<<"el usuario es:"<<newUser->getNumber()<<endl;
                listaUsuario.emplace_back(*iteracion , i);
                //creo que esto no es necesario, creo que simplemente meto 
                i++;
            }
            auto iteraciones = listaUsuario.begin();
            for(iteraciones;iteraciones !=listaUsuario.end();iteraciones++){
                cout<<"el dato es:"<<iteraciones->getNumber()<<endl;
            }
        }//lista personas debe de tener una variable 
        //lista personas va a ser la lista de las personas random con el usuario que se
        //haga el login.
        void treeForUser(listapersonas , hashtable, int personas){ //se deben de hacer 2 de estos arboles
        //uno para los primeros 5 como demanda y el otro como los primeros 5 para oferta
        //el otro arbol hace lo inverso, los primeros 5 como oferta y los otros como demanda.
        //segun la descripcion , 
        //PARA ANÁLISIS INDIVIDUAL*******
        //agarro 1 como oferta y el resto como demanda, luego hago la pasada
        //inversa agarro 1 como demanda y los demas como oferta , el total de personas que 
        //agarra el algoritmo debe de ser aleatorio. por lo tanto al hacer login
        //debe de insertar el usuario que se le pidio ingresar como el primer elemento
        //de esta lista.
        int counter=1; //contador que le va a agregar la letra al hashtable
        if(usuarioinsertado->getfirst->haydemanda==True){
            for(i=0 ; usuarioinsertado->getfirst->getlistdemanda->getsize(); i++){
                string palabra = usuarioinsertado->getfirst->getlistaletras(i)
                hashing(palabra , numero);
                i++
            }
            crear b+ oferta()

        }
        if usuario demanda{   

        }
    }
};
int main(){
    list<string> listas;
    listas.push_back("hola");
    listas.push_back("como");
    listas.push_back("estas");
    UserBuilder<list<string>> usuarios = UserBuilder<list<string>>(listas ,3);
}