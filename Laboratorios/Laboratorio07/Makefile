# ------------------------------------------------------------
# Makefile para compilar+ejecutar cada uno de los ejemplos
# ------------------------------------------------------------

# Compilador y banderas comunes
CXX      = g++
CXXFLAGS = -g      # información de depuración siempre activada
LDFLAGS  =        # (vacio por defecto; se añadirán según corresponda)

# --------------------------------------------------------------------------------
# TARGETS INDIVIDUALES
#
# Cada uno compila su .cpp y luego ejecuta el binario con la herramienta adecuada.
# El ejecutable se llama siempre "programa", para que siga el mismo 
# flujo de las capturas que enviaste.
# --------------------------------------------------------------------------------

# 1) GDB
#   - g++ -g -o programa programa.cpp
#   - gdb programa
# .PHONY: gdb
# gdb:
# 	chmod +x gdb.sh
# 	./gdb.sh

# 2) Valgrind (chequeo de fugas de memoria)
#   - g++ -g -o programa programa_valgrind.cpp
#   - valgrind --leak-check=yes ./programa
.PHONY: valgrind_leaks
valgrind_leaks:
	@echo "---- Compilando para Valgrind (--leak-check) ----"
	$(CXX) $(CXXFLAGS) -o programa programa_valgrind.cpp
	@echo "---- Ejecutando valgrind --leak-check=yes ./programa ----"
	@valgrind --leak-check=yes ./programa

# 3) AddressSanitizer
#   - g++ -fsanitize=address -g -o programa programa_sanitize.cpp
#   - ./programa
.PHONY: sanitize_address
sanitize_address:
	@echo "---- Compilando con -fsanitize=address ----"
	$(CXX) -fsanitize=address $(CXXFLAGS) -o programa programa_sanitize.cpp
	@echo "---- Ejecutando ./programa (AddressSanitizer) ----"
	@./programa

# 4) ThreadSanitizer
#   - g++ -fsanitize=thread -g -pthread -o programa programa_sanitize_thread.cpp
#   - ./programa
.PHONY: sanitize_thread
sanitize_thread:
	@echo "---- Compilando con -fsanitize=thread (-pthread) ----"
	$(CXX) -fsanitize=thread $(CXXFLAGS) -pthread -o programa programa_sanitize_thread.cpp
	@echo "---- Ejecutando ./programa (ThreadSanitizer) ----"
	@./programa

# 5) Helgrind (Valgrind para data races)
#   - g++ -g -o programa programa_valgrind_thread.cpp
#   - valgrind --tool=helgrind ./programa
.PHONY: helgrind
helgrind:
	@echo "---- Compilando para Helgrind ----"
	$(CXX) $(CXXFLAGS) -o programa programa_valgrind_thread.cpp
	@echo "---- Ejecutando valgrind --tool=helgrind ./programa ----"
	@valgrind --tool=helgrind ./programa

# 6) GDB + Valgrind + Sanitizers + Helgrind en cadena
#    (Este target "all" lanzará uno tras otro los targets anteriores)
.PHONY: all
all: valgrind_leaks sanitize_address sanitize_thread helgrind

# --------------------------------------------------------------------------------
# Limpiar binarios
# --------------------------------------------------------------------------------
.PHONY: clean
clean:
	@echo "---- Eliminando ejecutables 'programa' ----"
	@rm -f programa

