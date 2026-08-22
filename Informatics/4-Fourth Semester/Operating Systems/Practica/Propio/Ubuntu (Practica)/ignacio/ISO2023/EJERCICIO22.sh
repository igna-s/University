#!/bin/bash


num=(10 3 5 7 9 3 5 4)
producto=1

productoria(){

   for i in "${num[@]}";do
    producto=$(( i * producto ))

done
}



recorrido(){
    local sumao=0
   for i in "${num[@]}";do

   if [ "$(( i % 2 ))" -ne 0 ]; then
     suma=$(( i + suma ))
   else
     echo "$i"
   fi
done
echo "$suma"
}


productoria
echo "$producto"
recorrido

