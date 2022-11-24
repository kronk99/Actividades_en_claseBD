#include <iostream>
#include "User.cpp"
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
    public:
        Node(int deg ){
            key = new User*[deg];//esta picha ocura ser un array de usuarios
            leaf = true;
            child=new Node<T>*[deg+1];
            n = 0;
            for(int i=0;i<deg;i++){
                child[i]=NULL;
            }
        }
        Node<T>* findNode(T* data, Node<T>* node_active,int t,Node<T>*temp,Node<T>* Origin){
            if(leaf){
            int i=t;
            /// go through keys until the value before it isnt null///
            while(!key[i-1]){
                i--;
            }
            //// if value before key is greater than the data push it to the right///
            while(key[i-1]->getNumber()>data && i!=0){//poner el getNumber en el key de esta linea
                key[i]=key[i-1]; //esto en teoria mueve a los numeros
                i--;
            }
            //// insert the value in the respective place in the node////
            key[i]=data;
            n=n+1;
              }
        else{
            ///// If the node is not leaf go to its appropriate child ////
             int i=0;
            while(i<n && data->getNumber()>key[i]->getNumber() ){ //A ESTE KEY PONERLE GETDATA
                i++;
            }
            Origin->getChild()[i]->findNode(data,this,t,temp);
            //PONERNE A ESTE CHILD FINDNODE 
            //node_active->child[i]->findNode(data,node_active,t,temp);
        }
        ////// After insertion if the node is full then split it/////
        if(n==t){//si la cantidad insertada es igual al grado maximo 
///// If it is a root make the root the child of a new node then split the new node child///
            if(this==temp){
                Node<T>* s=new Node<T>(t);
                s->setleaf();
                s->setChild(0, this);
                s->splitChild(this,t , Origin); //ver split child
                return s;

            }
            else{
                ///// split the child of this parent /////.
               node_active->splitChild(this,t , Origin);
            }            
        }
        return temp;
        } //ese int t me da problemas
        void splitChild(Node*fullNode, int t , Node* OriginNode){
            Node<T>*rightNode=new Node<T>(t);
            int i_right=0,move_up=(t-1)/2;
        // The nunmber of keys in th4e node at first entry//
            int n_fullNode=fullNode->getN();
            T carry=fullNode->getKey()[move_up],i_child=0;//ponerle el getdata aca
            float val1=ceil(float(t)/2);
            int walk_child=val1;
            for(int i= move_up+1; i<n_fullNode; i++){
                rightNode->setkey(i_right,fullNode->getKey()[i]);//ponerle el getdata aca
                i_right++;
            //fullNode->key[i]=NULL;
                fullNode->setN(fullNode->getN()-1);
                rightNode->setN(rightNode->getN()+1);
            }
            if(fullNode->getleaf()==false){//ACA ESTOY
                for(int a=walk_child;a<=t;a++){
                rightNode->setChild(i_child , fullNode->getChild()[a]);
                i_child++;
            }
                rightNode->setleaf2(fullNode->getleaf());
            }
            int hold=t-1;
            while(OriginNode->getchild()[hold]!=fullNode){
                setchild(hold+1 ,OriginNode->getchild()[hold]);
                hold--;
            }
            setchild(hold+1,rightNode);
            int j=t-1;
            while(!OriginNode->getkey()[j-1] && j!=0){//ponerle el gedata aca
                j--;
            }
            //// if value before key is greater than the data push it to the right///
            while(OriginNode->getkey()[j-1]->getNumber()>carry->getNumber() && j!=0){ //PONER EL GETDATA ACA EN KEY
                setkey(j , getKey()[j-1]);
                j--;
            }
            //// insert the value in the respective place in the node////
            setkey(j,carry); //PONER EL GEDTADA ACA
            n=n+1;
            fullNode->setN(fullNode->getN()-1);
        }
        void fullCheck(Node*temp,int t);
        void printLevel(Node*temp,int level,ofstream& fout);
        void height(Node*temp,int height,int& result);
        T* getKey(){
            return this->key;
        }
        Node getChild(){
            return this->child;
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
        void setChild(int number , Node<T> data){ //sientoq que este data esta mal,creo
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