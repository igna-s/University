;Enunciado 1


.data
Tabla1: .double 1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.8
Tabla2: .double 0,0,0,0,0,0,0,0

Tamanio: .word 8


.text

dadd $s0, $0, $0
lw $t0, Tamanio($0)
daddi $s1, $0, Tabla1
daddi $s2, $0, Tabla2
daddi $s3, $0, 2


mtc1 $s3, f2
cvt.d.l f2, f2

Loop:  l.d f1, Tabla1 ($s0)
       mul.d f1,f2, f1
      
       s.d f1, Tabla2($s0)

       daddi $t0, $t0,-1
       daddi $s0,$s0,8
      
       bne $0, $t0, Loop

halt