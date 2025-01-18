#!/bin/bash

# Inicializamos un arreglo para almacenar los nombres de usuarios del grupo "users"
usuarios=()

# Obtener todos los usuarios del grupo "users" y agregarlos al arreglo
while IFS=: read -r nombre x uid gid x home shell; do
    if [ "$gid" -eq "$(getent group users | cut -d: -f3)" ]; then
        usuarios+=("$nombre")
    fi
done < /etc/passwd

# Función para mostrar un mensaje de error
mostrar_error() {
    echo "Error: El índice especificado no existe en el arreglo."
    exit 1
}

# Procesar los argumentos
while [ $# -gt 0 ]; do
    case "$1" in
        -b)
            if [ -n "$2" ]; then
                indice="$2"
                if [ "$indice" -ge 0 ] && [ "$indice" -lt "${#usuarios[@]}" ]; then
                    echo "Elemento en la posición $indice del arreglo: ${usuarios[indice]}"
                else
                    mostrar_error
                fi
            else
                mostrar_error
            fi
            shift 2
            ;;
        -l)
            echo "Longitud del arreglo: ${#usuarios[@]}"
            shift
            ;;
        -i)
            echo "Elementos del arreglo:"
            for usuario in "${usuarios[@]}"; do
                echo "$usuario"
            done
            shift
            ;;
        *)
            echo "Uso: $0 [-b n] [-l] [-i]"
            exit 1
            ;;
    esac
done
