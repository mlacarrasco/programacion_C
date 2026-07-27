/* Codigo 5.11: Función recursiva que calcula el n-ésimo término de la secuencia de Fibonacci */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Capitulo 5 */

int fibonacci(int n)
{
   if (n==0 || n==1)          //casos base
      return(n);
   else
      return( fibonacci(n-1) + fibonacci(n-2) );   //caso recursivo
}
