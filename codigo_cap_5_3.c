/* Codigo 5.3: Ejemplo función duplicar  con paso por valor */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Capitulo 5 */

	
int duplicar(int a){
   int b;
   b=a*2;
   return(b);
}
   
int main(){
  int a, b;
  a =10;
  b = duplicar(a);
  printf("Es resultado es %d", b);
 }
