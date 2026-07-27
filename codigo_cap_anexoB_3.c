/* Codigo anexoB.3: fragmento de respuesta a ejercicio */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Anexo B (Respuestas a los ejercicios) */

#include <stdio.h>

int main()
{
   int dia;

   printf("Ingrese un numero entre 1 y 7: ");
   scanf("%d", &dia);

   switch (dia)
   {
      case 1: printf("Lunes"); break;
      case 2: printf("Martes"); break;
      case 3: printf("Miercoles"); break;
      case 4: printf("Jueves"); break;
      case 5: printf("Viernes"); break;
      case 6: printf("Sabado"); break;
      case 7: printf("Domingo"); break;
      default: printf("Numero invalido");
   }
}
