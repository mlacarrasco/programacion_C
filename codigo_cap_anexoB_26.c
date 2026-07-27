/* Codigo anexoB.26: fragmento de respuesta a ejercicio */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Anexo B (Respuestas a los ejercicios) */

int suma_vector(int vector[], int tamano)
{
   int i, suma=0;

   for (i=0; i<tamano; i++)
      suma = suma + vector[i];

   return(suma);
}
