/* Codigo 8.7: Programa que recibe dos números como argumentos de la línea de comandos */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Capitulo 8 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
   int a, b;

   if (argc != 3)
   {
      printf("Uso: %s <numero1> <numero2>\n", argv[0]);
      return(1);
   }

   a = atoi(argv[1]);   //convierte el string "10" en el entero 10
   b = atoi(argv[2]);

   printf("La suma es: %d\n", a+b);
}
