#include "board.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>


void board_init (Sudoku *s) {       //функція ініціалізації дошки    *s щоб змінювати оригінальну структуру
    for (int i = 0; i < SIZE; i++) {        //зовнішній цикл: перебір рядків дошки
        for (int j = 0; j < SIZE; j++) {    //внутрішній цикл: перебір стовпців дошки
            s->board[i][j] = EMPTY;         //очищає массив клітинок від попередніх ігр
            s->solution[i][j] = EMPTY;      //очищає массив рішення від попередніх ігр
            s->fixed[i][j] = false;         //очищає прапорець фіксації
            s->initial[i][j] = false;       //очищає прапорець початкового числа
        }
    }
}

void clear() {             //функція очищення терміналу
    #ifdef _WIN32       //перевірка чи система є Віндовс (або компілюється у ньому)
        system("cls");      //очистка терміналу для віндовс
    #else                  //у інших випадках (лінукс, макінтош) 
        system("clear");    //очистка для юнікс-систем
    #endif
}