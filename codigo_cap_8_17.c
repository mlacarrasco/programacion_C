/* Codigo 8.17: Inversión de un vector dinámico empleando dos punteros */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Capitulo 8 */

#include <stdio.h>
#include <stdlib.h>

void invertir(int *vector, int n)
{
   int *inicio, *fin, tmp;

   inicio = vector;
   fin = vector + (n-1);

   while (inicio < fin)
   {
      tmp = *inicio;
      *inicio = *fin;
      *fin = tmp;

      inicio++;
      fin--;
   }
}

int main()
{
   int *v, n, i;

   printf("Tamano del vector: ");
   scanf("%d", &n);

   v = (int*) malloc(n*sizeof(int));

   for (i=0; i<n; i++)
      v[i] = i+1;   //llena el vector con 1..n

   invertir(v, n);

   for (i=0; i<n; i++)
      printf("%d ", v[i]);

   free(v);
}
