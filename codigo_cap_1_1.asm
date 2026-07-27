/* Codigo 1.1: Programa en Assembler que imprime  el mensaje <<Hola Mundo>> */
/* Libro: Introduccion a la Programacion y la Algoritmia en C - Capitulo 1 */

   
.model small
.stack 100h
.data
cadenatexto DB 'Hola Mundo.$'
.code
programa:
    mov ax, @data
    mov ds, ax
    mov dx, offset cadenatexto
    mov ah, 9
    int 21h
    mov ax, 4C00h
    int 21h
end programa
