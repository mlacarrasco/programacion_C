/* Codigo 5.21: Función que determina si un número es primo */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Capitulo 5 */

#include <stdio.h>

int es_primo(int n){

   int i, primo=1;

   if (n<2)
      primo=0;

   for (i=2; i<n; i++)   {
      if (n%i==0){
         primo=0;
         break;
      }
   }

   return(primo);
}

int main(){

   int n;
   printf("Ingrese un numero entero positivo: ");
   scanf("%d", &n);

   if (es_primo(n))
      printf("%d es primo", n);
   else
      printf("%d no es primo", n);
}
