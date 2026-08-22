
#!/bin/bash

usuarios=($(cut -d: -f1 /etc/passwd))

existe() {
    for i in "${usuarios[@]}"; do
        if [ "$i" == "$1" ]; then
            return 0
        fi
    done
    return 1
}

eliminar() {
    for i in "${!usuarios[@]}"; do
        if [ "${usuarios[i]}" == "$1" ]; then
            unset 'usuarios[i]'
            return 0
        fi
    done
    return 2
}

aparece() {
    for i in "${usuarios[@]}"; do
        aux=($(echo "$i" | grep -o "$1"))
        if [ "${#aux[@]}" -eq 1 ]; then
            echo "$i tiene el patrón"
        fi
    done
    return 3
}

cantidad() {
    echo "${#usuarios[@]}"
}

usuarios() {
    for i in "${usuarios[@]}"; do
        echo "$i"
    done
}

existe "root" && echo "El usuario 'root' existe en el sistema." || echo "No"

eliminar "ignacio"
if [ $? -eq 2 ]; then
    echo "El usuario no existe en el arreglo."
fi

echo "Usuarios que contienen 'roo':"
aparece "roo"

echo "Cantidad de usuarios:"
cantidad

echo "Todos los usuarios:"
usuarios

exit 0
