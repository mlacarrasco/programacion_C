/* Codigo 4.23: Programa que despliega el menú del día de la semana */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Capitulo 4 */

#include <stdio.h>

int main(){
   int dia;	
   printf("Ingrese un dia de la semana (1 al 7): ");
   if (scanf("%d", &dia)==1){
	printf("El Chef recomienda para el dia \n");
	
      switch (dia) {
        case 1:
          printf("Lunes: Cappelletti a la Emiliana\n");
          break;
        case 2:
          printf("Martes: Fettuccine a la papalina\n");
          break;
        case 3: 
          printf("Miércoles: Macarrones con la coliflor\n");
          break;
        case 4:
          printf("Jueves: Macarrones con queso y pimienta\n");
          break;
        case 5:
          printf("Viernes: Fusilli a la salchicha\n");
          break;
        case 6:
          printf("Sábado: Spaghetti a la Carbonara\n");
          break;
        case 7:
          printf("Domingo: Tortellini\n");
          break;
	default:
          printf("Ingrese un número entre 1 y 7");
          break;
          }
   }
   else{
	   printf("Ingrese un número entre 1 y 7");
   }
}
