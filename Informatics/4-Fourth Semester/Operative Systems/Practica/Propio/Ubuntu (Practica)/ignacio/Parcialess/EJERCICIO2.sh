#!/bin/bash
vector=()
arreglo=()

insert(){

if [ "$#" -ne 1 ]; then return 0;
fi

vector+=("$1")
return 0
}

rellenar(){

if [ "$#" -ne 1 ]; then return 0;
fi

for ((i=0;i<"$1";i++)); do

echo "Ingrese elemento"
read x
insert "$x"

done

}


seleccion(){

if [ "$#" -ne 1 ]; then return 0;
fi

if [ "$1" = "*" ]; then

for i in "${arreglo[@]}"; do
     echo "$i"
done
else
for i in "${arreglo[@]}"; do
     if [ "$i" = "$1" ]; then
      echo "$i"
      return 0
fi
done

echo "ELEMENTO NO ESCONTRADO"
fi


}

delete(){

if [ "$#" -ne 1 ]; then return 0;
fi

if [ "$1" = "*" ];then
     for ((i=0;i<"${#arreglo[@]}"; i++)); do
         echo "Hoal"
         unset arreglo[i]
done
else

for i in "${arreglo[@]}"; do
     if [ "$i" = "$1" ]; then
      echo "$i"
      return 0
     fi
done

echo "ELEMENTO NO ESCONTRADO"

return 1
fi

}




rellenar "5"
delete "*"

echo ${vector[@]}
echo ${#vector[@]}
exit
