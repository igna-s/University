#!/bin/bash

# Verificar que se haya proporcionado un directorio como parámetro
if [ $# -ne 1 ]; then
    echo "Uso: $0 <directorio>"
    exit 1
fi

directorio="$1"

# Verificar si el directorio existe
if [ ! -d "$directorio" ]; then
    echo "El directorio '$directorio' no existe."
    exit 4
fi

# Inicializar contadores
archivos_lectura_escritura=0

# Iterar por los archivos en el directorio
for archivo in "$directorio"/*; do
    # Verificar si el archivo es legible y escribible por el usuario actual
    if [ -f "$archivo" ] && [ -r "$archivo" ] && [ -w "$archivo" ]; then
        archivos_lectura_escritura=$((archivos_lectura_escritura + 1))
    fi
done

echo "Cantidad de archivos con permisos de lectura y escritura en '$directorio': $archivos_lectura_escritura".
