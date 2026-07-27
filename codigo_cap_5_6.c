/* Codigo 5.6: Variable local static que conserva su valor entre invocaciones */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Capitulo 5 */

#include <stdio.h>

void contador(void){
   static int veces = 0;

   veces = veces+1;
   printf("Invocación número: %d\n", veces);
}

int main(){

   contador();
   contador();
   contador();
}
