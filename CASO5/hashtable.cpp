#include <iostream>
#include <list>
#include <cstring>
#include "User.cpp"
using namespace std;
//template <class T>
class hashtable{
    private:
        static const int hashgroups = 10; //esto modificarlo despues a una plantilla de constante
        list<pair<int, string /*, T* valor*/>> table[hashgroups]; //verificar esto despues, esto 
        //es la hashtable , el T es para probar si le puedo meter el pointer al usuario
        //que imagino que voy a requerir agarrar el nombre, el string aca es para la palabra.
        //puesto que es una lista de usuarios no users , va a almacenar usuarios.
        public:
            bool isEmpty(){
                
                int suma;
                for(int i=0;i<hashgroups;i++){
                    suma+=table[i].size();
                }
                if (!suma){
                    return true;
                }
                return false;
            }
            int hashfunction(int key){ //se le mete un int y tira la palabra
                return key % hashgroups; //si la llave es 105, regresa 5 , aca puedo
                //hacer lo que dijo el profe de tirar randoms.
            }
            void insertItem(int key , string value /*, T* valor*/){ //el key cambiarlo luego 
                int hashvalue = hashfunction(key);
                auto& cell = table[hashvalue]; //aca le metemos en el indice de la tabla
                auto iterador = begin(cell); //iterador al inicio de la lista
                bool keyexist=false; //necesitamos validar si la llave dentro del hashtable
                //no esta vacia. ,se da el beneficio de la duda de que este vacia.
                for(;iterador !=end(cell);iterador++){
                    if(iterador->first==key){
                        keyexist = true;
                        iterador->second = value;
                        cout<<"CUIDADO ,LA LLAVE HA SIDO REEMPLAZADA"<<endl;
                        break;
                    }
                }
                if(!keyexist){
                    cell.emplace_back(key , value);
                }
                return;
            }
            void removeItem(int key){
                int hashvalue = hashfunction(key);
                auto& cell = table[hashvalue]; //aca le metemos en el indice de la tabla
                auto iterador = begin(cell); //iterador al inicio de la lista
                bool keyexist=false; //necesitamos validar si la llave dentro del hashtable
                //no esta vacia. ,se da el beneficio de la duda de que este vacia.
                for(;iterador != end(cell);iterador++){
                    if(iterador->first==key){
                        keyexist = true;
                        iterador = cell.erase(iterador); //osea el eliminar
                        //de la lista retorna un iterador nuevo, es decir si el iterador
                        //estaba en la posicion 2, regresa uno en la 3
                        cout<<"INFO ,LA LLAVE HA SIDO ELIMINADA"<<endl;
                        break;
                    }
                }
                if(keyexist==false){ //si el item no fue removido
                    cout<<"LLAVE NO ENCONTRADA"<<endl;
                }
                return;

            }
            string searchItem(int key){
                return "no function";
            }
            void printTable(){
                for(int i=0;i<hashgroups;i++){
                    if(table[i].size()==0){
                        //si la lista en la posicion i del array es 0, salimos de ahi
                        continue;
                    }
                    auto iterador = table[i].begin();
                    for (; iterador !=table[i].end(); iterador++){
                        cout<< "INFOR, LA LLAVE ES: Hash:"<<i<<"iterador:"<<iterador->first<<"con el valor"<<iterador->second<<endl; 
                    }//esto de iterador first y iterador second creo que llama a los atribudos declarados
                    //al declarar la lista
                }
                return;
            }

        //entonces para acceder a la lista 1 se escoge el indice 0, la lista 2 indice 1 
        //del array
};
int main(){
    hashtable las;
    las.insertItem(234 , "hola");
    las.insertItem(209 , "vendo");
    las.insertItem(2120 , "empanadas");
    las.insertItem(2341 , "de carne");
    las.insertItem(1387 , "y frijol");
    las.insertItem(1597 , "caldo");
    las.printTable();
    las.removeItem(234);
    las.printTable();
    cout<<"lo que pasa al dividir numero modulo 20"<<5013%10<<endl;
    return 0;
    //ahora lo que ocupo hacer es una funcion que vaya insertando en el arbol, esto puede
    //ser un ciclo for , del 0 al 9 , entonces en 0 vaya al hash, recorra la lista, get
    //first , get second -> insertbree
    //tambien necesito una forma de insertar en el btree todas las palabras, por lo tanto
    /*primero debo de insertar todas las palabras de las digamos 5 personas */
}