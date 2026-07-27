/* Codigo 6.27: Función que fusiona dos vectores ordenados en uno solo */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Capitulo 6 */

void fusionar(int A[], int tamA, int B[], int tamB,
              int C[])
{
   int i=0, j=0, k=0;

   // este ciclo copia los valores al arreglo C 
   // dado el menor valor en el arreglo A o B.
   while (i<tamA && j<tamB){
      if (A[i] <= B[j]){
         C[k] = A[i];
         i = i+1;
      }
      else{
         C[k] = B[j];
         j = j+1;
      }
      k = k+1;
   }

   while (i<tamA){ //copia los restantes elementos de A
      C[k] = A[i];
      i = i+1;
      k = k+1;
   }

   while (j<tamB) { //copia los restantes elementos de B
      C[k] = B[j];
      j = j+1;
      k = k+1;
   }
}
