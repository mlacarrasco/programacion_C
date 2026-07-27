/* Codigo 5.22: Función que retorna el mayor de tres números */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Capitulo 5 */

#include <stdio.h>

float mayor(float a, float b, float c){

   float max;
   max = a;

   if (b>max)
      max = b;

   if (c>max)
      max = c;

   return(max);
}

int main(){

   float nota1, nota2, nota3;

   printf("Ingrese tres notas: ");
   scanf("%f %f %f", &nota1, &nota2, &nota3);

   printf("La mayor nota es: %.1f", mayor(nota1, nota2, nota3));
}
