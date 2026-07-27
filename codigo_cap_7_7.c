/* Codigo 7.7: Función que retorna una estructura completa */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Capitulo 7 */

struct persona crear_persona(char nombre[30], int edad)
{
   struct persona nueva;

   strcpy(nueva.nombre, nombre);
   nueva.edad = edad;
   nueva.promedio = 0.0;   //aún no registra notas

   return(nueva);
}

int main()
{
   struct persona ana;

   ana = crear_persona("Ana", 20);
   printf("%s tiene %d años", ana.nombre, ana.edad);
}
