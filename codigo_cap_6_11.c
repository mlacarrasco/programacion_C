/* Codigo 6.11: Lectura de una línea completa de texto empleando fgets */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Capitulo 6 */

#include <stdio.h>
#include <string.h>

int main()
{
   char nombre[30];
   int largo;

   printf("Ingrese su nombre completo: ");
   fgets(nombre, 30, stdin);

   //fgets incluye el caracter '\n'; lo eliminamos si está presente
   largo = strlen(nombre);
   if (nombre[largo-1] == '\n')
   	// reemplazamos el símbolo que finaliza la cadena
      nombre[largo-1] = '\0';

   printf("Hola %s, bienvenido", nombre);
}
