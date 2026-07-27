/* Codigo anexoB.10: fragmento de respuesta a ejercicio */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Anexo B (Respuestas a los ejercicios) */

#include <stdio.h>

int main()
{
   float n1, n2, n3, menor;

   printf("Ingrese tres notas: ");
   scanf("%f %f %f", &n1, &n2, &n3);

   menor = n1;
   if (n2 < menor) menor = n2;
   if (n3 < menor) menor = n3;

   printf("La menor nota es: %.1f", menor);
}
