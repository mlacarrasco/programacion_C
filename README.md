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

### Un solo archivo, con `gcc`

Los ejemplos están escritos en C estándar y pueden compilarse individualmente con `gcc` (ver Anexo A):

```bash
gcc codigo_cap_1_3.c -o programa
./programa
```

### Todo el repositorio, con `make`

El repositorio incluye un [`Makefile`](Makefile) que compila, sin necesidad de invocar `gcc` manualmente, los **119 códigos que son programas completos y autocontenidos** (es decir, los que no dependen de otro fragmento del libro para compilar):

```bash
make                     # compila todos los programas autocontenidos en ./bin
make chapter N=6         # compila sólo los del capítulo 6
make chapter N=anexoB    # compila sólo los del Anexo B
make run FILE=codigo_cap_6_16.c   # compila y ejecuta un código puntual
make list                # lista los binarios ya compilados en ./bin
make clean               # elimina ./bin
make help                # resumen de los comandos disponibles
```

Cada archivo se compila como un programa independiente y su binario queda en `bin/` con el mismo nombre (sin la extensión `.c`), por ejemplo `bin/codigo_cap_6_16`. `make` usa `-std=c11 -Wall -Wextra` y enlaza con la biblioteca matemática (`-lm`), necesaria para los ejemplos del capítulo 5 que usan `math.h`. Con esta selección, `make` siempre termina sin errores de compilación.

**Sobre los códigos que quedan fuera del `Makefile`:** el resto de los archivos del repositorio son deliberadamente incompletos —esquemas generales (`if`, `while`, `for`), declaraciones sueltas (una `struct`, un vector), o la segunda mitad de un ejemplo que se apoya en una función definida en el código anterior (p. ej. `codigo_cap_5_9.c` define `factorial` y `codigo_cap_5_10.c` lo invoca desde `main`)—. No se incluyen en el `Makefile` porque no compilan de forma independiente; para ejecutar uno de estos ejemplos, basta con concatenar manualmente el fragmento con el código del que depende (normalmente el inmediatamente anterior) y compilarlo con `gcc`, o con `make run FILE=<archivo_combinado>.c`.

Los scripts `codigo_cap_anexoA_*.sh` del Anexo A ilustran comandos de terminal (compilación, ejecución, argumentos) y no están pensados para ejecutarse tal cual, sino como referencia de la sintaxis empleada.

## Licencia

Este proyecto se distribuye bajo licencia [CC0 1.0 Universal](LICENSE): el código se encuentra en dominio público y puede ser usado, copiado, modificado y distribuido libremente, incluso con fines comerciales, sin necesidad de solicitar permiso.
