.data
coorX: .byte 24 ; coordenada X de un punto
coorY: .byte 24 ; coordenada Y de un punto
color: .byte 255, 0, 255, 0 ; color: máximo rojo + máximo azul => magenta
CONTROL: .word32 0x10000
DATA: .word32 0x10008

.text
lwu $s6, CONTROL(r0) ; $s6 = dirección de CONTROL
lwu $s7, DATA(r0) ; $s7 = dirección de DATA


daddi $t0, $0, 7 
sd $t0, 0($s6) 


daddi $t0, $0, 8 
sd $t0, 0($s6) 

lbu $s0, 0($s7)

daddi $t0, $0, 8 
sd $t0, 0($s6) 

lbu $s1, 0($s7)


daddi $t0, $0, 8 
sd $t0, 0($s6) 

lbu $s2, 0($s7)
sb $s2, color($t1)

daddi $t0, $0, 8 
sd $t0, 0($s6) 

lbu $s2, 0($s7)
sb $s2, color($t1)
daddi $t1,$t1, 1

daddi $t0, $0, 8 
sd $t0, 0($s6) 

lbu $s2, 0($s7)
sb $s2, color($t1)
daddi $t1,$t1, 1

daddi $t0, $0, 8 
sd $t0, 0($s6) 

lbu $s2, 0($s7)
sb $s2, color($t1)
daddi $t1,$t1, 1

daddi $t0, $0, 6 
sd $t0, 0($s6)              


lwu $s2,color ($0)

sb $s0, 5($s7) ; DATA+5 recibe el valor de coordenada X

sb $s1, 4($s7) ; DATA+4 recibe el valor de coordenada Y

sw $s2, 0($s7) ; DATA recibe el valor del color a pintar

daddi $t0, $0, 5 ; $t0 = 5 -> función 5: salida gráfica
sd $t0, 0($s6) ; CONTROL recibe 5 y produce el dibujo del punto
halt
