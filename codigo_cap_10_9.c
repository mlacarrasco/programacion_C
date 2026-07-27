/* Codigo 10.9: Funciones que guardan y cargan un vector de estructuras persona desde un archivo de texto */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Capitulo 10 */

#include <stdio.h>

struct persona
{
   char nombre[30];
   int edad;
   float promedio;
};

void guardar_curso(struct persona curso[], int tamano, char nombre_archivo[])
{
   FILE *archivo;
   int i;

   archivo = fopen(nombre_archivo, "w");

   if (archivo == NULL)
   {
      printf("No fue posible crear el archivo.\n");
      return;
   }

   for (i=0; i<tamano; i++)
      fprintf(archivo, "%s %d %.1f\n", curso[i].nombre, curso[i].edad, curso[i].promedio);

   fclose(archivo);
}

int cargar_curso(struct persona curso[], char nombre_archivo[])
{
   FILE *archivo;
   int tamano=0;

   archivo = fopen(nombre_archivo, "r");

   if (archivo == NULL)
   {
      printf("No fue posible abrir el archivo.\n");
      return(0);
   }

   while (fscanf(archivo, "%s %d %f", curso[tamano].nombre,
                 &curso[tamano].edad, &curso[tamano].promedio) != EOF)
      tamano++;

   fclose(archivo);

   return(tamano);
}

int main()
{
   struct persona curso[10] = { {"Ana",20,6.2}, {"Luis",22,5.8} };
   int tamano, i;

   guardar_curso(curso, 2, "curso.txt");

   //curso queda reconstruido a partir del archivo, no de las líneas anteriores
   tamano = cargar_curso(curso, "curso.txt");

   for (i=0; i<tamano; i++)
      printf("%s (%d años): %.1f\n", curso[i].nombre, curso[i].edad, curso[i].promedio);
}
