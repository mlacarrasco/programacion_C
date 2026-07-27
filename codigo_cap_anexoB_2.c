/* Codigo anexoB.2: fragmento de respuesta a ejercicio */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Anexo B (Respuestas a los ejercicios) */

#include <stdio.h>

int main()
{
   float a, b, c;

   printf("Ingrese los tres lados: ");
   scanf("%f %f %f", &a, &b, &c);

   if (a==b && b==c)
      printf("Es equilatero");
   else if (a==b || b==c || a==c)
      printf("Es isosceles");
   else
      printf("Es escaleno");
}
