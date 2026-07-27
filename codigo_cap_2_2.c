/* Codigo 2.2: Uso de la directiva \#define para definir una constante */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Capitulo 2 */

#include <stdio.h>
#define PI 3.1415

int main()
{
   float radio, area;

   radio = 4;
   area = PI*radio*radio;
   printf("Area: %.2f", area);
}
