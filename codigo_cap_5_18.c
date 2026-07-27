/* Codigo 5.18: Función que convierte una nota de escala chilena a porcentaje */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Capitulo 5 */

#include <stdio.h>

float nota_a_porcentaje(float nota){

   float porcentaje;
   porcentaje = (nota-1)/6*100;  
   return(porcentaje);
}

int main(){

   float nota, porcentaje;

   printf("Ingrese una nota (1.0 a 7.0): ");
   scanf("%f", &nota);

   porcentaje = nota_a_porcentaje(nota);
   printf("Equivale a un %.1f%%", porcentaje);
}
