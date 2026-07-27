/* Codigo 8.9: Reserva de un vector de tamaño variable empleando memoria dinámica */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Capitulo 8 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
   int *vector, n, i;

   printf("Ingrese el tamaño del vector: ");
   scanf("%d", &n);

   //reserva n enteros en memoria dinámica
   vector = (int*) malloc(n*sizeof(int));

   for (i=0; i<n; i++)
      vector[i] = i*2;

   for (i=0; i<n; i++)
      printf("%d ", vector[i]);

   free(vector);   //libera la memoria reservada
}
