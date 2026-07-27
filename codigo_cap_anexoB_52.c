/* Codigo anexoB.52: fragmento de respuesta a ejercicio */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Anexo B (Respuestas a los ejercicios) */

int buscar_valor(NodoArbol *raiz, int valor)
{
   if (raiz == NULL)
      return(0);

   if (valor == raiz->valor)
      return(1);
   else if (valor < raiz->valor)
      return(buscar_valor(raiz->izquierdo, valor));
   else
      return(buscar_valor(raiz->derecho, valor));
}
