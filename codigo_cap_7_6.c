/* Codigo 7.6: Función que recibe una estructura por valor */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Capitulo 7 */

void cumplir_anos(struct persona alumno)
{
   //modifica solo la copia local
   alumno.edad = alumno.edad + 1;
}

int main()
{
   struct persona ana = {"Ana", 20, 6.2};

   cumplir_anos(ana);

   //imprime 20, no 21 (la función solo modificó la copia)
   printf("Edad de Ana: %d", ana.edad);
}
