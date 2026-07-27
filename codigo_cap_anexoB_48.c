/* Codigo anexoB.48: fragmento de respuesta a ejercicio */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Anexo B (Respuestas a los ejercicios) */

Nodo *insertar_inicio(Nodo *primero, int valor)
{
   Nodo *nuevo;

   nuevo = (Nodo*) malloc(sizeof(Nodo));
   nuevo->valor = valor;
   nuevo->siguiente = primero;   //el nuevo nodo apunta al antiguo primero

   return(nuevo);   //el nuevo nodo pasa a ser el primero
}
