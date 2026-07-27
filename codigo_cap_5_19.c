/* Codigo 5.19: Función que determina si un año es bisiesto */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Capitulo 5 */

#include <stdio.h>

int es_bisiesto(int anio){

   int bisiesto;
   bisiesto = (anio%4==0 && anio%100!=0) || (anio%400==0);
   return(bisiesto);
}

int main(){

   int anio;

   printf("Ingrese un año: ");
   scanf("%d", &anio);

   if (es_bisiesto(anio))
      printf("%d es bisiesto", anio);
   else
      printf("%d no es bisiesto", anio);
}
