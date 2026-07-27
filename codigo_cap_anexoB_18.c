/* Codigo anexoB.18: fragmento de respuesta a ejercicio */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Anexo B (Respuestas a los ejercicios) */

#include <stdio.h>
#include <math.h>

int es_cuadrado_perfecto(int n)
{
   int raiz;

   raiz = (int) sqrt(n);

   return(raiz*raiz == n);
}
