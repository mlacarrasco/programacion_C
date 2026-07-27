/* Codigo 7.16: Funciones que calculan el área y el perímetro de un rectángulo */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Capitulo 7 */

struct rectangulo
{
   float base;
   float altura;
};

float area(struct rectangulo r)
{
   return(r.base * r.altura);
}

float perimetro(struct rectangulo r)
{
   return(2*(r.base + r.altura));
}

int main()
{
   struct rectangulo r = {5, 3};

   printf("Area: %.1f\n", area(r));
   printf("Perimetro: %.1f", perimetro(r));
}
