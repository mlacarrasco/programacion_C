/* Codigo 10.6: Función que guarda el contenido de una lista enlazada en un archivo de texto */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Capitulo 10 */

#include <stdio.h>

typedef struct nodo
{
   int id;
   char nombre[20];
   struct nodo *siguiente;
} Nodo;

void guardar_lista(Nodo *primero, char nombre_archivo[])
{
   FILE *archivo;
   Nodo *actual;

   archivo = fopen(nombre_archivo, "w");

   if (archivo == NULL)
   {
      printf("No fue posible crear el archivo.\n");
      return;
   }

   for (actual=primero; actual!=NULL; actual=actual->siguiente)
      fprintf(archivo, "%d,%s\n", actual->id, actual->nombre);

   fclose(archivo);
}

int main()
{
   //lista de fichas ya enlazada (capítulo 8): 1-Pedro, 2-Juan, 3-Marta
   Nodo c = {3, "Marta", NULL};
   Nodo b = {2, "Juan", &c};
   Nodo a = {1, "Pedro", &b};

   guardar_lista(&a, "fichas.csv");

   printf("Lista guardada en fichas.csv");
}
