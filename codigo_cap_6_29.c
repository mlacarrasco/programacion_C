/* Codigo 6.29: Función que transpone una matriz cuadrada de 4x4 */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Capitulo 6 */

void transponer(int datos[][4], int n)
{
   int i, j, tmp;

   for (i=0; i<n; i++){
      for (j=i+1; j<n; j++){
         tmp = datos[i][j];
         datos[i][j] = datos[j][i];
         datos[j][i] = tmp;
      }
   }
}
