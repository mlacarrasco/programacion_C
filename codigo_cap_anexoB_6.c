/* Codigo anexoB.6: fragmento de respuesta a ejercicio */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Anexo B (Respuestas a los ejercicios) */

#include <stdio.h>

int main()
{
   int opcion;

   do
   {
      printf("1. Opcion A\n");
      printf("2. Opcion B\n");
      printf("3. Salir\n");
      printf("Ingrese una opcion: ");
      scanf("%d", &opcion);
   } while (opcion != 3);

   printf("Programa finalizado");
}
