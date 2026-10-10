/*
 * Студент: Белов Иван Александрович
 * Группа: ПИ-1 1
 * Лабораторная работа 9
 */


#include <stdio.h>

#define LIMIT 5

int main(void) {
    int a[LIMIT][LIMIT];
    int rows, cols;

    printf("Введите rows и cols (1..5): ");
    if (scanf("%d%d", &rows, &cols) != 2) {
        printf("Ошибка ввода\n");
        return 1;
    }

    if (rows < 1 || rows > LIMIT || cols < 1 || cols > LIMIT) {
        printf("Ошибка размера\n");
        return 1;
    }

    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            if (scanf("%d", &a[row][col]) != 1) {
                printf("Ошибка ввода\n");
                return 1;
            }
            if (a[row][col] < -1000 || a[row][col] > 1000) {
                printf("Ошибка значения\n");
                return 1;
            }
        }
    }

    printf("Матрица:\n");
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            printf("%6d", a[row][col]);
        }
        printf("\n");
    }

    printf("Суммы столбцов:\n");
    for (int col = 0; col < cols; col++) {
        long long colSum = 0;
        for (int row = 0; row < rows; row++) {
            colSum += a[row][col];
        }
        printf("Столбец %d: %lld\n", col, colSum);
    }

    long long bestSum = 0;
    for (int col = 0; col < cols; col++) {
        bestSum += a[0][col];
    }
    int bestRow = 0;

    for (int row = 1; row < rows; row++) {
        long long rowSum = 0;
        for (int col = 0; col < cols; col++) {
            rowSum += a[row][col];
        }
        if (rowSum < bestSum) {
            bestSum = rowSum;
            bestRow = row;
        }
    }

    printf("Строка с минимальной суммой: %d\n", bestRow);
    printf("Её сумма = %lld\n", bestSum);

    return 0;
}