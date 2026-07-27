/* Codigo 6.14: Copia y concatenación de cadenas empleando strcpy y strcat */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Capitulo 6 */

#include <stdio.h>
#include <string.h>

int main()
{
   char nombre[20] = "Ana";
   char apellido[20] = "Silva";
   char nombre_completo[50];

   strcpy(nombre_completo, nombre);
   strcat(nombre_completo, " ");
   strcat(nombre_completo, apellido);

   printf("Nombre completo: %s", nombre_completo);
}
