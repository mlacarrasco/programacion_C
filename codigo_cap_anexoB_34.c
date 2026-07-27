/* Codigo anexoB.34: fragmento de respuesta a ejercicio */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Anexo B (Respuestas a los ejercicios) */

int suma_diagonal(int matriz[3][3])
{
   int i, suma=0;

   for (i=0; i<3; i++)
      suma = suma + matriz[i][i];

   return(suma);
}
