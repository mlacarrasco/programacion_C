/* Codigo 9.2: Uso de una pila para almacenar y recuperar valores en orden LIFO */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Capitulo 9 */

int main()
{
   Pila p;
   p.tope = -1;      //pila vacia

   apilar(&p, 10);
   apilar(&p, 20);
   apilar(&p, 30);

   while (!pila_vacia(&p))
      printf("%d ", desapilar(&p));   //despliega: 30 20 10
}
