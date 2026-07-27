/* Codigo anexoB.49: fragmento de respuesta a ejercicio */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Anexo B (Respuestas a los ejercicios) */

int contar_nodos(Nodo *primero)
{
   int contador=0;
   Nodo *actual;

   actual = primero;
   while (actual != NULL)
   {
      contador++;
      actual = actual->siguiente;
   }

   return(contador);
}
