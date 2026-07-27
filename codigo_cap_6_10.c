/* Codigo 6.10: Cálculo de la longitud de una cadena empleando strlen */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Capitulo 6 */

#include <stdio.h>
#include <string.h>

int main()
{
   char nombre[30];
   int largo;

   printf("Ingrese su nombre: ");
   scanf("%s", nombre);

   largo = strlen(nombre);
   printf("Su nombre tiene %d caracteres", largo);
}
