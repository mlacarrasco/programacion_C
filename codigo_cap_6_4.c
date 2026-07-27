/* Codigo 6.4: Recorrido de un vector e impresión de sus elementos */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Capitulo 6 */

#include <stdio.h>

int main()
{
   int notas[5] = {65, 42, 78, 91, 55};
   int i;

   for (i=0; i<5; i++)
      printf("notas[%d] = %d\n", i, notas[i]);
}
