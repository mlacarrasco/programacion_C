/* Codigo 8.11: Ampliación de un vector dinámico empleando realloc */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Capitulo 8 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
   int *vector, i;

   vector = (int*) malloc(2*sizeof(int));
   vector[0] = 10;
   vector[1] = 20;

   //aumentamos la capacidad del vector a 5 enteros
   vector = (int*) realloc(vector, 5*sizeof(int));

   vector[2] = 30;
   vector[3] = 40;
   vector[4] = 50;

   for (i=0; i<5; i++)
      printf("%d ", vector[i]);

   free(vector);
}
