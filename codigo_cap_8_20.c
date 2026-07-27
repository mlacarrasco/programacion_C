/* Codigo 8.20: Función que reserva memoria a través de un puntero a puntero */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Capitulo 8 */

#include <stdio.h>
#include <stdlib.h>

void reservar_vector(int **vector, int n)
{
   *vector = (int*) malloc(n*sizeof(int));
}

int main()
{
   int *v, n, i;

   printf("Tamano del vector: ");
   scanf("%d", &n);

   reservar_vector(&v, n);

   for (i=0; i<n; i++)
      v[i] = i*i;

   for (i=0; i<n; i++)
      printf("%d ", v[i]);

   free(v);
}
