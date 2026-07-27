/* Codigo 5.20: Función que calcula el sueldo líquido a partir del sueldo bruto */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Capitulo 5 */

#include <stdio.h>

float sueldo_liquido(float bruto, float descuento){

   float liquido;
   liquido = bruto*(1-descuento/100);
   return(liquido);
}

int main(){
   float bruto, descuento, liquido;

   printf("Ingrese el sueldo bruto: ");
   scanf("%f", &bruto);

   printf("Ingrese el porcentaje de descuento: ");
   scanf("%f", &descuento);

   liquido = sueldo_liquido(bruto, descuento);
   printf("El sueldo líquido es: %.0f", liquido);
}
