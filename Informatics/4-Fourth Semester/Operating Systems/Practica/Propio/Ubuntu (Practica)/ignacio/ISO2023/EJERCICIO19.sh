#!/bin/bash
#Hola

echo " 12- Calculadora (Ingresa 1 2 +)" 
echo " 13-Cuadrados (Ingresa Arch)"
echo " 14-Renombre (Fichero, -b, Cadena)"
echo " 16-Tabla (.txt)"
echo " 17-Cambio (Arch) "
echo "Muestre la variable"
read x

var="/home/ignacio/ISO2023/EJERCICIO"
fin=".sh"

while [ "$x" -ne 0 ]; do 

x=${var}${x}${fin}
echo $x
echo "Ingrese las vars"
read A B C
"$x" "A" "B" "C" 

echo "Muestre la variable"
read x
done
echo "CHAU"
