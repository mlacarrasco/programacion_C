/* Codigo 7.14: Función que calcula la distancia de un punto al origen */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Capitulo 7 */

#include <math.h>

struct punto
{
   float x;
   float y;
};

float distancia_origen(struct punto p)
{
   return(sqrt(p.x*p.x + p.y*p.y));
}

int main()
{
   struct punto p = {3, 4};
   float distancia;

   distancia = distancia_origen(p);
   printf("Distancia al origen: %.2f", distancia);
}
