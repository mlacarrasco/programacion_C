/* Codigo 8.13: Función que inserta una nueva ficha al final de una lista enlazada */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Capitulo 8 */

Ficha* insertar_al_final(Ficha *primero, int id, char nombre[])
{
   Ficha *nueva, *nodo_virtual;

   //Paso 1: creamos el nuevo nodo, aun sin enlazar
   nueva = (Ficha*) malloc(sizeof(Ficha));
   nueva->id = id;
   strcpy(nueva->nombre, nombre);
   nueva->siguiente = NULL;

   if (primero == NULL)          //la lista se encontraba vacia
      return(nueva);

   //Paso 2: buscamos el ultimo nodo de la lista
   nodo_virtual = primero;
   while (nodo_virtual->siguiente != NULL)
      nodo_virtual = nodo_virtual->siguiente;

   //Paso 3: enlazamos el nuevo nodo al final
   nodo_virtual->siguiente = nueva;

   return(primero);
}
