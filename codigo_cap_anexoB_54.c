/* Codigo anexoB.54: fragmento de respuesta a ejercicio */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Anexo B (Respuestas a los ejercicios) */

int altura(NodoArbol *raiz)
{
   int alt_izq, alt_der;

   if (raiz == NULL)         //caso base: arbol vacio
      return(0);

   alt_izq = altura(raiz->izquierdo);
   alt_der = altura(raiz->derecho);

   if (alt_izq > alt_der)
      return(1 + alt_izq);
   else
      return(1 + alt_der);
}
