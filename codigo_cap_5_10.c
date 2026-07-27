/* Codigo 5.10: Llamado a la función factorial desde la función principal */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Capitulo 5 */

//función principal
int main()
{
   int n, resultado;

   printf("Ingrese un número: ");
   scanf("%d",&n);

   resultado = factorial(n);
   printf("El factorial de %d es: %d", n, resultado);
}
