/* Codigo 8.19: Vector dinámico que duplica su capacidad automáticamente al llenarse */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Capitulo 8 */

#include <stdio.h>
#include <stdlib.h>

int *agregar(int *vector, int *capacidad, int cantidad_actual, int valor)
{
   if (cantidad_actual == *capacidad){  
      *capacidad = *capacidad * 2;
      // aumentamos la capacidad al doble con realloc
      vector = (int*) realloc(vector, (*capacidad)*sizeof(int));
   }
   // agregamos el valor en la posición cantidad_actual
   vector[cantidad_actual] = valor;

   return(vector);
}

int main()
{
   int *v, capacidad=2, cantidad=0, i;
   
   v = (int*) malloc(capacidad*sizeof(int)); //creamos el vector

   for (i=1; i<=5; i++)  {  
     //este ciclo simula agregar valores
      v = agregar(v, &capacidad, cantidad, i*10);
      cantidad++;
   }

   for (i=0; i<cantidad; i++)
      printf("%d ", v[i]);

   printf("\nCapacidad final: %d", capacidad);

   free(v);
}
