#include <iostream>
#include <string>
using namespace std;
/*CODE MADE BY LUIS ALFREDO GONZALEZ 2021024482 2 sem 2022
******NOTAS IMPORTANTES*********
1- EN CASO DE NO COMPILAR , IR AL TASK MANAGER , BUSCAR LA "TASK" CON EL NOMBRE
CASO 1 Y FINALIZAR TAREA.
2- Debe utilizar la consola para dijitar los colores, utilizar exactamente
los nombres de los colores(rojo, verde, amarillo, azul), de no ser asi
el algoritmo no funcionara apropiadamente.
3- Para utilizar la consola en vs code ir a file --> preferences-->settings
-->buscar code runner ->>> run in terminal(check in the box) -->done
4- el mapa utilizado para demostrar el algoritmo es una matriz de 3x4, donde 
el usuario va pintando , y segun los adyacentes del sector actual a pintar(al ser matriz
la adyacencia es un espacio a la derecha y un espacio arriba) se determina si
usted puede pintar la matriz o no con el color que dijite.
5- el recorrido de la matriz es columna-fila(hasta llegar a la ultima
columna se aumenta/pasa a la siguiente la fila)
6- para suministrar mapas, usted puede cambiar la extension de la matriz
haciendo los ajustes correspondientes al codigo, como es solo demostrar el algoritmo
para pintar, no utilizé defines para la columna y fila.
7- Code tested with
***************************************************************
*/
void pintura(){//funcion que construye, pinta e imprime la matriz
    string previusC = "negro"; //color "anterior, por default al iniciar es negro"
    string pintura[3][4];//matriz utilizada
    string color; //color recibido como input
    int n;
    int col=0;
    int val=0;
    for( val ; val < 3 ; val++){ //ciclo for para aumentar las filas
        col = 0;
        while(col < 4){//ciclo while para aumentar las columnas
            printf("dijite un color, (rojo, verde, amarillo, azul)");
            std:: cin >> color;//input de color
            switch(val){//condicional de casos
                case 0: //caso fila 0
                    if(col == 3){//caso esquina
                        if(color != previusC){
                            pintura[val][col]= color;
                            printf("el color en la fila %d %d es: %s" , val ,col ,color.c_str());cout<<endl;
                            previusC = "negro";
                            col+=1;
                            break;
                        
                        }
                        else{
                            printf("favor escoja otro color");cout<<endl;
                            break;

                        }
                    }
                    else{//caso NO esquina de matriz
                        if(color != previusC){//si el color no es igual al anterior..
                            pintura[val][col]=color;
                            printf("el color en la fila %d %d es: %s" , val ,col ,color.c_str());cout<<endl;
                            previusC = color;
                            col+=1;
                            break;
                    
                        }
                        else{//de ser igual escoja otro color
                            printf("favor escoja otro color negan"); cout<<endl;
                            break;
                        }
                    }
                default://caso demas filas
                    if(col == 3){//caso esquina
                    /*si el color no es igual al anterior y al que tiene arriba en la matriz
                    */
                        if(color != previusC && color != pintura[val-1][col]){
                            pintura[val][col]= color;
                            printf("el color en la fila %d %d es: %s" , val ,col ,color.c_str());cout<<endl;
                            previusC = "negro";
                            col+=1;
                            break;
                        
                        }
                        else{//si no , escoja otro color
                            printf("favor escoja otro color markus");cout<<endl;
                            break;
                        }
                    }
                    else{//caso NO esquina de la matriz
                        cout << "entre aqui" << endl;
                        if(color != previusC && color != pintura[val-1][col]){
                            pintura[val][col]=color;
                            printf("el color en la fila %d %d es: %s" , val ,col ,color.c_str());cout<<endl;
                            previusC = color;
                            col+=1;
                            break;
                    
                        }
                        else{//si no, escoja otro color
                            printf("favor escoja otro color");cout<<endl;
                            break;
                        }
                    }
            }
        }
    }
}
int main(){
    pintura();
    cout << "usted ha pintado bien segun el algoritmo";
}