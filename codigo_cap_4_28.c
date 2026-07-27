/* Codigo 4.28: Programa que determina el número $\pi$ */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Capitulo 4 */

#include <stdio.h>

int main()
{
   float acum, pi;
   int  n, iter;
	
   printf("Ingrese el número de iteraciones: ");
   scanf("%d", &iter);

   for (n=0; n<iter; n++) 
   {
      if (n%2==0)
         acum = acum + (float)  1/(2*n+1);
      else
         acum = acum + (float) -1/(2*n+1);
   }
	
   pi = acum*4;
   printf("El numero pi es: %f", pi);		
}
