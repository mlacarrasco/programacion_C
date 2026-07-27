/* Codigo anexoC.5: Llamado a la función suma\_vector, que recibe un vector, desde Python */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Anexo C */

import ctypes

lib = ctypes.CDLL("./libbiblioteca.so")

lib.suma_vector.argtypes = [ctypes.POINTER(ctypes.c_int), ctypes.c_int]
lib.suma_vector.restype  = ctypes.c_int

datos = [4, 2, 3, 7, 0]
vector_c = (ctypes.c_int * len(datos))(*datos)

resultado = lib.suma_vector(vector_c, len(datos))
print("La suma es:", resultado)   # despliega: La suma es: 16
