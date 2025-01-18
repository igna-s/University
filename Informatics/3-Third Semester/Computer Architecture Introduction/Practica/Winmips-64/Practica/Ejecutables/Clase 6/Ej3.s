;Escriba un programa que realice la suma de dos números enteros (de un dígito cada uno) utilizando dos subrutinas: La
;denominada ingreso del ejercicio anterior (ingreso por teclado de un dígito numérico) y otra denominada
;resultado, que muestre en la salida estándar del simulador (ventana Terminal) el resultado numérico de la suma de
;los dos números ingresados (ejercicio similar al ejercicio 7 de Práctica 2)




.data
CONTROL: .word32 0x10000
DATA: .word32 0x10008



.text

lwu $s1, CONTROL($0)
lwu $s0, DATA ($0)


daddi $t0, $0, 6 ; $t0 = 6 -> función 6: limpiar pantalla alfanumérica
sd $t0, 0($s1) ; CONTROL recibe 6 y limpia la pantalla

jal Suma

halt

;---------------------------------------------------------

Ingreso: daddi $t0,$0,8 
         sd $t0, 0($s1)   ;Guardo numero

         lw $v1, 0($s0)
         daddi $t0, $0,10
         
         slt $v0, $v1, $t0
         
         beq $0, $v0, FAINA
         
FAINA: jr $ra
         

;---------------------------------------------------------



Suma: dadd $s2 ,$0, $ra

      jal Ingreso
      beq $v0, $0, PIZZA

      dadd $t2, $0, $v1
      jal Ingreso
      beq $v0, $0, PIZZA

      dadd $t3, $t2, $v1
      sd $t3, 0($s0)

      daddi $t0, $0, 2
      sd $t0, 0($s1)

PIZZA: dadd $ra, $s2, $0
       jr $ra