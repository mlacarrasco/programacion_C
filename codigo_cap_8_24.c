/* Codigo 8.24: Recorrido de un vector de estructuras empleando aritmética de punteros */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Capitulo 8 */

#include <stdio.h>

struct persona
{
   char nombre[30];
   int edad;
   float promedio;
};

void imprimir_aprobados(struct persona *curso, int tamano)
{
   struct persona *p;

   for (p=curso; p<curso+tamano; p++)
   {
      if (p->promedio >= 4.0)
         printf("%s\n", p->nombre);
   }
}

int main()
{
   struct persona curso[3] = { {"Ana",20,6.2}, 
                               {"Luis",22,3.5}, 
                               {"Eva",19,5.9} };

   imprimir_aprobados(curso, 3);
}
