#include <iostream>
#include "User.cpp"
#include <fstream>
#include <stack>
#include <queue>
#include <iterator>
#include <algorithm>
#include<cassert>
#include <map>
#include<cmath>
#ifndef NODE 
#define NODE 1
using namespace std;
template <class T>
class Node{
    private:
        User **key;
        Node<T> **child;
        bool leaf;
        int n; //cantidad insertada 
        int grado;
    public:
        Node(int deg ){
            key = new User*[deg];//esta picha ocura ser un array de usuarios
            leaf = true;
            child=new Node<T>*[deg+1];
            n = 0;
            grado = deg;
            for(int i=0;i<deg;i++){
                child[i]=NULL;
            }
        }
        Node<T>* findNode(T* data, Node<T>* node_active,int t,Node<T>*temp,Node<T>* Origin){
            cout<<"la 1data es:"<<data->getNumber()<<endl;
            cout<<"el n es:"<<n<<endl;
            if(leaf && n!=grado){

                int i=t;
            /// go through keys until the value before it isnt null///
                
                cout<<"la data es:"<<data->getNumber()<<endl;
                while(getKey(i-1)==NULL){
                    i--;
                }
                cout<<"la data es:"<<data->getNumber()<<endl;
                cout<<"sali del primer ciclo while"<<endl;
                cout<<"el i al salir del ciclo es:"<<i<<endl;
            //// if value before key is greater than the data push it to the right///
                /*while(getKey(i-1)->getNumber() > data->getNumber() && i!=0){
                    cout<<"entre al 2 while"<<endl;
                    setkey(i , getKey(i-1)) ; //esto en teoria mueve a los numeros
                    cout<<"hizo el setkey"<<endl;
                    i--;
                    cout<<"el i ahora es:"<<i<<endl;
                }*/
                cout<<"la data es:"<<data->getNumber()<<endl;
                while(i!=0){ //esto inserta a partir de la posicion 1 de keys
                    cout<<getKey(i-1)->getNumber() <<">"<<data->getNumber()<<endl;
                    if(getKey(i-1)->getNumber() > data->getNumber()){
                        setkey(i , getKey(i-1));//puede que el error 
                        //lo de este getkey que estaria retornando nulo en este caso.
                        cout<<"movio una key con setkey"<<endl;
                        i--;
                        cout<<"la llave ahora es: "<<i<<endl;
                    }
                    else{
                        cout<<"entro a un else, no debe entrar aca"<<endl;
                        break;
                    }
                }
                cout<<"sali del 2 ciclo while "<<endl;
            //// insert the value in the respective place in the node////
                setkey(i , data);
                n=n+1;
                cout<<"termine todo el if "<<endl;
            }else if(getleaf()==false){
                cout<<"entre al else if"<<endl;
            ///// If the node is not leaf go to its appropriate child ////
                int i=0;
                while(i<n && data->getNumber()>getKey(i)->getNumber() ){ //A ESTE KEY PONERLE GETDATA
                    i++;
                }
                Origin->getChild(i)->findNode(data,this,t,temp,Origin);
            //PONERNE A ESTE CHILD FINDNODE 
            //node_active->child[i]->findNode(data,node_active,t,temp);
            }
        ////// After insertion if the node is full then split it/////
            if(n==grado){//si la cantidad insertada es igual al grado maximo 
///// If it is a root make the root the child of a new node then split the new node child///
                cout<<"entre al splitchild"<<endl;
                //this->n = 0;
                if(this==temp){
                    Node<T>* s=new Node<T>(t);
                    s->setleaf(); //S es la nueva raiz
                    cout<<"esta a punto de crear el hijo"<<endl;
                    s->setChild(0, this); //siento que esto debe de ser 
                    //raiz en vez de this pero bueno. 
                    cout<<"creo el hijo y esta a punto de hacer splitchild"<<endl;
                    s->splitChild(this,t , Origin); //ver split child
                    cout<<"splitchild del if exitoso"<<endl;
                    return s;
                    //siento que aca el n debe volverse 0 de nuevo
                }
                else{
                ///// split the child of this parent /////.
                    node_active->splitChild(this,t , Origin);
                    cout<<"splitchild del else exitoso"<<endl;
                }    //NOTA*************
                //SIENTO QUE AL ENTRAR ACA, EL N DEBE DE PONERSE EN 0        
            }
            return temp;
        } //ese int t me da problemas
        void splitChild(Node<T>*fullNode, int t , Node<T>* OriginNode){
            ///ESTOY REVSANDO ESTO DE ACA DEL CODIGO PARA VER QUE ERROR ME GENERA 
            //Y POR QUE******************
            Node<T>*rightNode=new Node<T>(t);
            int i_right=0,move_up=(t-1)/2; //el nodo que se tiene que subir
        // The nunmber of keys in th4e node at first entry//
            cout<<"el valor de la mitad es:"<<move_up<<endl;
            int n_fullNode=fullNode->getN();
            T* carry=fullNode->getKey(move_up); //AGARRA LA DATA 
            //DE LA MITAD.
            int i_child=0;//ponerle el getdata aca
            float val1=ceil(float(t)/2);
            int walk_child=val1;
            for(int i= move_up+1; i<n_fullNode; i++){
                //aca estoy diciendo que todo lo que este despues
                //del centro insertelo como llave en el nuevo nodo.
                rightNode->setkey(i_right,fullNode->getKey(i));//ponerle el getdata aca
                i_right++;
            //fullNode->key[i]=NULL;*********************************************
            //recuerde a fullNode tengo que quitarle el valor que le inserto
            //al padre**************************************************.
                fullNode->setN(fullNode->getN()-1); //quitele 1
                rightNode->setN(rightNode->getN()+1);//sumele 1
            }//HASTA ACA ENTIENDO EL CODIGO CON OBJETOS.
            if(fullNode->getleaf()==false){//ACA ESTOY
                cout<<"entre a este if que no se que hace"<<endl;
                for(int a=walk_child;a<=t;a++){
                rightNode->setChild(i_child , fullNode->getChild(a));
                i_child++;
            }
                rightNode->setleaf2(fullNode->getleaf());
                //aca le estoy diciendo al right node que se vuelva leaf
            }
            int hold=t-1;
            while(OriginNode->getChild(hold)!=fullNode){
                setChild(hold+1 ,OriginNode->getChild(hold));
                hold--;
            }
            //A PARTIR DE ACA NO SE QUE VERGAS HACE.
            setChild(hold+1,rightNode);
            int j=t-1;
            while(!OriginNode->getKey(j-1) && j!=0){//ponerle el gedata aca
                j--;
            }
            //// if value before key is greater than the data push it to the right///
            while(OriginNode->getKey(j-1)->getNumber()>carry->getNumber() && j!=0){ //PONER EL GETDATA ACA EN KEY
                setkey(j , getKey(j-1));
                j--;
            }
            //// insert the value in the respective place in the node////
            setkey(j,carry); //PONER EL GEDTADA ACA
            n=n+1;
            fullNode->setN(fullNode->getN()-1);
        }//****************************************************
        //void fullCheck(Node*temp,int t);
        void printLevel(Node<T>*temp,int level){
            if(level>1 && leaf){
                return;
            }
            else if(level==1){
                for(int i=0;i<n;i++){
                    cout<<getKey(i)->getNumber();
                }
            }
            else{
                for(int i=0;i<=n;i++){
                    getChild(i)->printLevel(temp,level-1);
                }
            }
        }
        void height(Node*temp,int height,int& result);
        T* getKey(int valor){
            return this->key[valor];
        }
        Node<T>* getChild(int number){
            return this->child[number];
        }
        void setleaf(){
            if (this->leaf ==false){
                this->leaf = true;
            }
            else{
                this->leaf = false;
            }
        }
        void setN(int number){
            this->n = number;
        }
        int getN(){
            return this->n;
        }
        void setkey(int value , T* data){
            this->key[value] = data;
        }
        void setChild(int number , Node<T>* data){ //sientoq que este data esta mal,creo
        //que deberia de ser un *Node
            this->child[number] = data;
        }
        bool getleaf(){
            return this->leaf;
        }
        void setleaf2(bool data){
            this->leaf = data;
        }

};
/*
class Node {
    private:
        T *data;
        Node *next;
        Node *previous;    //modificacion, agrego link hacia atras 
    
    public:
        Node() {
            data = NULL;
            next = NULL;
            previous = NULL;   //modif, creo previous y la hago null
        }

        Node(T *pData) {
            this->data = pData;
            next = NULL;
            previous = NULL;  //modif, la pongo en null
        }

        T* getData() {
            return data;
        }

        void setData(T *pData) {
            this->data = pData;
        }

        Node* getNext() {
            return next;
        }

        Node* getPrevious() {    //modif, creo este metodo que retorna
            return previous;     //el previo
        }

        void setNext(Node *pValue) {
            this->next = pValue;
        }

        void setPrevious(Node *pValue) {   //modif, creo este metodo que
            this->previous = pValue;       //pone valor al previo    
        }

        Node* getPrev() {    //modif, creo este metodo que retorna
            return previous;     //el previo
        }

        void setPrev(Node *pValue) {   //modif, creo este metodo que
            this->previous = pValue;       //pone valor al previo    
        }
};
*/
#endif