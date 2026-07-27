/* Codigo 5.26: Función que calcula el interés ganado y el monto final mediante parámetros por referencia */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Capitulo 5 */

void calcular_interes(float capital, float tasa,
                       float *interes, float *monto_final)
{
   *interes = capital*tasa/100;
   *monto_final = capital + *interes;
}

int main()
{
   float capital, tasa, interes, total;

   printf("Ingrese el capital: ");
   scanf("%f", &capital);

   printf("Ingrese la tasa de interes (%%): ");
   scanf("%f", &tasa);

   calcular_interes(capital, tasa, &interes, &total);
   printf("Interes: %.2f\n", interes);
   printf("Monto final: %.2f", total);
}
