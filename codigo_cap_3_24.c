/* Codigo 3.24: Uso de la instrucción CONTINUE para omitir los números pares */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Capitulo 3 */

int i;

for (i=0; i<10; i++){

   if (i%2==0)
   {
      continue;
   }
   printf("%d ", i);
}
