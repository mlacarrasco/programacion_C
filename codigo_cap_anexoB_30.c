/* Codigo anexoB.30: fragmento de respuesta a ejercicio */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Anexo B (Respuestas a los ejercicios) */

#include <stdio.h>
#include <string.h>

int main()
{
   char nombre[50];

   printf("Ingrese su nombre completo: ");
   fgets(nombre, 50, stdin);

   nombre[strcspn(nombre, "\n")] = '\0';   //elimina el salto de linea

   printf("Hola, %s", nombre);
}
