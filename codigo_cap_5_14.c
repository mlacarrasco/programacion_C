/* Codigo 5.14: Cálculo de la hipotenusa empleando la biblioteca math.h */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Capitulo 5 */

#include <stdio.h>
#include <math.h>

int main()
{
   float c1, c2, hipotenusa;

   printf("Ingrese el primer cateto: ");
   scanf("%f", &c1);

   printf("Ingrese el segundo cateto: ");
   scanf("%f", &c2);

   hipotenusa = sqrt(pow(c1,2) + pow(c2,2));
   printf("La hipotenusa es: %.2f", hipotenusa);
}
