/* Codigo 7.9: Función que retorna un puntero a una estructura encontrada dentro de un vector */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Capitulo 7 */

struct persona *buscar_alumno(struct persona curso[], 
                              int tamano, 
                              char nombre[])
{
   int i;

   for (i=0; i<tamano; i++)
   {
      if (strcmp(curso[i].nombre, nombre) == 0)
         return(&curso[i]);   //retorna la dirección del elemento encontrado
   }

   return(NULL);   //no se encontró ningún alumno con ese nombre
}

int main()
{
   struct persona curso[2] = { {"Ana",20,6.2}, {"Luis",22,5.4} };
   struct persona *encontrado;

   encontrado = buscar_alumno(curso, 2, "Luis");

   if (encontrado != NULL)
      printf("%s tiene %d anos", (*encontrado).nombre, (*encontrado).edad);
   else
      printf("Alumno no encontrado");
}
