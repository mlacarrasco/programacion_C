/* Codigo 9.4: Uso de una cola para almacenar y recuperar valores en orden FIFO */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Capitulo 9 */

int main()
{
   Cola c;
   c.frente = NULL;
   c.final  = NULL;

   encolar(&c, 10);
   encolar(&c, 20);
   encolar(&c, 30);

   while (c.frente != NULL)
      printf("%d ", desencolar(&c));   //despliega: 10 20 30
}
