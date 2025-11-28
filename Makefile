CC = gcc

CFLAGS = -Wall -Wextra -std=c99 -Ilib/include
#прапори компіляції

BIN_DIR = bin
#папка куди будуть скидатися скомпільовані файли
LIB_DIR = lib
#папка, де знаходиться код бібліотеки

TARGET = sudoku
#ім'я кінцевого файлу

LIBRARY = $(BIN_DIR)/libsudoku.a
#шлях де буде скомпільована бібліотека

MAIN_OBJ = $(BIN_DIR)/main.o
#шлях об'єктного файлу мейна

ifeq ($(OS),Windows_NT)
	MKDIR_P = if not exist $(BIN_DIR) mkdir $(BIN_DIR)
	RM_CMD = del /Q /F
	RMDIR_CMD = rmdir /S /Q
else
	MKDIR_P = mkdir -p $(BIN_DIR)
	RM_CMD = rm -f
	RMDIR_CMD = rm -rf
endif

.PHONY: all prepare clean memcheck		#оголошення цілей

all: prepare $(TARGET)		#головна ціль

prepare:
	$(MKDIR_P)
#створення папки бін

$(LIBRARY): prepare
	@echo "--- [ROOT] Calling Library Makefile ---"
	$(MAKE) -C $(LIB_DIR)
#правила створення бібліотеки

$(MAIN_OBJ): render/main.c prepare
	@echo "--- [ROOT] Compiling Main ---"
	$(CC) $(CFLAGS) -c $< -o $@
#правило компіляції мейн.о

$(TARGET): $(MAIN_OBJ) $(LIBRARY)
	@echo "--- [ROOT] Linking Final Executable ---"
	$(CC) $(CFLAGS) $^ -o $@
#правило створення програми

memcheck: all
	@echo "--- [ROOT] Running Valgrind ---"
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(TARGET)
#правила для перевірки пам'яті

clean:
	@echo "--- [ROOT] Cleaning ---"
	$(RMDIR_CMD) $(BIN_DIR)
	$(RM_CMD) $(TARGET)
#правило для кліна