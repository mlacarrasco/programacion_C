/* Codigo 9.3: Declaración de una cola e implementación de sus operaciones fundamentales */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Capitulo 9 */

typedef struct nodo
{
   int valor;
   struct nodo *siguiente;
} Nodo;

typedef struct
{
   Nodo *frente;
   Nodo *final;
} Cola;

void encolar(Cola *c, int valor)
{
   Nodo *nuevo;

   nuevo = (Nodo*) malloc(sizeof(Nodo));
   nuevo->valor = valor;
   nuevo->siguiente = NULL;

   if (c->final == NULL)         //la cola se encontraba vacía
      c->frente = nuevo;
   else
      c->final->siguiente = nuevo;

   c->final = nuevo;
}

int desencolar(Cola *c)
{
   int valor;
   Nodo *tmp;

   valor = c->frente->valor;
   tmp = c->frente;
   c->frente = c->frente->siguiente;
   
   if (c->frente == NULL)     /* la cola quedó vacía */
      c->final = NULL;
   free(tmp);

   return(valor);
}
