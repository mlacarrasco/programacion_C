/* Codigo 10.1: Escritura de un archivo de texto empleando fprintf */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Capitulo 10 */

#include <stdio.h>

int main()
{
   FILE *archivo;

   archivo = fopen("notas.txt", "w");

   if (archivo == NULL)
   {
      printf("No fue posible crear el archivo.\n");
      return(1);
   }

   fprintf(archivo, "Ana 65\n");
   fprintf(archivo, "Luis 78\n");
   fprintf(archivo, "Eva 91\n");

   fclose(archivo);

   printf("Archivo notas.txt creado exitosamente.");
}
