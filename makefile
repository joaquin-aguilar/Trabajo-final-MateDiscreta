# Variables
CC = gcc
CFLAGS = -Wall -I./src/libs
SRC = src/src.c
OUT_DIR = builds
OUT = $(OUT_DIR)/programa.out

# Regla por defecto
all: $(OUT)

# Compilación
$(OUT): $(SRC)
	mkdir -p $(OUT_DIR)
	$(CC) $(CFLAGS) -o $(OUT) $(SRC)

# Limpieza
clean:
	rm -rf $(OUT_DIR)

# Ejecución con parámetros
run: all
	./$(OUT) $(ARGS)
