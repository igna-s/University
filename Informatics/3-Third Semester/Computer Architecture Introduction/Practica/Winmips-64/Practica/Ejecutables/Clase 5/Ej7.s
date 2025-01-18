;7) Escriba una subrutina que reciba como parámetros un número positivo M de 64 bits, la dirección del comienzo de una
;tabla que contenga valores numéricos de 64 bits sin signo y la cantidad de valores almacenados en dicha tabla.
;La subrutina debe retornar la cantidad de valores mayores que M contenidos en la tabla


.data
M: .word 1
TABLA: .word 1,2,3,4,5,6,7,8,9,10
CANT: .word 10
RES: .word 0

.code

ld $a0, M($zero)                       ;Valores
daddi $a1,$zero,TABLA
ld $a2, CANT($zero)

slti $t3,$a0,0                         ;Chequeo M positivo
bne $t3, $zero, Chau

jal Subrutina
sd $v0,RES($zero)                     ;Llamo a Subrutina
Chau: halt

;-----------------------------
Subrutina: dadd $t0,$zero,$a1          ;Subrutina
Lazo: beq $a2,$zero,Fin

ld $t1, 0($t0)

beq $a0, $t1, EsMenor                   ;Se fija si es igual y despues si es menor
slt $t3, $a0, $t1

beq $t3,$zero, EsMenor                  ;Sumo si es true
daddi $v0,$v0,1

EsMenor: daddi $a2,$a2,-1                ;Regreso
daddi $t0,$t0,8
j Lazo
Fin: jr $ra