/* Codigo 4.11: Programa que determinar el cuadrado de un número leído por teclado */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Capitulo 4 */

#include <stdio.h>

int main()
{
   int  a, b;
   
   scanf("%d", &a);
   
   b = a*a;
   printf("El cuadrado de %d  es %d ",a,b);
}
