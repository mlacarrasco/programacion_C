/* Codigo 8.14: Construcción de una lista de fichas empleando la función insertar\_al\_final */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Capitulo 8 */

int main()
{
   Ficha *primero = NULL, *actual;

   primero = insertar_al_final(primero, 1, "Pedro");
   primero = insertar_al_final(primero, 2, "Juan");
   primero = insertar_al_final(primero, 3, "Marta");

   //recorrido: despliega 1-Pedro 2-Juan 3-Marta
   actual = primero;
   while (actual != NULL)
   {
      printf("%d-%s ", actual->id, actual->nombre);
      actual = actual->siguiente;
   }
}
