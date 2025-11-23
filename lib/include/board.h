#ifndef BOARD_H
#define BOARD_H
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

#define SIZE 9          //константа розміру ігрового поля (9)
#define SUBGRID 3           //константа розміру малого квадрату 3х3
#define EMPTY 0             //константа порожньої клітинки

//Константи кольорів за допомогою ANSI
#define RESET "\033[0m"     //скидання до стандартного
#define RED "\033[31m"      //червоний колір
#define GREEN "\033[32m"    //зелений колір
#define CYAN "\033[36m"


//Головна структура данних
typedef struct {
    int board[SIZE][SIZE];          //поточний стан ігрового поля
    int solution[SIZE][SIZE];       //правильне рішення (для перевірки)
    bool fixed[SIZE][SIZE];         //прапорець: тру якщо клітинку не можна змінювати (фіксована)
    bool initial[SIZE][SIZE];       //прапорець: тру якщо число було згенероване граю 
} Sudoku;

void board_init(Sudoku *s); /*
Ініціалізує структуру судоку
Очищає всі масиви перед початком нової гри
*s вказівник на структуру судоку    */

void clear(); /*
очищує екран консолі згідно до ОС гравця    */

#endif // BOARD