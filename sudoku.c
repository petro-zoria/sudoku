#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define N 9

/*int main(void) {
    printf("Hello, world!\n");
    return 0;
}*/

 void print_board(int board[N][N], int fixed[N][N]) {
    printf("    1 2 3   4 5 6   7 8 9\n");
    printf("  +-------+-------+-------+\n");
    for (int row = 0; row < N; row++) {                                   // Цикл по всіх рядках поля
        printf("%d |", row+1);                                            // Думаю, ви знаєте як це працює
        for (int colm = 0; colm < N; colm++) {                            // Цикл по всіх стовпцях поля
            if (colm % 3 == 0)                                            // Додаю прогалину перед кожним 3 стовпцем
                printf(" ");                            
            if (board[row][colm] == 0)                                    // Якщо клітина порожня, друкує крапку
                printf(".");                      
            else {
                if (fixed[row][colm]) printf("%d", board[row][colm]);     // Якщо клітина фікс то друкує її значення
                else printf("%d", board[row][colm]);                      // Якщо клітина не фікс то друкує її значення
            }
            printf(" ");
            if ((colm+1)%3==0) printf("|");                               // Після кожного блоку із 3 стовпців друкує вертикальний кордон
        }
        printf("\n");
        if ((row+1)%3==0) printf("  +-------+-------+-------+\n");        // Після кожного блоку із 3 рядків друкує горизонтальний кордон
    }
}
