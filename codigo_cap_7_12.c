/* Codigo 7.12: Definición y uso de una enumeración */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Capitulo 7 */

typedef enum {ROJO, AMARILLO, VERDE} Color;

int main()
{
   Color estado;
   estado = VERDE;

   if (estado==VERDE)
      printf("Puede avanzar");
   else
      printf("Debe detenerse");
}
