/* Codigo 8.3: Función que intercambia dos valores empleando paso por referencia */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Capitulo 8 */

#include <stdio.h>

void swap(int *y, int *p)
{
   int tmp;

   tmp = *y;
   *y = *p;
   *p = tmp;
}

int main()
{
   int a, b;

   a = 5;
   b = 8;

   //paso por referencia: enviamos direcciones, no valores
   swap(&a, &b);    

   printf("a=%d b=%d", a, b);   //despliega a=8 b=5
}
