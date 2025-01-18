.data
TEXTO: .asciiz "CERO   "
       .asciiz "UNO    "
       .asciiz "DOS    "
       .asciiz "TRES   "
       .asciiz "CUATRO "
       .asciiz "CINCO  "
       .asciiz "SEIS   "
       .asciiz "SIETE  "
       .asciiz "OCHO   "
       .asciiz "NUEVE  "
CONTROL: .word32 0x10000
DATA: .word32 0x10008



;Escriba un programa que utilice sucesivamente dos subrutinas: La primera, denominada ingreso, debe solicitar el
;ingreso por teclado de un número entero (de un dígito), verificando que el valor ingresado realmente sea un dígito. La
;segunda, denominada muestra, deberá mostrar en la salida estándar del simulador (ventana Terminal) el valor del
;número ingresado expresado en letras (es decir, si se ingresa un ‘4’, deberá mostrar ‘CUATRO’). Establezca el pasaje
;de parámetros entre subrutinas respetando las convenciones para el uso de los registros y minimice las detenciones
;del cauce (ejercicio similar al ejercicio 6 de Práctica 2).



.text
lwu $s0, DATA($0)
lwu $s1, CONTROL($0)


daddi $t0, $0, 6 ; $t0 = 6 -> función 6: limpiar pantalla alfanumérica
sd $t0, 0($s1) ; CONTROL recibe 6 y limpia la pantalla

daddi $a0, $0, TEXTO
jal Ingreso
halt

;---------------------------------------------------------

Ingreso: daddi $t0,$0,8 
         sd $t0, 0($s1)   ;Guardo numero

         lw $a1, 0($s0)
         daddi $t0, $0,10
         
         slt $t0, $a1, $t0
         
         beq $0, $t0, FAINA
         
         dadd $s2,$0,$ra
         jal Muestra
         dadd $ra, $0,$s2

FAINA: jr $ra
         

;---------------------------------------------------------

Muestra: daddi $t0, $0, 8
         dmul $t0, $t0, $a1  

         dadd $t0, $a0, $t0  ;Dir efectiva en control
         sd $t0, 0($s0)

         daddi $t0, $0, 4 ; $t0 = 4 -> función 4: ascii
         sd $t0, 0($s1) ; 

jr $ra