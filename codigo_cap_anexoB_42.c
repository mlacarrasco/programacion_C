/* Codigo anexoB.42: fragmento de respuesta a ejercicio */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Anexo B (Respuestas a los ejercicios) */

typedef enum {LUNES, MARTES, MIERCOLES, JUEVES, VIERNES, SABADO, DOMINGO} Dia;

int es_fin_de_semana(Dia d)
{
   return(d==SABADO || d==DOMINGO);
}
