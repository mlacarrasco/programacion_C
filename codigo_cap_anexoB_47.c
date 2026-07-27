/* Codigo anexoB.47: fragmento de respuesta a ejercicio */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Anexo B (Respuestas a los ejercicios) */

int *duplicar_capacidad(int *vector, int tamano_actual)
{
   vector = (int*) realloc(vector, (tamano_actual*2)*sizeof(int));
   return(vector);
}
