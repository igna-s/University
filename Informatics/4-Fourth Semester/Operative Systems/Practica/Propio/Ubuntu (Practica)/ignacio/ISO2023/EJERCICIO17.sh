#!/bin/bash

cat "$1" | tr -d 'A' | tr -d 'a' | tr 'a-zA-Z' 'A-Za-z'
cat "$1" | tr -d 'A' | tr -d 'a' | tr 'a-zA-Z' 'A-Za-z' > "$1"
