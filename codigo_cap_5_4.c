/* Codigo 5.4: Función con paso por valor */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Capitulo 5 */

	
int sumatoria(int a, int b) 
{
   int i,tmp,res=0;
   
   if (a>b)  {
     tmp=a;
     a=b;
     b=tmp;
   }
   
   for (i=a; i<=b; i++)
      res= res+i;

   return(res);
}
