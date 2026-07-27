/* Codigo anexoC.1: Archivo biblioteca.c con cuatro funciones que emplearemos desde Python */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Anexo C */

struct persona
{
   char nombre[30];
   int edad;
   float promedio;
};

int duplicar(int a)
{
   return(a*2);
}

void incrementar(int *p)
{
   (*p)++;
}

int suma_vector(int vector[], int tamano)
{
   int i, suma=0;

   for (i=0; i<tamano; i++)
      suma = suma + vector[i];

   return(suma);
}

void cumplir_anos(struct persona *p)
{
   p->edad = p->edad + 1;
}
