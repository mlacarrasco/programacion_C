/* Codigo anexoB.40: fragmento de respuesta a ejercicio */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Anexo B (Respuestas a los ejercicios) */

struct persona *mejor_promedio(struct persona curso[], int tamano)
{
   struct persona *mejor;
   int i;

   mejor = &curso[0];

   for (i=1; i<tamano; i++)
   {
      if (curso[i].promedio > mejor->promedio)
         mejor = &curso[i];
   }

   return(mejor);
}
