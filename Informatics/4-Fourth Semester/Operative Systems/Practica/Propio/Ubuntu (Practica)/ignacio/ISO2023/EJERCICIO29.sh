#!/bin/bash

# Inicializar el arreglo de archivos .doc en /home
archivos_doc=("/home"/*.doc)

# Función para imprimir un archivo si existe en el arreglo
verArchivo() {
    local archivo="$1"
    if [[ " ${archivos_doc[*]} " == *" $archivo "* ]]; then
        cat "$archivo"
    else
        echo "Archivo no encontrado"
        return 5
    fi
}

# Función para imprimir la cantidad de archivos .doc en /home
cantidadArchivos() {
    local cantidad="${#archivos_doc[@]}"
    echo "Cantidad de archivos .doc en /home: $cantidad"
}

# Función para borrar un archivo lógicamente o del filesystem
borrarArchivo() {
    local archivo="$1"
    if [[ " ${archivos_doc[*]} " == *" $archivo "* ]]; then
        echo "¿Desea eliminar el archivo '$archivo' lógicamente? (Si/No)"
        read respuesta
        if [ "$respuesta" == "Si" ]; then
            archivos_doc=("${archivos_doc[@]/$archivo}")
        elif [ "$respuesta" == "No" ]; then
            archivos_doc=("${archivos_doc[@]/$archivo}")
            rm "$archivo"
        else
            echo "Respuesta no válida. No se realizó ninguna acción."
        fi
    else
        echo "Archivo no encontrado"
        return 10
    fi
}

# Ejemplo de uso
verArchivo "/home/archivo1.doc"
cantidadArchivos
borrarArchivo "/home/archivo2.doc"
verArchivo "/home/archivo2.doc"
