/* Codigo 8.26: Función que elimina un nodo de una lista enlazada */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Capitulo 8 */

#include <stdio.h>
#include <stdlib.h>

typedef struct nodo
{
   int valor;
   struct nodo *siguiente;
} Nodo;

Nodo *eliminar(Nodo *primero, int valor)
{
   Nodo *actual, *anterior;

   if (primero == NULL)
      return(NULL);   //lista vacía

   //caso especial: el nodo a eliminar es el primero
   if (primero->valor == valor)
   {
      actual = primero->siguiente;
      free(primero);
      return(actual);
   }

   //caso general: buscamos el nodo, recordando siempre al anterior
   anterior = primero;
   actual = primero->siguiente;

   while (actual != NULL)
   {
      if (actual->valor == valor)
      {
         anterior->siguiente = actual->siguiente;  // en este punto saltamos el nodo actual
         free(actual);
         return(primero); //retornamos la dirección del nodo inicial
      }

      anterior = actual;
      actual = actual->siguiente;
   }

   return(primero);   //no se encontró el valor, la lista no cambia
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

   primero = eliminar(primero, 20);   //elimina el nodo del medio

   //recorrido: despliega 10 30
   actual = primero;
   while (actual != NULL)
   {
      printf("%d ", actual->valor);
      actual = actual->siguiente;
   }
}
