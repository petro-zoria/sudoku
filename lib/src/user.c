#include "user.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

void board_print(Sudoku *s) {   //оголошення функції виведення дошки

    printf("\n");
    printf("    ");

    for (int i = 1; i <= SIZE; i++) {       //виведення номерів стовпців
        printf("%s%d%s ", CYAN, i, RESET);      //виведення номерів у кольорі
        if (i % 3 == 0 && i < SIZE) printf("  ");   //якщо це 3 або 6 стовпець, розділяємо візуально блоки 3х3
    }

    printf("\n");
    printf("  ┏━━━━━━━┳━━━━━━━┳━━━━━━━┓\n");
    
    for (int i = 0; i < SIZE; i++) {            //виведення рядків
        printf("%s%d%s ┃ ", CYAN, i + 1, RESET);       //колір
        for (int j = 0; j < SIZE; j++) {        //виведення клітинок у рядку
            
            //логіка відображення вмісту клітинки
            if (s->board[i][j] == EMPTY) {      //якщо клітинка порожня
                printf(". ");

            } else if (s->initial[i][j]) {      //якщо це початкове число
                printf("%d ", s->board[i][j]);

            } else {                            //якщо число гравця
                printf("%s%d%s ", GREEN, s->board[i][j], RESET);
            }
        
            if ((j + 1) % 3 == 0 && j < SIZE - 1) printf("┃ ");     //вертикальне розділення після 3 і 6 стовпців
        }
        printf("┃\n");      //кінець рядка

        if ((i + 1) % 3 == 0 && i < SIZE - 1) printf("  ┣━━━━━━━╋━━━━━━━╋━━━━━━━┫\n");  //після 3 да 6 рядків, розділюємо дошку
    }
    printf("  ┗━━━━━━━┻━━━━━━━┻━━━━━━━┛\n");        //нижня рамка
}