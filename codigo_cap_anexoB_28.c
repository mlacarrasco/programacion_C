/* Codigo anexoB.28: fragmento de respuesta a ejercicio */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Anexo B (Respuestas a los ejercicios) */

int contar_pares(int vector[], int tamano)
{
   int i, contador=0;

   for (i=0; i<tamano; i++)
   {
      if (vector[i]%2 == 0)
         contador++;
   }

   return(contador);
}
