/* Codigo anexoB.29: fragmento de respuesta a ejercicio */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Anexo B (Respuestas a los ejercicios) */

void invertir(int vector[], int tamano)
{
   int i, tmp;

   for (i=0; i<tamano/2; i++)
   {
      tmp = vector[i];
      vector[i] = vector[tamano-1-i];
      vector[tamano-1-i] = tmp;
   }
}
