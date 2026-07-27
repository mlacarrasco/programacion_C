/* Codigo 8.22: Función que retorna un puntero al alumno con mejor promedio de un vector de estructuras */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Capitulo 8 */

#include <stdio.h>

struct persona
{
   char nombre[30];
   int edad;
   float promedio;
};

struct persona *mejor_alumno(struct persona curso[], int tamano)
{
   struct persona *mejor;
   int i;

   mejor = &curso[0];

   for (i=1; i<tamano; i++)
   {
      if (curso[i].promedio > mejor->promedio)
         mejor = &curso[i];
   }

   return(mejor);
}

int main()
{
   struct persona curso[3] = { {"Ana",20,6.2}, 
                               {"Luis",22,6.8}, 
                               {"Eva",19,5.9} };
   struct persona *mejor;

   mejor = mejor_alumno(curso, 3);

   printf("El mejor alumno es %s, con promedio %.1f", mejor->nombre, mejor->promedio);
}
