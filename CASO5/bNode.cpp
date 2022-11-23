#include <iostream>
#include "User.cpp"
template <class T>
class bNode{
    private:
        T* key; //debe cambiar a un array/linked listde tipo T
        bNode** child; //ramas del nodo
        bool leaf;
    public:
      bNode(int grado){
        this->key = new T[grado-1]; //aca deberia de ser una linkedlist de tipo user
        leaf = true;
        child = new bNode*[grado];// array de pointers , como en el caso 4
        for(int i=0 ; i<grado ; i++){
            this->child[i] = NULL; 
        }
      }
      void setleaf(bool value){
        this->leaf = true;
      }
      bool getLeaf(){
        return this->leaf;
      }
      void setkey(T data , int i){ //vea que aca estoy añadiendo el datatype no el pointer
        this->key[i] = data;
      }
      T getkey(int number){
        return key[number];
      }
};