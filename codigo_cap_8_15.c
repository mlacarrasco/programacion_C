/* Codigo 8.15: Liberación de la memoria de todos los nodos de una lista enlazada */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Capitulo 8 */

Ficha *actual, *siguiente;

actual = primero;
while (actual != NULL){

   //guardamos la referencia antes de liberar
   siguiente = actual->siguiente;
   free(actual);
   actual = siguiente;
}
