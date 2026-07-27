/* Codigo 7.17: Función que cuenta los alumnos aprobados de un vector de estructuras */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Capitulo 7 */

struct alumno
{
   char nombre[30];
   float nota;
};

int contar_aprobados(struct alumno curso[], int tamano)
{
   int i, aprobados=0;

   for (i=0; i<tamano; i++)
   {
      if (curso[i].nota >= 4.0)
         aprobados = aprobados+1;
   }

   return(aprobados);
}

int main()
{
   struct alumno curso[4] = { {"Ana", 6.2},
                               {"Luis", 3.8},
                               {"Eva", 4.0},
                               {"Beto", 2.5} };

   printf("Aprobados: %d", contar_aprobados(curso, 4));
}
