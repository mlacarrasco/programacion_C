/* Codigo anexoB.12: fragmento de respuesta a ejercicio */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Anexo B (Respuestas a los ejercicios) */

#include <stdio.h>

int main()
{
   int n, original, invertido=0, digito;

   printf("Ingrese un numero entero: ");
   scanf("%d", &n);

   original = n;

   while (n > 0)
   {
      digito = n%10;
      invertido = invertido*10 + digito;
      n = n/10;
   }

   if (original == invertido)
      printf("Es capicua");
   else
      printf("No es capicua");
}
