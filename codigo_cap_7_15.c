/* Codigo 7.15: Función que determina si el año de una fecha es bisiesto */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Capitulo 7 */

struct fecha
{
   int dia;
   int mes;
   int anio;
};

int es_bisiesto(struct fecha f)
{
   if (f.anio%4==0 && f.anio%100!=0)
      return(1);
   else if (f.anio%400==0)
      return(1);
   else
      return(0);
}

int main()
{
   struct fecha f = {29, 2, 2024};

   if (es_bisiesto(f))
      printf("El anio %d es bisiesto", f.anio);
   else
      printf("El anio %d no es bisiesto", f.anio);
}
