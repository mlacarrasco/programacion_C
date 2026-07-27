/* Codigo anexoB.13: fragmento de respuesta a ejercicio */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Anexo B (Respuestas a los ejercicios) */

#include <stdio.h>

int main()
{
   int n, binario[32], i=0, j;

   printf("Ingrese un numero decimal: ");
   scanf("%d", &n);

   while (n > 0)
   {
      binario[i] = n%2;
      n = n/2;
      i++;
   }

   printf("En binario es: ");
   for (j=i-1; j>=0; j--)
      printf("%d", binario[j]);
}
