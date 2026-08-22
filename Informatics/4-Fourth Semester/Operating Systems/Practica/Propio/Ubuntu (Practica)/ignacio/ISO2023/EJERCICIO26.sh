#!/bin/bash

if [ "$#" -lt 1 ]; then
echo "Puto"
exit 7
fi


inexistente=0

for ((i=0; i<$#; i++)); do

     if [ $((i % 2)) -ne 0 ]; then
       ruta="$1"  # Obtener el parámetro en la posición actual
       shift
       if [ -e "$ruta" ]; then
            if [ -f "$ruta" ]; then
                echo "El objeto en la ruta $ruta es un archivo."
            elif [ -d "$ruta" ]; then
                echo "El objeto en la ruta $ruta es un directorio."
            else
                echo "El objeto en la ruta $ruta existe pero no es ni un archivo ni un directorio."
            fi
        else
            echo "El objeto en la ruta $ruta no existe en el sistema."
            ((archivos_inexistentes++))
        fi
     else
        shift  # Eliminar el parámetro en posición impar
     fi
done
