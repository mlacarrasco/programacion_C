/* Codigo 5.17: Ejemplos de conversión de datos de la biblioteca ctype.h */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Capitulo 5 */

#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char texto[] = "Hola Mundo 123!";
    int letras = 0, digitos = 0, espacios = 0;

    for (int i = 0; texto[i] != '\0'; i++) {
        if (isalpha(texto[i]))      letras++;
        else if (isdigit(texto[i])) digitos++;
        else if (isspace(texto[i])) espacios++;

        printf("%c", toupper(texto[i]));   // imprime todo en mayúsculas
    }

    printf("\nLetras: %d, Digitos: %d, Espacios: %d\n",
           letras, digitos, espacios);
    return 0;
}
