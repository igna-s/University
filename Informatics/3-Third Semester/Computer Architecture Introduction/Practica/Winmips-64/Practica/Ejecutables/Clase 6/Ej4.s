;Escriba un programa que solicite el ingreso por teclado de una clave (sucesión de cuatro caracteres) utilizando la
;subrutina char de ingreso de un carácter. Luego, debe comparar la secuencia ingresada con una cadena almacenada
;en la variable clave. Si las dos cadenas son iguales entre si, la subrutina llamada respuesta mostrará el texto
;“Bienvenido” en la salida estándar del simulador (ventana Terminal). En cambio, si las cadenas no son iguales, la
;subrutina deberá mostrar “ERROR” y solicitar nuevamente el ingreso de la clave.




.data
TEXTO:  .asciiz "BIENVENIDO"
TEXTO2: .asciiz "CHE, NO TENGO TODO EL DIA"
CLAVE: .asciiz "HOLA"
AUX: .asciiz "0000"
CONTROL: .word32 0x10000
DATA: .word32 0x10008



.text

lwu $s0, DATA($0)
lwu $s1, CONTROL($0)


daddi $t0, $0, 6 ; Limpio terminal
sd $t0, 0($s1)


loop:  daddi $t1, $0, 0

bucle: jal caracter
       sb $v0, AUX($t1)
       daddi $t1, $t1, 1

       slti $t0, $t1, 4
       beq $0, $t0, Sigo
       j bucle

Sigo:  dadd $t0, $0,$0
       dadd $t1, $0,$0
       lwu $t0, AUX($0)
       lwu $t1, CLAVE($0)

       beq $t0, $t1, SI
 
       daddi $t0, $0, TEXTO2 ; Paso inicio
       sd $t0, 0($s0)


       daddi $t0, $0, 4 ; Imprimo
       sd $t0, 0($s1)

       daddi $t0, $0, 6 ; Limpio terminal
       sd $t0, 0($s1)
      
       j loop

SI:    daddi $t0, $0, TEXTO ; Paso inicio
       sd $t0, 0($s0)


       daddi $t0, $0, 4 ;Imprimo
       sd $t0, 0($s1)

halt


;---------------------------------------------



caracter: daddi $t0, $0, 9
          sd $t0, 0($s1)


          lbu $v0, 0($s0)
          jr $ra 