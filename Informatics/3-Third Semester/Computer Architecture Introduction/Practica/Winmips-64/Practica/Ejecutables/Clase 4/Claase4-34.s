.data
A: .word 1
B: .word 6
TA: .word 1,1,1,1,1,1 


.code
ld r2, B(r0)
ld r1, A(r0)
;Nuevo
dadd r3,r0,r0
dadd r4,r0,r0

loop: daddi r2, r2, -1
dsll r1, r1, 1
;Nuevo
dadd r3,r0,r1
sd r3, TA(r4)
daddi r4,r4,8
;
bnez r2, loop
halt