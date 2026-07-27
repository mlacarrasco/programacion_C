/* Codigo 8.2: Declaración de un puntero y asignación de una dirección de memoria */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Capitulo 8 */

#include <stdio.h>

int main()
{
   int a=5;
   int *p;      //declaración de un puntero a entero

   p = &a;      //p almacena la dirección de memoria de a

   printf("Valor de a: %d\n", a);
   printf("Dirección de a: %p\n", (void*)&a);
   printf("Dirección de p: %p\n", (void*)p);
   printf("Valor apuntado por p: %d\n", *p);
}
