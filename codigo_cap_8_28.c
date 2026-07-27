/* Codigo 8.28: Función que invierte una lista enlazada reenlazando sus nodos */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Capitulo 8 */

#include <stdio.h>
#include <stdlib.h>

typedef struct nodo
{
   int valor;
   struct nodo *siguiente;
} Nodo;

Nodo *invertir(Nodo *primero)
{
   Nodo *anterior, *actual, *siguiente;

   anterior = NULL;
   actual = primero;

   while (actual != NULL)
   {
      siguiente = actual->siguiente;  //guardamos el siguiente antes de perderlo
      actual->siguiente = anterior; //invertimos el enlace del nodo actual
      anterior = actual;  //actualizamos la nueva lista
      actual = siguiente;  //avanza al siguiente nodo
   }

   return(anterior);   //anterior queda apuntando al nuevo primer nodo
}

int main()
{
   Nodo *primero, *segundo, *tercero, *actual;

   primero = (Nodo*) malloc(sizeof(Nodo));
   segundo = (Nodo*) malloc(sizeof(Nodo));
   tercero = (Nodo*) malloc(sizeof(Nodo));

   primero->valor = 10;   primero->siguiente = segundo;
   segundo->valor = 20;   segundo->siguiente = tercero;
   tercero->valor = 30;   tercero->siguiente = NULL;

   primero = invertir(primero);

   //recorrido: despliega 30 20 10
   actual = primero;
   while (actual != NULL)
   {
      printf("%d ", actual->valor);
      actual = actual->siguiente;
   }
}
