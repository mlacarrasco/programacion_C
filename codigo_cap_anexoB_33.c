/* Codigo anexoB.33: fragmento de respuesta a ejercicio */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Anexo B (Respuestas a los ejercicios) */

void ordenamiento_burbuja_descendente(int vector[], int tamano)
{
   int i, j, tmp;

   for (i=0; i<tamano-1; i++)
   {
      for (j=0; j<tamano-1-i; j++)
      {
         if (vector[j] < vector[j+1])   //unica diferencia: < en lugar de >
         {
            tmp = vector[j];
            vector[j] = vector[j+1];
            vector[j+1] = tmp;
         }
      }
   }
}
