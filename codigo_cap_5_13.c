/* Codigo 5.13: Llamado a la función sumatoria desde la función principal */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Capitulo 5 */

int main()
{
   int A[5] = {4, 2, 3, 7, 0};
   int suma;

   suma = sumatoria(A, 4);   //4 es el índice del último elemento
   printf("La suma es: %d", suma);
}
