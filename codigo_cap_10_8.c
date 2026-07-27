/* Codigo 10.8: Ordenamiento de las notas contenidas en un archivo, guardando el resultado en un nuevo archivo */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Capitulo 10 */

#include <stdio.h>

#define MAX 100

void ordenamiento_burbuja(int vector[], int tamano)
{
   int i, j, tmp;

   for (i=0; i<tamano-1; i++)
   {
      for (j=0; j<tamano-1-i; j++)
      {
         if (vector[j] > vector[j+1])
         {
            tmp = vector[j];
            vector[j] = vector[j+1];
            vector[j+1] = tmp;
         }
      }
   }
}

int main()
{
   FILE *entrada, *salida;
   int vector[MAX];
   int tamano=0, i;

   entrada = fopen("notas_desordenadas.txt", "r");

   if (entrada == NULL)
   {
      printf("No fue posible abrir el archivo de entrada.\n");
      return(1);
   }

   //lee notas hasta alcanzar el fin del archivo
   while (fscanf(entrada, "%d", &vector[tamano]) != EOF)
      tamano++;

   fclose(entrada);

   ordenamiento_burbuja(vector, tamano);

   salida = fopen("notas_ordenadas.txt", "w");

   if (salida == NULL)
   {
      printf("No fue posible crear el archivo de salida.\n");
      return(1);
   }

   for (i=0; i<tamano; i++)
      fprintf(salida, "%d\n", vector[i]);

   fclose(salida);

   printf("Se ordenaron %d notas.", tamano);
}
