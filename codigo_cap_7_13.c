/* Codigo 7.13: Función que calcula el valor total de un producto */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Capitulo 7 */

struct producto
{
   char nombre[30];
   float precio;
   int cantidad;
};

float valor_total(struct producto p)
{
   return(p.precio * p.cantidad);
}

int main()
{
   struct producto p = {"Teclado", 15990, 3};
   float total;

   total = valor_total(p);
   printf("Valor total: %.0f", total);
}
