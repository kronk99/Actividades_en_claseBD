#include "Node.h"

#ifndef COLA 

#define COLA 1

// 2. ajustar a que esta lista sea doblemente enlazada, cambia el add, find, insert y el remove
template <typename T> 
class Cola  {
    private:
        Node<T> *first;
        Node<T> *Empty;
        int size;
        Node<T> *last;
    public:
        Cola() {
            first = NULL;
            last = NULL;
            size = 0;
            Empty = new Node<T>(&size , "vacio");
        }
        //direccion puedo utilizarlo como indice del array
        void enqueue(T *pData , string nomMinero ) { //hay que modificar el add para que añada a cada
        //nodo otro nodo con las probalilidades.
            Node<T> *newNode = new Node<T>(pData , nomMinero);
            if (size>0) {
                this->last->setNext(newNode);
                this->last = newNode;
                cout<<"se inserto:"<<last->getNombre()<<endl;
                size++;
            }
            else {
                cout<<"el nodo es un first"<<endl;
                this->first = newNode;
                this->last = newNode;
                cout<<"se inserto como cabeza"<<first->getNombre()<<endl;
                cout<<"se inserto como cola"<<last->getNombre()<<endl;
                size++;

            }
            //size++;
        }
        Node<T>* dequeue() { //tal vez hacer un codicional si el first no es nulo.
            if(size >=1){
            /*esta condicional la meti aca y no en el pop por que al reali<ar
            pruebas, al intentar eliminar un elemento vacio y siplemente imprimir
            "la lista esta vacia" y luego volver a intenar insertar, el codigo
            no me inserta, pero si inserto esta condicional aca, el codigo si puede 
            borrar y eliminar varias veces.*/
                Node<T> *result= this->first;
                Pop();
                return result;
            }
            else{
                cout<<"la lista esta vacia"<<endl;
                return Empty; //este return null me daña el programa
                //entonces retorna un nodo Empty.
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
                
                Node<T> *current = first;
                first = current->getNext(); 
                current->setNext(NULL); //el error esta aca cuando queda 1 elemento 
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