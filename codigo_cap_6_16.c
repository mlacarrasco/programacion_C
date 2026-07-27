/* Codigo 6.16: Función que ordena un vector empleando el algoritmo de ordenamiento burbuja */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Capitulo 6 */

void ordenamiento_burbuja(int vector[], int tamano)
{
   int i, j, tmp;

   for (i=0; i<tamano-1; i++)
   {
      for (j=0; j<tamano-1-i; j++)
      {
         if (vector[j] > vector[j+1])
         {
            //intercambio de valores
            tmp = vector[j];
            vector[j] = vector[j+1];
            vector[j+1] = tmp;
         }
      }
   }
}
