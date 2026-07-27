/* Codigo anexoB.25: fragmento de respuesta a ejercicio */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Anexo B (Respuestas a los ejercicios) */

int maximo_iterativo(int A[], int p)
{
   int i, max;

   max = A[0];

   for (i=1; i<=p; i++)
   {
      if (A[i] > max)
         max = A[i];
   }

   return(max);
}
