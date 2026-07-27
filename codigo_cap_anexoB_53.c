/* Codigo anexoB.53: fragmento de respuesta a ejercicio */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Anexo B (Respuestas a los ejercicios) */

int contar_nodos(NodoArbol *raiz)
{
   if (raiz == NULL)         //caso base: arbol vacio
      return(0);

   return(1 + contar_nodos(raiz->izquierdo) + contar_nodos(raiz->derecho));
}
