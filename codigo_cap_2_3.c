/* Codigo 2.3: Ejemplo de overflow al sobrepasar el rango de un tipo de dato */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Capitulo 2 */

#include <stdio.h>

int main()
{
   char valor = 127;   //valor maximo admitido por char

   valor = valor+1;
   printf("%d", valor);   //despliega -128, no 128
}
