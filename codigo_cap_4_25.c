/* Codigo 4.25: Generación de un número secreto distinto en cada ejecución */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Capitulo 4 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
   int secreto;

   //semilla distinta en cada ejecución
   srand(time(NULL));
   secreto = rand()%100;    //numero secreto entre 0 y 99

   printf("Secreto (solo verificación): %d", secreto);
}
