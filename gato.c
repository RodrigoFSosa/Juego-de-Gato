#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

//Este programa generará en pantalla el tablero de gato, el usuario introducirá la posición en la que desee colocar su simbolo que por defecto será el símbolo X; por su parte el computador colocará el símbolo O en cualquier casilla que no se encuentre ocupado por alguno de ambos símbolos.
//La victoria será para el jugador que consiga completar una fila vertical, horizontal o diagonal con sus respectivos simbolos. 

main(){
int i, j;
char aux;
char c[3][3]; //El juego consistirá en llenar los elementos de una matriz de 3x3
system ("clear"); //Limpiar la pantalla

aux='1';
for (i=0;i<3;i++){
  for (j=0;j<3;j++){
        c[i][j]= aux; //Se procede a llenar los elementos de la matriz con dígitos de (1-9) de forma sucesiva en cada entrada 
        aux++; //Aumenta en 1 el valor de la variable aux
      }
   }

printf("\nColoca tu ficha en el tablero con el siguiente formato:\n");

tablero(c); //Imprime el tablero de juego con las posiciones de cada entrada

getchar(); //Recibe el digito tecleado

loop (c); // Actualiza el estado de juego

return 0;

}

loop (char c[3][3]){ //Esta funcion actualiza el estado de juego
int i,j;

i=0;
intro (c); //Se llena el tablero con espacios en blanco

do{ //El do while permitirá que las instrucciones se repitan mientras el número de tiradas sea menor a 9 y el estado de j sea 2
    system ("clear");
    tablero (c); //Imprime el estado actual del gato

    if (i % 2 ==0){ //Si el valor de  i es par 
         intro1 (c);  //El usuario digita la posición de X    
    }
    else{
     intro_IA(c); //La computadora coloca el simbolo O en alguna posición 
    }
    j= ganador(c); //Función 
    i++;

}while(i <= 9 && j == 2);

system ("clear");
tablero (c);

 if (j == 0){
    printf ("Felicidades!! Has ganado!!\n\n");
   }
 else if (j==1){
    printf ("Lo siento. Has perdido :(\n\n");
 }
 else{
     printf("Has empatado!! Intentalo de nuevo\n\n");
  } 
}


intro (char c[3][3]){ // Esta funcion llena las entradas de la matriz con espacios en blanco
     int i,j;

     for (i=0;i<3;i++){
         for (j=0;j<3;j++){
             c[i][j]=' ';

         }
     }
}

tablero (char c[3][3]){ //Esta función imprime el tablero de gato
     int i,j;
     printf("\n\n");

     for (i=0;i<3;i++){
        for (j=0;j<3;j++){
           if (j<2){
            printf (" %c |",c[i][j]); //Imprime las lineas verticales del tablero junto con el valor de la entrada de la matriz
           }
           else {
           printf (" %c ", c[i][j]); //Imprime el valor de la entrada de la matriz
           }
    }
   if (i<2){
   printf("\n------------\n"); //Imprime las lineas horizontales del tablero
   }
}
printf("\n\n");
}

intro1(char c[3][3]){
int i, j, k;
int cont;

    do{
        do{
//           system("clear");
           printf ("Coloca una ficha: ");
          // fflush (stdin);
           scanf ("%d", &cont);  
       }while (cont < 1 || cont > 9);
       
       k=0;

       switch (cont){
          case 1:{
             i=0;
             j=0;
             if (c[i][j] == 'X' || c[i][j] == 'O'){
               k=1;
            printf("La casilla esta ocupada! Intentalo con otro número!!\n\n"); 
             }
             break;   
          }
          
           case 2:{
             i=0;
             j=1;
             if (c[i][j] == 'X' || c[i][j] == 'O'){
               k=1;
             printf("La casilla esta ocupada! Intentalo con otro número!!\n\n");
             }
             break;
          }
          
            case 3:{
             i=0;
             j=2;
             if (c[i][j] == 'X' || c[i][j] == 'O'){
               k=1;
             printf("La casilla esta ocupada! Intentalo con otro número!!\n\n");
             }
             break;
          }

             case 4:{
             i=1;
             j=0;
             if (c[i][j] == 'X' || c[i][j] == 'O'){
               k=1;
             printf("La casilla esta ocupada! Intentalo con otro número!!\n\n");
             }
             break;
          }

             case 5:{
             i=1;
             j=1;
             if (c[i][j] == 'X' || c[i][j] == 'O'){
               k=1;
           printf("La casilla esta ocupada! Intentalo con otro número!!\n\n");
             }
             break;
          }

            case 6:{
             i=1;
             j=2;
             if (c[i][j] == 'X' || c[i][j] == 'O'){
               k=1;
            printf("La casilla esta ocupada! Intentalo con otro número!!\n\n");
             }
             break;
          }

            case 7:{
             i=2;
             j=0;
             if (c[i][j] == 'X' || c[i][j] == 'O'){
              k=1;
             printf("La casilla esta ocupada! Intentalo con otro número!!\n\n");
             }
             break;
          }

            case 8:{
             i=2;
             j=1;
             if (c[i][j] == 'X' || c[i][j] == 'O'){
               k=1;
             printf("La casilla esta ocupada! Intentalo con otro número!!\n\n");
             }
             break;
             }
  
            case 9:{
             i=2;
             j=2;
             if (c[i][j] == 'X' || c[i][j] == 'O'){
               k=1;
             printf("La casilla esta ocupada! Intentalo con otro número!!\n\n");
             }
             break;
          }

         }        
    
      }while(k==1);
     

      c[i][j] = 'X';
}

intro_IA(char c[3][3]){
int i,j,k;
char cont;

srand (time(NULL));
do{
    i=rand()%3;
    j=rand()%3;
    k=0;
    
    if (c[i][j] == 'X' || c[i][j] == 'O'){
     k=1;
    }
}while (k==1);
c[i][j]='O';
}

ganador (char c[3][3]){
  if (c[0][0] == 'X' || c[0][0] == 'O'){
     if (c[0][0] == c[0][1] && c[0][0] == c[0][2]){
         if (c[0][0] == 'X'){
             return 0; //He ganado
         } 
         else {
             return 1; //He perdido
         }
       }
  
     if (c[0][0] == c[1][0] && c[0][0] == c[2][0]){
            if (c[0][0] == 'X'){
             return 0; //He ganado
             }
              else {
             return 1; //He perdido
              }
        }
  }

   if (c[1][1] == 'X' || c[1][1] == 'O'){
     if (c[1][1] == c[0][0] && c[1][1] == c[2][2]){
            if (c[1][1] == 'X'){
             return 0; //He ganado
             }
              else {
             return 1; //He perdido
              }
        }
     if (c[1][1] == c[2][0] && c[1][1] == c[0][2]){
          if (c[1][1] == 'X'){
             return 0; //He ganado
             }
              else {
             return 1; //He perdido
              }
        }
     if (c[1][1] == c[0][1] && c[1][1] == c[2][1]){
          if (c[1][1] == 'X'){
             return 0; //He ganado
             }
              else {
             return 1; //He perdido
              }
        }
     if (c[1][1] == c[1][0] && c[1][1] == c[1][2]){
          if (c[1][1] == 'X'){
             return 0; //He ganado
             }
              else {
             return 1; //He perdido
              }
        } 
 }

  if (c[2][2] == 'X' || c[2][2] == 'O'){
     if (c[2][2] == c[2][0] && c[2][2] == c[2][1]){
          if (c[2][2] == 'X'){
             return 0; //He ganado
             }
              else {
             return 1; //He perdido
              }
        }
      if (c[2][2] == c[0][2] && c[2][2] == c[1][2]){
          if (c[2][2] == 'X'){
             return 0; //He ganado
             }
              else {
             return 1; //He perdido
              }
        }
    }
    return 2;
}



