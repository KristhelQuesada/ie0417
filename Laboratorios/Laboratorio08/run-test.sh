#!/bin/bash

# Entrar al directorio src (donde está CMakeLists.txt)
cd src || { echo "[Error] No se pudo entrar al directorio src"; exit 1; }

# Crear y entrar al directorio build
mkdir -p build
cd build || { echo "[Error] No se pudo entrar al directorio build"; exit 1; }

# Ejecutar cmake apuntando al directorio padre (src)
cmake .. || { echo "[Error] cmake falló"; exit 1; }

# Compilar con make
make || { echo "[Error] make falló"; exit 1; }

# Ejecutar tests
./test_calculator || { echo "[Error] test_calculator falló"; exit 1; }
./test_authentication || { echo "[Error] test_authentication falló"; exit 1; }

echo "[Success] Todos los tests pasaron correctamente"
