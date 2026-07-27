/* Codigo anexoB.14: fragmento de respuesta a ejercicio */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Anexo B (Respuestas a los ejercicios) */

#include <stdio.h>

int main()
{
   int n, i, primo=1;

   printf("Ingrese un numero entero positivo: ");
   scanf("%d", &n);

   if (n < 2)
      primo = 0;

   for (i=2; i<n; i++)
   {
      if (n%i == 0)
      {
         primo = 0;
         break;
      }
   }

   if (primo)
      printf("Es primo");
   else
      printf("No es primo");
}
