/* Codigo 8.25: Función que busca un valor dentro de una lista enlazada */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Capitulo 8 */

#include <stdio.h>
#include <stdlib.h>

typedef struct nodo
{
   int valor;
   struct nodo *siguiente;
} Nodo;

Nodo *buscar(Nodo *primero, int valor)  //la función retorna un Nodo
{
   Nodo *actual;

   actual = primero;
   while (actual != NULL)
   {
      if (actual->valor == valor)
         return(actual);

      actual = actual->siguiente;
   }

   return(NULL);   //no se encontró el valor
}

int main()
{
   Nodo *primero, *segundo, *tercero, *encontrado;

   primero = (Nodo*) malloc(sizeof(Nodo));
   segundo = (Nodo*) malloc(sizeof(Nodo));
   tercero = (Nodo*) malloc(sizeof(Nodo));

   primero->valor = 10;   primero->siguiente = segundo;
   segundo->valor = 20;   segundo->siguiente = tercero;
   tercero->valor = 30;   tercero->siguiente = NULL;

   encontrado = buscar(primero, 20);

   if (encontrado != NULL)
      printf("Valor encontrado: %d", encontrado->valor);
   else
      printf("Valor no encontrado");
}
