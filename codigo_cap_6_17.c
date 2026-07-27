/* Codigo 6.17: Llamado a la función ordenamiento\_burbuja desde la función principal */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Capitulo 6 */

int main()
{
   int vector[5] = {4, 2, 3, 7, 0};
   int i;

   ordenamiento_burbuja(vector, 5);

   for (i=0; i<5; i++)
      printf("%d ", vector[i]);
}
