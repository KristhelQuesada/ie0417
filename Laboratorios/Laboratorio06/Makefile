# Variables
CXX = g++
CXXFLAGS = -std=c++20 -pthread -Wall -Wextra
SRC_DIR = src

# Archivos a compilar (sin el deadlock aún)
EXES_NO_DEADLOCK = 1_racecond_nosync 2_racecond_mutex 3_racecond_semaphore \
                   4_condition_vars 5_sync_barriers 7_final_example 8_final_example_fixed

# Archivo deadlock a compilar
EXE_DEADLOCK = 6_deadlock

# Se agrupan los archivos a compilar
EXES = $(EXES_NO_DEADLOCK) $(EXE_DEADLOCK)

# Regla por defecto: compilar todo
all: $(EXES)

# Compilar cada archivo
$(EXES): %: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

# Ejecutar un archivo ya compilado (por file)
run-%: %
	./$<

# Compilar y ejecutar en un solo paso (por file)
build-run-%: %
	./$<

# Compilar y ejecutar todos (con 6_deadlock al final) para que no detenga la ejecucion del resto
# ya que debido a lo que el ejemplo queria mostrar, este queda colgando (en ejecucion o espera)
run-all: all
	@for exe in $(EXES_NO_DEADLOCK); do \
		echo "===== Ejecutando $$exe ====="; \
		./$$exe && printf "\033[0;32m[OK]\033[0m %s ejecutado con éxito\n" "$$exe" || printf "\033[0;31m[Error]\033[0m Fallo durante la ejecución de %s\n" "$$exe"; \
		echo ""; \
	done
	@echo "===== Ejecutando 6_deadlock (último) ====="; \
	./$(EXE_DEADLOCK) && printf "\033[0;32m[OK]\033[0m %s ejecutado con éxito\n" "$(EXE_DEADLOCK)" || printf "\033[0;31m[Error]\033[0m Fallo durante la ejecución de %s\n" "$(EXE_DEADLOCK)"; \
	echo ""


# Limpiar ejecutables
clean:
	rm -f $(EXES)

.PHONY: all clean run-% build-run-% run-all
