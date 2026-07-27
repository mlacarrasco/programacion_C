/* Codigo 5.24: Función que intercambia dos variables mediante paso por referencia */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Capitulo 5 */

#include <stdio.h>

void intercambiar(int *a, int *b){
   int tmp;

   tmp = *a;
   *a = *b;
   *b = tmp;
}

int main(){

   int x=5, y=8;

   intercambiar(&x, &y);
   printf("x=%d y=%d", x, y);   //despliega: x=8 y=5
}
