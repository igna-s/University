#!/bin/bash

if [ "$#" -ne 3 ]; then
    echo "Error"
    exit 1
fi

if [ ! -d "$1" ]; then
    echo "El directorio $1 no existe."
    exit 1
fi

directorio="$1"
opcion="$2"
cadena="$3"

for archivo in "$directorio"/*; do
    if [ -f "$archivo" ]; then
        nombre_archivo=$(basename "$archivo")
        extension="${nombre_archivo##*.}"
        nombre_sin_extension="${nombre_archivo%.*}"

        nuevo_nombre=""

        if [ "$opcion" == "-a" ]; then
            nuevo_nombre="${nombre_sin_extension}${cadena}.${extension}"
        elif [ "$opcion" == "-b" ]; then
            nuevo_nombre="${cadena}${nombre_sin_extension}.${extension}"
        else
            echo "Opción no válida. Use -a o -b."
            exit 1
        fi
        # Renombrar el archivo
        mv "$archivo" "${directorio}/${nuevo_nombre}"
        echo "Renombrado $archivo a ${directorio}/${nuevo_nombre}"
    fi
done
