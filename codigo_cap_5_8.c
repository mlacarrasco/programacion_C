/* Codigo 5.8: Función sin parámetros que retorna un valor */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Capitulo 5 */

#include <stdio.h>

//función sin parámetros que retorna un valor
int leer_numero(void){
   int n;

   printf("Ingrese un número: ");
   scanf("%d", &n);

   return(n);
}

//función principal
int main(){
   int a, b;

   a = leer_numero();
   b = leer_numero();

   printf("La suma es: %d", a+b);
}
