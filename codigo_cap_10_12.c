/* Codigo 10.12: Recorrido inorden que escribe cada valor del árbol en un archivo de texto */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Capitulo 10 */

#include <stdio.h>
#include <stdlib.h>

typedef struct nodoArbol
{
   int valor;
   struct nodoArbol *izquierdo;
   struct nodoArbol *derecho;
} NodoArbol;

NodoArbol* insertar(NodoArbol *raiz, int valor)
{
   if (raiz == NULL)
   {
      raiz = (NodoArbol*) malloc(sizeof(NodoArbol));
      raiz->valor = valor;
      raiz->izquierdo = NULL;
      raiz->derecho = NULL;
   }
   else if (valor < raiz->valor)
      raiz->izquierdo = insertar(raiz->izquierdo, valor);
   else
      raiz->derecho = insertar(raiz->derecho, valor);

   return(raiz);
}

void guardar_inorden(NodoArbol *raiz, FILE *archivo)
{
   if (raiz != NULL)
   {
      guardar_inorden(raiz->izquierdo, archivo);
      fprintf(archivo, "%d\n", raiz->valor);
      guardar_inorden(raiz->derecho, archivo);
   }
}

int main()
{
   NodoArbol *raiz = NULL;
   FILE *archivo;

   raiz = insertar(raiz, -5);
   raiz = insertar(raiz, 2);
   raiz = insertar(raiz, -6);
   raiz = insertar(raiz, 0);
   raiz = insertar(raiz, 7);
   raiz = insertar(raiz, -8);

   archivo = fopen("arbol_ordenado.txt", "w");

   if (archivo == NULL)
   {
      printf("No fue posible crear el archivo.\n");
      return(1);
   }

   guardar_inorden(raiz, archivo);

   fclose(archivo);

   printf("Árbol guardado en orden ascendente en arbol_ordenado.txt");
}
