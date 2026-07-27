/* Codigo anexoB.16: fragmento de respuesta a ejercicio */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Anexo B (Respuestas a los ejercicios) */

#include <stdio.h>

int main()
{
   double int_mensual, cuota, retiro, acum=0;
   int mes, i;

   printf("Ingrese numero de meses: ");
   scanf("%d", &mes);

   printf("Ingrese interes mensual: ");
   scanf("%lf", &int_mensual);

   printf("Ingrese cuota mensual: ");
   scanf("%lf", &cuota);

   printf("Ingrese el retiro mensual: ");
   scanf("%lf", &retiro);

   for (i=0; i<mes; i++)
      acum = (acum + cuota - retiro) * (1+int_mensual);

   printf("En %d meses ha acumulado: $%.2f", mes, acum);
}
