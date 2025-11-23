#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
#include "logic.h"
#include "user.h"
#include "board.h"

int main() {

    srand(time(NULL));      //ініціалізуємо рандом за часом
    Sudoku s;               //створюємо змінну с типу Судоку
    clear();                //очищуєм екран перед початком
    sudoku_generate(&s);    //генеруємо нову гру (передаємо адресу &s, щоб функція змінила саме цю змінну)
    
    while (true) {          //нескінченний цикл, поки не вийдемо
        clear();                //очищаємо екран на кожному кроці
        board_print(&s);        //малюємо поточний, оновлений
        
        //виведення підказок для гравця
        printf("\n%sВвести: %sрядок стовпець число (наприклад: 1 2 3)\n", CYAN, RESET);
        printf("\n%sВаш хід:%s ", GREEN, RESET);
        
        char input[100];    //буфер для вводу
        if (fgets(input, sizeof(input), stdin) == NULL){        //зчитує рядок, якщо помилка - спочатку
            continue;
        }
        
        int row, col, num;

        if (sscanf(input, "%d %d %d", &row, &col, &num) == 3) { //сканф шукає 3 числа в рядку
            row--; col--;       //массиви починаються з 0, тому -1
            
            //перевірка меж
            if (row < 0 || row >= SIZE || col < 0 || col >= SIZE) {    //якщо числа менше   нуля або більше 9
                printf("\n%sНевірні координати!%s\n", RED, RESET);     //помилка
                printf("Enter..."); getchar(); continue;                //гетчар аби гравець побачив помилку
            }
            //перевірка фіксації
            if (s.fixed[row][col]) {
                printf("\n%sЦя клітинка зафіксована!%s\n", RED, RESET);
                printf("Enter..."); getchar(); continue;
            }
            //обробка ходу
            if (num >= 1 && num <= 9) {         //якщо введено 1 - 9
                if (num == s.solution[row][col]) {      //якщо число співпадає з рішенням
                    s.board[row][col] = num;            //ставимо його на дошку
                    s.fixed[row][col] = true;           //фіксуємо
                    printf("\n%sПравильно! Число %d встановлено.%s\n", GREEN, num, RESET);
                    printf("Enter..."); getchar();
                } else {                                //якщо число не підхожить - помилка
                    printf("\n%sПомилка! Це число тут не правильне.%s\n", RED, RESET);
                    printf("Enter..."); getchar();
                }
            } 
            else {
                printf("\n%sТільки 1-9!%s\n", RED, RESET);
                printf("Enter..."); getchar(); continue;
            }

            if (win_check(&s)) {        //якщо виконані умови перемоги
                clear();
                board_print(&s);
                printf("\n%s🎉 ВІТАЄМО! ВИ ПЕРЕМОГЛИ! 🎉%s\n", GREEN, RESET);
                printf("Enter для виходу..."); getchar();
                return 0; 
            }
            continue;
        } 
    }
    return 0;
}