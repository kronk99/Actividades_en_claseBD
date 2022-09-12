#include <iostream>

#ifndef NODE 

#define NODE 1

using namespace std;

template <class T>
/*se modifico data, ya no es un pointer debido a mi codigo de la clase
converter, por lo que ahora recibe data normal, no pointers a cosas 
tener esto en cuenta (como nota de que modifique el nodo para que reciba
chars )
*/
class Node {
    private:
        T data;
        Node *next;
    
    public:
        Node() { //para el head,tail , etc
            data = NULL;
            next = NULL;
        }

        Node(T pData) {
            this->data = pData;
            next = NULL;
        }

        T getData() {
            return data;
        }

        Node* getNext() {
            return next;
        }

        void setNext(Node *pValue) {
            this->next = pValue;
        }
};
#endif