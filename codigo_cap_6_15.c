/* Codigo 6.15: Comparación de dos cadenas empleando strcmp */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Capitulo 6 */

#include <stdio.h>
#include <string.h>

int main()
{
   char clave[20];

   printf("Ingrese la clave: ");
   scanf("%s", clave);

   if (strcmp(clave, "secreto") == 0)
      printf("Clave correcta");
   else
      printf("Clave incorrecta");
}
