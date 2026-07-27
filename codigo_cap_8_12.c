/* Codigo 8.12: Declaración de un nodo de tipo ficha para una lista enlazada */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Capitulo 8 */

typedef struct ficha
{
   int id;
   char nombre[20];
   struct ficha *siguiente;
} Ficha;
