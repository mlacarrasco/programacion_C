/* Codigo anexoB.51: fragmento de respuesta a ejercicio */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Anexo B (Respuestas a los ejercicios) */

void invertir_pila(Pila *p)
{
   Pila aux;
   aux.tope = -1;

   while (!pila_vacia(p))
      apilar(&aux, desapilar(p));

   *p = aux;   //copiamos la pila completa, tal como estudiamos en el capitulo 7
}
