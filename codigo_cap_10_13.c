/* Codigo 10.13: Carga de un vector dinámico a partir de un archivo de tamaño desconocido */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Capitulo 10 */

#include <stdio.h>
#include <stdlib.h>

int *agregar(int *vector, int *capacidad, int cantidad_actual, int valor)
{
   if (cantidad_actual == *capacidad)
   {
      *capacidad = *capacidad * 2;
      vector = (int*) realloc(vector, (*capacidad)*sizeof(int));
   }
   vector[cantidad_actual] = valor;

   return(vector);
}

int main()
{
   FILE *archivo;
   int *datos, capacidad=2, n=0, valor, i;
   float suma=0;

   datos = (int*) malloc(capacidad*sizeof(int));

   archivo = fopen("datos.txt", "r");

   if (archivo == NULL)
   {
      printf("No fue posible abrir el archivo.\n");
      return(1);
   }

   while (fscanf(archivo, "%d", &valor) != EOF)
   {
      datos = agregar(datos, &capacidad, n, valor);
      n++;
   }

   fclose(archivo);

   for (i=0; i<n; i++)
      suma = suma + datos[i];

   printf("Se leyeron %d valores. Promedio: %.2f", n, suma/n);

   free(datos);
}
