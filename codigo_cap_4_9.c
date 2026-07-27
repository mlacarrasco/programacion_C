/* Codigo 4.9: Programa que modifica la presentación de los resultados */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Capitulo 4 */

	
#include <stdio.h>

int main()
{
   float a, b, c;
   a = 10;
   b = 2.5;
   c = a*b;
   
   printf("%.0f por %.1f \n",a,b);
   printf("es:\t\t\t%.1f\n", c);
   printf("a-b es:\t%.2f", a-b);
}
