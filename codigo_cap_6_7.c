/* Codigo 6.7: Función que recibe un vector y su tamaño como parámetros */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Capitulo 6 */

#include <stdio.h>

//función que imprime todos los elementos de un vector
void imprimir(int vector[], int tamano)
{
   int i;

   for (i=0; i<tamano; i++)
      printf("%d ", vector[i]);
}

//función que duplica cada elemento del vector
void duplicar(int vector[], int tamano)
{
   int i;

   for (i=0; i<tamano; i++)
      vector[i] = vector[i]*2;
}

int main()
{
   int notas[5] = {65, 42, 78, 91, 55};

   duplicar(notas, 5);
   imprimir(notas, 5);
}
