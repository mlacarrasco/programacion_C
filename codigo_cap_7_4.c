/* Codigo 7.4: Copia del contenido completo de una estructura */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Capitulo 7 */

struct persona alumno = {"Ana", 20, 6.2};
struct persona copia;

copia = alumno;   //copia los tres campos de una sola vez
