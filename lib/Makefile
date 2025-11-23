CC = gcc

CFLAGS = -Wall -Wextra -std=c99 -Iinclude

# папка для виводу результатів компіляції
BIN_DIR = ../bin

# список файлів які треба скомпілювати
SRCS = src/board.c src/logic.c src/user.c

# об'єктні файли
OBJS = $(patsubst src/%.c, $(BIN_DIR)/%.o, $(SRCS))

# шлях до бібліотеки яку створимо
TARGET = $(BIN_DIR)/libsudoku.a

# алл, клін - команди
.PHONY: all clean

# головна ціль
all: $(TARGET)

# правило створення бібліотеки
$(TARGET): $(OBJS)
	@echo "--- [LIB] Archiving $@ ---"
	ar rcs $@ $^

# правило компіляції
$(BIN_DIR)/%.o: src/%.c
	@echo "--- [LIB] Compiling $< to $@"
	$(CC) $(CFLAGS) -c $< -o $@

# правило очищення
clean:
	@echo "--- [LIB] Cleaning artifacts ---"
	rm -f $(OBJS) $(TARGET)