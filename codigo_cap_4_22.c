/* Codigo 4.22: Programa que determina el promedio de las mayores dos notas */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Capitulo 4 */

#include <stdio.h>

int main()
{
   float nota1, nota2, nota3, prom;
	
   printf("Ingrese tres notas  (ej. 2.3, 3.4, 5.5): ");
   scanf("%f,%f,%f", &nota1, &nota2, &nota3);
	
   if (nota1>=nota3 && nota2>=nota3) {
 	prom = (nota1+nota2)/2;
   }
   else if(nota1>=nota2 && nota3>=nota2) {
 	prom = (nota1+nota3)/2;
   }
   else {
	prom = (nota2+nota3)/2;
   }
   
   printf("El promedio es %.3f", prom);
}
