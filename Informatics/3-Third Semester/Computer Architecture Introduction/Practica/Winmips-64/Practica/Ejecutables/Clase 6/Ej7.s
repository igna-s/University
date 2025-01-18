;7) Se desea realizar la demostración de la transformación de un carácter codificado en ASCII a su visualización en una
;matriz de puntos con 7 columnas y 9 filas. Escriba un programa que realice tal demostración, solicitando el ingreso
;por teclado de un carácter para luego mostrarlo en la pantalla gráfica de la terminal.



.data
coorX: .byte 24 ; coordenada X de un punto
coorY: .byte 24 ; coordenada Y de un punto
color: .byte 255, 0, 255, 0 ; color: máximo rojo + máximo azul => magenta
CONTROL: .word32 0x10000
DATA: .word32 0x10008



.text

lwu $s6, CONTROL(r0) ; $s6 = dirección de CONTROL
lwu $s7, DATA(r0) ; $s7 = dirección de DATA

daddi $t0, $0, 7 ; $t0 = 7 -> función 7: limpiar pantalla gráfica
sd $t0, 0($s6) ; CONTROL recibe 7 y limpia la pantalla gráfica


daddi $t0, $0, 9 
sd $t0, 0($s6) 

lbu $t0, 0($s7)

;Solo hago 1, la h

daddi $t1, $t1, 104
bne $t0, $t1, Fin

;--------------------------------



sb $s0, 5($s7) ; DATA+5 recibe el valor de coordenada X
sb $s1, 4($s7) ; DATA+4 recibe el valor de coordenada Y
sw $s2, 0($s7) ; DATA recibe el valor del color a pintar

sb $s0, 5($s7) ; DATA+5 recibe el valor de coordenada X
sb $s1, 4($s7) ; DATA+4 recibe el valor de coordenada Y
sw $s2, 0($s7) ; DATA recibe el valor del color a pintar

sb $s0, 5($s7) ; DATA+5 recibe el valor de coordenada X
sb $s1, 4($s7) ; DATA+4 recibe el valor de coordenada Y
sw $s2, 0($s7) ; DATA recibe el valor del color a pintar

sb $s0, 5($s7) ; DATA+5 recibe el valor de coordenada X
sb $s1, 4($s7) ; DATA+4 recibe el valor de coordenada Y
sw $s2, 0($s7) ; DATA recibe el valor del color a pintar

sb $s0, 5($s7) ; DATA+5 recibe el valor de coordenada X
sb $s1, 4($s7) ; DATA+4 recibe el valor de coordenada Y
sw $s2, 0($s7) ; DATA recibe el valor del color a pintar

sb $s0, 5($s7) ; DATA+5 recibe el valor de coordenada X
sb $s1, 4($s7) ; DATA+4 recibe el valor de coordenada Y
sw $s2, 0($s7) ; DATA recibe el valor del color a pintar

sb $s0, 5($s7) ; DATA+5 recibe el valor de coordenada X
sb $s1, 4($s7) ; DATA+4 recibe el valor de coordenada Y
sw $s2, 0($s7) ; DATA recibe el valor del color a pintar

sb $s0, 5($s7) ; DATA+5 recibe el valor de coordenada X
sb $s1, 4($s7) ; DATA+4 recibe el valor de coordenada Y
sw $s2, 0($s7) ; DATA recibe el valor del color a pintar

sb $s0, 5($s7) ; DATA+5 recibe el valor de coordenada X
sb $s1, 4($s7) ; DATA+4 recibe el valor de coordenada Y
sw $s2, 0($s7) ; DATA recibe el valor del color a pintar

sb $s0, 5($s7) ; DATA+5 recibe el valor de coordenada X
sb $s1, 4($s7) ; DATA+4 recibe el valor de coordenada Y
sw $s2, 0($s7) ; DATA recibe el valor del color a pintar

sb $s0, 5($s7) ; DATA+5 recibe el valor de coordenada X
sb $s1, 4($s7) ; DATA+4 recibe el valor de coordenada Y
sw $s2, 0($s7) ; DATA recibe el valor del color a pintar 










Fin: halt


