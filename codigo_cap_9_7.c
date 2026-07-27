/* Codigo 9.7: Recorrido inorden de un árbol binario */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Capitulo 9 */

void inorden(NodoArbol *raiz)
{
   if (raiz != NULL)
   {
      inorden(raiz->izquierdo);
      printf("%d ", raiz->valor);
      inorden(raiz->derecho);
   }
}
