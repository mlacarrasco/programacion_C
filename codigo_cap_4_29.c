/* Codigo 4.29: Programa que determina el ahorro logrado con depósitos mensuales */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Capitulo 4 */

#include <stdio.h>

int main()
{
   double int_mensual, cuota, acum=0;
   int mes;
	
   printf("Ingrese número de meses: "); 
   scanf("%d", &mes);
	
   printf("Ingrese interés mensual: "); 
   scanf("%lf", &int_mensual);
	
   printf("Ingrese cuota mensual: ");
   scanf("%lf", &cuota);
	
   for (int i=0; i<mes; i++)
   {
       acum = (acum+cuota)*(1+int_mensual);
   }

   printf("En %d meses ha acumulado: $%.2f", mes, acum);
}
