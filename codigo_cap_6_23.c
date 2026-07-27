/* Codigo 6.23: Función que retorna la posición del valor mínimo de un vector */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Capitulo 6 */

int posicion_minimo(int vector[], int tamano)
{
   int i, pos=0;

   for (i=1; i<tamano; i++){
      if (vector[i] < vector[pos])
         pos = i;
   }

   return(pos);
}

int main()
{
   int notas[6] = {7, 3, 9, 1, 5, 2};
   int pos;

   pos = posicion_minimo(notas, 6);
   printf("Mínimo: %d, posición: %d", notas[pos], pos);
}
