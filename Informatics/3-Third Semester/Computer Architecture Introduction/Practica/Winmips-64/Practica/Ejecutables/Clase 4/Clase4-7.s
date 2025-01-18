;7)Escribir un programa que recorra una TABLA de diez números enteros y determine cuántos elementos son mayores que X. El
;resultado debe almacenarse en una dirección etiquetada CANT. El programa debe generar además otro arreglo llamado RES
;cuyos elementos sean ceros y unos. Un ‘1’ indicará que el entero correspondiente en el arreglo TABLA es mayor que X,
;mientras que un ‘0’ indicará que es menor o igual




.data

TABLA: .word 1,2,3,4,5,6,7,8,9,10
CANT: .word 9999
RES: .word 999


.code                   ;r1: desplazamiento, r2: Tabla, r3: Comp , r4:res mayor, r5:Cont mayor 

daddi r1,r0,80          ;Recorro la tabla al revez para ahorrar 1 registro
daddi r3,r0,7            ;Comparo con 7
dadd r5, r0, r0

loop: daddi r1,r1,-8
ld r2,TABLA(r1)
slt r4,r3,r2            ;Me fijo si r3(VALOR)<r2(TABLA)  true==1
sd r4,RES(r1)

beq r4,r0, Sigo
daddi r5,r5,1

Sigo: Bne r1,r0, loop

Fin: sd r5,CANT(r0)
halt