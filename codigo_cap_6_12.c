/* Codigo 6.12: Función que determina si una cadena es un palíndromo */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Capitulo 6 */

#include <stdio.h>
#include <string.h>

int main()
{
   char palabra[30];
   int i, largo, es_palindromo=1;

   printf("Ingrese una palabra: ");
   scanf("%s", palabra);

   largo = strlen(palabra);

   for (i=0; i<largo/2; i++)
   {
      if (palabra[i] != palabra[largo-1-i])
         es_palindromo = 0;
   }

   if (es_palindromo)
      printf("%s es un palindromo", palabra);
   else
      printf("%s no es un palindromo", palabra);
}
