;9)Escribir un programa que implemente el siguiente fragmento escrito en un lenguaje de alto nivel:
;   while a > 0 do
;   begin
;   x := x + y;
;   a := a - 1;
;   end;
;Ejecutar con la opción Delay Slot habilitada.



.data
A: .word 7
X: .word 3
Y: .word 2

.code
ld r1, A(r0)
ld r2, X(r0)
ld r3, Y(r0)

Loop: beq r1,r0, Fin    ;While estricto
nop
daddi r1,r1,-1
j Loop
dadd r2,r2,r3

Fin: halt 