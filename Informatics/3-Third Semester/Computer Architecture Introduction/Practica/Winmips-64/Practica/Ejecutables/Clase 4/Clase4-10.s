;10) Escribir un programa que cuente la cantidad de veces que un determinado caracter aparece en una cadena de texto. Observar
;cómo se almacenan en memoria los códigos ASCII de los caracteres (código de la letra “a” es 61H). Utilizar la instrucción lbu
;(load byte unsigned) para cargar códigos en registros. La inicialización de los datos es la siguiente:




.data
cadena: .asciiz "ddbdcdedfdgdhdid"              ; cadena a analizar
car: .asciiz "d"                                ; caracter buscado
cant: .word 0                                   ; cantidad de veces que se repite el caracter car en cadena.

.code

lbu r2, car(r0)
daddi r3,r0,0
dadd r4,r0,r0
daddi r5,r0,16

Loop: lbu r1, cadena(r3)
bne r1,r2, Sigo
daddi r4,r4,1

Sigo: daddi r3,r3,1
bne r3,r5, Loop


sd r4, cant(r0)
halt


