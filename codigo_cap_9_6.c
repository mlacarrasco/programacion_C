/* Codigo 9.6: Inserción recursiva de un valor en un árbol binario de búsqueda */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Capitulo 9 */

NodoArbol* insertar(NodoArbol *raiz, int valor)
{
   if (raiz == NULL)            //caso base: se encontró la posición vacía
   {
      raiz = (NodoArbol*) malloc(sizeof(NodoArbol));
      raiz->valor = valor;
      raiz->izquierdo = NULL;
      raiz->derecho = NULL;
   }
   else if (valor < raiz->valor)   //caso recursivo
      raiz->izquierdo = insertar(raiz->izquierdo, valor);
   else                            //caso recursivo
      raiz->derecho = insertar(raiz->derecho, valor);

   return(raiz);
}
