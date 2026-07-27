/* Codigo anexoB.31: fragmento de respuesta a ejercicio */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Anexo B (Respuestas a los ejercicios) */

int contar_vocales(char texto[])
{
   int i, contador=0;

   for (i=0; texto[i] != '\0'; i++)
   {
      char c = texto[i];

      if (c=='a' || c=='e' || c=='i' || c=='o' || c=='u' ||
          c=='A' || c=='E' || c=='I' || c=='O' || c=='U')
         contador++;
   }

   return(contador);
}
