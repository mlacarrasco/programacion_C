/* Codigo 6.9: Lectura de una cadena de caracteres desde el teclado */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Capitulo 6 */

#include <stdio.h>

int main()
{
   char nombre[30];

   printf("Ingrese su nombre: ");
   scanf("%s", nombre);

   printf("Hola %s, bienvenido", nombre);
}
