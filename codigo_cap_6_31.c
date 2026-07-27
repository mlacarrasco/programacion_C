/* Codigo 6.31: Función que determina el valor máximo de una matriz y su posición */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Capitulo 6 */

void valor_maximo(int datos[][4], int n, int *maximo,
                   int *fila, int *columna)
{
   int i, j;

   *maximo = datos[0][0];
   *fila = 0;
   *columna = 0;

   for (i=0; i<n; i++){
      for (j=0; j<n; j++){
         if (datos[i][j] > *maximo){
            *maximo = datos[i][j];
            *fila = i;
            *columna = j;
         }
      }
   }
}
