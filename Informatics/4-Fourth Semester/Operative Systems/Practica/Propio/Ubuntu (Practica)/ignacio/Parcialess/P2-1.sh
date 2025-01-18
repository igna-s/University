#!/bin/bash

#/home/users yqs una ruta

if [ "$#" -eq 0 ]; 
   then exit 77
fi

cant=0

for i in "$@" ;do
echo "$i"
  if [ -e "$i" ];then

      if [ -f "$i" ];then
             gzip "$i"

      elif [ -d "$i" ];then 
            
          if [ -r "$i" ];then
          tar -czf "$elemento.tar.gz" "$i"
          else
          rm -r "$i"
          fi

      fi
   else cant=$(($cant + 1))
   fi

done
echo "hay $cant ausentes"
exit 0
