/* Codigo 5.5: Llamado desde la función principal */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Capitulo 5 */

//función principal
int main()
{
   int a,b,tmp;
   
   printf("ingrese el valor A: ");
   scanf("%d",&a);
   
   printf("ingrese el valor B: ");
   scanf("%d",&b);
   
   //llamado a la función
   tmp=sumatoria(a,b);
   printf("La sumatoria desde %d a %d es: %d", a,b,tmp);
}

