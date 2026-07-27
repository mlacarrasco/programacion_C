/* Codigo 3.23: Término anticipado del ciclo  FOR por la instrucción BREAK */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Capitulo 3 */

	
int a=0, i;

for (i=0; i<10; i++){
    a= a+1;
    
    if (a==6)
    {
       break;
    }
}
