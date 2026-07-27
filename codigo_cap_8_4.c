/* Codigo 8.4: Función que modifica una estructura a través de un puntero */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Capitulo 8 */

//estructura definida en el capítulo 7
struct persona
{
   char nombre[30];
   int edad;
   float promedio;
};

void cumplir_anos(struct persona *p)
{
   //equivalente a (*p).edad = (*p).edad + 1;
   p->edad = p->edad + 1;   
}

int main()
{
   struct persona ana = {"Ana", 20, 6.2};

   cumplir_anos(&ana);

   //ahora imprime 21
   printf("Edad de Ana: %d", ana.edad);
}
