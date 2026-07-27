/* Codigo anexoB.27: fragmento de respuesta a ejercicio */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Anexo B (Respuestas a los ejercicios) */

int maximo_vector(int vector[], int tamano)
{
   int i, max;

   max = vector[0];

   for (i=1; i<tamano; i++)
   {
      if (vector[i] > max)
         max = vector[i];
   }

   return(max);
}
