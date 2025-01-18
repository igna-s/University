.data
TEXTO: .asciiz ""
CONTROL: .word32 0x10000
DATA: .word32 0x10008

;El siguiente programa produce la salida de un mensaje predefinido en la ventana Terminal del simulador
;WinMIPS64. Teniendo en cuenta las condiciones de control del puerto de E/S (en el resumen anterior), modifique el
;programa de modo que el mensaje a mostrar sea ingresado por teclado en lugar de ser un mensaje fijo

.text

lwu $s0, DATA(r0) ; $s0 = dirección de DATA
lwu $s1, CONTROL(r0) ; $s1 = dirección de CONTROL


daddi $t0, $0, 6 ; $t0 = 6 -> función 6: limpiar pantalla alfanumérica
sd $t0, 0($s1) ; CONTROL recibe 6 y limpia la pantalla

daddi $t0, $0, 9 ; $t0 = 9 -> función :ingreso de un caracter ASCII
sd $t0, 0($s1) ; CONTROL recibe 9 y produce la salida del mensaje

lbu r30, 0($s0)   ;Paso el caracter a el ascii
sb r30, TEXTO($0)

daddi $t0,$0, TEXTO     ;Mando la dir de inicio a TEXTO
sd $t0, 0($s0)

daddi $t0, $0, 4 ; $t0 = 9 -> función : salida de un caracter ASCII
sd $t0, 0($s1) ; CONTROL recibe 9 y produce la salida del mensaje

halt