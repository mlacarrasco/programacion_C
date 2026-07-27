/* Codigo anexoB.8: fragmento de respuesta a ejercicio */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Anexo B (Respuestas a los ejercicios) */

#include <stdio.h>

int main()
{
   float radio;
   const float PI = 3.14159;

   printf("Ingrese el radio: ");
   scanf("%f", &radio);

   printf("Area: %.2f\n", PI*radio*radio);
   printf("Perimetro: %.2f\n", 2*PI*radio);
}
