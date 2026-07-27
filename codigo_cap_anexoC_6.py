/* Codigo anexoC.6: Llamado a la función cumplir\_anos, que recibe un puntero a una estructura, desde Python */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Anexo C */

import ctypes

class Persona(ctypes.Structure):
    _fields_ = [
        ("nombre",   ctypes.c_char * 30),
        ("edad",     ctypes.c_int),
        ("promedio", ctypes.c_float),
    ]

lib = ctypes.CDLL("./libbiblioteca.so")

lib.cumplir_anos.argtypes = [ctypes.POINTER(Persona)]
lib.cumplir_anos.restype  = None

ana = Persona(nombre=b"Ana", edad=20, promedio=6.2)
lib.cumplir_anos(ctypes.byref(ana))

print("Edad de Ana:", ana.edad)   # despliega: Edad de Ana: 21
