/* Codigo 2.11: Comparacion lógica anidada */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Capitulo 2 */

#include <stdio.h>

int main()
{
   int  a=10, b=15, c= 13, u, v;

   u =  (a<b) || (c>a)  && (c>c);
   v = ((a<b) || (c>a)) && (c>c);
}
