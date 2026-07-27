/* Codigo 2.15: Ejemplo de operadores de bits */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Capitulo 2 */

#include <stdio.h>

int main()
{
   int a=12, b=10;

   printf("a&b = %d\n", a&b);
   printf("a|b = %d\n", a|b);
   printf("a^b = %d\n", a^b);
   printf("~a = %d\n", ~a);
   printf("a<<1 = %d\n", a<<1);
   printf("a>>1 = %d\n", a>>1);
}
