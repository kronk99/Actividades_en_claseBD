#include <iostream>
#include "Node.cpp"
#include "Pila.cpp"
template <class T>
class Cola{
    private:
        Pila<T> *front;
        Pila<T> *back;
        int counter;
        int conMovimientos;
    public:
        Cola(){
            this->front = new Pila<T>();
            this->back = new Pila<T>();
            this->counter = 0;
        }
        void enqueue(T *data){
            switch (counter){ 
            case 0:
                back->Push(data);
                counter+=1;
                cout<<"el counter es:"<<counter<<endl;
                break;
            case 1:
                front->Push(data);
                front->Push(back->Top());
                back->Pop(); //revisar el pop
                counter+=1;
                cout<<"el counter es:"<<counter<<endl;
                break;
            case 2:
                back->Push(data);
                counter+=1;
                cout<<back->getSize()<<endl;
                cout<<"el counter es:"<<counter<<endl;
                break;
            default:
                for(int i = 0; i<=back->getSize();i++){
                    cout<<"entre al primer ciclo"<<endl;
                    front->Push(back->Top());
                    back->Pop();
                    conMovimientos+=1;
                }
                back->Push(data);
                for(int i = 0; i<=conMovimientos;i++){
                    back->Push(front->Top());
                    front->Pop();
                }
                conMovimientos = 0;
                break;
            }

        }
        bool isEmpty(){
            if(counter !=0){
                return false;
            }
            else{
                return true;
            }
        }
        T* primero(){
            T* result;
            if(counter < 2){
                result = back->Top();
            }
            else{
               result = front->Top(); 
            }
            return result;
        }
        void dequeue(){
            if(front->getSize() ==1 && back->getSize()>0){
                front->Pop();
                front->Push(back->Top());
                back->Pop();
            }
            else if(front->getSize() == 2){
                front->Pop();
            }
            else if(front->getSize() ==1 && back->getSize()==0){
                front->Pop();
                counter = 0;
            }
            else{
                cout << "la lista esta vacia";
            }
        }


};