/* Codigo anexoB.32: fragmento de respuesta a ejercicio */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Anexo B (Respuestas a los ejercicios) */

void a_mayusculas(char texto[])
{
   int i;

   for (i=0; texto[i] != '\0'; i++)
   {
      if (texto[i] >= 'a' && texto[i] <= 'z')
         texto[i] = texto[i] - 32;
   }
}
