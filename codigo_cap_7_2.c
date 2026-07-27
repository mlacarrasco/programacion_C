/* Codigo 7.2: Declaración de una variable de tipo estructura y acceso a sus campos */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Capitulo 7 */

struct persona alumno;

//el campo nombre es un vector de caracteres
strcpy(alumno.nombre, "Ana");
alumno.edad = 20;
alumno.promedio = 6.2;

printf("%s tiene %d años", alumno.nombre, alumno.edad);
printf(" y promedio %.1f", alumno.promedio);
