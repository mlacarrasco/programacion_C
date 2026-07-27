/* Codigo 6.20: Función que realiza una búsqueda binaria en un vector ordenado */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Capitulo 6 */

int busqueda_binaria(int vector[], int tamano, int buscado)
{
   int inicio=0, fin=tamano-1, medio;

   while (inicio <= fin)   {
      medio = (inicio+fin)/2;

      if (vector[medio] == buscado)
         return(medio);
      else if (buscado < vector[medio])
         fin = medio-1;      //descartamos la mitad derecha
      else
         inicio = medio+1;   //descartamos la mitad izquierda
   }
   return(-1);   //no se encontró el valor
}
