/* Codigo anexoB.23: fragmento de respuesta a ejercicio */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Anexo B (Respuestas a los ejercicios) */

int potencia(int b, int n)
{
   if (n == 0)               //caso base
      return(1);
   else
      return(b * potencia(b, n-1));   //caso recursivo
}
