#!/bin/bash
#uncomentario

for ((i = 1; i <= 10; i++)); do
    cuadrado=$((i * i))
    echo "Número: $i - Cuadrado: $cuadrado"
done

numero=1

while [ $numero -le 10 ]; do
      cuadrado=$((numero * numero))
      echo "El numero es $numero y su cuadrado es $cuadrado"

      numero=$((numero + 1))
done

case "$1" in
listar) echo "El directorio contiene $(ls)";;
donde) echo "El directorio esta en $(pwd)";;
quien) echo "Esta conectado $(who)";;
*) echo "Error";;
esac

if [ "$#" -ne 2 ];
then echo "Error"
echo exit 77
fi


nombre="$2"


if [ -e "$nombre" ]; then
    if [ -d "$nombre" ]; then
        echo "El directorio $nombre existe."
    elif [ -f "$nombre" ]; then
        echo "El archivo $nombre existe."
    else
        echo "El objeto $nombre existe, pero no es ni un archivo ni un directorio."
    fi
else
    echo "El objeto $nombre no existe. Creando directorio..."
    mkdir "$nombre"
    echo "Directorio $nombre creado."
fi



