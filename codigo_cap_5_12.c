/* Codigo 5.12: Función recursiva que calcula la suma de los elementos de un arreglo */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Capitulo 5 */

int sumatoria(int A[], int p)
{
   if (p==0)                              //caso base
      return(A[0]);
   else
      return( A[p] + sumatoria(A,p-1) );   //caso recursivo
}
