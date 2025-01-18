# Creamos un arreglo entero
arreglo=( 1 2 3 4 5 )

# Imprimimos el arreglo
echo ${arreglo[@]}

# Eliminamos el arreglo
unset arreglo

# Imprimimos el arreglo
echo "${arreglo[*]}"

