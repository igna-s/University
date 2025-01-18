#!/bin/bash


echo -n "Ingrese 2 numeros "
read x y
if [ "$#" -ne 3 ]
then echo "Error parametros"
exit 3
fi

echo "Mayor"
if [ "$x" -lt "$y" ]
then echo "$y"
else echo "$x"
fi

echo "Suma: $((x + y))"
echo "Resta: $((x - y))"
echo "Multiplicación: $((x * y))"
if [ "$y" -eq 0 ]
then
    echo "No se puede dividir por cero."
else
    echo "División: $((x / y))"
fi

echo "Mayor"
if [ "$1" -lt "$2" ]
then echo "$2"
else echo "$1"
fi

echo "Suma: $(($1 + $2))"
echo "Resta: $(($1 - 42))"
echo "Multiplicación: $(($1 * $2))"
if [ "$2" -eq 0 ]
then
    echo "No se puede dividir por cero."
else
    echo "División: $(($1 / $2))"
fi

echo "Calculadora"
case "$3" in

   +)echo "Res: $(($1 + $2))";;
   -)echo "Res: $(($1 - $2))";;
   x)echo "Res: $(($1 * $2))";;
   %)echo "Res: $(($1 % $2))";;
   .*)echo "Invalido"

esac
exit 7
