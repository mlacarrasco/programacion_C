/* Codigo anexoC.3: Llamado a la función duplicar de biblioteca.c desde Python */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Anexo C */

import ctypes

lib = ctypes.CDLL("./libbiblioteca.so")

lib.duplicar.argtypes = [ctypes.c_int]
lib.duplicar.restype  = ctypes.c_int

resultado = lib.duplicar(21)
print("El doble de 21 es:", resultado)   # despliega: El doble de 21 es: 42
