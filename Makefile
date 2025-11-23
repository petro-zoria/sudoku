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

.PHONY: all prepare clean memcheck		#оголошення цілей

all: prepare $(TARGET)		#головна ціль

prepare:
	@mkdir -p $(BIN_DIR)		
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
	rm -rf $(BIN_DIR)
	rm -f $(TARGET)
#правило для кліна