/* Codigo 6.18: Función que ordena un vector empleando el algoritmo de ordenamiento por selección */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Capitulo 6 */

void ordenamiento_seleccion(int vector[], int tamano)
{
   int i, j, menor, tmp;

   for (i=0; i<tamano-1; i++) {
      //se asume que el menor es el primero de la porción restante
      menor = i;   
      for (j=i+1; j<tamano; j++)   {
         if (vector[j] < vector[menor])
            menor = j;
      }
      //intercambio del menor valor encontrado con la posición actual
      tmp = vector[i];
      vector[i] = vector[menor];
      vector[menor] = tmp;
   }
}
