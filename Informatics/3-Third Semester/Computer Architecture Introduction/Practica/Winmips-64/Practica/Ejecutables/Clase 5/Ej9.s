;9) El siguiente programa espera usar una subrutina que calcule en forma recursiva el factorial de un número entero:


.data
valor: .word 10
result: .word 0

.text
daddi $sp, $0, 0x400 ; Inicializa el puntero al tope de la pila (1)
ld $a0, valor($0)
jal factorial
sd $v0, result($0)
halt

;--------------------------------------

factorial: bne $a0,$zero, Sigo    
           daddi $v0,$zero,1       ;Caso Base
           j Fin

     Sigo: daddi $sp,$sp,-16
           sd $ra, 0($sp)
           sd $a0, 8($sp)
        
           daddi $a0,$a0,-1        ;Recursion
           jal factorial

           ld $ra, 0($sp)
           ld $a0, 8($sp)
           daddi $sp,$sp,16
           dmul $v0,$v0,$a0       ;Instruccion de Multi
           
        Fin: jr $ra

;a) Implemente la subrutina factorial definida en forma recursiva. Tenga presente que el factorial de un número
;entero n se calcula como el producto de los números enteros entre 1 y n inclusive:
;factorial(n) = n! = n x (n-1) x (n-2) x … x 3 x 2 x 1

;b) ¿Es posible escribir la subrutina factorial sin utilizar una pila? Justifique.

;Es posible hacer una subrutina factorial iterativa, dicho esto, si se quiere recursiva, No