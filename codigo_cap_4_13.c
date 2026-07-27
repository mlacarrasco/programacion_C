/* Codigo 4.13: Programa que  multiplica dos números leídos por el teclado */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Capitulo 4 */

#include <stdio.h>

int main()
{
   int  a, b, c;
   
   scanf("%d%d", &a, &b);
   
   c = a*b;
   printf("%d por %d es %d",a,b,c);
}
