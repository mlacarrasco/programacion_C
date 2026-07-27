/* Codigo 7.20: Llamado a la función aplicar\_descuento desde la función principal */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Capitulo 7 */

int main()
{
   struct producto vector[3] = { {"Mouse", 8000},
                                  {"Teclado", 15990},
                                  {"Monitor", 120000} };
   int i;

   aplicar_descuento(vector, 3, 10);

   for (i=0; i<3; i++)
   {
      printf("%s: ", vector[i].nombre);
      printf("%.0f\n", vector[i].precio);
   }
}
