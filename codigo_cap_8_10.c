/* Codigo 8.10: Reserva de un vector inicializado en cero empleando calloc */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Capitulo 8 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
   int *vector, n, i;

   printf("Ingrese el tamaño del vector: ");
   scanf("%d", &n);

   //reserva n enteros, todos inicializados en 0
   vector = (int*) calloc(n, sizeof(int));

   for (i=0; i<n; i++)
      printf("%d ", vector[i]);   //despliega n ceros

   free(vector);
}
