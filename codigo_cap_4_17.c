/* Codigo 4.17: Programa que lee dos números separados por una coma */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Capitulo 4 */

#include <stdio.h>

int main()
{
   int  a=10, b=5;
   
   scanf("%d",  &a);
   scanf("%d",  &b);
   a= a*b;
   printf("resultado: %d",a);
}
