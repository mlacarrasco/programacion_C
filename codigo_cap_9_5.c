/* Codigo 9.5: Declaración de un nodo para un árbol binario */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Capitulo 9 */

typedef struct nodoArbol
{
   int valor;
   struct nodoArbol *izquierdo;
   struct nodoArbol *derecho;
} NodoArbol;
