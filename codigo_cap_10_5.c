/* Codigo 10.5: Construcción de una matriz a partir de un archivo de valores separados por comas */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Capitulo 10 */

#include <stdio.h>

#define FILAS 3
#define COLUMNAS 4

int main()
{
   FILE *archivo;
   int notas[FILAS][COLUMNAS];
   int i, j;

   archivo = fopen("notas.csv", "r");

   if (archivo == NULL)
   {
      printf("No fue posible abrir el archivo.\n");
      return(1);
   }

   for (i=0; i<FILAS; i++)
   {
      for (j=0; j<COLUMNAS; j++)
         fscanf(archivo, "%d%*c", &notas[i][j]);  //lee la nota y descarta la coma o el salto de línea
   }

   fclose(archivo);

   //despliega la matriz recién construida
   for (i=0; i<FILAS; i++)
   {
      for (j=0; j<COLUMNAS; j++)
         printf("%d ", notas[i][j]);
      printf("\n");
   }
}
