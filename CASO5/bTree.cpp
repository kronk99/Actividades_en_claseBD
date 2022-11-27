#include <iostream>
#include "bNode.cpp"
template <class T>
class bTree{
    private:
        bNode* root; //debe ser un pointer a linked list.
        int tGrado;
        int cantInsert;
    public:
        bTree(int grado){
            root = NULL;
            tGrado = grado;
            cantInserT = 0;
        }
        void insert(T* data){
            if (root = NULL){ //si la raiz esta nula 
                root = new bNode(tGrado);
                root->setleaf(true);
                root->setKey(data , cantInsert);
                cantInsert+=1;
            }
            else{
                findBnode(data , root, tGrado); //busca si el array no esta vacio y el elemento
                //a insertar no esta
            }
        }
        void findnode(T data , bNode* current_root ,int tGrado){
            if (current_root->getleaf()==true){ //si es una hoja
            //aca debo hacer un ciclo while para ver si el array esta vacio.
                int i = tGrado-1;
                while(!current_root->getkey(i)){ //por lo que entiendo esto es como decir
                //mientras que current root get key SEA NULO, y si no es eso cambiarlo a un
                //equivalente tipo while current_root->getkey == NULL , esto es basicamente
                //que mientras las llaves sean nulas , restele al maximo
                i--
                }//este get key de aca abajo debe de decir getkey->getData() 
                //para agarrar la palabra, puesto que lo que retorna un 
                while (current_root->getkey(i)>)
                //int counter = 0;
                /*
                while(counter != cantInsert){
                    counter++
                }
                if(!(counter ==tGrado-1)){ //si counter NOllego a la cantidad maxima del array
                    //inserte y mueva data
                    int verificartamaño 
                    if verificartamaño < grado-1 
                     ->partirnodo
                }
                else{
                    //si no haga el split
                    //llame a splitnode.
                }
                */
            }
        }

}