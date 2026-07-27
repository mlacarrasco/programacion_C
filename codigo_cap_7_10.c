/* Codigo 7.10: Redefinición de una estructura empleando typedef */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Capitulo 7 */

typedef struct
{
   char nombre[30];
   int edad;
   float promedio;
} Persona;

int main()
{
   //no es necesario escribir struct en cada declaración
   Persona alumno = {"Ana", 20, 6.2};

   printf("%s tiene %d anos", alumno.nombre, alumno.edad);
}
