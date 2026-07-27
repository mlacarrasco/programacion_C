/* Codigo 9.8: Construcción y recorrido de un árbol binario de búsqueda */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Capitulo 9 */

int main()
{
   NodoArbol *raiz = NULL;

   raiz = insertar(raiz, -5);
   raiz = insertar(raiz, 2);
   raiz = insertar(raiz, -6);
   raiz = insertar(raiz, 0);
   raiz = insertar(raiz, 7);
   raiz = insertar(raiz, -8);

   inorden(raiz);   //despliega: -8 -6 -5 0 2 7
}
