/* Codigo 5.16: Simulación de un dado empleando la biblioteca stdlib.h */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Capitulo 5 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
   int dado;

   srand(time(NULL));
   dado = rand() % 6 + 1;

   printf("El dado cayó en: %d", dado);
}
