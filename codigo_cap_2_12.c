/* Codigo 2.12: Asignación indirecta de  valores */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Capitulo 2 */

#include <stdio.h>

int main()
{
   int a = 4;

   a = a*2;
   a = a%(a/2);
   a = a+8;
   a = a-4;
}
