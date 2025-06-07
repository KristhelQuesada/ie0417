#!/bin/bash

# Entrar al directorio src (donde está CMakeLists.txt)
cd src || { echo "[Error] No se pudo entrar al directorio src"; exit 1; }

echo
echo "=========================================="
echo "Compilando y ejecutando 1_seed.cpp"
echo "=========================================="

# Compilar el archivo de ejemplo
g++ -o exe 1_seed.cpp || { echo "[Error] Falló compilación de 1_seed.cpp"; exit 1; }

# Ejecutar el archivo compilado
./exe || { echo "[Error] Falló ejecución de exe"; exit 1; }

echo
echo "============================================="
echo "Creando directorio build y configurando CMake"
echo "============================================="

# Crear y entrar al directorio build
mkdir -p build
cd build || { echo "[Error] No se pudo entrar al directorio build"; exit 1; }

# Ejecutar cmake apuntando al directorio padre (src)
cmake .. || { echo "[Error] cmake falló"; exit 1; }

# Compilar con make
make || { echo "[Error] make falló"; exit 1; }

echo
echo "=========================================="
echo "Ejecutando test_calculator"
echo "=========================================="
./test_calculator || { echo "[Error] test_calculator falló"; exit 1; }

echo
echo "=========================================="
echo "Ejecutando test_authentication"
echo "=========================================="
./test_authentication || { echo "[Error] test_authentication falló"; exit 1; }

echo
echo "=================================================================="
echo "[Success] Todos los tests y el ejemplo se ejecutaron correctamente"
echo "=================================================================="
