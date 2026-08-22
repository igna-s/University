#!/bin/bash

vetor=($(cat /home/ignacio/Parcialess/LaMuni.txt | cut -d " " -f 1))


for i in "${vetor[@]}"; do

echo "$i"
done




vector=()


existe(){

if [ "$#" -ne 1 ]; then return 2
fi


for i in "${vector[@]}"; do
 if [ "$1" = "$i" ]; then 
      return 0
 fi
done
return 1
}

agregar(){

if [ "$#" -ne 1 ]; then return 2
fi

existe "$1"

if [ "$?" -eq 1 ]; then
    vector+=("$1")
    return 0
fi
return 1
}


listar(){

for i in "${vector[@]}"; do
echo "$i"
done
}

cantidad(){
echo "${#vector[@]}"



}




arch="/home/ignacio/Parcialess/LaMuni.txt"

if [ -f "$arch" ]; then

aux=$(cat "$arch" | cut -d " " -f 1)

echo 
for i in "$aux" ; do
agregar "$i"

done

fi

echo "Hola"
listar

exit 0

