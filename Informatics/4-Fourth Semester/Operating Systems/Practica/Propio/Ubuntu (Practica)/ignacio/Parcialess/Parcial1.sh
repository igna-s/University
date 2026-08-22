#!/bin/bash


mail=$(find /home -maxdepth 2 -type d -name "mailDir" -exec test -e {}/../.bashrc \; -exec basename {} \;)

echo "$mail" > /home/Parcialess/lista.txt
