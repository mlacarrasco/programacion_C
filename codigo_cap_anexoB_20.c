/* Codigo anexoB.20: fragmento de respuesta a ejercicio */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Anexo B (Respuestas a los ejercicios) */

#include <stdio.h>

int calcular_edad(void)
{
   int nacimiento;

   printf("Ingrese su año de nacimiento: ");
   scanf("%d", &nacimiento);

   return(2026 - nacimiento);
}
