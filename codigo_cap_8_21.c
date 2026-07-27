/* Codigo 8.21: Función que modifica el promedio de una estructura a través de un puntero */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Capitulo 8 */

#include <stdio.h>

struct persona
{
   char nombre[30];
   int edad;
   float promedio;
};

void aplicar_bono(struct persona *p)
{
   p->promedio = p->promedio + 0.3;

   if (p->promedio > 7.0)
      p->promedio = 7.0;
}

int main()
{
   struct persona ana = {"Ana", 20, 6.9};

   aplicar_bono(&ana);

   //despliega 7.0, no 7.2, ya que el bono fue acotado
   printf("Nuevo promedio de %s: %.1f", ana.nombre, ana.promedio);
}
