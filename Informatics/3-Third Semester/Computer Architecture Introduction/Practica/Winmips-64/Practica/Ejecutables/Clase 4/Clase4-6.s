;6) Escribir un programa que lea tres números enteros A, B y C de la memoria de datos y determine cuántos de ellos son iguales
;Entre sí (0, 2 o 3). El resultado debe quedar almacenado en la dirección de memoria D.

.data
A: .word 8
B: .word 8
C: .word 7

D: .word 77


.code
ld r1, A(r0)
ld r2, B(r0)
ld r3, C(r0)
dadd r4, r0, r0

BNE r1, r2, Si
daddi r4, r4, 1
Si: BNE r1, r3, Si2
daddi r4, r4, 1
Si2: BNE r2, r3, Si3
daddi r4, r4, 1

Si3: daddi r5, r5, 1
BNE r4, r5, Fin
daddi r4, r4, 1

Fin: sd r4, D(r0)
halt
