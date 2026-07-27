/* Codigo anexoC.4: Llamado a la función incrementar, que recibe un puntero, desde Python */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Anexo C */

import ctypes

lib = ctypes.CDLL("./libbiblioteca.so")

lib.incrementar.argtypes = [ctypes.POINTER(ctypes.c_int)]
lib.incrementar.restype  = None   # equivalente a void en C

valor = ctypes.c_int(10)
lib.incrementar(ctypes.byref(valor))

print("Nuevo valor:", valor.value)   # despliega: Nuevo valor: 11
