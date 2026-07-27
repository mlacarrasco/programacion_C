/* Codigo anexoB.45: fragmento de respuesta a ejercicio */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Anexo B (Respuestas a los ejercicios) */

void recorrer(int *vector, int tamano)
{
   int *p;

   for (p=vector; p<vector+tamano; p++)
      printf("%d ", *p);
}
