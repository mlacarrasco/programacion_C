/* Codigo 6.3: Acceso y asignación de elementos de un vector */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Capitulo 6 */

int notas[5] = {65, 42, 78, 91, 55};

notas[2] = 100;              //modifica el tercer elemento
printf("%d", notas[0]);      //imprime el primer elemento
notas[4] = notas[4] + 5;     //incrementa en 5 el último elemento
