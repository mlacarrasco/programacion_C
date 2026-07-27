/* Codigo anexoB.17: fragmento de respuesta a ejercicio */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Anexo B (Respuestas a los ejercicios) */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
   int dado;

   srand(time(NULL));
   dado = rand()%6 + 1;

   printf("El dado cayo en: %d", dado);
}
