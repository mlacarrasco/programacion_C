/* Codigo 4.27: Programa que transforma un número binario a decimal */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Capitulo 4 */

#include <stdio.h>

int main()
{
   int num_bin, digito, acum=0, exp=1;
    
   printf("Ingrese un número binario (solo ceros y unos):");
   scanf("%d",&num_bin);
    
   while (num_bin)
   {
      digito   = num_bin%10;
      num_bin  = num_bin /10; 
      acum     = acum + digito*exp;
      exp      = exp*2;
   }

   printf("El numero decimal es: %d",acum);
}
