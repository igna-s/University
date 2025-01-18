;3) Escribir un programa que calcule la superficie de un triángulo rectángulo de base 5,85 cm y altura 13,47 cm.
;Pista: la superficie de un triángulo se calcula como: (BXA)/2


.data
n1: .double 5.85
n2: .double 13.47
n3: .double 0

.code
l.d f1, n1(r0)
l.d f2, n2(r0)  
mul.d f2,f1,f2

daddi r1,r0,2
mtc1 r1, f1       ;Tambien se puede multiplicar x .5, con esa variable iniciialmente en n3
cvt.d.l f1, f1
 
div.d f2,f2,f1
s.d f2, n3(r0)
halt