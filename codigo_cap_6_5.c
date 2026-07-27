/* Codigo 6.5: Cálculo del promedio de los elementos de un vector */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Capitulo 6 */

#include <stdio.h>

int main()
{
   int notas[5] = {65, 42, 78, 91, 55};
   int i, suma=0;
   float promedio;

   for (i=0; i<5; i++)
      suma = suma + notas[i];

   promedio = (float)suma/5;
   printf("El promedio es: %.2f", promedio);
}
