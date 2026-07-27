/* Codigo anexoB.15: fragmento de respuesta a ejercicio */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Anexo B (Respuestas a los ejercicios) */

#include <stdio.h>

int main()
{
   int n, i;
   double termino=1, suma=0;

   printf("Ingrese la cantidad de terminos: ");
   scanf("%d", &n);

   for (i=0; i<n; i++)
   {
      if (i > 0)
         termino = termino/i;   //termino = 1/i!, acumulado progresivamente

      suma = suma + termino;
   }

   printf("Aproximacion de e: %.6f", suma);
}
