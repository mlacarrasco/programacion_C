/* Codigo anexoB.7: fragmento de respuesta a ejercicio */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Anexo B (Respuestas a los ejercicios) */

#include <stdio.h>

int main()
{
   int i;

   for (i=1; i<=30; i++)
   {
      if (i%3 != 0)
         continue;

      printf("%d ", i);
   }
}
