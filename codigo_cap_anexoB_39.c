/* Codigo anexoB.39: fragmento de respuesta a ejercicio */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Anexo B (Respuestas a los ejercicios) */

float promedio_edad(struct persona curso[], int tamano)
{
   int i, suma=0;

   for (i=0; i<tamano; i++)
      suma = suma + curso[i].edad;

   return((float)suma / tamano);
}
