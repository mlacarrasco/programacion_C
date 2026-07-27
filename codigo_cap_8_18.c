/* Codigo 8.18: Función que retorna un puntero al mayor elemento de un vector */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Capitulo 8 */

#include <stdio.h>

int *maximo(int *vector, int n)
{
   int *mayor, i;

   mayor = vector;   //se asume que el primero es el mayor

   for (i=1; i<n; i++)
   {
      if (vector[i] > *mayor)
         mayor = &vector[i];
   }
   //aca retornamos una dirección ya que mayor es puntero
   return(mayor); 
}

int main()
{
   int notas[5] = {65, 90, 42, 78, 55};
   int *max;

   max = maximo(notas, 5);

   printf("El mayor valor es: %d\n", *max);

   *max = 100;   //podemos modificar el elemento del vector
   printf("Nuevo valor en esa posición: %d\n", notas[1]);
}
