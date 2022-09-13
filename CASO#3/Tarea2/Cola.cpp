#include <iostream>
#include <Node.cpp>
template <class T>
class cola{
    private:
        Pila<T> *front;
        Pila<T> *back;
        int counter;
    public:
        cola(){
            this->front = new Pila();
            this->back = new Pila();
            this->counter = 0;
        }
        void enqueue(T *data){
            switch (counter)
            {
            case 0:
                back->push(data);
                counter+=1;
                break;
            case 1:
                front->push(data);
                front->push(back->Top());
                back->Pop();
            
            default:
                for(int i = 0; i<=counter-2;i++){
                    front->push(back->Top());
                    back->Pop();
                }
                back->push(data);
                for(int i = 0; i<=counter-2;i++){
                    back->push(front->Top());
                    front->Pop();
                }
                break;
            }

        }


};