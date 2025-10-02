#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define N 9

int main(void) {
    printf("Hello, world!\n");
    return 0;
}

void print_board(int board[N][N], int fixed[N][N])
{
    printf("    1 2 3   4 5 6   7 8 9\n");
    printf("  +-------+-------+-------+\n");
    for (int row = 0; row < N; row++)
    {                            // Цикл по всем строкам поля
        printf("%d |", row + 1); // Думаю вы знаете как это работает
        for (int c = 0; c < N; c++)
        {                   // Цикл по всем столбцам поля
            if (c % 3 == 0) // Добовляю пробел перед каждым 3 столбцом
                printf(" ");
            if (board[row][c] == 0) // Если клетка пуста, печатает точку
                printf(".");
            else
            {
                if (fixed[row][c])
                    printf("%d", board[row][c]); // Если клетка фикс то печатает ее значение
                else
                    printf("%d", board[row][c]); // Если клетка не фикс то печатает ее значение
            }
            printf(" ");
            if ((c + 1) % 3 == 0)
                printf("|"); // После каждого блока из 3 столбцов печатает вертикальную границу
        }
        printf("\n");
        if ((row + 1) % 3 == 0)
            printf("  +-------+-------+-------+\n"); //
    }
}
void copy_board(int src[N][N], int dest[N][N])
{
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            dest[i][j] = src[i][j];
        }
    }
}
int is_valid(int board[N][N], int row, int col, int num)
{
    for (int x = 0; x < N; x++)
    {
        if (board[row][x] == num) // Проверка строки
            return 0;
    }
    for (int x = 0; x < N; x++)
    {
        if (board[x][col] == num) // Проверка столбца
            return 0;
    }
    int startRow = row - row % 3, startCol = col - col % 3; // Определение начальных индексов 3x3 блока
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i + startRow][j + startCol] == num) // Проверка 3x3 блока
                return 0;
        }
    }
    return 1; // Если число не найдено в строке, столбце и блоке, возвращаем истину
}
int find_empty(int board[N][N], int *row, int *col) 
{
    for (*row = 0; *row < N; (*row)++)
    {
        for (*col = 0; *col < N; (*col)++)
        {
            if (board[*row][*col] == 0) // Если клетка пуста, возвращаем истину
                return 1;
        }
    }
    return 0; // Если пустых клеток нет, возвращаем ложь
}
int solve_sudoku(int board[N][N])
{
    int row, col;
    if (!find_empty(board, &row, &col)) // Если нет пустых клеток, судоку решено
        return 1;
    for (int num = 1; num <= 9; num++) // Пробуем числа от 1 до 9
    {
        if (is_valid(board, row, col, num)) // Если число можно поставить
        {
            board[row][col] = num; // Ставим число
            if (solve_sudoku(board)) // Рекурсивно пытаемся решить оставшуюся часть
                return 1;
            board[row][col] = 0; // Если не получилось, сбрасываем клетку
        }
    }
    return 0; // Если ни одно число не подошло, возвращаем ложь
}

