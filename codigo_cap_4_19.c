/* Codigo 4.19: Validación del valor de retorno de scanf */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Capitulo 4 */

#include <stdio.h>

int main()
{
   int edad;

   printf("Ingrese su edad: ");

   if (scanf("%d", &edad) == 1)
      printf("Edad ingresada: %d", edad);
   else
      printf("Error: debe ingresar un numero entero");
}
