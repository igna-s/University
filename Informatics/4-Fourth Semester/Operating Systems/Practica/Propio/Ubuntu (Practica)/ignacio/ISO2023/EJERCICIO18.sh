#!/bin/bash

if [ $# -ne 1 ]; then
    echo "Uso: $0 <nombre_de_usuario>"
    exit 1
fi


function verificar {
  if who | cut -d' ' -f1 | grep -q "^$1"; then
    return 0  # Usuario logueado
  else
    return 1  # Usuario no logueado
  fi
}

usuario="$1"

while true; do
  if verificar "$1" ; then
    echo "Usuario $usuario logueado en el sistema"
    exit 0
  fi
  echo "NO"
  read -t 1 -n 1
done
