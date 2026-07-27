/* Codigo anexoB.36: fragmento de respuesta a ejercicio */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Anexo B (Respuestas a los ejercicios) */

struct persona crear_persona(char nombre[30], int edad, float promedio)
{
   struct persona nueva;

   strcpy(nueva.nombre, nombre);
   nueva.edad = edad;
   nueva.promedio = promedio;

   return(nueva);
}
