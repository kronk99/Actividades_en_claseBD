#include <iostream>
//#include "ArgumentManager.h"
#include <fstream>
#include <stack>
#include <queue>
#include <iterator>
#include <algorithm>
#include<cassert>
#include <map>
#include<cmath>
#include "Node.cpp"
#include "User.cpp"
using namespace std;
/*struct node{
    int *key;
    node **child;
    bool leaf;
    int n; //cantidad insertada 
    node(int deg) //se le inserta un numero grado, que es el numero de llaves
    //grado+1 == numero de nodos o hijos o como se llamara lo que valia m o como 
    //minimo m/2
    {
        key = new int[deg];//llave como array de ints
        leaf = true;
        child=new node*[deg+1];
        n = 0;
        for(int i=0;i<deg;i++){
            child[i]=NULL;
        }
    }
    node* findNode(int data, node*temp,int t,node* root);
    void splitChild(node*temp,int t);
    void fullCheck(node*temp,int t);
    void printLevel(node*temp,int level,ofstream& fout);
    void height(node*temp,int height,int& result);
};*/
template <class T>
class btree{
    private:
    Node<T>* root;
    int t; //grado
    public:

    btree(int val){
    Node<T>*root=NULL;
    t=val;
    }
    Node<T>* getRoot(){
        return root;
    }
    void insert(T* User){//cambiar esto a un User
        if(root==NULL){
            root=new Node<T>(t); //inserte un nuevo nodo de grado m-1
            root->setleaf();
            root->setkey(0 , User);
            root->setN(1);
        }
        else{
           root= root->findNode(User, root,t,root,root);
           // root->fullCheck(root,t);
            }
    }

    void printLevel(int level,ofstream &fout){
        root->printLevel(root,level,fout);
    }

    int height(){
        int result;
        root->height(root,1,result);
        return result;
    }

};
int main(){
User* user1 = new User("hola" , 5);
User* user2 = new User("hola" , 2);
User* user3 = new User("hola" , 3);
User* user4 = new User("hola" , 7);
User* user5 = new User("hola" , 8);
btree<User>* tree = new btree<User>(4);
tree->insert(user1);
tree->insert(user2);
tree->insert(user3);
tree->insert(user4);
tree->insert(user5);
}