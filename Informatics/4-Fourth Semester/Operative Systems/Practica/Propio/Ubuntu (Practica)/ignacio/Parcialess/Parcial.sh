#!/bin/bash




if [ "$#" -lt 3 ];then

echo "Error, parametros insuficientes"
exit 88
fi

ruta="/home/EJERCICIO11"
dia="$1"
vector=( "$@" )

for(( i=1 ; i<"$#" ; i++ )); do  #Porque arranca en 1

aux="${vector[i]}"

cont=$( cat "$ruta" | grep "$aux" | grep "$dia" | wc -l )

echo "La direccion ${vector[i]}, tiene $cont ingresos"
done


echo "Parte 2 - UwUntu "

par="$3"

vector=($( cat "/etc/passwd" | cut -d: -f 1 )) #| grep "$par"  ))


imprimir(){
for i in "${vector[@]}"; do
echo "$i"
done
return 0
}

eliminar(){
aux=0

for i in "${vector[@]}"; do
echo "$aux - $i"
aux="$(($aux + 1))"
done

echo "Cual saco"
read aux
unset vector[aux]
return 0
}

contar(){
echo "hay ${#vector[@]} elementos"
return 0
}

imprimir
eliminar
imprimir
contar









exit 0
