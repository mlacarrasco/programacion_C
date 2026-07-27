/* Codigo 6.13: Cifrado simple de una cadena a través de su valor ASCII */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Capitulo 6 */

#include <stdio.h>
#include <string.h>

int main()
{
   char texto[100];
   int i, largo;

   printf("Ingrese un texto: ");
   scanf("%s", texto);

   largo = strlen(texto);

   for (i=0; i<largo; i++)
   {
      if (texto[i] != ' ')
         texto[i] = texto[i] + 1;
   }

   printf("Texto cifrado: %s", texto);
}
