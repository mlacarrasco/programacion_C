/* Codigo 6.26: Función que rota los elementos de un vector una posición a la derecha */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Capitulo 6 */

void rotar_derecha(int vector[], int tamano)
{
   int i, ultimo;

   ultimo = vector[tamano-1];

   for (i=tamano-1; i>0; i--)
      vector[i] = vector[i-1];

   vector[0] = ultimo;
}

int main()
{
   int datos[5] = {10, 20, 30, 40, 50};
   int i;

   rotar_derecha(datos, 5);

   for (i=0; i<5; i++)
      printf("%d ", datos[i]);
}
