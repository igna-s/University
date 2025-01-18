;8)Escribir un programa que multiplique dos números enteros utilizando sumas repetidas (similar al Ejercicio 7 de la Práctica 1).
;El programa debe estar optimizado para su ejecución con la opción Delay Slot habilitada.


.data
A: .word 8
B: .word 4
RES: .word 0


.code
ld r1, A(r0)
ld r2, B(r0)


beq r1,r0, Fin          ;Si los 2 son 0 saltaria 2 veces, y el dadd no afecta al resultado
beq r2,r0, Fin
dadd r3,r0,r0

Lazo: daddi r2, r2, -1
bne r2,r0, Lazo 
dadd r3, r3, r1


sd r3, RES(r0)
Fin: halt