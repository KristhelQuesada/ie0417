#!/bin/bash

# Nombre del archivo fuente
SRC="programa.cpp"
OUT="programa"

# Compilar con información de depuración
g++ -g -o "$OUT" "$SRC"

# Crear archivo de comandos para GDB
cat << EOF > gdb_commands.txt
run
break funcion1
continue
next
print a
step
backtrace
continue
EOF

# Ejecutar GDB con el archivo de comandos
gdb -x gdb_commands.txt "$OUT"
