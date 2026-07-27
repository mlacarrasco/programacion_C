/* Codigo 6.30: Llamado a la función transponer desde la función principal */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Capitulo 6 */

int main()
{
   int datos[4][4] = { {4, 2, 3, 7},
                       {1, 5, 9, 2},
                       {8, 3, 6, 4},
                       {3, 1, 5, 0} };
   int i, j;

   transponer(datos, 4);

   for (i=0; i<4; i++){
      for (j=0; j<4; j++)
         printf("%d ", datos[i][j]);

      printf("\n");
   }
}
