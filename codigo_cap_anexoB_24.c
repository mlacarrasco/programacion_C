/* Codigo anexoB.24: fragmento de respuesta a ejercicio */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Anexo B (Respuestas a los ejercicios) */

int maximo(int A[], int p)
{
   if (p == 0)                        //caso base
      return(A[0]);

   int resto = maximo(A, p-1);        //caso recursivo

   if (A[p] > resto)
      return(A[p]);
   else
      return(resto);
}
