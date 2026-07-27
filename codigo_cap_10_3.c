/* Codigo 10.3: Lectura de un archivo de texto empleando fscanf hasta alcanzar su fin */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Capitulo 10 */

#include <stdio.h>

int main()
{
   FILE *archivo;
   char nombre[20];
   int nota;

   archivo = fopen("notas.txt", "r");

   if (archivo == NULL)
   {
      printf("No fue posible abrir el archivo.\n");
      return(1);
   }

   while (fscanf(archivo, "%s %d", nombre, &nota) != EOF)
      printf("%s obtuvo %d puntos\n", nombre, nota);

   fclose(archivo);
}
