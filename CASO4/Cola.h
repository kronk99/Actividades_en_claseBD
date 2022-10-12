#include "Nodes.h"
#include "Door.cpp"
#include "Nodo.cpp"
#ifndef COLA 

#define COLA 1

// 2. ajustar a que esta lista sea doblemente enlazada, cambia el add, find, insert y el remove
template <typename T> 
class Cola  {
    private:
        Nodes<T> *first;
        Nodes<T> *Empty;
        int size;
        Nodes<T> *last;
    public:
        Cola() {
            first = NULL;
            last = NULL;
            Door *emptyDoor = new Door;
            Nodo<Door> *empty = new Nodo<Door>();
            emptyDoor->setEmpty();
            Empty = new Nodes<T>(empty); //el empty no sirve arreglar esto
        }
        //direccion puedo utilizarlo como indice del array
        void enqueue(T *pData) { //hay que modificar el add para que añada a cada
        //nodo otro nodo con las probalilidades.
            Nodes<T> *newNode = new Nodes<T>(pData);
            if (size>0) {
                this->last->setNext(newNode);
                this->last = newNode;
                
                size++;
            }
            else {
                this->first = newNode;
                this->last = newNode;
                size++;

            }
            //size++;
        }
        Nodes<T>* dequeue() { //tal vez hacer un codicional si el first no es nulo.
            if(size >=1){
            /*esta condicional la meti aca y no en el pop por que al reali<ar
            pruebas, al intentar eliminar un elemento vacio y siplemente imprimir
            "la lista esta vacia" y luego volver a intenar insertar, el codigo
            no me inserta, pero si inserto esta condicional aca, el codigo si puede 
            borrar y eliminar varias veces.*/
                Nodes<T> *result= this->first;
                Pop();
                return result;
            }
            else{
                cout<<"la lista esta vacia"<<endl;
                return Empty; //este return null me daña el programa
                //entonces retorna un nodo llamado Empty que tiene un objeto puerta
                //que indica "vacio" , ese vacio es condicion a la hora de verificar 
                //la cola de datos.
            }
        }
        int getSize() {
            return size;
        }
        bool isEmpty() {
            return !size;
        }
        void Pop(){
            if(size >1){
                
                Nodes<T> *current = first;
                first = current->getNext(); 
                current->setNext(NULL); 
                size-=1;
            }
            else if(size==1){
                first = NULL;
                last = NULL;
                size-=1;
                cout<<"el size es :"<<size<<endl;
            }
        }
        // si el position es mayor a la cantidad, entonces inserto al final
        //creo que el search debe de decirme, en que cuadrante (0,1,2,3) entrar y un n
        //que ese n es cuantas veces debe entrar por esa puerta.
        //hacer un clear a la cola.
};

#endif