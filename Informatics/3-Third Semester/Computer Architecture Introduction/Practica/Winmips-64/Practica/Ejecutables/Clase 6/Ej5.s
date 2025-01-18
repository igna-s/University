;Escriba un programa que calcule el resultado de elevar un valor en punto flotante a la potencia indicada por un
;exponente que es un número entero positivo. Para ello, en el programa principal se solicitará el ingreso de la base (un
;número en punto flotante) y del exponente (un número entero sin signo) y se deberá utilizar la subrutina
;a_la_potencia para calcular el resultado pedido (que será un valor en punto flotante). Tenga en cuenta que
;cualquier base elevada a la 0 da como resultado 1. Muestre el resultado numérico de la operación en la salida estándar
;del simulador (ventana Terminal).

.data
CONTROL: .word32 0x10000
DATA: .word32 0x10008



.text
lwu $v0, DATA($0)
LWU $v1, CONTROL($0)

daddi $t0, $0, 8
sd $t0, 0($v1)

ld $a1, 0($v0)

daddi $t0, $0, 8
sd $t0, 0($v1)

l.d f1, 0($v0)

jal alapotencia


      
       s.d f2, 0($v0)

       daddi $t0, $0, 3 ;Imprimo
       sd $t0, 0($v1)




halt

;--------------------------------------



alapotencia:   mtc1 $0, f0
     cvt.d.l f0, f0
     daddi $t1, $0,1
     mtc1 $t1, f2
     cvt.d.l f2, f2
 
beq $a1, $0, Es1

Loop: mul.d f2, f2, f1


     daddi $a1, $a1, -1
     beq $a1,$0, Fin
     j Loop


Es1:  add.d f2, f0, f2
Fin: jr $ra