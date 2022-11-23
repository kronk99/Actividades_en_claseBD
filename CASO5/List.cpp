#include "Node.cpp"
#include "User.cpp"
#include <unordered_map>
#ifndef LIST 
#define LIST 1
using namespace std;
template <typename T> 
class List{
    private:
        Node<T> *first;
        Node<T> *last;
        Node<T> *searchPosition;
        unordered_map<int, Node<T>*> nodeIndex;
        int size;

    public:
        List() {
            first = NULL;
            last = NULL;
            size = 0;
        }

        Node<T>* getFirst() {
            return this->first;
        }

        int getSize() {
            return size;
        }

        bool isEmpty() {
            return !size;
        }
        //ocupo una funcion checksize

        T* find(int pPosition) {
            T* result = NULL;
            searchPosition = NULL;

            if (nodeIndex.find(pPosition) != nodeIndex.end()) {
                searchPosition = nodeIndex[pPosition];
                result = searchPosition->getData();
            }

            return result;
        }
        void add(T *pData) {
            Node<T> *newNode = new Node<T>(pData);

            if (size>0) {
                this->last->setNext(newNode);
                newNode->setPrev(this->last);  // esta linea se agrega para quiz #4 #5
            } else {
                this->first = newNode;
            }
            this->last = newNode;

            nodeIndex[size] = newNode; // save for indexing
            size++;
        }

        // si el position es mayor a la cantidad, entonces inserto al final
        void insert(int pPosition, T *pData) {
            if (pPosition<getSize() && first!=NULL) {
                Node<T> *newNodo = new Node<T>(pData);

                T* result = find(pPosition); 
                // esta linea se quita para quiz #4 #5, ya no hace falta, aqui iba searchBehind
                
                newNodo->setNext(searchPosition);
                if (searchPosition->getPrev()!=NULL) {  // apariciones de searchBehind ahora serian getPrev de searchPosition, quiz #4 #5
                    searchPosition->getPrev()->setNext(newNodo); // esas lineas se arreglaan con el prev #4 #5
                    newNodo->setPrev(searchPosition->getPrev());
                    searchPosition->setPrev(newNodo);  
                } else {
                    this->first->setPrev(newNodo); // quiz #4 #5
                    this->first = newNodo;
                }
                
                for(int indexToAdjust=getSize()-1; indexToAdjust>=pPosition; indexToAdjust--) {
                    if (nodeIndex.find(indexToAdjust) != nodeIndex.end()) {
                        nodeIndex[indexToAdjust+1] = nodeIndex[indexToAdjust]; 
                    }
                }

                nodeIndex[pPosition] = newNodo;
                size++;
            } else {
                add(pData);
            }
        }

        T* remove(int pPosition) {
            T* result = NULL;
            if (first!=NULL && pPosition<getSize()) {
                searchPosition = first;

                if (pPosition!=0) {
                    T* data = find(pPosition);

                    searchPosition->getPrev()->setNext(searchPosition->getNext()); // quiz #4 #5, se quita searchBehind

                    if (searchPosition==last) {
                        last = searchPosition->getPrev();  // quiz #4 #5
                    } else {
                        searchPosition->getNext()->setPrev(searchPosition->getPrev()); // quiz #4 #5
                    }
                    searchPosition->setNext(NULL);
                    searchPosition->setPrev(NULL);

                    result = searchPosition->getData();
                } else {
                    first = first->getNext();
                    searchPosition->setNext(NULL);

                    if (first!=NULL) { // quiz #4 #5, hay que limpiar el anterior del que esta despues del primero
                        first->setPrev(NULL); 
                    } else {
                        last = NULL;
                    }
                    result = searchPosition->getData();
                }

                int indexToAdjust=pPosition;
                for(; indexToAdjust<getSize()-1; indexToAdjust++) {
                    if (nodeIndex.find(indexToAdjust) != nodeIndex.end()) {
                        nodeIndex[indexToAdjust] = nodeIndex[indexToAdjust+1]; 
                    }
                }

                nodeIndex.erase(indexToAdjust+1);

                size--;
            }
            return result;
        };
};
int main(){
    User* usuario1 = new User("hola german");
    User* usuario2 = new User("hola pablo");
    User* usuario3 = new User("hola gustavo");
    List<User>* list = new List<User>();
    list->add(usuario1);
    list->add(usuario2);
    list->add(usuario2);
    cout<<"el usuario es :"<<list->find(2)->getext()<<endl;
    list->remove(2);
    cout<<"el usuario es :"<<list->find(0)->getext()<<endl;

}

#endif