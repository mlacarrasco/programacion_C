/* Codigo anexoB.1: fragmento de respuesta a ejercicio */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Anexo B (Respuestas a los ejercicios) */

#include <stdio.h>

int main()
{
   int n;

   printf("Ingrese un numero: ");
   scanf("%d", &n);

   if (n > 0)
      printf("Es positivo");
   else if (n < 0)
      printf("Es negativo");
   else
      printf("Es igual a cero");
}
