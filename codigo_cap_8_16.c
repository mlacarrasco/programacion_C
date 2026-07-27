/* Codigo 8.16: Cálculo del promedio de un vector de notas reservado dinámicamente */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Capitulo 8 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
   float *notas, suma=0;
   int n, i;

   printf("Cuántas notas desea ingresar? ");
   scanf("%d", &n);

   notas = (float*) malloc(n*sizeof(float));

   for (i=0; i<n; i++)
   {
      printf("Nota %d: ", i+1);
      scanf("%f", &notas[i]);
      suma = suma + notas[i];
   }

   printf("Promedio: %.2f", suma/n);

   free(notas);
}
