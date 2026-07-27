/* Codigo anexoB.22: fragmento de respuesta a ejercicio */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Anexo B (Respuestas a los ejercicios) */

int es_primo(int n)
{
   int i;

   if (n < 2)
      return(0);

   for (i=2; i<n; i++)
   {
      if (n%i == 0)
         return(0);
   }

   return(1);
}
