#include <iostream>
#include <Node.cpp>
template <class T>
class cola{
    private:
        Pila<T> *front;
        Pila<T> *back;
        int counter;
        int conMovimientos;
    public:
        cola(){
            this->front = new Pila();
            this->back = new Pila();
            this->counter = 0;
        }
        void enqueue(T *data){
            switch (counter){ 
            case 0:
                back->push(data);
                counter+=1;
                break;
            case 1:
                front->push(data);
                front->push(back->Top());
                back->Pop();
                counter+=1;
            
            default:
                for(int i = 0; i<=back->getSize();i++){
                    front->push(back->Top());
                    back->Pop();
                    conMovimientos+=1;
                }
                back->push(data);
                for(int i = 0; i<=conMovimientos;i++){
                    back->push(front->Top());
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
        T* front(){
            return front->Top();
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
                cout << "la lista esta vacia"
            }
        }


};