/* Codigo 8.5: Recorrido de un vector empleando aritmética de punteros */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Capitulo 8 */

#include <stdio.h>

int main()
{
   int notas[5] = {65, 42, 78, 91, 55};
   int *p, i;

   p = notas;   //equivalente a: p = &notas[0];

   for (i=0; i<5; i++)
      printf("%d ", *(p+i));   //equivalente a: notas[i]
}
