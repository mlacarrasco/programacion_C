/* Codigo 6.25: Función que cuenta la cantidad de valores distintos de un vector */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Capitulo 6 */

int contar_distintos(int vector[], int tamano)
{
   int i, j, distintos=0, repetido;

   for (i=0; i<tamano; i++)
   {
      repetido = 0;

      for (j=0; j<i; j++)
      {
         if (vector[i] == vector[j])
            repetido = 1;
      }

      if (repetido == 0)
         distintos = distintos+1;
   }

   return(distintos);
}

int main()
{
   int valores[6] = {4, 2, 4, 7, 2, 4};

   printf("Distintos: %d", contar_distintos(valores, 6));
}
