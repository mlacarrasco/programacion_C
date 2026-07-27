/* Codigo 5.2: Programa que llama a la función duplicar con un prototipo antes del main */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Capitulo 5 */

#include <stdio.h>

int duplicar(int a);  //prototipo de la función

//función principal
int main()
{
   int a, b;
   printf("numero: ");
   scanf("%d", &a);
   b= duplicar(a);
   printf("%d\n", b);
}

//funcion interna
int duplicar(int a)
{
   int b;
   b= a*2;
   return(b);
}
