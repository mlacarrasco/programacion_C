/* Codigo 5.25: Función que calcula dos resultados mediante parámetros por referencia */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Capitulo 5 */

#include <stdio.h>

void convertir_temperatura(float celsius,
                            float *fahrenheit,
                            float *kelvin){
                            
   *fahrenheit = celsius*9/5 + 32;
   *kelvin = celsius + 273.15;
}

int main(){

   float c, f, k;
   printf("Ingrese temperatura en Celsius: ");
   scanf("%f", &c);

   convertir_temperatura(c, &f, &k);
   printf("Fahrenheit: %.2f, Kelvin: %.2f", f, k);
}
