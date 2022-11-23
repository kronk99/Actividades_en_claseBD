#include<iostream>
using namespace std;
struct BplusTree {
   int *d;
   BplusTree **child_ptr; //ramas ddel nodo
   bool l;
   int n;
}*r = NULL, *np =  NULL, *x = NULL;
BplusTree* init(){ //ok esto es un constructor de un arbol , va a crear una instancia
//de tipo arbol que a su vez va a tener un "hijo" que va a ser un array
//de arboles bplus, para mi caso se debe cambiar a un array de nodos b+
//d creo que es degree que son las llaves, l son las hojas , esto crea 
//el array de pointers del arbol y los pone nulos inicialmente
   int i;
   np = new BplusTree;
   np->d = new int[6];//order 6 , es el array de llaves o datos
   np->child_ptr = new BplusTree *[7];
   np->l = true;
   np->n = 0;
   for (i = 0; i < 7; i++) {
      np->child_ptr[i] = NULL; //ok aca lo que hace es meterle un array de punteros
      //de tipo arbol
   }
   return np;
}

void traverse(BplusTree *p) {
   cout<<endl;
   int i;
   for (i = 0; i < p->n; i++) {
      if (p->l == false) {
         traverse(p->child_ptr[i]);
      }
      cout << " " << p->d[i];
   }
   if (p->l == false) {
      traverse(p->child_ptr[i]);
   }
   cout<<endl;
}

void sort(int *p, int n) { //busca 
   int i, j, t;
   for (i = 0; i < n; i++) {
      for (j = i; j <= n; j++) {
         if (p[i] >p[j]) {
            t = p[i];
            p[i] = p[j];
            p[j] = t;
         }
      }
   }
}

int split_child(BplusTree *x, int i) {
   int j, mid;
   BplusTree *np1, *np3, *y;
   np3 = init();
   np3->l = true;
   if (i == -1) {
      mid = x->d[2];
      x->d[2] = 0;
      x->n--;
      np1 = init();
      np1->l = false;
      x->l = true;
      for (j = 3; j < 6; j++) {
         np3->d[j - 3] = x->d[j];
         np3->child_ptr[j - 3] = x->child_ptr[j];
         np3->n++;
         x->d[j] = 0;
         x->n--;
      }
      for (j = 0; j < 6; j++) {
         x->child_ptr[j] = NULL;
      }
      np1->d[0] = mid;
      np1->child_ptr[np1->n] = x;
      np1->child_ptr[np1->n + 1] = np3;
      np1->n++;
      r = np1;
   } else {
      y = x->child_ptr[i];
      mid = y->d[2];
      y->d[2] = 0;
      y->n--;
      for (j = 3; j <6 ; j++) {
         np3->d[j - 3] = y->d[j];
         np3->n++;
         y->d[j] = 0;
         y->n--;
      }
      x->child_ptr[i + 1] = y;
      x->child_ptr[i + 1] = np3;
   }
   return mid;
}

void insert(int a) {
   int i, t;
   x = r;
   if (x == NULL) {
      //si el puntero a la raiz esta nulo, crea un nuevo arbol b y el puntero a la raiz
      // se vuelve el x (current)
      r = init(); //crea el arbol b
      x = r;
   } 
   else { //si la raiz no es nula 
      if (x->l== true && x->n == 6) { //si el current es hoja y el contador de insercion
      //esta lleno, parte el arbol
         t = split_child(x, -1); //parta el arbol
         x = r;
         for (i = 0; i < (x->n); i++) { //por i =0 hasta el contador de insercion(que va a estar full) 
         //i++
            if ((a >x->d[i]) && (a < x->d[i + 1])) {
            i++;
            break;
         } else if (a < x->d[0]) {
            break;
         } else {
            continue;
         }
      }
      x = x->child_ptr[i]; //x apunta a su hijo en la posicion i
      //y como no se inicia me imagino que el valor por default es 0.
   } //ERROR EN ESPACIADO??????? 
   else { //si el arbol no es hoja o no esta lleno
      while (x->l == false) { //mientras que el current no sea hoja
         for (i = 0; i < (x->n); i++) { //desde 0 mientras que i sea menor 
         //al total insertado, sumele 
            if ((a >x->d[i]) && (a < x->d[i + 1])) {
               //si el valor que se le inserta es mayor al dato en la posicion actual
               //y es menor al dato siguiente en el array de datos
               i++; //sumele a "i" 1
               break; //rompa el ciclo
            } else if (a < x->d[0]) {
               break; //si a es menor al inicial 
            } else {
               continue; //si no continue
            }
         } //sale del cilo for SI NO HIZO BREAK
         if ((x->child_ptr[i])->n == 6) { //si el hijo en la posicion i esta lleno
            t = split_child(x, i); //parte al hijo , t un int de lo que returne
            //split child
            x->d[x->n] = t; //entonces el array de nodos , en el total de inserciones
            //ahora es lo que retorne t, osea basicamente mete al hijo que se partio en 
            //el array que almacena punteros
            x->n++; //como inserta, sumele a n
            continue;
         } else {
            x = x->child_ptr[i]; //el puntero pasa a ser el hijo
         }
      }
   }
}
   x->d[x->n] = a; //aca inserta el valor en el x actual
   sort(x->d, x->n); //hace sort
   x->n++; //suma
}

int main() {
   int i, n, t;
   cout<<"enter the no of elements to be inserted";
   cin>>n;
   for(i = 0; i < n; i++) {
      cout<<"enter the element";
      cin>>t;
      insert(t);
   }
   cout<<"traversal of constructed B tree";
   traverse(r);
}