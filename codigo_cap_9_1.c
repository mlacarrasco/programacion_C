/* Codigo 9.1: Declaración de una pila e implementación de sus operaciones fundamentales */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Capitulo 9 */

typedef struct
{
   int datos[10];
   int tope;
} Pila;

int pila_vacia(Pila *p)
{
   return(p->tope == -1);
}

void apilar(Pila *p, int valor)
{
   p->tope++;
   p->datos[p->tope] = valor;
}

int desapilar(Pila *p)
{
   int valor;

   valor = p->datos[p->tope];
   p->tope--;

   return(valor);
}
