/* Codigo anexoB.9: fragmento de respuesta a ejercicio */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Anexo B (Respuestas a los ejercicios) */

#include <stdio.h>

int main()
{
   float celsius, fahrenheit;

   printf("Ingrese la temperatura en Celsius: ");
   scanf("%f", &celsius);

   fahrenheit = celsius*9.0/5.0 + 32;

   printf("Equivale a %.2f Fahrenheit", fahrenheit);
}
