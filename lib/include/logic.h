#ifndef LOGIC_H
#define LOGIC_H
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
#include "board.h"

bool valid_check(int board[SIZE][SIZE], int row, int col, int num); /*
Перевіряє, чи можна поставити число num у клітинку [row][col] за правилами судоку
row - індекс рядка 0-8
col - індекс стовпця 0-8
num - число яке вставляємо */
bool sudoku_solve(int board[SIZE][SIZE], int row, int col);/*
створює або розв'язує судоку методом бектрекінгу
функція розв'язує судоку з якимось числом, якщо заходить в глухий кут - змінює число і продовжує розв'язок
*/

bool win_check(Sudoku *s);      /*перевіряє чи виконана умова перемоги (стандартні для судоку)
перевіряє умову перемоги завдяки порівнянню поточної дошки з дошкою рішення
*/

bool solution_check(int board[SIZE][SIZE]); /*перевіряє цілістність вже згенерованої дошки
проходиться по всім ччислм і робить valid_check*/

void sudoku_generate(Sudoku *s);  /*головна функція генерування гри
очищає дошку
генерує ідеальне рішення та копіює його
видаляє певну кількість чисел
фіксує числа які залишилися*/

#endif // LOGIC