/* Codigo anexoB.46: fragmento de respuesta a ejercicio */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Anexo B (Respuestas a los ejercicios) */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
   int i, mayor, valor;

   if (argc < 2)
   {
      printf("Uso: %s <numero1> [numero2 ...]\n", argv[0]);
      return(1);
   }

   mayor = atoi(argv[1]);

   for (i=2; i<argc; i++)
   {
      valor = atoi(argv[i]);
      if (valor > mayor)
         mayor = valor;
   }

   printf("El mayor valor es: %d", mayor);
}
