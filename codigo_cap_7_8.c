/* Codigo 7.8: Función que retorna una estructura modificada */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Capitulo 7 */

struct persona cumplir_anos(struct persona alumno)
{
   alumno.edad = alumno.edad + 1;
   return(alumno);
}

int main()
{
   struct persona ana = {"Ana", 20, 6.2};

   //reasignamos el resultado retornado por la función
   ana = cumplir_anos(ana);

   //ahora imprime 21
   printf("Edad de Ana: %d", ana.edad);
}
