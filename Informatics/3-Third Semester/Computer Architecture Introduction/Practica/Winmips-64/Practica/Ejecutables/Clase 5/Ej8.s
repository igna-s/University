;8) Escriba una subrutina que reciba como parámetros las direcciones del comienzo de dos cadenas terminadas en cero y
;retorne la posición en la que las dos cadenas difieren. En caso de que las dos cadenas sean idénticas, debe retornar -1.


.data
Tabla: .asciiz "SEXOOOOOOO"
ALBAT: .asciiz "SEXOOOOOOO"
RES: .word 999

.code
daddi $a0, $zero, Tabla
daddi $a1, $zero, ALBAT

jal Subrutina
sd $v0, RES($zero)
halt



;-----------------------------------

Subrutina:  daddi $t2, $zero,1      ;Cargo
Lazo: lb $t0, 0($a0)
      lb $t1, 0($a1)

bne $t0, $t1, Malo                    ;Si son distintos salgo
beq $t0, $zero, Bueno                 ;Si son iguales y uno de ellos =0 True
daddi $t2,$t2,1
daddi $a0,$a0,1                       ;Sumo 1 y reinicio
daddi $a1,$a1,1
j Lazo

Bueno: daddi $v0,$zero,-1
j Fin

Malo: dadd $v0,$zero,$t2
Fin: jr $ra