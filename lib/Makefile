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

ifeq ($(OS),Windows_NT)
    RM_CMD = del /Q /F
    FIX_PATH = $(subst /,\,$1)
else
    RM_CMD = rm -f
    FIX_PATH = $1
endif

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
	$(RM_CMD) $(call FIX_PATH,$(OBJS))
	$(RM_CMD) $(call FIX_PATH,$(TARGET))