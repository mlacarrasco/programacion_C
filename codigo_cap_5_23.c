/* Codigo 5.23: Intento fallido de intercambiar dos variables mediante paso por valor */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Capitulo 5 */

#include <stdio.h>

void intercambiar_valor(int a, int b){

   int tmp;

   tmp = a;
   a = b;
   b = tmp;
}

int main(){

   int x=5, y=8;

   intercambiar_valor(x, y);
   printf("x=%d y=%d", x, y);   //despliega: x=5 y=8 (sin cambios)
}
