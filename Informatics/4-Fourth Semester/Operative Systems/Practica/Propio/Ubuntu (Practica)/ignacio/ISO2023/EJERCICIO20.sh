#!/bin/bash


pila=()

#Funciones

push(){
pila+=("$1")
}

print(){

if [ ${#pila[@]} -gt 0 ]; then
     for elemento in "${pila[@]}"; do
          echo "$elemento"
     done 
else
        echo "La pila está vacía"
    fi
}

pop(){

if [ ${#pila[@]} -gt 0 ]; then
     elemento="${pila[-1]}"
        unset 'pila[${#pila[@]}-1]'
    else
        echo "La pila está vacía"
    fi

}

length(){
 return "${#pila[@]}" #Ns si piden exacto esto, pero mejor es devolver una var glob
}


push 4
push 7
push 6
push 4
push 7
push 67
push 42
push 79
push 77
pop
elemento
echo "El elemento  es $elemento"
pop
pop

length
echo "Longitud es $?"
print

exit 0
