/* Codigo anexoB.4: fragmento de respuesta a ejercicio */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Anexo B (Respuestas a los ejercicios) */

#include <stdio.h>

int main()
{
   int n, i, suma=0;

   printf("Ingrese N: ");
   scanf("%d", &n);

   for (i=1; i<=n; i++)
      suma = suma + i;

   printf("La suma es: %d", suma);
}
