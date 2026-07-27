/* Codigo 5.15: Conversión de cadenas a valores numéricos con atoi y atof */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Capitulo 5 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
   char edad_texto[] = "17";
   char precio_texto[] = "990.50";

   int edad = atoi(edad_texto);
   float precio = atof(precio_texto);

   printf("Edad: %d años\n", edad);
   printf("Precio: %.2f\n", precio);
}
