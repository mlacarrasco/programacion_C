/* Codigo 8.23: Función que intercambia el contenido de dos estructuras mediante punteros */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Capitulo 8 */

#include <stdio.h>

struct persona
{
   char nombre[30];
   int edad;
   float promedio;
};

void intercambiar_alumnos(struct persona *a, struct persona *b)
{
   struct persona tmp;

   tmp = *a; //tmp toma el contenido  a (por el operador indirección)
   *a = *b;  //reemplazamos el contenido de a
   *b = tmp; //reemplazamos el contenido de b
}

int main()
{
   struct persona ana = {"Ana", 20, 6.2};
   struct persona luis = {"Luis", 22, 5.4};

   intercambiar_alumnos(&ana, &luis);

   printf("%s tiene %d anos\n", ana.nombre, ana.edad);    //ahora Luis, 22
   printf("%s tiene %d anos\n", luis.nombre, luis.edad);  //ahora Ana, 20
}
