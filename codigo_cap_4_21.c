/* Codigo 4.21: Programa que transforma de grados Fahrenheit a grados Celsius */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Capitulo 4 */

#include <stdio.h>

int main()
{
   float C, F;

   printf("Ingrese temperatura en grados Fahrenheit: ");
   scanf("%f", &F);
	
   C = (F-32) * 5/9;	
   printf("La temperatura en Celsius es %.3f\n", C);
	
   if (C>=15){
 	printf("Alerta: Apagar estufa");
   }	
}
