/* Codigo anexoC.2: Compilación de biblioteca.c como biblioteca compartida */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Anexo C */

gcc -shared -fPIC -o libbiblioteca.so biblioteca.c    # Linux
gcc -shared -fPIC -o libbiblioteca.dylib biblioteca.c # macOS
