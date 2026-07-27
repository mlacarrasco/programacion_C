/* Codigo 4.26: Programa que verifica si un número es mágico */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Capitulo 4 */

#include <stdio.h>

int main()
{
   int num, old_num, dig, acum=0;
   printf("Ingrese un número: ");
   scanf("%d",&num);
   old_num=num;
	
   while (num)  {
      dig  = num%10;
      acum = acum+dig;		
      num  = num/10;		
   }
	
   if (dig*dig==acum)
	printf("El número %d es magico\n", old_num );
   else
	printf("No es magico\n" );
}
