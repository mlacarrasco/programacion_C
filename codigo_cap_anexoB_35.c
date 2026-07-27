/* Codigo anexoB.35: fragmento de respuesta a ejercicio */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Anexo B (Respuestas a los ejercicios) */

int es_simetrica(int datos[][4], int n)
{
   int i, j;

   for (i=0; i<n; i++)
   {
      for (j=i+1; j<n; j++)   //solo se necesita comparar la mitad superior
      {
         if (datos[i][j] != datos[j][i])
            return(0);
      }
   }

   return(1);
}
