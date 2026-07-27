/* Codigo 8.1: Impresión del valor y la dirección de memoria de una variable */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Capitulo 8 */

#include <stdio.h>

int main()
{
   int a=5;

   printf("Valor de a: %d\n", a);
   printf("Direccion de a: %p\n", (void*)&a);
}
