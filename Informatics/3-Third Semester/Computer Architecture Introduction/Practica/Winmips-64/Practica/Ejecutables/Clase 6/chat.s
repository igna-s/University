.data
CONTROL: .word 0x10000   # Dirección de CONTROL
DATA: .word 0x10008     # Dirección de DATA
BUFFER: .space 256      # Buffer para almacenar el mensaje ingresado por el usuario

.text
main:
    lwu $s0, DATA($0)    # $s0 = dirección de DATA

    lwu $s1, CONTROL($0)   # $s1 = dirección de CONTROL
    daddi $t0, $0, 6    # $t0 = 6 -> función 6: limpiar pantalla alfanumérica
    sd $t0, 0($s1)    # CONTROL recibe 6 y limpia la pantalla

    daddi $t0, $0, 9    # $t0 = 9 -> función: ingreso de un caracter ASCII
    sd $t0, 0($s1)    # CONTROL recibe 9 y produce la salida del mensaje

    li $v0, 8    # $v0 = 8 -> código de llamada al sistema para leer una cadena
    la $a0, BUFFER    # $a0 = dirección del buffer
    li $a1, 256    # $a1 = número máximo de caracteres a leer
    syscall    # Leer cadena de entrada

    lb $t3, 0($a0)    # Cargar el primer caracter de la cadena de entrada
    sb $t3, 0($s0)    # Almacenar el caracter en DATA

    daddi $t0, $0, TEXTO    # Cargar la dirección de inicio de TEXTO
    sd $t0, 0($s0)    # Almacenar la dirección en DATA

    daddi $t0, $0, 4    # $t0 = 4 -> función: salida de un caracter ASCII
    sd $t0, 0($s1)    # CONTROL recibe 4 y produce la salida del mensaje

    haltcursiva, No