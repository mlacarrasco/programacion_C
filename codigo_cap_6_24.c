/* Codigo 6.24: Función que determina si un vector está ordenado en forma ascendente */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Capitulo 6 */

int esta_ordenado(int vector[], int tamano)
{
   int i;

   for (i=0; i<tamano-1; i++){
      if (vector[i] > vector[i+1])
         return(0);
   }

   return(1);
}

int main()
{
   int datos[5] = {2, 5, 5, 9, 12};

   if (esta_ordenado(datos, 5))
      printf("El vector está ordenado");
   else
      printf("El vector no está ordenado");
}
