/* Codigo 7.19: Función que aplica un descuento a un vector de estructuras producto */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Capitulo 7 */

struct producto
{
   char nombre[30];
   float precio;
};

void aplicar_descuento(struct producto vector[],
                        int tamano, float porcentaje)
{
   int i;
   float p;

   for (i=0; i<tamano; i++)
   {
      p = vector[i].precio;
      vector[i].precio = p*(1-porcentaje/100);
   }
}
