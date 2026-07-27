/* Codigo 2.4: Uso del operador sizeof sobre los principales tipos de datos */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Capitulo 2 */

#include <stdio.h>

int main()
{
   int tam_int, tam_float, tam_double, tam_char;

   tam_int    = sizeof(int);
   tam_float  = sizeof(float);
   tam_double = sizeof(double);
   tam_char   = sizeof(char);

   printf("int: %d bytes\n", tam_int);
   printf("float: %d bytes\n", tam_float);
   printf("double: %d bytes\n", tam_double);
   printf("char: %d bytes\n", tam_char);
}
