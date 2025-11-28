#include "logic.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

bool valid_check(int board[SIZE_BOARD][SIZE_BOARD], int row, int col, int num) {        //функція перевірки правильності ходу гравця
    
    //перевірка рядка
    for (int i = 0; i < SIZE_BOARD; i++) {
        if (board[row][i] == num) {         //проходимо по всім рядам, якщо є це число - то повертаємо фолс
            return false;
        }
    }
    //перевірка стовпця
    for (int i = 0; i < SIZE_BOARD; i++) {        //проходимо по всім стовпцям, якщо є це число - повертаємо фолс
        if (board[i][col] == num) {
            return false;
        }
    }
    //перевірка квадрата 3х3
    int start_row = row - row % SUBGRID;
    int start_col = col - col % SUBGRID;
    //формули знаходять координати верхнього лівого кута квадрату 3х3

    for (int i = 0; i < SUBGRID; i++) {     //проходимось по рядкам квадрату
        for (int j = 0; j < SUBGRID; j++) {     //проходимось по стовпцям квадрату
            if (board[i + start_row][j + start_col] == num)  {       //перевіряємо 9 клітинок квадрату 3х3
            return false;                                           //якщо це число є - фолс
            }
        }
    }
    return true;    //якщо нема помилки - число можна ставити
}

bool sudoku_solve(int board[SIZE_BOARD][SIZE_BOARD], int row, int col) {        //функція розв'язання використовуючи бектрекінг

    if (row == SIZE_BOARD - 1 && col == SIZE_BOARD) {   //якщо дійшли до кінця дошки - рішення знайдено (вихід)
        return true;
    }
    if (col == SIZE_BOARD)  {     //якщо дійшли до кінця рядка - переходимо на наступний рядок, перший стовпець
        row++;
        col = 0; 
    }

    if (board[row][col] != EMPTY) {         //якщо клітинка не пуста -
        return sudoku_solve(board, row, col + 1);   //ідемо до наступної
    }

    int nums[SIZE_BOARD];
    for (int i = 0; i < SIZE_BOARD; i++) {    //створюємо массив чисел, аби пробувати їх у випадковому порядку
        nums[i] = i + 1;
    }

    for (int i = SIZE_BOARD - 1; i > 0; i--) {   //переміщуєм числа у массиві 
        int j = rand() % (i + 1);
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

    for (int i = 0; i < SIZE_BOARD; i++) {        
        int num = nums[i];          //беремо рандомне число
        if (valid_check(board, row, col, num)) {    //якщо правила дозволяють..
            board[row][col] = num;                  //..ставимо це число
            if (sudoku_solve(board, row, col + 1)) {    //пробуємо вирішити усю головоломку з цим числом  (рекурсія)
                return true;
            }     
            board[row][col] = EMPTY;        //якщо рекурсія повернула false - стираємо число і пробуємо наступне
        }
    }
    return false;   //якщо перебрали всі числа і жодне не підійшло - повертаємо фолс
}

bool win_check(Sudoku *s) {     //функція перевірки перемоги
    for (int i = 0; i < SIZE_BOARD; i++) {
        for (int j = 0; j < SIZE_BOARD; j++) {
            if (s->board[i][j] != s->solution[i][j])    //перевіряє дошку гравця з дошкою рішення
            return false;
        }
    }
    return true;
}

bool solution_check(int board[SIZE_BOARD][SIZE_BOARD]) {        //функція для перевірки внутрішніх конфліктів дошки
    for (int i = 0; i < SIZE_BOARD; i++) {
        for (int j = 0; j < SIZE_BOARD; j++) {
            int num = board[i][j];
            board[i][j] = EMPTY;        //тимчасово прибираємо це число
            
            if (!valid_check(board, i, j, num)) {       //якщо число не можна поставити за правилами
                board[i][j] = num;          //повертаємо
                return false;           //але фолс
            }
            board[i][j] = num;          //повертаємо
        }
    }
    return true;                       //але тру
}

void sudoku_generate(Sudoku *s) {       //генерація гри
    bool success = false;
    while (!success) {              //гарантія генерування валідної дошки
        board_init(s);              //очищаємо структуру

        if (sudoku_solve(s->solution, 0, 0)) {      //генеруєо рішення в массив solution
            if (solution_check(s->solution)) {      //додаткова перевірка цілісності рішення
                success = true;                     //якщо успіх - виходимо
            }
        }
    }

    for (int i = 0; i < SIZE_BOARD; i++) {
        for (int j = 0; j < SIZE_BOARD; j++) {
            s->board[i][j] = s->solution[i][j];     //копіюємо в нашу дошку наше правильне рішення
        }
    }

    const int cells_to_remove = 35;             //скільки клітинок видалити
    int removed = 0;                            //скільки видалено
    
    while (removed < cells_to_remove) {         //поки видалено менше ніж треба
        int row = rand() % SIZE_BOARD;                //випадковий рядок
        int col = rand() % SIZE_BOARD;                //випадковий стовпець
        
        if (s->board[row][col] != EMPTY) {      //видаляємо тільки якщо є число
            s->board[row][col] = EMPTY;
            removed++;
        }
    }

    for (int i = 0; i < SIZE_BOARD; i++) {
        for (int j = 0; j < SIZE_BOARD; j++) {

            if (s->board[i][j] != EMPTY) {          //якщо число залишилось після видалення - воно початкове 
                s->fixed[i][j] = true;              //фіксуємо
                s->initial[i][j] = true;            //робимо початковим
            }
        }
    }
}