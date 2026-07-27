/* Codigo 6.6: Cálculo del máximo elemento de un vector */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Capitulo 6 */

#include <stdio.h>

int main()
{
   int notas[5] = {65, 33, 78, 91, 55};
   int i, maximo;
   
   maximo = notas[0]; //definimos un valor inicial
   
   for (i=0; i<5; i++)
      if (notas[i]> maximo)
        maximo = notas[i];  //actualizamos el máximo
     
   printf("El máximo valor es: %d", maximo);
}
