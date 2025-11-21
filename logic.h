#ifndef LOGIC
#define LOGIC
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

bool valid_check(); 
//перевіряє валідність розміщення num у (row; size) за правилами судоку

bool sudoku_solve();       //вирішує судоку (знаходить правильні числа для заповнення) за допомогою бектрекінгу

bool win_check();      //перевіряє чи виконана умова перемоги (стандартні для судоку)

void sudoku_generate ();  //генерує готове для гри поле судоку 

bool current_check();   //після кожного ходу гравця, перевіряє чи підходитть туди цифра

#endif // LOGIC