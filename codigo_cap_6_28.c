/* Codigo 6.28: Llamado a la función fusionar desde la función principal */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Capitulo 6 */

int main()
{
   int A[3] = {2, 5, 8};
   int B[4] = {1, 3, 6, 9};
   int C[7];
   int i;

   fusionar(A, 3, B, 4, C);

   for (i=0; i<7; i++)
      printf("%d ", C[i]);
}
