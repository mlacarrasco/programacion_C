# Introducción a la Programación y la Algoritmia en C

Este repositorio contiene el código fuente de los ejemplos utilizados en el libro **"Introducción a la Programación y la Algoritmia en C"**, junto con las respuestas a los ejercicios propuestos en cada capítulo.

Cada archivo corresponde a un fragmento de código citado en el texto, y está nombrado según el capítulo y el número de código al que pertenece, siguiendo el formato:

```
codigo_cap_<capítulo>_<número>.c
```

Por ejemplo, `codigo_cap_6_16.c` corresponde al código 6.16 del capítulo 6.

## Contenidos del libro

| Capítulo | Tema |
|---|---|
| 1 | Introducción a la programación y la algoritmia |
| 2 | Variables y tipos de datos |
| 3 | Estructuras de control (condicionales y ciclos) |
| 4 | Entrada y salida estándar (`printf`, `scanf`) |
| 5 | Funciones |
| 6 | Vectores, matrices y cadenas de caracteres |
| 7 | Estructuras (`struct`) |
| 8 | Punteros y memoria dinámica |
| 9 | Estructuras de datos (pilas, colas y árboles binarios) |
| 10 | Manejo de archivos |
| Anexo A | Compilación y ejecución de programas en C |
| Anexo B | Respuestas a los ejercicios de cada capítulo |

Las respuestas completas a los ejercicios propuestos se encuentran en [`respuestas_anexoB.md`](respuestas_anexoB.md), y su código asociado en los archivos `codigo_cap_anexoB_*.c`.

## Cómo compilar y ejecutar los ejemplos

Los ejemplos están escritos en C estándar y pueden compilarse con `gcc` (ver Anexo A):

```bash
gcc codigo_cap_1_3.c -o programa
./programa
```

Algunos códigos son fragmentos incompletos (esquemas generales, declaraciones o funciones sueltas) pensados para ilustrar un concepto puntual y no compilan de forma independiente; estos se identifican por su comentario inicial, que indica el número y la descripción del código dentro del libro.

## Licencia

Este proyecto se distribuye bajo licencia [CC0 1.0 Universal](LICENSE): el código se encuentra en dominio público y puede ser usado, copiado, modificado y distribuido libremente, incluso con fines comerciales, sin necesidad de solicitar permiso.
