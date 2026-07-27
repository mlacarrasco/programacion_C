/* Codigo 5.1: Programa que llama a la función duplicar (Forma estándar) */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Capitulo 5 */

#include <stdio.h>

int duplicar(int a) //funcion interna
{
   int b;
   b= a*2;
   return(b);
}

//funcion principal
int main()
{
   int a, b;
   printf("numero: ");
   scanf("%d", &a);
   b = duplicar(a);
   printf("%d", b);
}
