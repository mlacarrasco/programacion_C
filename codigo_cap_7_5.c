/* Codigo 7.5: Vector de estructuras y su recorrido */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Capitulo 7 */

#include <stdio.h>
#include <string.h>

struct persona
{
   char nombre[30];
   int edad;
   float promedio;
};

int main()
{
   struct persona curso[30];
   int i;

   strcpy(curso[0].nombre, "Ana");
   curso[0].edad = 20;
   curso[0].promedio = 6.2;

   strcpy(curso[1].nombre, "Luis");
   curso[1].edad = 22;
   curso[1].promedio = 5.4;

   for (i=0; i<2; i++)
   {
      printf("%s: ", curso[i].nombre);
      printf("%d anos, ", curso[i].edad);
      printf("promedio %.1f\n", curso[i].promedio);
   }
}
