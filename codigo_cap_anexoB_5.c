/* Codigo anexoB.5: fragmento de respuesta a ejercicio */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Anexo B (Respuestas a los ejercicios) */

#include <stdio.h>

int main()
{
   int n, i=1;
   long factorial=1;

   printf("Ingrese un numero: ");
   scanf("%d", &n);

   while (i <= n)
   {
      factorial = factorial * i;
      i++;
   }

   printf("El factorial es: %ld", factorial);
}
