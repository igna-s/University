#!/bin/bash

res=0

logueado() {
    if [ "$#" -ne 1 ]; then
        return 1
    fi

    aux=$(who | grep "$1" | wc -l)

    if [ "$aux" -ne 1 ]; then
        return 1
    fi
    echo " h"
    return 0
}

procesos() {
    if [ "$#" -ne 1 ]; then
        return 255
    fi

    aux=$(ps aux | grep "$1" | wc -l)
    if [ "$aux" -gt 254 ]; then
        return 254
    fi
    return "$aux"
}

uso() {
    if [ "$#" -ne 1 ]; then
        return 1
    fi

    procesos "$1"

    if [ "$?" -gt 1 ]; then
        return 0
    fi
    return 1
}

if [ "$#" -eq 0 ]; then
    echo "Por favor, proporciona al menos un argumento."
    exit 1
fi

for i in "$@"; do
    logueado "$i"
    if [ "$?" -eq 0 ]; then
        uso "$i"
        if [ "$?" -eq 0 ]; then
            echo "$i usa más procesos de los permitidos en $(date)" >> ./res.txt
        fi
    fi
done

