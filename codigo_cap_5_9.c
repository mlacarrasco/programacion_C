/* Codigo 5.9: Función recursiva que calcula el factorial de un número */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Capitulo 5 */

int factorial(int n)
{
   if (n==0)          //caso base
      return(1);
   else
      return( n*factorial(n-1) );   //caso recursivo
}
