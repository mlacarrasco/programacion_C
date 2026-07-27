/* Codigo 6.19: Función que realiza una búsqueda lineal en un vector */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Capitulo 6 */

//retorna el índice del valor buscado, o -1 si no se encuentra
int busqueda_lineal(int vector[], int tamano, int buscado)
{
   int i;

   for (i=0; i<tamano; i++)   {
      if (vector[i]==buscado)
         return(i);
   }
   
   return(-1);   //no se encontró el valor
}
