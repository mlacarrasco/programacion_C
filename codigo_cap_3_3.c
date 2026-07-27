/* Codigo 3.3: Ejemplo de dos bifurcadores lógicos IF anidados */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Capitulo 3 */

	
int a=5, b=8, c=1;
 
  if (a<b && c==1)
  {
     c = a*b;
     c++;
     
     if (c==41)
        a= 10;  
  }
