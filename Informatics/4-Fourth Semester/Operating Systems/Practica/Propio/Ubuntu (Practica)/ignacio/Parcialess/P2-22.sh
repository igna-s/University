#!/bin/bash



usuarios=($(cut -d: -f1 /etc/passwd))



existe(){

for i in " ${usuarios[@]}"; do
 
   if [ "$i" == "$1" ];then
      return 0

   fi
done

return 1
}


eliminar(){

for i in " ${#usuarios[@]}"; do

   if [ "${usuarios[i]}" == "$1" ]; then
      return 0

   fi
done

return 2
}



aparece(){

for i in " ${usuarios[@]}"; do

   aux=("${usuarios[i]" | grep -o "$1" }
   if [ "$(aux | wc -l)" -eq 1 ]; then
    echo "$(aux) tiene el patron" 
   fi
done

return 3
}


cantidad(){ 
echo "${#usuarios[@]}"
}

usuarios(){

for i in " ${usuarios[@]}"; do

   echo "$i"

done

return 3
}




existe "root" && echo "El usuario 'root' existe en el sistema." || echo  "No"

eliminar "ignacio"
if [ $? -eq 2 ]; then
    echo "El usuario no existe en el arreglo."
fi

echo "Usuarios que contienen 'us':"
aparece "root"

cantidad

echo "Todos los usuarios:"
usuarios

exit 0
