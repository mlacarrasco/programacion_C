/* Codigo 4.30: Programa que determina si un número es perfecto */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Capitulo 4 */

#include <stdio.h>

int main ()
{
   int a, b, acum=0;

   printf("Ingrese un número: ");
   scanf("%d", &a);
	
   for (b=a-1; b>0; b--)   {
      if (a%b==0)
          acum+=b;
   }	
   
    if(acum==a)
       printf("El numero %d es perfecto", a);
}
