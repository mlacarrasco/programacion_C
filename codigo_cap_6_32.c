/* Codigo 6.32: Llamado a la función valor\_maximo desde la función principal */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Capitulo 6 */

int main()
{
   int datos[4][4] = { {4, 2, 3, 7},
                       {1, 5, 9, 2},
                       {8, 3, 6, 4},
                       {3, 1, 5, 0} };
   int max, fila, columna;

   valor_maximo(datos, 4, &max, &fila, &columna);
   printf("Máximo: %d\n", max);
   printf("Fila: %d, Columna: %d", fila, columna);
}
