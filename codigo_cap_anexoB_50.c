/* Codigo anexoB.50: fragmento de respuesta a ejercicio */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Anexo B (Respuestas a los ejercicios) */

int expresion_balanceada(char expresion[])
{
   Pila p;
   int i;

   p.tope = -1;

   for (i=0; expresion[i] != '\0'; i++)
   {
      if (expresion[i] == '(')
         apilar(&p, 1);
      else if (expresion[i] == ')')
      {
         if (pila_vacia(&p))
            return(0);   //cierre sin apertura correspondiente

         desapilar(&p);
      }
   }

   return(pila_vacia(&p));   //balanceada solo si no quedan parentesis pendientes
}
