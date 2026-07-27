/* Codigo 4.24: Juego para adivinar un número secreto */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Capitulo 4 */

#include <stdio.h>

int main() 
{
   int numero, puntaje = 100;
   int secreto = 239421216;
   
   do{
	printf("Ingrese un número: ");
	scanf("%d",&numero);
	puntaje--;
		
	if (numero>secreto)
		printf("Es menor \n");
	else if (numero<secreto)
		printf("Es mayor \n");
	
    }while (numero!=secreto);
	
   printf("\nFelicitaciones! Adivinaste el número!\n");
   printf("Obtuviste  %d puntos", puntaje+1);

}
