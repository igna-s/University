#!/bin/bash


# Función para inicializar un arreglo vacío
inicializar() {
    array=()
}

# Función para agregar un elemento al final del arreglo
agregar_elem() {
    array+=("$1")
}

# Función para eliminar un elemento del arreglo en la posición especificada
eliminar_elem() {
    local posicion="$1"
    if [ "$posicion" -ge 0 ] && [ "$posicion" -lt "${#array[@]}" ]; then
        unset 'array[posicion]'
        array=("${array[@]}")  # Elimina los elementos vacíos
    else
        echo "Posición inválida: $posicion"
    fi
}

# Función para obtener la longitud del arreglo
longitud() {
    echo "Longitud del arreglo: ${#array[@]}"
}

# Función para imprimir todos los elementos del arreglo
imprimir() {
    echo "Elementos del arreglo:"
    for elemento in "${array[@]}"; do
        echo "$elemento"
    done
}

# Función para inicializar un arreglo con longitud y valor específicos
inicializar_Con_Valores() {
    local longitud="$1"
    local valor="$2"
    array=()
    for ((i = 0; i < longitud; i++)); do
        array+=("$valor")
    done
}

# Ejemplo de uso
inicializar
agregar_elem "A"
agregar_elem "B"
agregar_elem "C"
eliminar_elem 1
longitud
imprimir

inicializar_Con_Valores 5 "X"
longitud
imprimir
