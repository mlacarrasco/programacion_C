/* Codigo 8.27: Función recursiva que suma los valores de una lista enlazada */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Capitulo 8 */

#include <stdio.h>
#include <stdlib.h>

typedef struct nodo
{
   int valor;
   struct nodo *siguiente;
} Nodo;

int suma_lista(Nodo *primero)
{
   if (primero == NULL)      //caso base: lista vacía
      return(0);

   //caso recursivo
   return(primero->valor + suma_lista(primero->siguiente));
}

int main()
{
   Nodo *primero, *segundo, *tercero;
   int total;

   primero = (Nodo*) malloc(sizeof(Nodo));
   segundo = (Nodo*) malloc(sizeof(Nodo));
   tercero = (Nodo*) malloc(sizeof(Nodo));

   primero->valor = 10;   primero->siguiente = segundo;
   segundo->valor = 20;   segundo->siguiente = tercero;
   tercero->valor = 30;   tercero->siguiente = NULL;

   total = suma_lista(primero);

   printf("La suma total es: %d", total);   //despliega 60
}
