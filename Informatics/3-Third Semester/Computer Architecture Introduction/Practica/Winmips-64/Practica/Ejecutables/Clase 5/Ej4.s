
.data
n1: .double 68,7
n2: .double 1.57
IMC: .double 0
RES: .word 0

a: .double 18.5
b: .double 25
c: .double 30


.code
l.d f1, n1(r0)
l.d f2, n2(r0)

l.d f4, a(r0)
l.d f5, b(r0)
l.d f6, c(r0)

mul.d f2,f2,f2
div.d f3,f1,f2
s.d f3, IMC(r0)

dadd r1,r0,r0
c.lt.d f3, f4
bc1f Salto2
daddi r1,r0,1 
j Salto5

Salto2: c.lt.d f3, f5
bc1f Salto3
daddi r1,r0,2 
j Salto5

Salto3: c.lt.d f3, f6
bc1f Salto4
daddi r1,r0,3 
j Salto5

Salto4: bne r1,r0, Salto5
daddi r1,r0,4

Salto5: sd r1, RES(r0)
halt