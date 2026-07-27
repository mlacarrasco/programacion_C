/* Codigo 10.11: Pila dinámica que reserva y amplía su capacidad con malloc y realloc, y guarda su contenido en un archivo de texto */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Capitulo 10 */

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
   int *datos;
   int tope;
   int capacidad;
} Pila;

void crear_pila(Pila *p, int capacidad_inicial)
{
   p->datos = (int*) malloc(capacidad_inicial*sizeof(int));
   p->tope = -1;
   p->capacidad = capacidad_inicial;
}

void apilar(Pila *p, int valor)
{
   if (p->tope+1 == p->capacidad)
   {
      p->capacidad = p->capacidad * 2;
      p->datos = (int*) realloc(p->datos, p->capacidad*sizeof(int));
   }
   p->tope++;
   p->datos[p->tope] = valor;
}

void guardar_pila(Pila *p, char nombre_archivo[])
{
   FILE *archivo;
   int i;

   archivo = fopen(nombre_archivo, "w");

   if (archivo == NULL)
   {
      printf("No fue posible crear el archivo.\n");
      return;
   }

   //recorre desde la base (posición 0) hasta el tope, sin desapilar
   for (i=0; i<=p->tope; i++)
      fprintf(archivo, "%d\n", p->datos[i]);

   fclose(archivo);
}

int main()
{
   Pila p;

   crear_pila(&p, 2);   //capacidad inicial pequeña, a propósito

   apilar(&p, 10);
   apilar(&p, 20);
   apilar(&p, 30);   //la tercera apilada ya duplica la capacidad a 4

   guardar_pila(&p, "pila.txt");

   printf("Pila guardada en pila.txt, con %d elementos.", p.tope+1);

   free(p.datos);
}
