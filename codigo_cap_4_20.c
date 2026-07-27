/* Codigo 4.20: Programa que determina el área de un rectángulo */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Capitulo 4 */

#include <stdio.h>

int main()
{
   float alto, ancho, resultado;
	
   printf("Ingrese el alto: ");
   scanf("%f", &alto);	
   
   printf("Ingrese el ancho: ");
   scanf("%f", &ancho);
		  
   resultado = alto* ancho;
   printf("El resultado es %.3f",resultado);
}
